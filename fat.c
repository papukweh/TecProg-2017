#include <stdio.h>
#include "maq.h"

int main(int argc, char *argv) {
    INSTR fat[] = {
    {PUSH, cria_operando(NUM, 8)},  // 0
    {SAVE, 0},  // 1
    {CALL, cria_operando(NUM, 6)},  // 2
    {REST, 0},  // 3
    {PRN,    0},  // 4
    {END,    0},  // 5
    {ALC,    cria_operando(NUM, 1)},  // 6
    {DUP,    0},  // 7
    {STL,    0},  // 8 n
    {PUSH, cria_operando(NUM, 1)},  // 9
    {EQ,     0},  // 10 n == 1 ?
    {JIF, cria_operando(NUM, 15)},  // 11
    {PUSH, cria_operando(NUM, 1)},  // 12
    {FRE,    cria_operando(NUM, 1)},  // 13
    {RET,    0},  // 14
    {RCE,    0},  // 15 n
    {PUSH, cria_operando(NUM, 1)},  // 16
    {SUB,    0},  // 17 n-1
    {SAVE, 0},  // 18
    {CALL, cria_operando(NUM, 6)},  // 19 fat(n-1)
    {REST, 0},  // 20
    {RCE,    0},  // 21 n
    {MUL,    0},  // 22 n * fat(n-1)
    {FRE,    cria_operando(NUM, 1)},  // 23
    {RET,    0}   // 24
};
    Maquina *maq = cria_maquina(fat,0,0,0);
    exec_maquina(maq, 200);
    destroi_maquina(maq);
    return 0;
}
