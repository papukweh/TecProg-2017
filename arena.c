#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arena.h"
#include "maq.h"


/*
 * Expande o modo DEBUG criado em maq.c
 * para arena.c. Nesse modo sao impressos
 * todas as modificacoes feitas na arena.
 * Por exemplo, movimento de robos, retirada
 * de e deposito de cristais
 */
#define DEBUG
#ifdef DEBUG
    #define D(X) X
    char *Direc[] = {
        "N",
        "NE",
        "SE",
        "S",
        "SW",
        "NW",
        "CN",
    };
#else
#define D(X)
#endif

/*
 * Condicoes de jogo.
 * "MAX_ROBOS" e o numero de robos por time
 * "MAX_TURNOS" e a quantidade de turnos do
 *     jogo caso nenhum time venca a partida
 * "MAX_TIME" e a quantidade de times na partida
 *     (pensamos em permitir batalhas alem da 1x1)
 * "MAX_INSTR" e o numero de instrucoes que podem
 *     ser executadas durante um turno
 */
#define MAX_ROBOS 2
#define MAX_TURNOS 5
#define MAX_TIME 2
#define MAX_INSTR 50

/*
 * Struct da Arena.
 * Nossa arena e composta de um mapa e de um 
 * numero definido de robos.
 * A struct e definida aqui devido a problemas
 * relacionados a dependencias e inclusoes
 */
typedef struct{
    Maquina robots[6];
    Mapa mapa;
} Arena;


/*
 * Definicao das variaveis globais.
 * "positions" guarda a posicao de robos sendo
 *     positions[k]=pos.X e positions[k+1]=pos.Y
 * "arena" e a unica instancia da struct arena. 
 *     Usamos "arena" como o 'runner' do jogo.
 * "ids" e a variavel usada para acessar cada 
 *     robo pelo 'nome'
 */
static int positions[MAX_ROBOS*MAX_TIME*2];
static Arena arena;
static int ids=0;

// Programa teste para as chamadas de sistema
static INSTR sis[] = {{PUSH, {ACAO, VER}}, 
                {SYS, {NUM, 0}},        // Testa o VER     
                {POP, {NUM, 0}},     
                {ATR, {NUM, 0}},        // Testa o ATR
                {PUSH, {VAR, NW}},     
                {PUSH, {ACAO, MOV}}, 
                {SYS, {NUM, 0}},        // Testa o MOV
                {PUSH, {VAR, SE}},
                {PUSH, {ACAO, REC}},
                {SYS, {NUM, 0}},        // Testa o REC
                {PUSH, {VAR, CN}}, 
                {PUSH, {ACAO, DEP}},    // Testa o DEP
                {SYS, {NUM, 0}} };

// Programa teste para as demais instrucoes do robo 
static INSTR fat[] = {
                {PUSH, {NUM, 8}},  // 0
                {SAVE, {NUM, 0}},  // 1
                {CALL, {NUM, 6}},  // 2
                {REST, {NUM, 0}},  // 3
                {PRN,  {NUM, 0}},  // 4
                {END,  {NUM, 0}},  // 5
                {ALC,  {NUM, 1}},  // 6
                {DUP,  {NUM, 0}},  // 7
                {STL,  {NUM, 0}},  // 8 n
                {PUSH, {NUM, 1}},  // 9
                {EQ,   {NUM, 0}},  // 10 n == 1 ?
                {JIF,  {NUM, 15}},  // 11
                {PUSH, {NUM, 1}},  // 12
                {FRE,  {NUM, 1}},  // 13
                {RET,  {NUM, 0}},  // 14
                {RCE,  {NUM, 0}},  // 15 n
                {PUSH, {NUM, 1}},  // 16
                {SUB,  {NUM, 0}},  // 17 n-1
                {SAVE, {NUM, 0}},  // 18
                {CALL, {NUM, 6}},  // 19 fat(n-1)
                {REST, {NUM, 0}},  // 20
                {RCE,  {NUM, 0}},  // 21 n
                {MUL,  {NUM, 0}},  // 22 n * fat(n-1)
                {FRE,  {NUM, 1}},  // 23
                {RET,  {NUM, 0}} };   // 24 

// Programa que de fato será carregado nos robos: apenas
// copiamos para ele os outros programas
static INSTR* p;
static int instrSize = 0;

/*
 * O jogo inicia nesse ponto.
 *
 * Recebe como argumento qual programa sera testado
 *
 * "CriaArena" e "insereExercito" sao
 * responsaveis pela inicialização e 
 * "Atualiza" e responsavel pelo 'GameLoop'
 */
int main(int argc, char *argv[]){

    if (argc > 1) {
        if (strcmp(argv[1], "fat") == 0) {
            p = (INSTR*)malloc(sizeof(fat));
            memcpy(p, fat, sizeof(fat));
            instrSize = sizeof(fat)/sizeof(p[0]);
        }
        else if (strcmp(argv[1], "sis") == 0) {
            p = (INSTR*)malloc(sizeof(sis));
            memcpy(p, sis, sizeof(sis));
            instrSize = sizeof(sis)/sizeof(p[0]);
        }
        else {
            puts("Use os argumentos 'fat' ou 'sis' para rodar os testes\n");
            return 1;
        }
    }
    else {
        puts("Use os argumentos 'fat' ou 'sis' para rodar os testes\n");
        return 1;
    }

    criaArena();
    insereExercito();
    Atualiza();
    return 0;
}


/*
 * Instancia a arena e guarda a posicao dos robos
 *
 * Recebe da entrada padrao instrucoes para a
 * inicializacao dos 'tiles' e para a
 * localicacao dos robos
 *
 * Realiza sua funcao lendo o arquivo usando
 * unicamente a funcao getchar()
 */
void criaArena(){
    int c;
    int terr;
    int cris, ocup, base, i, j, k;
    i = 0;
    j = 0;
    k = 0;

    //Escaneia o arquivo buscando por valores para os
    //atributos dos tiles
    while((c=getchar()) != EOF ){
        scanf("%d", &terr);
        c = getchar();
        scanf("%d", &cris);
        c = getchar();
        scanf("%d", &ocup);
        c = getchar();
        scanf("%d", &base);
        arena.mapa.tiles[i][j] = Inicializa(terr, cris, ocup, base);

        //Caso tenha algum robo no tile, salva a posicao
        //para que no futuro ele seja iniciado com as
        //posicoes corretas
        if (ocup == 1) {
            positions[k] = i;
            k++;
            positions[k] = j;
            k++;
        } 

        j++;
        if(j==5){
            j=0;
            i++;
        }
    }

   D(imprime_arena());
}


/*
 * Escalonador
 *
 * Da, alternadamente, a chance de cada robo
 * executar funcoes e fazer calculos por um
 * 'tempo' igual a "MAX_INSTR"
 */
void Atualiza(){
    for(int j=0; j<MAX_TURNOS; j++){
        for(int i=0; i<ids; i++){
            exec_maquina(&arena.robots[i], MAX_INSTR);        
        }

        // Imprime a arena apos cada turno
        D(imprime_arena());
    }
}


/*
 * Insere todos os robos na arena
 *
 * Presente:
 * gera copias iguais de um robo com o programa "p"
 * em posicoes diferentes da arena
 *
 * Futuro:
 * Lera de diferentes arquivos o codigo fonte de
 * cada robo, especificamente
 *
 * Utiliza a funcao cria_maquina de maq.c
 */
void insereExercito(){
    
    int k=0;
    
    for(int i = 0; i < MAX_ROBOS*MAX_TIME; i++){
        int j = k+1;
        arena.robots[i] = cria_maquina(p, instrSize, ids, positions[k], positions[j]);
        ids++;
        k+=2;
    }
}

/*
 * Instancia um "Tile"
 *
 * retorna um "Tile" definido por valores passados
 * como argumentos
 */
Tile Inicializa(Terreno terr, int cris, int ocup, int base){
    Tile t;
    t.terreno = terr;
    t.cristais = cris;
    t.ocupado = ocup;
    t.base = base;
    return t;
}


/*
 * Responde as chamadas de sistema realizadas pelos robos
 *
 * Retira informacoes da pilha de dados
 * de um robo identificado pelo argumento
 * Realiza tarefas especificas com base na
 * "solicitacao" feita pelo robo (instrucoes
 * da pilha)
 * 
 * Retorna valores como identificacao de problemas
 * ret == 0, tudo OK
 * ret != 0, algum problema
 */
int Sistema(int id){
    OPERANDO arg;
    OPERANDO ver;
    OPERANDO instr = desempilha(&arena.robots[id].pil);
    int posx = arena.robots[id].position[0];
    int posy = arena.robots[id].position[1];
    int old_posx = posx;
    int old_posy = posy;

    // VER: empilha os 6 tiles vizinhos e o
    // proprio tile do robo
    if(instr.valor.ac==VER){
        ver.t = TILE;
        for (int i = 0; i < 7; i++) {
            switch (i) {
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
            case CN:
                break;
            }

            // Checa se os tiles estão na arena, retorna -1 caso contrario
            if (posx >= 0 && posx <= 4 && posy >= 0 && posy <= 4) {
                ver.valor.tile = arena.mapa.tiles[posx][posy];
                empilha(&arena.robots[id].pil, ver);
            }
            else 
                empilha(&arena.robots[id].pil, cria_operando(NUM, -1));

            posx = old_posx;
            posy = old_posy;
        }
        return 0;
    }

    // Demais chamadas: primeiro define o vizinho sobre o qual
    // a acao sera executada
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
        case CN:
            break;
        }

        // Retorna -1 se estiver fora da arena
        if(posx < 0 || posy > 4 || posx > 4 || posy < 0) return -1;
            
        switch(instr.valor.ac){
            // Move o robo caso o tile nao esteja ocupado
            case MOV:
                if(arena.mapa.tiles[posx][posy].ocupado == 0){
                    arena.robots[id].position[0] = posx;
                    arena.robots[id].position[1] = posy;
                    arena.mapa.tiles[posx][posy].ocupado = 1;
                    arena.mapa.tiles[old_posx][old_posy].ocupado = 0;
                    D(printf("\nRobô %d se moveu para %s (posição %d, %d)\n", id, Direc[arg.valor.v], posx, posy));
                    return 0;
                }
                else return 1;

            // Recolhe um cristal se o tile o tiver
            case REC:
                if(arena.mapa.tiles[posx][posy].cristais > 0){
                    arena.mapa.tiles[posx][posy].cristais--;
                    arena.robots[id].cristais++;
                    D(printf("\nRobô %d recolheu um cristal no %s (posição %d, %d)\n", id, Direc[arg.valor.v], posx, posy));
                    return 0;
                }

            // Deposita um cristal se o robo o tiver
            case DEP:
                if(arena.robots[id].cristais > 0){
                    arena.mapa.tiles[posx][posy].cristais++;
                    arena.robots[id].cristais--;
                    D(printf("\nRobô %d depositou um cristal no %s (posição %d, %d)\n", id, Direc[arg.valor.v], posx, posy));
                    return 0;
                }
        }
    }
    return 1;
}


/*
 * Imprime estado atual da arena
 *
 * Segue a forma:
 *    |tile.terreno    tile.cristais|
 *    |                             |
 *    |tile.ocupado    tile.base    |
 *
 * Nessa representacao as posicoes sao da forma:
 * 
 *       |  N  | 
 *       |     | 
 *    | NW  |  NE | 
 *    |     |     | 
 *       |  CN | 
 *       |     | 
 *    |     |     | 
 *    | SW  |  SE | 
 *       |     | 
 *       |  S  | 
 *
 * OBS: CN é o tile onde o robo se encontra
 */
void imprime_arena(){
    for (int i = 0; i < 5; i++){
        // Nossa organizacao de "mapa" tem comportamento
        // diferente para linhas pares e impares, logo,
        // precisamos trata-los de maneira especifica
        if(i % 2 == 0){
            printf("| %d %d | %d %d | %d %d | %d %d | %d %d |\n", arena.mapa.tiles[i][0].terreno,
                arena.mapa.tiles[i][0].cristais, arena.mapa.tiles[i][1].terreno,
                arena.mapa.tiles[i][1].cristais, arena.mapa.tiles[i][2].terreno,
                arena.mapa.tiles[i][2].cristais, arena.mapa.tiles[i][3].terreno,
                arena.mapa.tiles[i][3].cristais, arena.mapa.tiles[i][4].terreno,
                arena.mapa.tiles[i][4].cristais);
            printf("| %d %d | %d %d | %d %d | %d %d | %d %d |\n", arena.mapa.tiles[i][0].ocupado,
                arena.mapa.tiles[i][0].base, arena.mapa.tiles[i][1].ocupado,
                arena.mapa.tiles[i][1].base, arena.mapa.tiles[i][2].ocupado,
                arena.mapa.tiles[i][2].base, arena.mapa.tiles[i][3].ocupado,
                arena.mapa.tiles[i][3].base, arena.mapa.tiles[i][4].ocupado,
                arena.mapa.tiles[i][4].base);
        }
        else{
            printf("   | %d %d | %d %d | %d %d | %d %d | %d %d |\n", arena.mapa.tiles[i][0].terreno,
                arena.mapa.tiles[i][0].cristais, arena.mapa.tiles[i][1].terreno,
                arena.mapa.tiles[i][1].cristais, arena.mapa.tiles[i][2].terreno,
                arena.mapa.tiles[i][2].cristais, arena.mapa.tiles[i][3].terreno,
                arena.mapa.tiles[i][3].cristais, arena.mapa.tiles[i][4].terreno,
                arena.mapa.tiles[i][4].cristais);
            printf("   | %d %d | %d %d | %d %d | %d %d | %d %d |\n", arena.mapa.tiles[i][0].ocupado,
                arena.mapa.tiles[i][0].base, arena.mapa.tiles[i][1].ocupado,
                arena.mapa.tiles[i][1].base, arena.mapa.tiles[i][2].ocupado,
                arena.mapa.tiles[i][2].base, arena.mapa.tiles[i][3].ocupado,
                arena.mapa.tiles[i][3].base, arena.mapa.tiles[i][4].ocupado,
                arena.mapa.tiles[i][4].base);           
        }
    }
    puts("\n");
}
