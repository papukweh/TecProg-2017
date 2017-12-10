/* Compilador */

%{
#include <stdio.h>
#include <math.h>
#include "symrec.h"
#include "acertos.h"
#include "instr.h"

// Declarações do lex:  
int yylex();
void yyerror(char const *);

//int compilador(FILE *, INSTR *);
static int ip  = 0;					// ponteiro de instruções 
static int mem = 11;				// ponteiro da memória 
static INSTR *prog;					// programa
static int parmcnt = 0;		// contador de parâmetros //

// Variáveis auxiliares para armazenar a última expressão
// de um "for"
static int ip2 = 0;
static INSTR prog2[10];

// Funções auxiliares
void AddInstr(OpCode op, OPERANDO valor) {
  	prog[ip++] = (INSTR) {op,  valor};
}

void AddInstr2(OpCode op, OPERANDO valor){
	prog2[ip2++] = (INSTR) {op, valor};
}
%}

/*  Declaracoes */
%union {
	int num;
	double val;
	Dir direc;
	char cod[30];
}

%token <num> ATRt
%token <val>  NUMt
%token <cod> ID
%token <direc> DIRECAOt
%token ADDt SUBt MULt DIVt ASGN OPEN CLOSE RETt EOL
%token ADDs SUBs MULs DIVs 
%token EQt NEt LTt LEt GTt GEt INCt DECt ABRE FECHA SEP PONTO NEW
%token IF ELSE WHILE FOR FUNC PRINT VERt MOVt RECt DEPt ATQt JGCt KMKt

%right ASGN
%left ADDt SUBt
%left MULt DIVt
%left NEG
%right PWR
%left LTt GTt LEt GEt EQt NEt


/* Gramatica */
%%

// Programa: sequência de comandos
Programa: Comando
       | Programa Comando
	   ;

// Comando: expressão, condicional, laço, print, return ou chama de sistema
Comando: Expr EOL
       | Cond
       | Loop
       | Func
	   | PRINT Expr EOL { AddInstr(PRN, (OPERANDO) {NUM, 0}); }
	   | Return
 	   | Sis EOL
;

// Return: Pode retornar um valor ou não (com ou sem parênteses)
Return:  RETt EOL {
		 	AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			AddInstr(RET, (OPERANDO) {NUM, 0});
 		}
 		| RETt Expr EOL {
		 	   AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			   AddInstr(RET, (OPERANDO) {NUM, 0});
 		}

// Expressão condicional: expressão seguida de <, >, <=, >=, == ou !=
// seguido de outra expressão
ExprC:  Expr LTt Expr  { AddInstr(LT,   (OPERANDO) {NUM, 0});}
	| Expr GTt Expr  { AddInstr(GT,   (OPERANDO) {NUM, 0});}
	| Expr LEt Expr  { AddInstr(LE,   (OPERANDO) {NUM, 0});}
	| Expr GEt Expr  { AddInstr(GE,   (OPERANDO) {NUM, 0});}
	| Expr EQt Expr  { AddInstr(EQ,   (OPERANDO) {NUM, 0});}
	| Expr NEt Expr  { AddInstr(NE,   (OPERANDO) {NUM, 0});}

// Expressão:
Expr: NUMt {  AddInstr(PUSH, (OPERANDO) {NUM, $1});}
	| NEW ID ASGN Expr {symrec *s = putsym($2); /* não definida */
						AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
						}
    | ID   {
	        symrec *s = getsym($1);
			if (s==0) s = putsym($1); /* não definida */
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
	| ID ASGN Expr {
	        symrec *s = getsym($1);
			if (s==0) s = putsym($1); /* não definida */
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	| Ver
	| ID PONTO ATRt  { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr(ATR, (OPERANDO) {NUM, $3}); 
  	 	} 
	| Chamada 
    | Expr ADDt Expr { AddInstr(ADD,  (OPERANDO) {NUM, 0});}
	| Expr SUBt Expr { AddInstr(SUB,  (OPERANDO) {NUM, 0});}
	| Expr MULt Expr { AddInstr(MUL,  (OPERANDO) {NUM, 0});}
	| Expr DIVt Expr { AddInstr(DIV,  (OPERANDO) {NUM, 0});}
//    | '-' Expr %pRec NEG  { printf("  {CHS,  0},\n"); }
	| OPEN Expr CLOSE
	| ID INCt {
	         symrec *s = getsym($1);
			 if (s==0) s = putsym($1); /* não definida */
			 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			 AddInstr(PUSH, (OPERANDO) {NUM, 1});
			 AddInstr(ADD, (OPERANDO) {NUM, 0});
			 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	| ID DECt {
	         symrec *s = getsym($1);
			 if (s==0) s = putsym($1); /* não definida */
			 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			 AddInstr(PUSH, (OPERANDO) {NUM, 1});
			 AddInstr(SUB, (OPERANDO) {NUM, 0});
			 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	| ID ADDs Expr { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr(ADD, (OPERANDO) {NUM, 0});
	  		 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
 	| ID SUBs Expr { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr(SUB, (OPERANDO) {NUM, 0});
	  		 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
 	| ID MULs Expr { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr(MUL, (OPERANDO) {NUM, 0});
	  		 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 	}
 	| ID DIVs Expr { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr(DIV, (OPERANDO) {NUM, 0});
	  		 AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
  	 	;

ExprM: NUMt {  AddInstr2(PUSH, (OPERANDO) {NUM, $1});}
    | ID   {
	        symrec *s = getsym($1);
			if (s==0) s = putsym($1); /* não definida */
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
	| ID ASGN ExprM {
	        symrec *s = getsym($1);
			if (s==0) s = putsym($1); /* não definida */
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	| Ver
	| ID PONTO ATRt  { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr2(ATR, (OPERANDO) {NUM, $3}); 
  	 	} 
	| Chamada 
    | ExprM ADDt ExprM { AddInstr2(ADD,  (OPERANDO) {NUM, 0});}
	| ExprM SUBt ExprM { AddInstr2(SUB,  (OPERANDO) {NUM, 0});}
	| ExprM MULt ExprM { AddInstr2(MUL,  (OPERANDO) {NUM, 0});}
	| ExprM DIVt ExprM { AddInstr2(DIV,  (OPERANDO) {NUM, 0});}
//    | '-' Expr %pRec NEG  { printf("  {CHS,  0},\n"); }
	| OPEN ExprM CLOSE
	| ID INCt {
	         symrec *s = getsym($1);
			 if (s==0) s = putsym($1); /* não definida */
			 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			 AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			 AddInstr2(ADD, (OPERANDO) {NUM, 0});
			 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	| ID DECt {
	         symrec *s = getsym($1);
			 if (s==0) s = putsym($1); /* não definida */
			 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			 AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			 AddInstr2(SUB, (OPERANDO) {NUM, 0});
			 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 }
 	 | ID ADDs ExprM { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr2(ADD, (OPERANDO) {NUM, 0});
	  		 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
 	| ID SUBs ExprM { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr2(SUB, (OPERANDO) {NUM, 0});
	  		 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
 	| ID MULs ExprM { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr2(MUL, (OPERANDO) {NUM, 0});
	  		 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 	}
 	| ID DIVs ExprM { 
	         symrec *s = getsym($1); 
	  		 if (s==0) s = putsym($1);  
	  		 AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		 AddInstr2(DIV, (OPERANDO) {NUM, 0});
	  		 AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 	} 
  	 	;

;

// Condicionais: if (expressão condicional) sozinho ou if seguido de um else
Cond: IF OPEN {AddInstr(PUSH, (OPERANDO) {NUM, 0});} ExprC {
  	  	 	   salva_end(ip);
			   AddInstr(JIF,  (OPERANDO) {NUM, 0});
 		 }
		 CLOSE  Bloco {
		 	AddInstr(PUSH, (OPERANDO) {NUM, 1});
		   prog[pega_end()].op.valor.n = ip;
		 };
		| Cond ELSE {salva_end(ip); AddInstr(JIT, (OPERANDO) {NUM, 0}); }
				Bloco {prog[pega_end()].op.valor.n = ip;}

// Loops: while (expressão condicional) ou 
// for (expressão, expressão condicional, expressão)
Loop: WHILE OPEN  {salva_end(ip);}
	  		ExprC  { salva_end(ip); AddInstr(JIF, (OPERANDO) {NUM, 0}); }
	  		CLOSE Bloco {
				int tmp = pega_end();
				AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
				prog[tmp].op.valor.n = ip;
			} 
		| FOR OPEN Expr EOL {salva_end(ip);} 
		ExprC EOL{ salva_end(ip); AddInstr(JIF, (OPERANDO) {NUM, 0});}
		 ExprM { salva_end(ip2); while(ip2 > 0){push(prog2[--ip2]);}}
		 CLOSE Bloco  { 
		 	int a = pega_end();
		 	for (int i = 0; i < a; i++) 
		 		prog[ip++] = pop();
			int tmp = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[tmp].op.valor.n = ip;
		}

// Chamadas de sistema: Move, Recolher cristal, Depositar cristal,
// atacar, jogar cristal ou kamikaze
Sis: Mov
	| Rec
	| Dep
	| Atq
	| Jgc
	| Kmk

Mov: MOVt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, MOV});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
Rec: RECt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, REC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
Dep: DEPt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, DEP});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}	
Atq: ATQt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, ATQ});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}							
Jgc: JGCt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, JGC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
Ver: VERt OPEN Direcao_esp CLOSE {
								   AddInstr(PUSH, (OPERANDO) {ACAO, VER});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								   AddInstr(RCM, (OPERANDO) {NUM, 0}); }


Kmk: KMKt OPEN  CLOSE { AddInstr(PUSH, (OPERANDO) {ACAO, KMK});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}


Direcao: DIRECAOt {AddInstr(PUSH, (OPERANDO) {VAR, $1});}

Direcao_esp: DIRECAOt {AddInstr(PUSH, (OPERANDO) {NUM, $1});}

// Bloco: { comandos }
Bloco: ABRE Comandos FECHA ;

// Comandos: Sequência de comando(s)
Comandos: Comando 
    | Comandos Comando
	;

// Declaração de função: def (argumentos)
Func: FUNC ID
	  {
		salva_end(ip);
		AddInstr(JMP,  (OPERANDO) {NUM, 0});
		symrec *s = getsym($2);
		if (s==0) s = putsym($2);
		else {
		  yyerror("Função definida duas vezes\n");
		  YYABORT;
		}
		s->val = ip;
	  } OPEN
	  {
		newtab(lastval());
	  }
	  Args CLOSE  Bloco
	  {
		AddInstr(LEAVE, (OPERANDO) {NUM, 0});
		AddInstr(RET, (OPERANDO) {NUM, 0});
		prog[pega_end()].op.valor.n = ip;
		deltab();
	  }
	  ;

// Argumentos: identificadores separados por ","
Args: 
	| ID {
	  	 putsym($1);
	  }
    | Args SEP ID {
	  	 putsym($3);
	  }
	;

// Chamada de função:
Chamada: ID OPEN
		 {
			 parmcnt = mem;
			 /* posição da memória mais avançada */
		 }
		 ListParms
		 {
		   symrec *s = getsym($1);
		   if (s == 0) {
			 yyerror("Função não definida\n");
			 YYABORT;
		   }
		   AddInstr(ENTRY, (OPERANDO) {NUM, lastval()});
		   /* Cópia dos parâmetros */
		   while (parmcnt > mem) 
			 AddInstr( STO, (OPERANDO) {NUM, --parmcnt});
		   AddInstr(CALL, (OPERANDO) {NUM, s->val});
		 }
	  	 CLOSE ;


ListParms:
	| Expr { parmcnt++;}
	| Expr { parmcnt++;} SEP ListParms
;

%%
extern FILE *yyin;

void yyerror(char const *msg) {
	fprintf(stderr, "IP: %d\n", ip);
	fprintf(stderr,"ERRO: %s",msg);
}

int compilador(FILE *cod, INSTR *dest) {
	ip = 0;
	cleartab();
	yyin = cod;
	prog = dest;
	int r = yyparse();
	AddInstr(END,(OPERANDO) {NUM, 0});
	deltab();
	return ip;
}
