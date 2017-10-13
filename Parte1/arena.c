#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

static Arena arena;
static int ids=0;

#define MAX_ROBOS 1
#define MAX_TURNOS 7
#define MAX_TIME 1
#define MAX_INSTR 1

int main(){
	criaArena();
	insereExercito();
	Atualiza();
	return 0;
}

// Recebe um prototipo de arena pela entrada padrao e cria
// os respectivos tiles
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

// Escalonador: manda cada robo executar suas instrucoes sucessivamente
void Atualiza(){
	for(int j=0; j<MAX_TURNOS; j++){
		for(int i=0; i<ids; i++){
			exec_maquina(arena.robots->robots[i], MAX_INSTR);		
		}
	}
}

// Funcao que insere todos os robos na arena
void insereExercito(){
	INSTR p[] = {{PUSH, {VAR, NW}}, {PUSH, {ACAO, REC}}, 
	{SYS, {NUM, 0}}, {PUSH, {ACAO, VER}}, {SYS, {NUM, 0}}, {POP, {NUM, 0}}, {ATR, {NUM, 2}}  };
	arena.robots = (Robos*)malloc(sizeof(Robos));
	for(int i=0; i<MAX_ROBOS*MAX_TIME; i++){
		arena.robots->robots[i] = cria_maquina(p, ids, 2, 1);
		ids++;
	}
}

// Funcao que inicializa os valores de um tile da arena
Tile Inicializa(int terr, int cris, int ocup, int base){
	Tile t;
	t.terreno = terr;
	t.cristais = cris;
	t.ocupado = ocup;
	t.base = base;
	return t;
}

// Funcao que responde as chamadas de sistema realizadas pelos robos
// Recebe um numero de identificacao e responde 0 ou 1
int Sistema(int id){
	OPERANDO instr = desempilha(&arena.robots->robots[id]->pil);
	OPERANDO arg;
	OPERANDO ver;
	int posx = arena.robots->robots[id]->position[0];
	int posy = arena.robots->robots[id]->position[1];
	if(instr.ac==VER){
		ver.t = TILE;
		ver.tile = arena.mapa.tiles[posx][posy];
		empilha(&arena.robots->robots[id]->pil, ver);
		return 0;
	}
	else{
		arg = desempilha(&arena.robots->robots[id]->pil);
		switch(arg.v){
			case N:
			  posx--;  
			  break;
			case NE:
			  posx--;
			  posy++;
			  break;
			case SE:
			  posy++;
			  break;
			case S:
			  posx++;
			  break;
			case SW:
			  posx++;
			  posy--;
			  break;
			case NW:
			  posy--;
			  break;

			if(posx<0 || posy>4) return -1;
			
			switch(instr.t){
				case MOV:
					if(arena.mapa.tiles[posx][posy].ocupado == 0){
						arena.robots->robots[id]->position[0] = posx;
						arena.robots->robots[id]->position[0] = posy;
						return 0;
					}
					else return 1;
				case REC:
					if(arena.mapa.tiles[posx][posy].cristais > 0){
						arena.mapa.tiles[posx][posy].cristais--;
						arena.robots->robots[id]->cristais++;
						return 0;
					}
				case DEP:
					arena.mapa.tiles[posx][posy].cristais++;
					return 0;
			}
		}
	}
	return 1;
}

