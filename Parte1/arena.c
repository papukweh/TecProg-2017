#include <stdio.h>
#include <stdlib.h>
#include "maq.h"
#include "arena.h"
#include "hlinstr.h"

static Arena arena;

int main(){
	criaArena();
	insereExercito();
	//Sistema(0);
	return 0;
}

void criaArena(){
	int c;
	int terr, cris, ocup, base,i,j;
	i=0;
	j=0;
	while((c=getchar()) != EOF ){
		scanf("%d", &terr);
		c = getchar();
		scanf("%d", &cris);
		c = getchar();
		scanf("%d", &ocup);
		c = getchar();
		scanf("%d", &base);
		arena.mapa.tiles[i][j++] = Inicializa(terr, cris, ocup, base);
		if(j==4){
			j=0;
			i++;
		}
	}

	//printf("%d\n", arena.mapa->tiles[0][1]->base);
}

Maquina *criaRobo(int id){
	//INSTR p[] = {
    //	{28, 5},  // 0
	 //   {SISTEMA, 0},	// 1
	//};
	INSTR p[] = {{PRN,0},{PUSH,7}};
	Maquina *m = cria_maquina(p, id,  1, 1);
	return m;
}

void insereExercito(){
	arena.robots = (Robos*)malloc(sizeof(Robos));
	for(int i=0; i<1; i++){
		//arena.robots->robots[i] = (Maquina*)malloc(sizeof(Maquina));
		arena.robots->robots[i] = criaRobo(i);
	}
	exec_maquina(arena.robots->robots[0], 2);
	//printf("%d\n", arena.robots->robots[0]->position[0]);
}

Tile Inicializa(int terr, int cris, int ocup, int base){
	//Tile t = (Tile*)malloc(sizeof(Tile));
	Tile t;
	t.terreno = terr;
	t.cristais = cris;
	t.ocupado = ocup;
	t.base = base;
	return t;
}

int Sistema(int id){
	int arg = desempilha(&arena.robots->robots[id]->pil);
	printf("%d", arg);
	printf("haha");
	return 0;
}

