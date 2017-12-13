/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "compila.y" /* yacc.c:339  */

#include <stdio.h>
#include <math.h>
#include "symrec.h"
#include "acertos.h"
#include "instr.h"

// Declaracoes do lex:  
int yylex();
int compilador();
void yyerror(char const *);
void Fatal();

// Variaveis principais
static int ip  = 0;					// ponteiro de instrucoes 
static int mem = 9;				// ponteiro da memoria 
static INSTR *prog;					// programa
static int parmcnt = 0;		// contador de parametros 

// Variaveis axiliares para armazenar a ultima expressao
// de um "for"
static int ip2 = 0;
static INSTR prog2[10];

// Funcoes auxiliares
void AddInstr(OpCode op, OPERANDO valor) {
  	prog[ip++] = (INSTR) {op,  valor};
}

void AddInstr2(OpCode op, OPERANDO valor){
	prog2[ip2++] = (INSTR) {op, valor};
}

#line 100 "compila.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compila.tab.h".  */
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
#line 38 "compila.y" /* yacc.c:355  */

	int num;
	double val;
	Dir direc;
	Terreno terr;
	char cod[30];

#line 199 "compila.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "compila.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    72,    73,    74,    75,    76,    77,
      78,    82,    86,    94,    95,    96,    97,    98,    99,   100,
     113,   114,   118,   123,   128,   129,   130,   131,   137,   138,
     139,   140,   141,   142,   143,   144,   152,   160,   167,   174,
     181,   194,   195,   200,   205,   206,   212,   213,   214,   215,
     216,   217,   218,   219,   227,   235,   242,   249,   256,   266,
     267,   266,   275,   275,   286,   287,   286,   296,   297,   301,
     296,   320,   321,   322,   323,   324,   325,   326,   327,   330,
     336,   342,   348,   353,   359,   365,   368,   374,   378,   380,
     383,   386,   389,   390,   394,   404,   394,   414,   415,   416,
     420,   421,   420,   436,   437,   438,   438
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATRt", "NUMt", "ID", "DIRECAOt",
  "TERRt", "ADDt", "SUBt", "MULt", "DIVt", "ASGN", "OPEN", "CLOSE", "RETt",
  "EOL", "ADDs", "SUBs", "MULs", "DIVs", "EQt", "NEt", "LTt", "LEt", "GTt",
  "GEt", "INCt", "DECt", "ABRE", "FECHA", "SEP", "PONTO", "NEW", "TRUEt",
  "RESPt", "IF", "ELSE", "WHILE", "FOR", "FUNC", "PRINT", "VERt", "MOVt",
  "RECt", "DEPt", "ATQt", "JGCt", "KMKt", "VERt2", "NEGt", "$accept",
  "Programa", "Comando", "Return", "ExprC", "Expr", "ExprM", "Cond", "$@1",
  "$@2", "$@3", "Loop", "$@4", "$@5", "$@6", "$@7", "$@8", "Sis", "Mov",
  "Rec", "Dep", "Atq", "Jgc", "Ver", "Checa_dir", "Kmk", "Direcao",
  "Direcao_esp", "Resposta", "Bloco", "Terreno", "Comandos", "Func", "$@9",
  "$@10", "Args", "Chamada", "$@11", "$@12", "ListParms", "$@13", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     176,  -140,    80,  -140,   222,   222,    11,     3,    -3,     1,
       4,     6,    17,   222,    21,    23,    25,    30,    32,    34,
      35,    49,   110,  -140,  -140,   166,    -9,  -140,    19,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,   222,  -140,   222,   222,   222,   222,  -140,  -140,    60,
       2,  -140,   130,  -140,   306,    54,    50,  -140,  -140,   222,
    -140,   315,    53,    71,    71,    71,    71,    71,    67,    76,
    -140,  -140,   222,   222,   222,   222,  -140,  -140,  -140,    64,
     222,    64,    64,    64,    64,  -140,  -140,  -140,   222,  -140,
      45,    45,   319,    70,  -140,  -140,  -140,    81,    82,    95,
      97,    99,  -140,  -140,   102,     2,     2,  -140,  -140,    56,
      22,  -140,    64,  -140,  -140,   277,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   176,  -140,    87,   106,   108,
     222,   222,   222,   222,   222,   222,   120,    45,   119,  -140,
     157,   222,  -140,    56,    64,    64,    64,    64,    64,    64,
      56,   126,  -140,    -8,  -140,  -140,  -140,  -140,  -140,  -140,
      56,   131,    52,  -140,  -140,  -140,   264,   222,    52,    94,
    -140,  -140,    52,    52,    52,    52,    52,  -140,  -140,   132,
       2,   328,    52,    52,    52,    52,   146,    94,    94,    94,
      94,    94,  -140,  -140,    15,    15,  -140,  -140,    56,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    22,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     9,     0,     5,     6,     0,    71,
      72,    73,    74,    75,    77,    25,    76,    24,    26,     7,
      28,     0,   100,     0,     0,     0,     0,    35,    36,     0,
      33,    24,     0,    11,     0,     0,     0,    59,    64,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     3,     0,     0,     0,     0,     4,    62,    10,    23,
     103,    37,    38,    39,    40,    27,    34,    12,     0,    89,
       0,     0,     0,     0,     8,    84,    87,     0,     0,     0,
       0,     0,    86,    88,     0,    29,    30,    31,    32,     0,
     104,   101,    21,    19,    60,     0,    65,    67,    95,    79,
      80,    81,    82,    83,    85,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    92,
       0,   103,   102,     0,    17,    18,    13,    15,    14,    16,
       0,     0,    98,     0,    90,    93,   106,    61,    66,    68,
       0,     0,     0,    96,    99,    41,    42,     0,     0,    69,
      44,    46,     0,     0,     0,     0,     0,    53,    54,     0,
      51,     0,     0,     0,     0,     0,     0,    43,    55,    56,
      57,    58,    45,    52,    47,    48,    49,    50,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,   -19,  -140,   -86,    -4,   136,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,    66,  -140,    24,  -140,     7,  -139,
    -140,  -140,  -140,  -140,  -140,  -140,    90,  -140,  -140,    26,
    -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,   114,    25,   169,    26,    90,   129,
     109,    27,    91,   136,   137,   162,   186,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    97,   104,    51,   126,
      38,   140,    39,    93,   138,   153,    40,    80,   128,   111,
     127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    52,    54,    71,   157,   116,   160,    37,    55,    61,
      56,   158,    74,    75,    57,     1,     2,    58,     3,    59,
       4,   163,    60,   161,     5,   184,   185,    53,    77,    37,
      72,    73,    74,    75,    62,    78,    63,    79,    64,    81,
      82,    83,    84,    65,     7,    66,     8,    67,    68,     1,
       2,   151,     3,  -105,     4,    92,   165,   166,     5,   199,
      21,   167,    69,    85,    89,   168,    88,    95,   105,   106,
     107,   108,    72,    73,    74,    75,   110,    96,     7,   113,
       8,   102,   103,   118,   112,   125,   115,   115,    98,    99,
     100,   101,    41,    42,    21,   119,   120,    43,    44,    45,
      46,    21,   182,   183,   184,   185,   139,    47,    48,   121,
      70,   122,    49,   123,     1,     2,   124,     3,   141,     4,
     142,   155,   143,     5,   152,     6,   144,   145,   146,   147,
     148,   149,    37,   115,   150,   192,   164,   110,    72,    73,
      74,    75,   159,     7,    86,     8,     9,    37,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     198,     1,     2,   180,     3,     0,     4,   156,     0,     0,
       5,     0,     6,     0,    72,    73,    74,    75,     0,     0,
       1,     2,    76,     3,     0,     4,     0,   154,     0,     5,
       7,     6,     8,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     7,
       0,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,     2,   170,     3,
       0,     4,     0,     0,   170,     5,     0,     0,   170,   170,
     170,   170,   170,     0,     0,     0,     0,     0,   170,   170,
     170,   170,   171,     0,     0,     7,     0,     8,   171,     0,
       0,     0,   171,   171,   171,   171,   171,     0,     0,     0,
       0,    21,   171,   171,   171,   171,   172,    42,     0,     0,
       0,   173,   174,   175,   176,    72,    73,    74,    75,     0,
       0,   177,   178,     0,     0,     0,   179,     0,   130,   131,
     132,   133,   134,   135,   181,     0,     0,     0,   187,   188,
     189,   190,   191,     0,    72,    73,    74,    75,   194,   195,
     196,   197,    87,    72,    73,    74,    75,    72,    73,    74,
      75,    94,     0,     0,     0,   117,   182,   183,   184,   185,
       0,     0,   193
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,    22,   143,    91,    14,     0,     5,    13,
      13,   150,    10,    11,    13,     4,     5,    13,     7,    13,
       9,   160,     5,    31,    13,    10,    11,    16,    37,    22,
       8,     9,    10,    11,    13,    16,    13,    41,    13,    43,
      44,    45,    46,    13,    33,    13,    35,    13,    13,     4,
       5,   137,     7,    31,     9,    59,     4,     5,    13,   198,
      49,     9,    13,     3,    14,    13,    12,    14,    72,    73,
      74,    75,     8,     9,    10,    11,    80,     6,    33,    34,
      35,    14,     6,    13,    88,    29,    90,    91,    64,    65,
      66,    67,    12,    13,    49,    14,    14,    17,    18,    19,
      20,    49,     8,     9,    10,    11,   125,    27,    28,    14,
       0,    14,    32,    14,     4,     5,    14,     7,    31,     9,
      14,   140,    14,    13,     5,    15,   130,   131,   132,   133,
     134,   135,   125,   137,    14,     3,     5,   141,     8,     9,
      10,    11,    16,    33,    14,    35,    36,   140,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      14,     4,     5,   167,     7,    -1,     9,   141,    -1,    -1,
      13,    -1,    15,    -1,     8,     9,    10,    11,    -1,    -1,
       4,     5,    16,     7,    -1,     9,    -1,    30,    -1,    13,
      33,    15,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     4,     5,   162,     7,
      -1,     9,    -1,    -1,   168,    13,    -1,    -1,   172,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,   185,   162,    -1,    -1,    33,    -1,    35,   168,    -1,
      -1,    -1,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,    49,   182,   183,   184,   185,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    20,     8,     9,    10,    11,    -1,
      -1,    27,    28,    -1,    -1,    -1,    32,    -1,    21,    22,
      23,    24,    25,    26,   168,    -1,    -1,    -1,   172,   173,
     174,   175,   176,    -1,     8,     9,    10,    11,   182,   183,
     184,   185,    16,     8,     9,    10,    11,     8,     9,    10,
      11,    16,    -1,    -1,    -1,    16,     8,     9,    10,    11,
      -1,    -1,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     7,     9,    13,    15,    33,    35,    36,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    52,    53,    54,    56,    58,    62,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    79,    81,    83,
      87,    12,    13,    17,    18,    19,    20,    27,    28,    32,
      56,    79,    56,    16,    56,     5,    13,    13,    13,    13,
       5,    56,    13,    13,    13,    13,    13,    13,    13,    13,
       0,    53,     8,     9,    10,    11,    16,    37,    16,    56,
      88,    56,    56,    56,    56,     3,    14,    16,    12,    14,
      59,    63,    56,    84,    16,    14,     6,    77,    77,    77,
      77,    77,    14,     6,    78,    56,    56,    56,    56,    61,
      56,    90,    56,    34,    55,    56,    55,    16,    13,    14,
      14,    14,    14,    14,    14,    29,    80,    91,    89,    60,
      21,    22,    23,    24,    25,    26,    64,    65,    85,    53,
      82,    31,    14,    14,    56,    56,    56,    56,    56,    56,
      14,    55,     5,    86,    30,    53,    90,    80,    80,    16,
      14,    31,    66,    80,     5,     4,     5,     9,    13,    57,
      75,    87,    12,    17,    18,    19,    20,    27,    28,    32,
      56,    57,     8,     9,    10,    11,    67,    57,    57,    57,
      57,    57,     3,    14,    57,    57,    57,    57,    14,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    59,
      60,    58,    61,    58,    63,    64,    62,    65,    66,    67,
      62,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    82,    84,    85,    83,    86,    86,    86,
      88,    89,    87,    90,    90,    91,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     3,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     4,     1,     3,     1,     1,     1,     3,     1,     3,
       3,     3,     3,     2,     3,     2,     2,     3,     3,     3,
       3,     1,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     2,     3,     2,     2,     3,     3,     3,     3,     0,
       0,     7,     0,     4,     0,     0,     7,     0,     0,     0,
      12,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     3,     4,     3,     1,     1,     3,
       3,     1,     1,     2,     0,     0,     8,     0,     1,     3,
       0,     0,     6,     0,     1,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 76 "compila.y" /* yacc.c:1646  */
    { AddInstr(PRN, (OPERANDO) {NUM, 0}); }
#line 1463 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "compila.y" /* yacc.c:1646  */
    {
		 	AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			AddInstr(RET, (OPERANDO) {NUM, 0});
 			}
#line 1472 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "compila.y" /* yacc.c:1646  */
    {
		 	   AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			   AddInstr(RET, (OPERANDO) {NUM, 0});
 			}
#line 1481 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 94 "compila.y" /* yacc.c:1646  */
    { AddInstr(LT,   (OPERANDO) {NUM, 0});}
#line 1487 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 95 "compila.y" /* yacc.c:1646  */
    { AddInstr(GT,   (OPERANDO) {NUM, 0});}
#line 1493 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "compila.y" /* yacc.c:1646  */
    { AddInstr(LE,   (OPERANDO) {NUM, 0});}
#line 1499 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 97 "compila.y" /* yacc.c:1646  */
    { AddInstr(GE,   (OPERANDO) {NUM, 0});}
#line 1505 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "compila.y" /* yacc.c:1646  */
    { AddInstr(EQ,   (OPERANDO) {NUM, 0});}
#line 1511 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 99 "compila.y" /* yacc.c:1646  */
    { AddInstr(NE,   (OPERANDO) {NUM, 0});}
#line 1517 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 100 "compila.y" /* yacc.c:1646  */
    { AddInstr(PUSH, (OPERANDO) {NUM, 1});}
#line 1523 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 113 "compila.y" /* yacc.c:1646  */
    {  AddInstr(PUSH, (OPERANDO) {NUM, (yyvsp[0].val)});}
#line 1529 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 114 "compila.y" /* yacc.c:1646  */
    {
						symrec *s = putsym((yyvsp[-2].cod)); 
						AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
						}
#line 1538 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[0].cod));
			if (s==0) s = putsym((yyvsp[0].cod)); 
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
#line 1548 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 123 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-2].cod));
			if (s==0) s = putsym((yyvsp[-2].cod)); 
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1558 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 131 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(ATR, (OPERANDO) {NUM, (yyvsp[0].num)}); 
  	 		}
#line 1569 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "compila.y" /* yacc.c:1646  */
    { AddInstr(ADD,  (OPERANDO) {NUM, 0});}
#line 1575 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 139 "compila.y" /* yacc.c:1646  */
    { AddInstr(SUB,  (OPERANDO) {NUM, 0});}
#line 1581 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "compila.y" /* yacc.c:1646  */
    { AddInstr(MUL,  (OPERANDO) {NUM, 0});}
#line 1587 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 141 "compila.y" /* yacc.c:1646  */
    { AddInstr(DIV,  (OPERANDO) {NUM, 0});}
#line 1593 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 142 "compila.y" /* yacc.c:1646  */
    { AddInstr(NEG,  (OPERANDO) {NUM, 0}); }
#line 1599 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 144 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr(PUSH, (OPERANDO) {NUM, 1});
			AddInstr(ADD, (OPERANDO) {NUM, 0});
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1612 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr(PUSH, (OPERANDO) {NUM, 1});
			AddInstr(SUB, (OPERANDO) {NUM, 0});
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1625 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 160 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(ADD, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1637 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 167 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  	 	AddInstr(SUB, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1649 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 174 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(MUL, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1661 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(DIV, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1673 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "compila.y" /* yacc.c:1646  */
    {  AddInstr2(PUSH, (OPERANDO) {NUM, (yyvsp[0].val)});}
#line 1679 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 195 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[0].cod));
			if (s==0) s = putsym((yyvsp[0].cod)); 
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
#line 1689 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 200 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-2].cod));
			if (s==0) s = putsym((yyvsp[-2].cod)); 
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1699 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  	 	AddInstr2(ATR, (OPERANDO) {NUM, (yyvsp[0].num)}); 
  	 		}
#line 1710 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 213 "compila.y" /* yacc.c:1646  */
    { AddInstr2(ADD,  (OPERANDO) {NUM, 0});}
#line 1716 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "compila.y" /* yacc.c:1646  */
    { AddInstr2(SUB,  (OPERANDO) {NUM, 0});}
#line 1722 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 215 "compila.y" /* yacc.c:1646  */
    { AddInstr2(MUL,  (OPERANDO) {NUM, 0});}
#line 1728 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 216 "compila.y" /* yacc.c:1646  */
    { AddInstr2(DIV,  (OPERANDO) {NUM, 0});}
#line 1734 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 217 "compila.y" /* yacc.c:1646  */
    { AddInstr(NEG,  (OPERANDO) {NUM, 0}); }
#line 1740 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 219 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			AddInstr2(ADD, (OPERANDO) {NUM, 0});
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1753 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 227 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			AddInstr2(SUB, (OPERANDO) {NUM, 0});
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1766 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 235 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(ADD, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1778 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(SUB, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1790 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 249 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(MUL, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1802 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(DIV, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1814 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 266 "compila.y" /* yacc.c:1646  */
    {
				AddInstr(PUSH, (OPERANDO) {NUM, 0});}
#line 1821 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 267 "compila.y" /* yacc.c:1646  */
    {
  	  	 	   	salva_end(ip);
			   	AddInstr(JIF,  (OPERANDO) {NUM, 0});
 		 		}
#line 1830 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "compila.y" /* yacc.c:1646  */
    {
		 		AddInstr(PUSH, (OPERANDO) {NUM, 1});
		   		prog[pega_end()].op.valor.n = ip;
		 		}
#line 1839 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 275 "compila.y" /* yacc.c:1646  */
    {
				salva_end(ip); 
				AddInstr(JIT, (OPERANDO) {NUM, 0}); 
				}
#line 1848 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 279 "compila.y" /* yacc.c:1646  */
    { prog[pega_end()].op.valor.n = ip; }
#line 1854 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 286 "compila.y" /* yacc.c:1646  */
    { salva_end(ip); }
#line 1860 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 287 "compila.y" /* yacc.c:1646  */
    {
	  		salva_end(ip); 
	  		AddInstr(JIF, (OPERANDO) {NUM, 0});
	  		}
#line 1869 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 291 "compila.y" /* yacc.c:1646  */
    {
			int tmp = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[tmp].op.valor.n = ip;
			}
#line 1879 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 296 "compila.y" /* yacc.c:1646  */
    { salva_end(ip); }
#line 1885 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 297 "compila.y" /* yacc.c:1646  */
    { 	
			salva_end(ip); 
			AddInstr(JIF, (OPERANDO) {NUM, 0});
			}
#line 1894 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 301 "compila.y" /* yacc.c:1646  */
    { 	
		 	salva_end(ip2); 
		 	while(ip2 > 0)
		 		push(prog2[--ip2]);
		 	}
#line 1904 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 306 "compila.y" /* yacc.c:1646  */
    { 
		 	int a = pega_end();
		 	for (int i = 0; i < a; i++) 
		 		prog[ip++] = pop();
			int tmp = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[tmp].op.valor.n = ip;
			}
#line 1917 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 330 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, MOV});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1926 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 336 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, REC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1935 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 342 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, DEP});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1944 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 348 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, ATQ});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1953 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 353 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, JGC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1962 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 359 "compila.y" /* yacc.c:1646  */
    {
								   AddInstr(PUSH, (OPERANDO) {ACAO, VER});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
									}
#line 1971 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 365 "compila.y" /* yacc.c:1646  */
    { AddInstr(RCM, (OPERANDO) {NUM, 0});}
#line 1977 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 368 "compila.y" /* yacc.c:1646  */
    { 
						AddInstr(PUSH, (OPERANDO) {ACAO, KMK});
						AddInstr(SYS, (OPERANDO) {NUM, 0});
						}
#line 1986 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 374 "compila.y" /* yacc.c:1646  */
    { AddInstr(PUSH, (OPERANDO) {VAR, (yyvsp[0].direc)}); }
#line 1992 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 378 "compila.y" /* yacc.c:1646  */
    { AddInstr(PUSH, (OPERANDO) {NUM, (yyvsp[0].direc)}); }
#line 1998 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 380 "compila.y" /* yacc.c:1646  */
    {AddInstr(RCL, (OPERANDO) {NUM, 8}); }
#line 2004 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 386 "compila.y" /* yacc.c:1646  */
    {AddInstr(PUSH, (OPERANDO) {TERRENO, (yyvsp[0].terr)}); }
#line 2010 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 394 "compila.y" /* yacc.c:1646  */
    {
		salva_end(ip);
		AddInstr(JMP,  (OPERANDO) {NUM, 0});
		symrec *s = getsym((yyvsp[0].cod));
		if (s==0) s = putsym((yyvsp[0].cod));
		else {
			yyerror("Função definida duas vezes\n");
			YYABORT;
		}
		s->val = ip;
	  	}
#line 2026 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 404 "compila.y" /* yacc.c:1646  */
    { newtab(lastval()); }
#line 2032 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 405 "compila.y" /* yacc.c:1646  */
    {
			AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			AddInstr(RET, (OPERANDO) {NUM, 0});
			prog[pega_end()].op.valor.n = ip;
			deltab();
	  	}
#line 2043 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 415 "compila.y" /* yacc.c:1646  */
    { putsym((yyvsp[0].cod)); }
#line 2049 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 416 "compila.y" /* yacc.c:1646  */
    { putsym((yyvsp[0].cod)); }
#line 2055 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 420 "compila.y" /* yacc.c:1646  */
    { parmcnt = mem; }
#line 2061 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 421 "compila.y" /* yacc.c:1646  */
    {
			symrec *s = getsym((yyvsp[-3].cod));
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
#line 2078 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 437 "compila.y" /* yacc.c:1646  */
    { parmcnt++;}
#line 2084 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 438 "compila.y" /* yacc.c:1646  */
    { parmcnt++;}
#line 2090 "compila.tab.c" /* yacc.c:1646  */
    break;


#line 2094 "compila.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 441 "compila.y" /* yacc.c:1906  */

extern FILE *yyin;

// Mensagem de erro 
void yyerror(char const *msg) {
	fprintf(stderr, "IP: %d\n", ip);
	fprintf(stderr,"ERRO: %s\n",msg);
}

// Funcao que chama o yyparse para compilar o programa
// que se encontra no arquivo dado como argumento
int compilador(FILE *cod, INSTR *dest, int id) {
	ip = 0;
	cleartab();
	yyin = cod;
	prog = dest;
	int r = yyparse();
	if (r == 0){
		AddInstr(END,(OPERANDO) {NUM, 0});
		return ip;
	}
	else Fatal("Erro na compilacao: cheque os seus programas!");
}
