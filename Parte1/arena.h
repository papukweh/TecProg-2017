#include <stdio.h>
#include <stdlib.h>
#include "maq.h"

typedef struct{
	Tile tiles[5][5];
} Mapa;

typedef struct{
	Maquina* robots[5];
} Robos;

typedef struct{
	Robos *robots;
	Mapa mapa;
} Arena;

void criaArena();
Tile Inicializa();
void insereExercito();
void Atualiza();
int Sistema();