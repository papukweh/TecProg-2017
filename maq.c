#include <stdio.h>
#include <stdlib.h>
#include "maq.h"

#define DEBUG

#ifdef DEBUG
	#define D(X) X
#else
#define D(X)
#endif

char *CODES[] = {
  "PUSH",
  "POP",
  "DUP",
  "ADD",
  "SUB",
  "MUL",
  "DIV",
  "JMP",
  "JIT",
  "JIF",
  "CALL",
  "RET",
  "EQ",
  "GT",
  "GE",
  "LT",
  "LE",
  "DIFF",
  "STO",
  "RCL",
  "STL",
  "RCE",
  "ALC",
  "FRE",
  "SAVE",
  "REST",
  "END",
  "PRN",
  "SYS",
  "ATR"
};

char *Chamadas[] = {
  "MOV",
  "REC",
  "DEP",
  "VER",
};

char *Direcao[] = {
  "N",
  "NE",
  "SE",
  "S",
  "SW",
  "NW",
};

static void Erro(char *msg) {
  fprintf(stderr, "%s\n", msg);
}
static void Fatal(char *msg, int cod) {
  Erro(msg);
  exit(cod);
}

Maquina *cria_maquina(INSTR *p, int iSize, int id, int posx, int posy) {
  Maquina *m = (Maquina*)malloc(sizeof(Maquina));
  if (!m) Fatal("Memória insuficiente",4);
  m->pil = *cria_pilha();
  m->exec = *cria_pilha();
  m->id = id;
  m->position[0]=posx;
  m->position[1]=posy;
  m->ip = 0;
  m->rbp = 0;
  m->time = 0;
  m->instrSize = iSize;
  m->prog = p;
  m->cristais = 0;
  return m;
}

void destroi_maquina(Maquina *m) {
  free(m);
}

/* Alguns macros para facilitar a leitura do código */
#define ip (m->ip)
#define pil (&m->pil)
#define exec (&m->exec)
#define prg (m->prog)
#define rbp (m->rbp)
#define id (m->id)


void exec_maquina(Maquina *m, int n) {
    int i, tmp, tmp2;
    OPERANDO resposta, tmpop;
    for (i = 0; i < n; i++) {
      	if(ip>=m->instrSize-1) ip = 0;
      	OpCode   opc = prg[ip].instr;
      	OPERANDO arg = prg[ip].op;

      	D(printf("Turno da máquina %d\n", id));
      	D(printf("%3d: %-4.4s     ", ip, CODES[opc]); imprime_op(arg); puts("");); 
      
        switch (opc) {
            //Se pilha de dados tiver mais que dois elementos, desempilha ambos
            //os soma, e adiciona o resultado a pilha
    	    case ADD:
                if(pil->topo >= 2){
    		  		tmp = desempilha(pil).valor.n;
    		 	 	tmp2 = desempilha(pil).valor.n;
    		  		empilha(pil, cria_operando(NUM, tmp+tmp2));
    			}
    			break;
            //Se pilha de dados tiver mais que dois elementos, desempilha ambos
            //subtrai o topo do segundo, e adiciona o resultado a soma a pilha
    		case SUB: 
    			if(pil->topo >= 2){
    			  tmp = desempilha(pil).valor.n;
    			  tmp2 = desempilha(pil).valor.n;
    			  empilha(pil, cria_operando(NUM, tmp2-tmp));
    			}
    		    break;
            //Se pilha de dados tiver mais que dois elementos, desempilha ambos
            //Multiplica seus valores e adiciona o resultado a pilha
    		case MUL: 
    			if(pil->topo >= 2){
    			  tmp = desempilha(pil).valor.n;
    			  tmp2 = desempilha(pil).valor.n;
    			  empilha(pil, cria_operando(NUM, tmp*tmp2));
    			}
    			break;
            //Se pilha de dados tiver mais que dois elementos, desempilha ambos
            //Divide o segundo pelo que estava no topo, e adiciona o resultado a pilha
    		case DIV: 
                if(pil->topo >= 2){  
    			  tmp = desempilha(pil).valor.n;
    			  tmp2 = desempilha(pil).valor.n;
    			  empilha(pil, cria_operando(NUM, tmp2/tmp));
                }
    			break;
    		//Pula para a instrucao de indice igual ao valor encontrado no operando
    		case JMP:
    			  ip = arg.valor.n;
    			  continue;
            //Desempilha o topo da pilha de dados e, caso o valor seja diferente de zero,
            //move o ponteiro de instrucoes para o valor desempilhado
    		case JIT:
                if(pil->topo == 0) break;
                if (desempilha(pil).valor.n != 0) {
                    ip = arg.valor.n;
                    continue;
                }
                break;
            //Desempilha o topo da pilha de dados e, caso o valor seja igual a zero,
            //move o ponteiro de instrucoes para o valor desempilhado
    		case JIF: //k
    		    if(pil->topo == 0) break;
                if (desempilha(pil).valor.n == 0) {
    				ip = arg.valor.n;
    				continue;
    			  }
                    break;
    		//Empilha o endereço de retorno na pilha de execução,
    		// atualiza o valor de rbp para o topo
    		case CALL:
    			  empilha(exec, cria_operando(NUM, ip));
    			  ip = arg.valor.n;
    			  rbp = exec->topo;
    			  continue;
    		//Atualiza o valor do topo para o valor de rbp e muda
    		// o ip para o endereço de retorno
    		case RET:
    			  exec->topo = rbp;
    			  ip = desempilha(exec).valor.n;
    			  break;
            //Desempilha dois operandos da pilha de dados, caso sejam iguais,
            //empilha '1' e caso sejam diferentes, empilha '0'
    		case EQ:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n == desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
            //Desempilha dois operandos da pilha de dados, caso o primeiro seja
            //menor que o segundo, empilha '1', caso contrario, empilha '0'
            case GT:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n < desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
            //Desempilha dois operandos da pilha de dados, caso o primeiro seja
            //menor ou igual ao segundo, empilha '1', caso contrario, empilha '0'
            case GE:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n <= desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
            //Desempilha dois operandos da pilha de dados, caso o primeiro seja
            //maior que o segundo, empilha '1', caso contrario, empilha '0'
            case LT:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n > desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
            //Desempilha dois operandos da pilha de dados, caso o primeiro seja
            //maior ou igual ao segundo, empilha '1', caso contrario, empilha '0'
            case LE:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n >= desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
            //Desempilha dois operandos da pilha de dados, caso sejam diferentes,
            //empilha '1' e caso sejam diferentes, empilha '0'
            case DIFF:
    			if(pil->topo < 1) break;
                if (desempilha(pil).valor.n != desempilha(pil).valor.n)
                    empilha(pil, cria_operando(NUM, 1));
                else
                    empilha(pil, cria_operando(NUM, 0));
                break;
                
            //
            //ate aqui tudo ok
            //
            
            //Aloca um espaço na pilha de execução para o vetor de variáveis
            //locais, com tamanho argumento (mudando o topo da pilha de execução)
            case ALC:
                exec->topo = exec->topo + arg.valor.n;
                break;
            //Libera o espaço alocado (o argumento deve ser o mesmo do usado em ALC),
            //retornando o valor do topo da pilha para o que era antes da alocação
            case FRE:
                exec->topo = exec->topo - arg.valor.n;
                break;
            //Salva o valor de rbp, empilhando-o na pilha de execução
            case SAVE:
                empilha(exec, cria_operando(NUM, rbp));
                break;
    		//Restaura o valor de rbp, desempilhando-o da pilha de execução
            case REST:
                rbp = desempilha(exec).valor.n;
                break;
            case PUSH:
                // printf("%d\n", arg.valor.n);
                empilha(pil, arg);
                break;
            case POP:
                if(pil->topo == 0) break;
                desempilha(pil);
                break;
            case DUP:
                if(pil->topo == 0) break;
                tmpop = desempilha(pil);
                empilha(pil, tmpop);
                empilha(pil, tmpop);
                break;
            case STO:
                if(pil->topo == 0) break;
                m->Mem[arg.valor.n] = desempilha(pil);
                break;
            case RCL:
                empilha(pil,m->Mem[arg.valor.n]);
                break;
            //Remove o primeiro elemento da pilha de dados e armazena
            // no vetor de variáveis locais (posição rbp+argumento)
            case STL:
                if(pil->topo == 0) break;
                exec->val[rbp + arg.valor.n] = desempilha(pil);
                break;
            //Empilha o elemento do vetor de variáveis locais na posição
            // rbp+argumento na pilha de dados
            case RCE:
                empilha(pil, exec->val[rbp + arg.valor.n]);
                break;
            case END:
                return;
            case PRN:
                if(pil->topo == 0) break;
                printf("%d\n", desempilha(pil).valor.n);
                break;
            case SYS: 
                resposta = cria_operando(NUM, Sistema(id));
                D(printf("Resposta: %d\n", resposta.valor.n));
                empilha(pil, resposta);
                i=n;
                break;
            case ATR:
                if(pil->topo == 0) break;
                tmpop = desempilha(pil);
                if(tmpop.t==TILE){
	                switch (arg.valor.n){
	                    case 0:
	                        empilha(pil, cria_operando(NUM, tmpop.valor.tile.terreno));
	                        break;
	                    case 1:
	                        empilha(pil, cria_operando(NUM, tmpop.valor.tile.cristais));
	                        break;
	                    case 2:
	                        empilha(pil, cria_operando(NUM, tmpop.valor.tile.ocupado));
	                        break;
	                    case 3:
	                        empilha(pil, cria_operando(NUM, tmpop.valor.tile.base));
	                        break;
	                    default:
	                        Erro("Atributo inexistente");
	                        break;
                    }//fecha o "switch"
       			}//fecha o "if"
        		else{
        		Erro("Tipo invalido");
        		}
        		break;
			} //fecha o "switch"
    
    	//Imprimindo as pilhas por motivos de debug
    	D(puts("Pilha de dados:\n"));
    	D(imprime(pil,5));
    	D(puts("\n Pilha de execução: \n"));
    	D(imprime(exec,10));
    	D(puts("\n"));
    	D(puts("++++++++++++++++++++++++++++++++++\n"));
    	ip++;
    }//fecha o "for"
}//fecha o "exec_maquina"
    
//Funções auxiliares
OPERANDO cria_operando(Tipo t, int arg){
   	OPERANDO a;
   	a.t = t;
   	switch(t){
   		case NUM:
   		  a.valor.n = arg;
   		  break;
   		case ACAO:
   		  a.valor.ac = arg;
   		  break;
   		case VAR:
   		  a.valor.v = arg;
   		  break;
	} 
	return a;
}

void imprime_op(OPERANDO arg){
	switch(arg.t){
		case NUM:
		  printf("%d", arg.valor.n);
		  break;
		case ACAO:
		  printf("%s", Chamadas[arg.valor.ac]);
		  break;
		case VAR:
		  printf("%s", Direcao[arg.valor.v]);
		  break;
		case TILE:
		  printf("Tile {%d, %d, %d, %d}", arg.valor.tile.terreno, arg.valor.tile.cristais, arg.valor.tile.ocupado, arg.valor.tile.base);
		  break;
		default:
			break;
	}
}
