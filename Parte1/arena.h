#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int terreno;
  int cristais;
  int ocupado;
  int base;
} Tile;

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

//extern volatile Arena arena;

void Atualiza();
void criaArena();
Tile Inicializa();
Maquina *criaRobo();
void RemoveRobo();
void insereExercito();
int Sistema();