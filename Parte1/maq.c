#include <stdio.h>
#include <stdlib.h>
#include "maq.h"

#define DEBUG

#ifdef DEBUG
	#define D(X) X
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
#else
#define D(X)
#endif

static void Erro(char *msg) {
  fprintf(stderr, "%s\n", msg);
}

static void Fatal(char *msg, int cod) {
  Erro(msg);
  exit(cod);
}

Maquina *cria_maquina(INSTR *p, int id, int posx, int posy) {
  Maquina *m = (Maquina*)malloc(sizeof(Maquina));
  if (!m) Fatal("Memória insuficiente",4);
  m->pil = *cria_pilha();
  m->exec = *cria_pilha();
  m->id = id;
  m->position[0]=posx;
  m->position[1]=posy;
  m->ip = 0;
  m->rbp = 0;
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
	OpCode   opc = prg[ip].instr;
	OPERANDO arg = prg[ip].op;

	D(printf("Turno da máquina %d\n", id));
	D(printf("%3d: %-4.4s %d\n     ", ip, CODES[opc], arg.n));

			switch (opc) {
			case ADD: //ok
			  tmp = desempilha(pil).n;
			  tmp2 = desempilha(pil).n;
			  empilha(pil, cria_operando(NUM, tmp+tmp2));
			  break;
			case SUB: //ook
			  tmp = desempilha(pil).n;
			  tmp2 = desempilha(pil).n;
			  empilha(pil, cria_operando(NUM, tmp2-tmp2));
			  break;
			case MUL: //ok
			  tmp = desempilha(pil).n;
			  tmp2 = desempilha(pil).n;
			  empilha(pil, cria_operando(NUM, tmp*tmp2));
			  break;
			case DIV: //ok
			  tmp = desempilha(pil).n;
			  tmp2 = desempilha(pil).n;
			  empilha(pil, cria_operando(NUM, tmp2/tmp));
			  break;
			case JMP: //ok
			  ip = arg.n;
			  continue;
			case JIT: //k
			  if (desempilha(pil).n != 0) {
				ip = arg.n;
				continue;
			  }
			  break;
			case JIF: //k
			  if (desempilha(pil).n == 0) {
				ip = arg.n;
				continue;
			  }
			  break;
			//Empilha o endereço de retorno na pilha de execução,
			// atualiza o valor de rbp para o topo
			case CALL:
			  empilha(exec, cria_operando(NUM, ip));
			  ip = arg.n;
			  rbp = exec->topo;
			  continue;
			//Atualiza o valor do topo para o valor de rbp e muda
			// o ip para o endereço de retorno
			case RET:
			  exec->topo = rbp;
			  ip = desempilha(exec).n;
			  break;
			case EQ:
			  if (desempilha(pil).n == desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			case GT:
			  if (desempilha(pil).n < desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			case GE:
			  if (desempilha(pil).n <= desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			case LT:
			  if (desempilha(pil).n > desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			case LE:
			  if (desempilha(pil).n >= desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			case DIFF:
			  if (desempilha(pil).n != desempilha(pil).n)
				empilha(pil, cria_operando(NUM, 1));
			  else
				empilha(pil, cria_operando(NUM, 0));
			  break;
			//Aloca um espaço na pilha de execução para o vetor de variáveis
			// locais, com tamanho argumento (mudando o topo da pilha de execução)
			case ALC:
			  exec->topo = exec->topo + arg.n;
			  break;
			//Libera o espaço alocado (o argumento deve ser o mesmo do usado em ALC),
			// retornando o valor do topo da pilha para o que era antes da alocação
			case FRE:
			  exec->topo = exec->topo - arg.n;
			  break;
			//Salva o valor de rbp, empilhando-o na pilha de execução
			case SAVE:
			  empilha(exec, cria_operando(NUM, rbp));
			  break;
			//Restaura o valor de rbp, desempilhando-o da pilha de execução
			case REST:
			  rbp = desempilha(exec).n;
			  break;
			case PUSH:
			  printf("%d\n", arg.n);
			  empilha(pil, arg);
			  break;
			case POP:
			  desempilha(pil);
			  break;
			case DUP:
			  tmpop = desempilha(pil);
			  empilha(pil, tmpop);
			  empilha(pil, tmpop);
			  break;
			case STO:
			  m->Mem[arg.n] = desempilha(pil);
			  break;
			case RCL:
			  empilha(pil,m->Mem[arg.n]);
			  break;
			//Remove o primeiro elemento da pilha de dados e armazena
			// no vetor de variáveis locais (posição rbp+argumento)
			case STL:
			  exec->val[rbp + arg.n] = desempilha(pil);
			  break;
			//Empilha o elemento do vetor de variáveis locais na posição
			// rbp+argumento na pilha de dados
			case RCE:
			  empilha(pil, exec->val[rbp + arg.n]);
			  break;
			case END:
			  return;
			case PRN:
			  printf("%d\n", desempilha(pil).n);
			  break;
			case SYS: 
			  resposta = cria_operando(NUM, Sistema(id));
			  D(printf("Resposta: %d\n", resposta.n));
			  empilha(pil, resposta);
			  i=n;
			  break;
			case ATR:
			  tmpop = desempilha(pil);
			  if(tmpop.t==TILE){
			  	switch (arg.n){
			  		case 0:
			  		empilha(pil, cria_operando(NUM, tmpop.tile.terreno));
			  		break;
			  		case 1:
			  		empilha(pil, cria_operando(NUM, tmpop.tile.terreno));
			  		break;
			  		case 2:
			  		empilha(pil, cria_operando(NUM, tmpop.tile.terreno));
			  		break;
			  		case 3:
			  		empilha(pil, cria_operando(NUM, tmpop.tile.terreno));
			  		break;
			  		default:
			  		Erro("Atributo inexistente");
			  	}
			  }
			  else{
			  	Erro("Tipo invalido");
			  }
			  break;
	}


	//Imprimindo as pilhas por motivos de debug
	D(puts("Pilha de dados:\n"));
	D(imprime(pil,5));
	D(puts("\n Pilha de execução: \n"));
	D(imprime(exec,10));
	D(puts("\n"));
	// D(printf("topo dados = %d \n", pil->topo));
	// D(printf("topo exec = %d \n", exec->topo));
	// D(printf("rbp = %d \n", rbp));
	D(puts("++++++++++++++++++++++++++++++++++\n"));
	ip++;
  }
}

//Funções auxiliares
OPERANDO cria_operando(Tipo t, int arg){
	OPERANDO a;
	a.t = t;
	switch(t){
		case NUM:
		a.n = arg;
		//printf("%d\n", a.n);
		break;
		case ACAO:
		a.ac = arg;
		break;
		case VAR:
		a.v = arg;
		break;
	} 
	return a;
}
OPERANDO cria_operando_tile(Tipo t, Tile arg){
  OPERANDO a;
  a.t = t;
  a.n = 0;
  a.v = 0;
  a.ac = 0;
  a.tile = arg;
}
OPERANDO cria_operando_acao(Tipo t, High_instr arg){
  OPERANDO a;
  a.t = t;
  a.n = 0;
  a.v = 0;
 // a.tile = Inicializa(0,0,0,0);
  a.ac = arg;
}
OPERANDO cria_operando_dir(Tipo t, Dir arg){
  OPERANDO a;
  a.t = t;
  a.n = 0;
  a.ac = 0;
  //a.tile = Inicializa(0,0,0,0);
  a.v = arg;
}

