#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "maq.h"

static void Erro(char *msg) {
    fprintf(stderr,"%s\n", msg);
}

static void Fatal(char *msg, int cod) {
    Erro(msg);
    exit(cod);
}


Pilha cria_pilha() {
    Pilha p;
    //Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    //if (!p) Fatal("Memória insuficiente",4);
    p.topo = 0;
    return p;
}

void destroi_pilha(Pilha p) {
    //free(p);
}

void empilha(Pilha *p, OPERANDO op) {
    if (p->topo < PILMAX)
    p->val[p->topo++] = op;
    else Erro("Pilha cheia");
}

OPERANDO desempilha(Pilha *p) {
    if (p->topo > 0)
    return p->val[--p->topo];
    else {
    Erro("Pilha vazia");
    return cria_operando(NUM, -1);
    }
}

void imprime(Pilha *p, int n) {
    int t = p->topo-1;
    int i;
    printf("[");
    for (i = t; i >= 0 && i > p->topo-n; i--){ 
    printf(" ");
    imprime_op(p->val[i]);
    printf(", ");
    }
    printf("]");
    return;
}
