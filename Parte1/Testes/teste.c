#include <stdio.h>
#include "maq.h"

INSTR programa[] = {
  {PUSH, 10},
  {DUP, 0},
  {PRN, 0},
  {PUSH, 1},
  {SUB, 0},
  {DUP, 0},
  {PUSH, 0},
  {EQ, 0},
  {JIF, 1},
  {PRN, 0},
  {END, 0},
};

int main(int argc, char *argv) {
	Maquina *maq = cria_maquina(programa);
	exec_maquina(maq, 100);
	destroi_maquina(maq);
	return 0;
}
