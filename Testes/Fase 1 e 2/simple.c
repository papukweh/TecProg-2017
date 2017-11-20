#include <stdio.h>
#include "maq.h"

INSTR programa[] = {
    {PUSH, 10},
    {PUSH, 4},
    {ADD, 0},
    {PUSH, 3},
    {MUL, 0},
    {PRN, 0},
    {END, 0},
};

int main(int argc, char *argv) {
    Maquina *maq = cria_maquina(programa);
    exec_maquina(maq, 100);
    destroi_maquina(maq);
    return 0;
}
