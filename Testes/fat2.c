#include <stdio.h>
#include "maq.h"

INSTR fat[] = {
    	{PUSH, 7},  // 0
    	{SAVE, 0},  // 1
    	{CALL, 6},  // 2
    	{REST, 0},  // 3
    	{PRN,  0},  // 4
    	{END,  0},  // 5

	{ALC,  1},  // 6
    	{DUP,  0},  // 7
    	{STL,  0},  // 8 n
    	{PUSH, 1},  // 9
    	{EQ,   0},  // 10 n == 1 ?
    	{JIF, 15},  // 11
    	{PUSH, 1},  // 12
    	{FRE,  1},  // 13
    	{RET,  0},  // 14
    	{RCE,  0},  // 15 n
    	{PUSH, 1},  // 16
    	{SUB,  0},  // 17 n-1
	{SAVE, 0},  // 18
    	{CALL, 6},  // 19 fat(n-1)
    	{REST, 0},  // 20
    	{RCE,  0},  // 21 n
    	{MUL,  0},  // 22 n * fat(n-1)
    	{FRE,  1},  // 23
    	{RET,  0}   // 24
};

int main(int argc, char *argv) {
	Maquina *maq = cria_maquina(fat);
	exec_maquina(maq, 200);
	destroi_maquina(maq);
	return 0;
}
