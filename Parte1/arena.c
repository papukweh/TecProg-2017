#include <stdio.h>
#include <stdlib.h>
#include "maq.h"
#include "arena.h"
#include "hlinstr.h"

static Arena arena;

int main(){
	criaArena();
	insereExercito();
	Atualiza();
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
}

// Maquina *criaRobo(int id){
// 	//INSTR p[] = {
//     //	{28, 5},  // 0
// 	 //   {SISTEMA, 0},	// 1
// 	//};
// 	INSTR p[] = {{PRN,0},{PUSH,7}};
// 	Maquina *m = cria_maquina(p, id,  1, 1);
// 	return m;
// }

void Atualiza(){
	for(int j=0; j<2; j++){
		for(int i=0; i<3; i++){
			exec_maquina(arena.robots->robots[i], 3);
		}
	}
}

void insereExercito(){
	INSTR p[] = {{PUSH,5}, {SISTEMA,0}, {PUSH,10}, {PRN,0}, {PUSH, 1}, {POP, 2} };
	arena.robots = (Robos*)malloc(sizeof(Robos));
	for(int i=0; i<3; i++){
		arena.robots->robots[i] = cria_maquina(p, i, 5*i, 5*i);
		//exec_maquina(arena.robots->robots[i], 4);
	}
	//exec_maquina(arena.robots->robots[0], 4);
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
	printf("%d\n", arg);
	if(arg==5) return 0;
	else return 1;
}

