#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

static Arena arena;
static int ids=0;

#define MAX_ROBOS 3
#define MAX_TURNOS 2
#define MAX_TIME 2
#define MAX_INSTR 3

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
		arena.mapa.tiles[i][j] = Inicializa(terr, cris, ocup, base);
		j++;
		if(j==5){
			j=0;
			i++;
		}
	}
}

void Atualiza(){
	//for(int j=0; j<MAX_TURNOS; j++){
		//for(int i=0; i<ids; i++){
			exec_maquina(arena.robots->robots[0], MAX_INSTR);		
		//}
	//}
}

void insereExercito(){
	INSTR p[] = {{PUSH, cria_operando_dir(VAR, NW)}, {PUSH, cria_operando_acao(ACAO, REC)}, 
	{SYS, cria_operando(NUM, 0)}  };
	arena.robots = (Robos*)malloc(sizeof(Robos));
	for(int i=0; i<MAX_ROBOS*MAX_TIME; i++){
		arena.robots->robots[i] = cria_maquina(p, ids, 5, 5);
		ids++;
	}
}

Tile Inicializa(int terr, int cris, int ocup, int base){
	Tile t;
	t.terreno = terr;
	t.cristais = cris;
	t.ocupado = ocup;
	t.base = base;
	return t;
}

int Sistema(int id){
	OPERANDO instr = desempilha(&arena.robots->robots[id]->pil);
	OPERANDO arg;
	int posx = arena.robots->robots[id]->position[0];
	int posy = arena.robots->robots[id]->position[1];
	switch(instr.t){
		case REC:
		arg = desempilha(&arena.robots->robots[id]->pil);
		switch(arg.v){
			case NW:
			if(arena.mapa.tiles[posx][posy-1].cristais > 0){
				arena.mapa.tiles[posx][posy-1].cristais = arena.mapa.tiles[posx][posy-1].cristais-1;
				arena.robots->robots[id]->cristais++;
				return 0;
			}
		}
	}
	return 1;
}

