/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_COMPILA_TAB_H_INCLUDED
# define YY_YY_COMPILA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ATRt = 258,
    NUMt = 259,
    ID = 260,
    DIRECAOt = 261,
    TERRt = 262,
    ADDt = 263,
    SUBt = 264,
    MULt = 265,
    DIVt = 266,
    ASGN = 267,
    OPEN = 268,
    CLOSE = 269,
    RETt = 270,
    EOL = 271,
    ADDs = 272,
    SUBs = 273,
    MULs = 274,
    DIVs = 275,
    EQt = 276,
    NEt = 277,
    LTt = 278,
    LEt = 279,
    GTt = 280,
    GEt = 281,
    INCt = 282,
    DECt = 283,
    ABRE = 284,
    FECHA = 285,
    SEP = 286,
    PONTO = 287,
    NEW = 288,
    TRUEt = 289,
    RESPt = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    FOR = 294,
    FUNC = 295,
    PRINT = 296,
    VERt = 297,
    MOVt = 298,
    RECt = 299,
    DEPt = 300,
    ATQt = 301,
    JGCt = 302,
    KMKt = 303,
    VERt2 = 304,
    NEGt = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "compila.y" /* yacc.c:1909  */

	int num;
	double val;
	Dir direc;
	Terreno terr;
	char cod[30];

#line 113 "compila.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILA_TAB_H_INCLUDED  */
