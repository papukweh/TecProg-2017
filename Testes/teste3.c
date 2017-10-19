#include <stdio.h>
#include "maq.h"

INSTR programa[] = {
    {PUSH, 5},
    {PUSH, 4},
    {PUSH, 3},
    {SAVE, 0},
    {CALL, 10},
    {REST, 0},
    {PUSH, 10},
    {PRN, 0},
    {END, 0},
    {POP, 0},
    {ALC, 2},
    {ADD, 0},
    {STL, 0},
    {STL, 1},
    {RCE, 1},
    {RCE, 0},
    {SAVE, 0},
    {CALL, 22},
    {REST, 0},
    {RET, 0},
    {POP, 0},
    {POP, 0},
    {ALC, 5},
    {STL, 0},
    {STL, 1},
    {RCE, 0},
    {RCE, 1},
    {ADD, 0},
    {PRN, 0},
    {RET, 0},
};

int main(int argc, char *argv) {
    Maquina *maq = cria_maquina(programa);
    exec_maquina(maq, 100);
    destroi_maquina(maq);
    return 0;
}
