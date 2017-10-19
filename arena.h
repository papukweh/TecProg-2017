#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    GRAMA,
    ESTRADA,
    MONTANHA,
    AGUA,
    AREIA,
} Terreno;

typedef struct {
    Terreno terreno;
    int cristais;
    int ocupado;
    int base;
} Tile;

typedef struct{
    Tile tiles[5][5];
} Mapa;

void criaArena();
Tile Inicializa();
void insereExercito();
void Atualiza();
int Sistema();