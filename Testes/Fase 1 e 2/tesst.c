#include <stdio.h>
#include "maq.h"

INSTR programa[] = {
    {PUSH, 1},
    {PRN, 0},
    {CALL, 9},
    {PUSH, 3},
    {PRN, 0},
    {POP, 0},
    {POP, 0},
    {RET, 0},
    {PRN, 0},
    {PUSH, 2},
    {PRN, 0},
    {CALL, 3},
    {END, 0},
};

int main(int argc, char *argv) {
    Maquina *maq = cria_maquina(programa);
    exec_maquina(maq, 100);
    destroi_maquina(maq);
    return 0;
}
