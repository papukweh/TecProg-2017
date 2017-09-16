#include <stdio.h>
#include <stdlib.h>
#include "maq.h"

#define DEBUG

#ifdef DEBUG
#  define D(X) X
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
  "STS",
  "RCS",
  "EQ",
  "GT",
  "GE",
  "LT",
  "LE",
  "NE",
  "STO",
  "RCL",
  "STL",
  "RCE",
  "ALC",
  "FRE",
  "SAVE",
  "REST",
  "END",
  "PRN"
};
#else
#  define D(X)
#endif

static void Erro(char *msg) {
  fprintf(stderr, "%s\n", msg);
}

static void Fatal(char *msg, int cod) {
  Erro(msg);
  exit(cod);
}

Maquina *cria_maquina(INSTR *p) {
  Maquina *m = (Maquina*)malloc(sizeof(Maquina));
  if (!m) Fatal("Memória insuficiente",4);
  m->ip = 0;
  m->rbp = 0;
  m->prog = p;
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

void exec_maquina(Maquina *m, int n) {
  int i;

  for (i = 0; i < n; i++) {
	OpCode   opc = prg[ip].instr;
	OPERANDO arg = prg[ip].op;

	D(printf("%3d: %-4.4s %d\n     ", ip, CODES[opc], arg));

	switch (opc) {
	  OPERANDO tmp;
	case PUSH:
	  empilha(pil, arg);
	  break;
	case POP:
	  desempilha(pil);
	  break;
	case DUP:
	  tmp = desempilha(pil);
	  empilha(pil, tmp);
	  empilha(pil, tmp);
	  break;
	case ADD:
	  empilha(pil, desempilha(pil)+desempilha(pil));
	  break;
	case SUB:
	  tmp = desempilha(pil);
	  empilha(pil, desempilha(pil)-tmp);
	  break;
	case MUL:
	  empilha(pil, desempilha(pil)*desempilha(pil));
	  break;
	case DIV:
	  tmp = desempilha(pil);
	  empilha(pil, desempilha(pil)/tmp);
	  break;
	case JMP:
	  ip = arg;
	  continue;
	case JIT:
	  if (desempilha(pil) != 0) {
		ip = arg;
		continue;
	  }
	  break;
	case JIF:
	  if (desempilha(pil) == 0) {
		ip = arg;
		continue;
	  }
	  break;
	//Empilha o endereço de retorno na pilha de execução,
	// atualiza o valor de rbp para o topo
	case CALL:
	  empilha(exec, ip);
	  ip = arg;
	  rbp = exec->topo;
	  continue;
	//Atualiza o valor do topo para o valor de rbp e muda
	// o ip para o endereço de retorno
	case RET:
	  exec->topo = rbp;
	  ip = desempilha(exec);
	  break;
	case EQ:
	  if (desempilha(pil) == desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case GT:
	  if (desempilha(pil) < desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case GE:
	  if (desempilha(pil) <= desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case LT:
	  if (desempilha(pil) > desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case LE:
	  if (desempilha(pil) >= desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case NE:
	  if (desempilha(pil) != desempilha(pil))
		empilha(pil, 1);
	  else
		empilha(pil, 0);
	  break;
	case STO:
	  m->Mem[arg] = desempilha(pil);
	  break;
	case RCL:
	  empilha(pil,m->Mem[arg]);
	  break;
	//Remove o primeiro elemento da pilha de dados e armazena
	// no vetor de variáveis locais (posição rbp+argumento)
	case STL:
	  exec->val[rbp + arg] = desempilha(pil);
	  break;
	//Empilha o elemento do vetor de variáveis locais na posição
	// rbp+argumento na pilha de dados
	case RCE:
	  empilha(pil, exec->val[rbp + arg]);
	  break;
	//Aloca um espaço na pilha de execução para o vetor de variáveis
	// locais, com tamanho argumento (mudando o topo da pilha de execução)
	case ALC:
	  exec->topo = exec->topo + arg;
	  break;
	//Libera o espaço alocado (o argumento deve ser o mesmo do usado em ALC),
	// retornando o valor do topo da pilha para o que era antes da alocação
	case FRE:
	  exec->topo = exec->topo - arg;
	  break;
	//Salva o valor de rbp, empilhando-o na pilha de execução
	case SAVE:
	  empilha(exec, rbp);
	  break;
	//Restaura o valor de rbp, desempilhando-o da pilha de execução
	case REST:
	  rbp = desempilha(exec);
	  break;
	case END:
	  return;
	case PRN:
	  printf("%d\n", desempilha(pil));
	  break;
	}
	D(puts("Pilha de dados:\n"));
	D(imprime(pil,5));
	D(puts("\n Pilha de execução: \n"));
	D(imprime(exec,10));
	D(puts("\n"));
	D(printf("topo dados = %d \n", pil->topo));
	D(printf("topo exec = %d \n", exec->topo));
	D(printf("rbp = %d \n", rbp));
	D(puts("++++++++++++++++++++++++++++++++++\n"));
	ip++;
  }
}
