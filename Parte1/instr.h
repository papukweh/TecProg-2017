/* Códigos das instruções */
typedef enum {
  PUSH,       //Empilha argumento na pilha de dados
  POP,        //Desempilha elemento da pilha de dados
  DUP,        //Duplica o topo da pilha de dados
  ADD,        //Soma os dois elementos no topo da pilha
  SUB,        //Subtrai os dois elementos no topo da pilha
  MUL,        //Multiplica os dois elementos no topo da pilha
  DIV,        //Divide os dois elementos no topo da pilha
  JMP,        //Pulo incondicional para argumento
  JIT,        //Pulo se verdadeiro
  JIF,        //Pulo se falso
  CALL,       //Chama a função no endereço argumento
  RET,        //Retorna  
  EQ,         //Compara os dois elementos do topo da pilha de dados (=)
  GT,         //Compara os dois elementos do topo da pilha de dados (>)
  GE,         //Compara os dois elementos do topo da pilha de dados (>=)
  LT,         //Compara os dois elementos do topo da pilha de dados (<)
  LE,         //Compara os dois elementos do topo da pilha de dados (<=)
  NE,         //Compara os dois elementos do topo da pilha de dados (!=)
  STO,        //Desempilha elemento da pilha de dados e armazena em mem[arg]
  RCL,        //Empilha elemento de mem[arg] na pilha de dados
  STL,        //Desempilha elemento da pilha de dados e armazena em exec[rbp+arg]
  RCE,        //Empilha elemento de exec[rbp+arg] na pilha de dados
  ALC,        //Aloca arg espaços na pilha de execução
  FRE,        //Libera arg espaçoes na pilha de execução
  SAVE,       //Salva o valor de rbp
  REST,       //Restaura o valor de rbp
  END,        //Finaliza a execução do programa
  PRN,        //Desempilha e imprime o elemento da pilha de dados
  SISTEMA,    //Chamada para o sistema (arena)
  ATR,
} OpCode;

/* Tipos dos operandos */
/* no momento, são todos inteiros */
typedef enum {
  NUM,
  ACAO,
  VAR,
  TILE,
} Tipo;

typedef struct {
  int terreno;
  int cristais;
  int ocupado;
  int base;
} Tile;
 
/* Operando */
typedef struct { 
  Tipo t; 
  union { 
 	  int n; 
 	  int ac; 
    int v; 
    Tile tile;
  }; 
} OPERANDO; 

/* Instrução */
typedef struct {
  OpCode instr;
  OPERANDO op;
} INSTR;


