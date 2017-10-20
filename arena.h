#pragma once
#include <stdio.h>
#include <stdlib.h>

/*
 * Enumerador para o tipo de terreno que um "Tile"
 * pode apresentar. O tipo do terreno esta 
 * relacionado ao custo de transpo-lo
 */
typedef enum {
    GRAMA,
    ESTRADA,
    MONTANHA,
    AGUA,
    AREIA,
} Terreno;


/*
 * Definicao de "Tile"
 *
 * Basicamente uma area que pode ser ocupado por
 * um unico robo por vez e que custa algumas 
 * rodadas para ser atravessada.
 * 
 * Ela tambem pode apresentar cristais que podem
 * ser recolhidos
 */
typedef struct {
    Terreno terreno;
    int cristais;
    int ocupado;
    int base;
} Tile;


/*
 * Definicao de Mapa
 *
 * E o tabuleiro do jogo. Basicamente um conjunto de
 * tiles que e administrado pela arena
 */
typedef struct{
    Tile tiles[5][5];
} Mapa;


/*
 * Instancia a arena e guarda a posicao dos robos
 *
 * Recebe da entrada padrao instrucoes para a
 * inicializacao dos 'tiles' e para a
 * localizacao dos robos
 *
 * Realiza sua funcao lendo o arquivo usando
 * unicamente a funcao getchar()
 */
void criaArena();


/*
 * Instancia um "Tile"
 *
 * retorna um "Tile" definido por valores passados
 * como argumentos
 */
Tile Inicializa();


/*
 * Insere todos os robos na arena
 *
 * Presente:
 * gera copias iguais de um robo definido em "p"
 * em posicoes diferentes da arena
 *
 * Futuro:
 * Lera de diferentes arquivos o codigo fonte de
 * cada robo, especificamente
 *
 * Utiliza a funcao cria_maquina de maq.c
 */
void insereExercito();



/*
 * Escalonador
 *
 * Da, alternadamente, a chance de cada robo
 * executar funcoes e fazer calculos por um
 * 'tempo' igual a "MAX_INSTR"
 */
void Atualiza();



/*
 * Responde as chamadas de sistema realizadas pelos robos
 *
 * Retira informacoes da pilha de instrucoes
 * de um robo especificado pelo argumento
 * Realiza tarefas especificas com base na
 * "solicitacao" feita pelo robo (instrucoes
 * da pilha)
 * 
 * Retorna valores como identificacao de problemas
 * ret == 0, tudo OK
 * ret != 0, algum problema
 */
int Sistema();


/*
 * Imprime estado atual da arena
 *
 * Segue a forma:
 *    |tile.terreno    tile.cirstais|
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
 */
void imprime_arena();