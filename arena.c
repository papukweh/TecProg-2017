#include <stdio.h>
#include <stdlib.h>
#include "arena.h"
#include "maq.h"

typedef struct{
    Maquina robots[6];
    Mapa mapa;
} Arena;

static Arena arena;
static int ids=0;

#define MAX_ROBOS 3
#define MAX_TURNOS 5
#define MAX_TIME 2
#define MAX_INSTR 80

int main(){
    //arena.robots = (Maquina*)malloc(5*sizeof(Maquina));
    criaArena();
    insereExercito();
    Atualiza();
    return 0;
}

// Recebe um prototipo de arena pela entrada padrao e cria
// os respectivos tiles
void criaArena(){
    int c;
    int terr;
    int cris, ocup, base,i,j;
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
            exec_maquina(&arena.robots[i], MAX_INSTR);        
        }
    }
}

// Funcao que insere todos os robos na arena
void insereExercito(){
    //arena.robots = (Robos*)malloc(sizeof(Robos));
    
    static INSTR p[] = {{PUSH, {ACAO, VER}}, //0
                    {SYS, {NUM, 0}},     //1
                    {POP, {NUM, 0}},     //2
                    {ATR, {NUM, 0}},     //3
                    {PUSH, {VAR, NW}},     //5
                    {PUSH, {ACAO, MOV}}, //6
                    {SYS, {NUM, 0}}};    //7

    // INSTR aux = cria_instr(END, cria_operando(NUM, 0));
    // INSTR p[] = {{ADD, {NUM, 0}}, {STL, {NUM, 2}},  {PUSH, {NUM, 1}}, {CALL, {NUM, 4}}, //{SAVE, {NUM, 0}},
    // /*{SYS, {NUM, 0}},*/ {PUSH, {ACAO, VER}}, // {ADD, {NUM,1}}, {DUP, {NUM,0}}, {MUL, {NUM, 2}}, {SUB, {NUM, 8}}, 
    // {SYS, {NUM, 0}}, {POP, {NUM, 0}}, {ATR, {NUM, 2}}, {SYS, {NUM, 0}}, {PUSH, {NUM, 2}},  {END, ǸUM, 0}};
    int instrSize = sizeof(p)/sizeof(p[0]);
    printf("%d\n", instrSize);
    //p[instrSize] = cria_instr(END, cria_operando(NUM, 0));
    //p.insert(nweOperando)

    int positions[12] = {0,1,1,0,2,0,2,4,3,3,3,4};
    int k=0;
    
    for(int i=0; i<MAX_ROBOS*MAX_TIME; i++){
        int j = k+1;
        arena.robots[i] = cria_maquina(p, instrSize, ids, positions[k], positions[j]);
        printf("Posx = %d\n", positions[k]);
        printf("Posy = %d\n", positions[j]);
        ids++;
        k+=2;
    }

    // for(int j=0; j<MAX_TURNOS; j++){
    //       for(int i=0; i<ids; i++){
    //           exec_maquina(arena.robots[i], MAX_INSTR);        
    //     }
    // }
}

// Funcao que inicializa os valores de um tile da arena
Tile Inicializa(Terreno terr, int cris, int ocup, int base){
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
    OPERANDO instr = desempilha(&arena.robots[id].pil);
    OPERANDO arg;
    OPERANDO ver;
    int posx = arena.robots[id].position[0];
    int posy = arena.robots[id].position[1];
    int old_posx = posx;
    int old_posy = posy;
    if(instr.valor.ac==VER){
        ver.t = TILE;
        for (int i = 0; i < 6; i++) {
            switch (i) {
            case N:
                posx -= 2;  
                break;
            case NE:
                if(posx % 2 != 0) posy++;
                posx--;
                break;
            case SE:
                if(posx % 2 != 0) {
                    posy++;
                }
                posx++;
                break;
            case S:
                posx+=2;
                break;
            case SW:
                if(posx % 2 == 0) posy--;
                posx++;
                break;
            case NW:
                if(posx % 2 == 0) posy--;
                posx--;
                break;
            }
            if (posx >= 0 && posx <= 4 && posy >= 0 && posy <= 4) {
                ver.valor.tile = arena.mapa.tiles[posx][posy];
                empilha(&arena.robots[id].pil, ver);
            }
            posx = old_posx;
            posy = old_posy;
        }
        return 0;
    }
    else{
        arg = desempilha(&arena.robots[id].pil);
        switch(arg.valor.v){
        case N:
            posx -= 2;  
            break;
        case NE:
            if(posx % 2 != 0) posy++;
            posx--;
            break;
        case SE:
            if(posx % 2 != 0) posy++;
            posx++;
            break;
        case S:
            posx+=2;
            break;
        case SW:
            if(posx % 2 == 0) posy--;
            posx++;
            break;
        case NW:
            if(posx % 2 == 0) posy--;
            posx--;
            break;
        }

        if(posx<0 || posy>4 || posx>4 || posy<0) return -1;
            
        switch(instr.valor.ac){
            case MOV:
                if(arena.mapa.tiles[posx][posy].ocupado == 0){
                    arena.robots[id].position[0] = posx;
                    arena.robots[id].position[1] = posy;
                    arena.mapa.tiles[posx][posy].ocupado = 1;
                    arena.mapa.tiles[old_posx][old_posy].ocupado = 0;
                    return 0;
                }
                else return 1;
            case REC:
                if(arena.mapa.tiles[posx][posy].cristais > 0){
                    arena.mapa.tiles[posx][posy].cristais--;
                    arena.robots[id].cristais++;
                    return 0;
                }
            case DEP:
                arena.mapa.tiles[posx][posy].cristais++;
                arena.robots[id].cristais--;
                return 0;
        }
    }
    return 1;
}

INSTR cria_instr(OpCode oC, OPERANDO o){
    INSTR a = {oC, o};
    return a;
}

