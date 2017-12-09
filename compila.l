DIRECAO [N|S][E|W]?|CN
ATRIBUTO terreno|cristais|ocupado|base
D [0-9]
L [a-zA-Z_]
H [a-zA-Z_0-9]
E [Ee][+-]?{D}+

%{
#include <math.h>
#include <string.h>
#include "instr.h"
#include "compila.tab.h"

Dir acha_dir(char *s){
	if (strcmp(s, "NW") == 0)
		return (Dir) NW;
	if (strcmp(s, "N") == 0)
		return (Dir) N;
	if (strcmp(s, "NE") == 0)
		return (Dir) NE;
	if (strcmp(s, "SW") == 0)
		return (Dir) SW;
	if (strcmp(s, "S") == 0)
		return (Dir) S;
	if (strcmp(s, "SE") == 0)
		return (Dir) SE;
	if (strcmp(s, "CN") == 0)
		return (Dir) CN;
}

int acha_atr(char *s){
	if (strcmp(s, "terreno") == 0)
		return 0;
	if (strcmp(s, "cristais") == 0)
		return 1;
	if (strcmp(s, "ocupado") == 0)
		return 2;
	if (strcmp(s, "base") == 0)
		return  3;
}
%}


%%
{D}*[.]?{D}+{E}?	{ yylval.val = atof(yytext); return NUMt; }

ret(urn)?  { return RETt; }

if      { return IF; }
else	{return ELSE; }
while	{ return WHILE; }
for 	{ return FOR;}
func|def { return FUNC; }
print   { return PRINT; }
move	{ return MOVt; }
ataca	{ return ATQt; } //ataca(ne)
recolhe	{ return RECt; } //recolhe(nw);
deposita {return DEPt; }
joga_cristal {return JGCt;}
kamikaze {return KMKt;}
ver {return VERt;}
{DIRECAO} { yylval.direc = acha_dir(yytext); return DIRECAOt;}
{ATRIBUTO} {yylval.num = acha_atr(yytext); return ATRt; }

{L}{H}* { 
  strncpy(yylval.cod, yytext, 30);
  return ID;
}

[ \t\n]+	/* pula espacos em branco */

#.*		/* comentarios simples */

"."		{ return PONTO; }
;		{ return EOL; }
,		{ return SEP; }
=		{ return ASGN; }
[(]		{ return OPEN; }
[)]		{ return CLOSE; }
[{]		{ return ABRE; }
[}]		{ return FECHA; }
[+]		{ return ADDt; }
[-]		{ return SUBt; }
[*]		{ return MULt; }
[/]		{ return DIVt; }
==		{ return EQt; }
!=		{ return NEt; }
"<"		{ return LTt; }
"<="	{ return LEt; }
">"		{ return GTt; }
">="	{ return GEt; }
"++"	{ return INCt; }
"--"	{ return DECt; }
"+="	{ return ADDs; }
"-="	{ return SUBs; }
"*="	{ return MULs; }
"/="	{ return DIVs; }

.	{  fprintf(stderr, "Entrada ignorada\n-->%s\n", yytext); }

%%

/* Local Variables: */
/* mode: c */
/* End: */