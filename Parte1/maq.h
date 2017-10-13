#include "pilha.h"

#define MAXMEM 100

typedef struct {
  Pilha pil;
  Pilha exec;
  OPERANDO Mem[MAXMEM];
  INSTR *prog;
  int ip;
  int rbp;
  int id;
  int time;
  int position[2];
  int cristais;
} Maquina;

Maquina *cria_maquina(INSTR *p, int id, int posx, int posy);

void destroi_maquina(Maquina *m);

void exec_maquina(Maquina *m, int n);


OPERANDO cria_operando(Tipo t, int arg);
void imprime_op(OPERANDO arg);