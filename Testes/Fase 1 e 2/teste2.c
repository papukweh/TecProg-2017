#include <stdio.h>
#include "maq.h"

INSTR programa[] = {
    {PUSH, 1},
    {SAVE, 0},
    {CALL, 5},
    {REST, 0},
    {JMP, 21},
    {PRN, 0},
    {ALC, 3},
    {PUSH, 2},
    {PUSH, 3},
    {PUSH, 4},
    {STL, 0},
    {STL, 1},
    {STL, 2},
    {RCE, 0},
    {RCE, 1},
    {ADD, 0},
    {RCE, 2},
    {ADD, 0},
    {PRN, 0},
    {FRE, 3},
    {RET, 0},
    {PUSH, 5},
    {PRN, 0},
    {END, 0},
};

int main(int argc, char *argv) {
    Maquina *maq = cria_maquina(programa);
    exec_maquina(maq, 100);
    destroi_maquina(maq);
    return 0;
}
