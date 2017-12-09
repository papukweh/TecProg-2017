/* Compilador */

%{
#include <stdio.h>
#include <math.h>
#include "symrec.h"
#include "acertos.h"
#include "instr.h"
  
int yylex();
void yyerror(char const *);
int compila(FILE *, INSTR *);
static int ip  = 0;					/* ponteiro de instruções */
static int mem = 11;
static int ip3 = 0;	
static int last = 0;
static int lastlast = 0;				/* ponteiro da memória */
static INSTR *prog;
static INSTR *prog2;
static int parmcnt = 0;		/* contador de parâmetros */

void AddInstr(OpCode op, OPERANDO valor) {
  	prog[ip++] = (INSTR) {op,  valor};
}

void AddInstr2(OpCode op, OPERANDO valor){
	fprintf(stderr, "ip is %d\n", ip3);
	prog2[ip3++] = (INSTR) {op, valor};
}
%}

/*  Declaracoes */
%union {
	int num;
	double val;
	Dir direc;
	/* symrec *cod; */
	char cod[30];
}

/* %type  Expr */

%token <num> ATRt
%token <val>  NUMt
%token <cod> ID
%token <direc> DIRECAOt
%token ADDt SUBt MULt DIVt ASGN OPEN CLOSE RETt EOL
%token ADDs SUBs MULs DIVs 
%token EQt NEt LTt LEt GTt GEt INCt DECt ABRE FECHA SEP PONTO ATRt
%token IF ELSE WHILE FOR FUNC PRINT VERt MOVt RECt DEPt ATQt JGCt KMKt DIRECAOt

%right ASGN
%left ADDt SUBt
%left MULt DIVt
%left NEG
%right PWR
%left LTt GTt LEt GEt EQt NEt


/* Gramatica */
%%

Programa: Comando
       | Programa Comando
	   ;

Comando: Expr EOL
       | Cond
       | Loop
       | Func
	   | PRINT Expr EOL { AddInstr(PRN, (OPERANDO) {NUM, 0}); }
	   | RETt EOL {
		 	    AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			    AddInstr(RET, (OPERANDO) {NUM, 0});
 			}
	   
	   | RETt OPEN  Expr CLOSE EOL {
		 	   AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			   AddInstr(RET, (OPERANDO) {NUM, 0});
 		    }
 		| Sis EOL
	   /* | EOL {printf("--> %d\n", ip);} */
;

Expr: NUMt {  AddInstr(PUSH, (OPERANDO) {NUM, $1});}
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
 	| ver
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
//    | '-' Expr %prec NEG  { printf("  {CHS,  0},\n"); }
	| OPEN Expr CLOSE
	| Expr LTt Expr  { AddInstr(LT,   (OPERANDO) {NUM, 0});}
	| Expr GTt Expr  { AddInstr(GT,   (OPERANDO) {NUM, 0});}
	| Expr LEt Expr  { AddInstr(LE,   (OPERANDO) {NUM, 0});}
	| Expr GEt Expr  { AddInstr(GE,   (OPERANDO) {NUM, 0});}
	| Expr EQt Expr  { AddInstr(EQ,   (OPERANDO) {NUM, 0});}
	| Expr NEt Expr  { AddInstr(NE,   (OPERANDO) {NUM, 0});}
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
 	| ver
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
//    | '-' Expr %prec NEG  { printf("  {CHS,  0},\n"); }
	| OPEN ExprM CLOSE
	| ExprM LTt ExprM  { AddInstr2(LT,   (OPERANDO) {NUM, 0});}
	| ExprM GTt ExprM  { AddInstr2(GT,   (OPERANDO) {NUM, 0});}
	| ExprM LEt ExprM  { AddInstr2(LE,   (OPERANDO) {NUM, 0});}
	| ExprM GEt ExprM  { AddInstr2(GE,   (OPERANDO) {NUM, 0});}
	| ExprM EQt ExprM  { AddInstr2(EQ,   (OPERANDO) {NUM, 0});}
	| ExprM NEt ExprM  { AddInstr2(NE,   (OPERANDO) {NUM, 0});}
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

Cond: IF OPEN {AddInstr(PUSH, (OPERANDO) {NUM, 0});} Expr {
  	  	 	   salva_end(ip);
			   AddInstr(JIF,  (OPERANDO) {NUM, 0});
 		 }
		 CLOSE  Bloco {
		 	AddInstr(PUSH, (OPERANDO) {NUM, 1});
		   prog[pega_end()].op.valor.n = ip;
		 };
		| Cond ELSE {salva_end(ip); AddInstr(JIT, (OPERANDO) {NUM, 0}); }
				Bloco {prog[pega_end()].op.valor.n = ip;}

Loop: WHILE OPEN  {salva_end(ip);}
	  		Expr  { salva_end(ip); AddInstr(JIF, (OPERANDO) {NUM, 0}); }
	  		CLOSE Bloco {
				int ip2 = pega_end();
				AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
				prog[ip2].op.valor.n = ip;
			} 
		| FOR OPEN Expr EOL {salva_end(ip);} 
		Expr EOL{ salva_end(ip); AddInstr(JIF, (OPERANDO) {NUM, 0});}
		 ExprM { lastlast = last; last = ip3;
		 		fprintf(stderr, "ll=%d\n", lastlast);
		 		fprintf(stderr, "l=%d\n", last);
		 		fprintf(stderr, "ip3=%d\n", ip3);} 
		 CLOSE Bloco  { 
		 	for (int i = last-lastlast; i<last; i++){ 
		 		prog[ip++] = prog2[i];}
		 	last = lastlast;
			int ip2 = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[ip2].op.valor.n = ip;
			}

Sis: mov
	| rec
	| dep
	| atq
	| jgc
	| kmk

mov: MOVt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, MOV});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
rec: RECt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, REC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
dep: DEPt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, DEP});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}	
atq: ATQt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, ATQ});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}							
jgc: JGCt OPEN  Direcao CLOSE { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, JGC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
ver: VERt OPEN Direcao_esp CLOSE {
								   AddInstr(PUSH, (OPERANDO) {ACAO, VER});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								   AddInstr(RCM, (OPERANDO) {NUM, 0}); }


kmk: KMKt OPEN  CLOSE { AddInstr(PUSH, (OPERANDO) {ACAO, KMK});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}

Direcao: DIRECAOt {AddInstr(PUSH, (OPERANDO) {VAR, $1});}

Direcao_esp: DIRECAOt {AddInstr(PUSH, (OPERANDO) {NUM, $1});}

Bloco: ABRE Comandos FECHA ;

Comandos: Comando 
    | Comandos Comando
	;

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
		newtab(0);
	  }
	  Args CLOSE  Bloco
	  {
		AddInstr(LEAVE, (OPERANDO) {NUM, 0});
		AddInstr(RET, (OPERANDO) {NUM, 0});
		prog[pega_end()].op.valor.n = ip;
		deltab();
	  }
	  ;

Args: 
	| ID {
	  	 putsym($1);
	  }
    | Args SEP ID {
	  	 putsym($3);
	  }
	;

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
	prog2 = malloc(sizeof(INSTR)*20);
	ip = 0;
	yyin = cod;
	prog = dest;
	int r = yyparse();
	AddInstr(END,(OPERANDO) {NUM, 0});
	free(prog2);
	return ip;
}

// int main(int ac, char **av){ 
// 	ac --; av++; 
// 	if (ac>0) 
// 		yyin = fopen(*av,"r"); 

// 	yyparse(); 
// 	return 0; 
// } 
