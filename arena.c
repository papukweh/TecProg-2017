#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
#define MAX_ROBOS 5
#define MAX_TURNOS 100
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
    Maquina robots[10];
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
 * "instrSize" representa o numero de instrucoes
 * em cada programa - e usada na funcao readProg
 * "display" representa o stream que sera enviaado
 * para apres
 */
static int positions[MAX_ROBOS*MAX_TIME*2];
static Arena arena;
static int ids=0;
static int instrSize=0;
FILE *display;

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
    srand(time(NULL));    
    // Abre o pipe que fara a comunicacao com a parte 
    // visual do "apres"
    display = popen("./apres", "w");

    criaArena();
    insereExercito();
    Atualiza();
    return 0;
}

/*
 * Instancia a arena e guarda a posicao dos robos
 * A arena agora já tem posições pré-definidas para
 * as bases e os robôs, porém a disposição dos cristais
 * e dos tipos de terreno é aleatória
 */
void criaArena(){
    int id=0;
    int terr;
    int base=0;
    int cris=0;
    int ntime=5;
    int ocup, i, j, k;
    i = 0;
    j = 0;
    k = 0;

    // Posições importantes:
    // Bases: (1,0) e (18,11)
    // Time1: (0,0); (0,1); (2,0); (3,1); (3,0)
    // Time2: (19, 11); (17,11); (16,11); (19, 10); (17,10)

    // Posiciona os robôs nos tiles pré-determinados
    for (int l = 0; l < 240; l++){
        if (l == 0 || l == 1 || l == 24 || l == 25 || l == 36
            || l == 203 || l == 214 || l == 215 || l == 238 || l == 239){
            ocup = id;
            terr = 1;
            cris = 0;
            arena.mapa.tiles[i][j] = Inicializa(terr, 0, ocup, base);
            id++;
        }

        // Posiciona as bases nos tiles pré-determinados
        else if (l == 12 || l == 227){
            cris = 0;
            ocup = -1;
            base = 1;
            terr = 1;
            arena.mapa.tiles[i][j] = Inicializa(terr, 0, -1, base);
        }

        // Demais tiles: setamos o atributo ocupado para -1 e geramos
        // os terrenos e o número de cristais de forma aleatória
        else {
            ocup = -1;
            terr = rand() % 101;
                                                // Terrenos | Probabilidade
            if (terr <= 40) terr = 0;           // GRAMA    | 40 %
            else if (terr <= 60) terr = 1;      // ESTRADA  | 20 %
            else if (terr <= 65 ) terr = 2;     // MONTANHA | 5 %
            else if (terr <= 80) terr = 3;      // AGUA     | 15 %
            else terr = 4;                      // AREIA    | 20 %

            // Chance de um tile possuir cristais: 60%
            // Número máximo de cristais por tile: 10
            cris = rand() % 101;
            if (cris <= 60) cris = rand() % 11;
            else cris = 0;
            arena.mapa.tiles[i][j] = Inicializa(terr, cris, ocup, base); 
        }

        // Caso tenha algum robo no tile, salva a posicao
        // para que no futuro ele seja iniciado com as
        // posicoes corretas
        if (ocup > -1) {
            positions[k] = i;
            k++;
            positions[k] = j;
            k++;
        }

        // Parte grafica: para cada tile, mandamos a arena recolorir
        // o tile com a cor específica de seu terreno (no futuro, cada
        // tipo de terreno terá uma textura própria)
        switch(terr){
            case GRAMA:
                fprintf(display, "terr %d %d 0\n", i,j);
                break;
            case ESTRADA:
                fprintf(display, "terr %d %d 1\n", i,j);
                break;
            case MONTANHA:
                fprintf(display, "terr %d %d 2\n", i,j);
                break;
            case AGUA:
                fprintf(display, "terr %d %d 3\n", i,j);
                break;
            case AREIA:
                fprintf(display, "terr %d %d 4\n", i,j);
                break;
        }

        // Parte gráfica: mandamos a arena recolorir os tiles que
        // representam as bases com a cor branca
        if (base == 1){
            base = 0;
            cris = 0;
            fprintf(display, "terr %d %d %d\n", i, j, ntime);
            ntime++;
        }

        // Parte grafica: se houver cristais no tile, mandamos a 
        // arena imprimir um pequeno cristal no tile correspondente
        if (cris >= 1 && cris < 3 && base == 0)
            fprintf(display, "cris %d %d\n", i, j);

        // se houver 3 ou mais cristais, imprimimos a imagem de um
        // pequeno lote de cristais
        else if (cris >= 3) 
            fprintf(display, "lotecris %d %d\n", i, j);

        fflush(display);
        
        j++;
        if(j==12){
            j=0;
            i++;
        }
    }
}

/*
 * Funcao que le um programa da entrada padrao e
 * retorna um ponteiro para o mesmo
 * Recebe como argumento o ponteiro no qual devera
 * armazenar o programa
 *
 * Um programa deve obrigatoriamente ter a seguinte
 * estrutura:
 *
 * p(id)\n -> Indica o inicio do programa
 * {OpCode, {Tipo, Arg}},\n -> Instrucoes
 * ; -> Indica o fim do programa
 * \n -> Separa os dois programas
 * p(id++)\n -> Indica o inicio de um novo programa
 *
 */
INSTR* readProg(INSTR* prog){
    char *op = malloc(15*sizeof(char));
    char *tipo = malloc(15*sizeof(char));
    char *arg = malloc(5*sizeof(char));
    int instr = 0;
    int i,j,k,o,t,a;
    int c;

    // Pega o p(id)\n
    getchar();
    getchar();
    getchar();
    while (1){

        // Detecta o fim do programa
        c = getchar();
        if (c == ';') break;
        else c = getchar();

        // Constroi o operando
        i = 0;
        while (c != ',' && c != EOF){
            op[i++] = c;
            c = getchar();
        }

        // Apaga "residuos" do opcode anterior
        if (i < 5) op[i] = NULL;

        // Pega o " {" antes do tipo
        getchar();
        getchar();
        c = getchar();

        // Constroi o tipo
        j = 0;
        while (c != ',' && c != EOF){
            tipo[j++] = c;
            c = getchar();
        }

        // Apaga "residuos" do tipo anterior
        if (j < 5) tipo[j] = NULL;

        // Pega o " " antes do argumento
        getchar();
        c = getchar();

        // Constroi o argumento
        k = 0;
        while (c != '}' && c != EOF){
            arg[k++] = c;
            c = getchar();
        }

        // Apaga "residuos" do argumento anterior
        if (k < 4) arg[k] = NULL;

        // Pega o "},\n" antes da proxima instrucao
        getchar();
        getchar();
        getchar();

        // Parsea a instrucao obtida e coloca os valores dos enums
        // correspondentes

        // Parser do tipo
        for (int i = 0; i < 5; i++){
            char *aux = Tipos[i];
            if (strcmp(tipo, aux) == 0){
                t = i;
                break;
            }
        }

        // Se o tipo for num, converte o argumento para inteiro
        if (t == 0) a = atoi(arg);

        // Se for ACAO, parsear o argumento como uma Chamada:
        else if (t == 1){
            for (int i = 0; i < 7; i++){
                char *aux = Chamadas[i];
                if (strcmp(arg, aux) == 0){
                    a = i;
                    break;
                }
            }
        }

        // Se for VAR, parsear o argument como uma Direcao:
        else if (t == 2) {
            for (int i = 0; i < 7; i++){
                char *aux = Direcao[i];
                if (strcmp(arg, aux) == 0){
                    a = i;
                    break;
                }
            }
        }

        else fprintf(stderr, "Problemas no código\n");

        // Parsear o opcode
        for (int i = 0; i < 31; i++){
            char *aux = CODES[i];
            if (strcmp(op, aux) == 0){
                o = i;
                break;
            }
        }

        // Por fim, cria a instrucao
        prog[instr++] = cria_instr((OpCode)o, cria_operando((Tipo)t, a));  
    }
    
    // Pega o "\n\n" antes do proximo programa
    getchar();
    getchar();
    instrSize = instr; 

    free(op);
    free(tipo);
    free(arg);

    return prog;
}

/*
 * Insere todos os robos na arena
 *
 * Cria, para cada um dos robos um programa correspondente
 * usando a funcao readProg e instancia-os na arena usando
 * cria_maquina de maq.c
 * 
 * Manda tambem os comandos necessarios para que esses
 * robos sejam criados no "apres"
 *
 */
void insereExercito(){
    int k = 0;
    int x = 0;

    if (display == NULL) {
        fprintf(stderr,"Não encontrei o programa de exibição\n");
        exit(1);
    }

    // Cria cada robo, individualmente, com programas distintos
    ids = 0;
    for(int i = 0; i < MAX_ROBOS*MAX_TIME; i++){
        int j = k+1;
        if (i == 5) x = 1;

        INSTR *p = malloc(sizeof(INSTR)*100);
        p = readProg(p);
        arena.robots[i] = cria_maquina(p, instrSize, ids, positions[k], positions[j], 100, x);
        free(p);

        // Para cada robo, associa-o com o sprite de seu time
        // e o desenha em sua posicao inicial
        if (x == 0) fprintf(display, "rob A.png\n");
        else fprintf(display, "rob B.png\n");
        fprintf(display, "%d 99 99 %d %d\n", ids, positions[k], positions[j]);
        printf("Robô %d posicionado\n", ids);
        ids++;
        k+=2;
        fflush(display);
    }
}

/*
 * Escalonador
 *
 * Da, alternadamente, a chance de cada robo
 * executar funcoes e fazer calculos por um
 * 'tempo' igual a "MAX_INSTR"
 * Agora também checa e decrementa o contador
 * de ocupacao do robo "cont"
 */
void Atualiza(){

    for(int j=0; j<MAX_TURNOS; j++){

        for(int i=0; i<ids; i++){
            // Se o robo nao estiver ocupado, ele pode executar seu
            // programa normalmente
            if (arena.robots[i].cont == 0)
                exec_maquina(&arena.robots[i], MAX_INSTR);

            // Senao, decrementa o contador e imprime uma mensagem no log
            // Tambem restaura a vida do robo caso ele possa voltar no 
            // proximo turno
            else {
                arena.robots[i].cont--;
                D(printf("Robô %d não consegue se mexer!\n", i));
                if (arena.robots[i].vida <= 0 && arena.robots[i].cont == 0) {
                    arena.robots[i].vida = 100;
                    fprintf(display, "ress %d %d %d\n", i, arena.robots[i].position[0], arena.robots[i].position[1]);
                }
            }

            // Atualiza o estado, vida e numero de cristais de cada robo nos
            // graficos da UI na parte inferior da tela
            int estado = 0;
            if (arena.robots[i].vida <= 0) estado = 1;
            fprintf(display, "UI_atu %d %d %d %d %d %d\n", i, arena.robots[i].vida, arena.robots[i].cristais, estado, 
                arena.mapa.tiles[1][0].cristais, arena.mapa.tiles[18][11].cristais);
            fprintf(display, "atu\n");
            fflush(display);        
        }

        // Condições de parada:
        // No momento, para fins de debug, basta que um robo deposite um cristal
        // na base inimiga para finalizar o jogo
        if (arena.mapa.tiles[1][0].cristais >= 1 || arena.mapa.tiles[18][11].cristais >= 1) {
            if (arena.mapa.tiles[1][0].cristais >= 1)
                printf("Fim de jogo! O time 2 ganhou, yay!\n");
            else
                printf("Fim de jogo! O time 1 ganhou, yay!\n");
            fprintf(display, "fim\n");
            fflush(display);
            break;
        }

        // Numero maximo de turnos atingido
        else if (j == MAX_TURNOS-1){
            fprintf(display, "stop\n");
            printf("Fim de jogo (por turnos)\n");
            fprintf(display, "fim\n");
            fflush(display);
            break;
        }
        fflush(display);
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
 * ret == 1, tudo OK
 * ret == -1, algum problema
 *
 * O robo agora armazena as ultimas 4 respostas
 * na posicoes 7, 8, 9 e 10 de sua memoria
 */
int Sistema(int id){
    OPERANDO arg;
    OPERANDO ver;
    OPERANDO instr = desempilha(&arena.robots[id].pil);
    int posx = arena.robots[id].position[0];
    int posy = arena.robots[id].position[1];
    int old_posx = posx;
    int old_posy = posy;

    // Chamadas que nao precisam de direcao:
    // VER: guarda nas 7 primeiras posicoes da memoria 
    // os 6 tiles vizinhos e o proprio tile do robo
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
            if (posx >= 0 && posx <= 19 && posy >= 0 && posy <= 11) {
                ver.valor.tile = arena.mapa.tiles[posx][posy];
                arena.robots[id].Mem[i] = ver;
            }
            else 
                arena.robots[id].Mem[i] = cria_operando(NUM, -1);

            posx = old_posx;
            posy = old_posy;
        }
        return 1;
    }

    // KMK: robo se explode causando dano a si mesmo e 
    // a qualquer robo nos tiles vizinhos (mesmo que
    // eles sejam do mesmo time)
    else if (instr.valor.ac == KMK){

        // Pega o id de todos os vizinhos
        int vizinhos[6] = {-1,-1,-1,-1,-1,-1};
        for (int i = 0; i < 6; i++){
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
            }
        
            if (posx >= 0 && posx <= 19 && posy >= 0 && posy <= 11)
                vizinhos[i] = arena.mapa.tiles[posx][posy].ocupado;

            posx = old_posx;
            posy = old_posy;   
        }
        
        // Danifica o proprio robo e detecta se ele ainda esta vivo
        arena.robots[id].vida -=100;
        D(printf("\nRobô %d se explodiu!\n", id));
        D(printf("\nRobô %d agora tem %d de vida restante!\n", id, arena.robots[id].vida));

        // Incrementa o contador do robo em 5 e atualiza seu sprite
        // na arena para refletir sua condicao ("morte")
        if (arena.robots[id].vida <= 0){
                    arena.robots[id].cont = 5;
                    D(printf("\nOh, não! Robô %d morreu!\n", id));
                    fprintf(display, "morte %d %d %d\n", id, posx, posy);
        }

        // Danifica os demais robos e detecta se eles ainda estao vivos
        for (int i = 0; i < 6; i++){
            if (vizinhos[i] != -1){
                int eid = vizinhos[i];
                if (arena.robots[eid].vida > 0){
                    arena.robots[eid].vida -=100;
                    D(printf("\nRobô %d foi danificado na explosão!\n", eid));
                    D(printf("\nRobô %d agora tem %d de vida restante!\n", eid, arena.robots[eid].vida));

                    // Incrementa o contador do robo em 5 e atualiza seu sprite
                    // na arena para refletir sua condicao ("morte")
                    if (arena.robots[eid].vida <= 0){
                        arena.robots[eid].cont = 5;
                        D(printf("\nOh, não! Robô %d morreu!\n", eid));
                        fprintf(display, "morte %d %d %d\n", eid, arena.robots[eid].position[0], arena.robots[eid].position[1]);
                    }
                }
            }
        }
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
        if(posx < 0 || posy > 11 || posx > 19 || posy < 0) return -1;
            
        switch(instr.valor.ac){
            // Move o robo caso o tile nao esteja ocupado
            case MOV:
                if(arena.mapa.tiles[posx][posy].ocupado == -1){
                    arena.robots[id].position[0] = posx;
                    arena.robots[id].position[1] = posy;
                    arena.mapa.tiles[posx][posy].ocupado = id;
                    arena.mapa.tiles[old_posx][old_posy].ocupado = -1;
                    printf("\nRobô %d se moveu para %s (posição %d, %d)\n", id, Direcao[arg.valor.v], posx, posy);

                    // Atualiza a posicao do robo na tela e redesenha
                    // possiveis cristais que tenham sido apagados
                    fprintf(display, "%d %d %d %d %d\n", id, old_posx, old_posy, posx, posy);
                    if (arena.mapa.tiles[old_posx][old_posy].cristais >= 1){
                        fprintf(display, "cris %d %d\n", old_posx, old_posy);
                    }

                    // Atualiza o contador de ocupacao do robo de acordo
                    // com o custo de cada terreno
                    Terreno terr = arena.mapa.tiles[posx][posy].terreno;

                    switch(terr){
                        case GRAMA:
                            arena.robots[id].cont +=1;
                            D(printf("Robô %d pisou na GRAMA: +1\n", id));
                            break;
                        case ESTRADA:
                            D(printf("Robô %d pisou na ESTRADA: +0\n", id));
                            break;
                        case MONTANHA:
                            arena.robots[id].cont +=4;
                            D(printf("Robô %d pisou na MONTANHA: +4\n", id));
                            break;
                        case AGUA:
                            arena.robots[id].cont +=3;
                            D(printf("Robô %d pisou na AGUA: +3\n", id));
                            break;
                        case AREIA:
                            arena.robots[id].cont +=2;
                            D(printf("Robô %d pisou na AREIA: +2\n", id));
                            break;
                    }

                    return 1;
                }
                else return -1;

            // Recolhe um cristal se o tile o tiver
            case REC:
                if(arena.mapa.tiles[posx][posy].cristais > 0){
                    arena.mapa.tiles[posx][posy].cristais--;
                    arena.robots[id].cristais++;
                    D(printf("\nRobô %d recolheu um cristal no %s (posição %d, %d)\n", id, Direcao[arg.valor.v], posx, posy));
                    return 1;
                }
                else return -1;

            // Deposita um cristal se o robo o tiver
            case DEP:
                if(arena.robots[id].cristais > 0){
                    arena.mapa.tiles[posx][posy].cristais++;
                    arena.robots[id].cristais--;
                    D(printf("\nRobô %d depositou um cristal no %s (posição %d, %d)\n", id, Direcao[arg.valor.v], posx, posy));
                    return 1;
                }
                else return -1;
            // Ataca um tile vizinho, pode conter um robo ou nao
            case ATQ:
                if(arena.mapa.tiles[posx][posy].ocupado > -1){
                    int eid = arena.mapa.tiles[posx][posy].ocupado;
                    if (arena.robots[eid].vida > 0) {
                        arena.robots[eid].vida -= 100;
                        D(printf("\nRobô %d atacou o robô %d\n", id, eid));
                        D(printf("\nRobô %d agora tem %d de vida restante!\n", eid, arena.robots[eid].vida));

                        if (arena.robots[eid].vida <= 0){
                            arena.robots[eid].cont = 5;
                            D(printf("\nOh, não! Robô %d morreu!\n", eid));
                            fprintf(display, "morte %d %d %d\n", eid, posx, posy);
                        }

                        return 1;
                    }
                    else return -1;
                }
                else return -1;
            // Joga um cristal no tile vizinho, so funciona se tiver
            // um robo no tile: neste caso, o robo atingido fica incapacitado
            // por 2 turnos e derruba todos os seus cristais
            case JGC:
                if(arena.mapa.tiles[posx][posy].ocupado > -1 && arena.robots[id].cristais > 0){
                    int eid = arena.mapa.tiles[posx][posy].ocupado;
                    arena.robots[eid].cont +=2;
                    D(printf("\nRobô %d lançou um cristal no robô %d!\n", id, eid));
                    D(printf("\nRobô %d agora está incapacitado por 2 turnos!\n", eid));
            if (arena.robots[eid].cristais > 0){
                        arena.mapa.tiles[posx][posy].cristais += arena.robots[eid].cristais;
                        arena.robots[eid].cristais = 0; 
                        D(printf("\nRobô %d derrubou todos os seus cristais!\n", eid));
                    }
                    arena.robots[id].cristais--;
                    return 1;
                }
                else return -1;
        }
    }
    return -1;
}

