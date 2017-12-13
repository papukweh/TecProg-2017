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
    ADDt = 262,
    SUBt = 263,
    MULt = 264,
    DIVt = 265,
    ASGN = 266,
    OPEN = 267,
    CLOSE = 268,
    RETt = 269,
    EOL = 270,
    ADDs = 271,
    SUBs = 272,
    MULs = 273,
    DIVs = 274,
    EQt = 275,
    NEt = 276,
    LTt = 277,
    LEt = 278,
    GTt = 279,
    GEt = 280,
    INCt = 281,
    DECt = 282,
    ABRE = 283,
    FECHA = 284,
    SEP = 285,
    PONTO = 286,
    NEW = 287,
    TRUEt = 288,
    RESPt = 289,
    IF = 290,
    ELSE = 291,
    WHILE = 292,
    FOR = 293,
    FUNC = 294,
    PRINT = 295,
    VERt = 296,
    MOVt = 297,
    RECt = 298,
    DEPt = 299,
    ATQt = 300,
    JGCt = 301,
    KMKt = 302,
    VERt2 = 303,
    NEGt = 304
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
	char cod[30];

#line 197 "compila.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "compila.tab.c" /* yacc.c:358  */

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    66,    70,    71,    72,    73,    74,    75,
      76,    80,    84,    92,    93,    94,    95,    96,    97,    98,
     111,   112,   116,   121,   126,   127,   128,   134,   135,   136,
     137,   138,   139,   140,   141,   149,   157,   164,   171,   178,
     191,   192,   197,   202,   203,   209,   210,   211,   212,   213,
     214,   215,   216,   224,   232,   239,   246,   253,   263,   264,
     263,   272,   272,   283,   284,   283,   293,   294,   298,   293,
     317,   318,   319,   320,   321,   322,   323,   324,   327,   333,
     339,   345,   350,   356,   362,   365,   371,   377,   380,   383,
     384,   388,   398,   388,   408,   409,   410,   414,   415,   414,
     430,   431,   432,   432
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATRt", "NUMt", "ID", "DIRECAOt", "ADDt",
  "SUBt", "MULt", "DIVt", "ASGN", "OPEN", "CLOSE", "RETt", "EOL", "ADDs",
  "SUBs", "MULs", "DIVs", "EQt", "NEt", "LTt", "LEt", "GTt", "GEt", "INCt",
  "DECt", "ABRE", "FECHA", "SEP", "PONTO", "NEW", "TRUEt", "RESPt", "IF",
  "ELSE", "WHILE", "FOR", "FUNC", "PRINT", "VERt", "MOVt", "RECt", "DEPt",
  "ATQt", "JGCt", "KMKt", "VERt2", "NEGt", "$accept", "Programa",
  "Comando", "Return", "ExprC", "Expr", "ExprM", "Cond", "$@1", "$@2",
  "$@3", "Loop", "$@4", "$@5", "$@6", "$@7", "$@8", "Sis", "Mov", "Rec",
  "Dep", "Atq", "Jgc", "Ver", "Checa_dir", "Kmk", "Direcao", "Resposta",
  "Bloco", "Comandos", "Func", "$@9", "$@10", "Args", "Chamada", "$@11",
  "$@12", "ListParms", "$@13", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     173,  -137,    89,    48,    48,    10,     1,    -2,    14,    16,
      18,    26,    48,    31,    33,    34,    39,    45,    49,    50,
      52,   109,  -137,  -137,    64,    29,  -137,    22,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,    48,
    -137,    48,    48,    48,    48,  -137,  -137,    73,     3,  -137,
     129,  -137,   216,    55,    65,  -137,  -137,    48,  -137,   278,
      68,    71,    71,    71,    71,    71,    74,    71,  -137,  -137,
      48,    48,    48,    48,  -137,  -137,  -137,   166,    48,   166,
     166,   166,   166,  -137,  -137,  -137,    48,  -137,    15,    15,
     287,    72,  -137,  -137,  -137,    75,    78,    79,    82,    86,
    -137,    90,     3,     3,  -137,  -137,    66,    25,  -137,   166,
    -137,  -137,   248,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,   173,  -137,    80,    98,    99,    48,    48,    48,
      48,    48,    48,   105,    15,    93,  -137,   154,    48,  -137,
      66,   166,   166,   166,   166,   166,   166,    66,    87,  -137,
      -6,  -137,  -137,  -137,  -137,  -137,  -137,    66,   117,    85,
    -137,  -137,  -137,   153,    48,    85,   257,  -137,  -137,    85,
      85,    85,    85,    85,  -137,  -137,   131,     3,   291,    85,
      85,    85,    85,   119,   257,   257,   257,   257,   257,  -137,
    -137,     7,     7,  -137,  -137,    66,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     9,     0,     5,     6,     0,    70,    71,
      72,    73,    74,    76,    25,    75,    24,     7,    27,     0,
      97,     0,     0,     0,     0,    34,    35,     0,    32,    24,
       0,    11,     0,     0,     0,    58,    63,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     3,
       0,     0,     0,     0,     4,    61,    10,    23,   100,    36,
      37,    38,    39,    26,    33,    12,     0,    87,     0,     0,
       0,     0,     8,    83,    86,     0,     0,     0,     0,     0,
      85,     0,    28,    29,    30,    31,     0,   101,    98,    21,
      19,    59,     0,    64,    66,    92,    78,    79,    80,    81,
      82,    84,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    89,     0,   100,    99,
       0,    17,    18,    13,    15,    14,    16,     0,     0,    95,
       0,    88,    90,   103,    60,    65,    67,     0,     0,     0,
      93,    96,    40,    41,     0,     0,    68,    43,    45,     0,
       0,     0,     0,     0,    52,    53,     0,    50,     0,     0,
       0,     0,     0,     0,    42,    54,    55,    56,    57,    44,
      51,    46,    47,    48,    49,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   -18,  -137,   -84,    -3,   110,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,    63,  -137,   243,     8,  -136,  -137,
    -137,  -137,  -137,  -137,    81,  -137,  -137,     2,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,   111,    24,   166,    25,    88,   126,
     106,    26,    89,   133,   134,   159,   183,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    95,    49,   123,   137,
      37,    91,   135,   150,    38,    78,   125,   108,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    50,    52,    69,   154,   113,    53,   157,    36,    59,
      54,   155,    72,    73,     1,     2,   181,   182,     3,     1,
       2,   160,     4,     3,   158,    51,    55,     4,    56,    36,
      57,    58,    70,    71,    72,    73,    77,    76,    79,    80,
      81,    82,     6,    60,     7,    61,    62,     6,   110,     7,
     148,    63,     1,     2,    90,  -102,     3,    64,    20,   196,
       4,    65,    66,    20,    67,    75,    86,   102,   103,   104,
     105,    70,    71,    72,    73,   107,    83,    94,    87,    74,
       6,    93,     7,   109,   115,   112,   112,   100,   116,   162,
     163,   117,   118,   164,   122,   119,    20,   165,   149,   120,
      39,    40,   156,   121,   136,    41,    42,    43,    44,    68,
     138,   139,   140,     1,     2,    45,    46,     3,   147,   152,
      47,     4,   161,     5,   141,   142,   143,   144,   145,   146,
      36,   112,   195,    20,   189,   107,    70,    71,    72,    73,
     153,     6,    84,     7,     8,    36,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     1,     2,
       0,   177,     3,     0,   169,    40,     4,     0,     5,   170,
     171,   172,   173,    70,    71,    72,    73,     1,     2,   174,
     175,     3,     0,   151,   176,     4,     6,     5,     7,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     6,     0,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   167,    70,    71,    72,    73,     0,   167,     0,
       0,    85,   167,   167,   167,   167,   167,     0,     0,     0,
     168,     0,   167,   167,   167,   167,   168,     0,     0,     0,
     168,   168,   168,   168,   168,    70,    71,    72,    73,     0,
     168,   168,   168,   168,   179,   180,   181,   182,   127,   128,
     129,   130,   131,   132,     0,   178,     0,     0,     0,   184,
     185,   186,   187,   188,     0,    70,    71,    72,    73,   191,
     192,   193,   194,    92,    70,    71,    72,    73,   179,   180,
     181,   182,   114,     0,   190,    96,    97,    98,    99,     0,
     101
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,    21,   140,    89,     5,    13,     0,    12,
      12,   147,     9,    10,     4,     5,     9,    10,     8,     4,
       5,   157,    12,     8,    30,    15,    12,    12,    12,    21,
      12,     5,     7,     8,     9,    10,    39,    15,    41,    42,
      43,    44,    32,    12,    34,    12,    12,    32,    33,    34,
     134,    12,     4,     5,    57,    30,     8,    12,    48,   195,
      12,    12,    12,    48,    12,    36,    11,    70,    71,    72,
      73,     7,     8,     9,    10,    78,     3,     6,    13,    15,
      32,    13,    34,    86,    12,    88,    89,    13,    13,     4,
       5,    13,    13,     8,    28,    13,    48,    12,     5,    13,
      11,    12,    15,    13,   122,    16,    17,    18,    19,     0,
      30,    13,    13,     4,     5,    26,    27,     8,    13,   137,
      31,    12,     5,    14,   127,   128,   129,   130,   131,   132,
     122,   134,    13,    48,     3,   138,     7,     8,     9,    10,
     138,    32,    13,    34,    35,   137,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     4,     5,
      -1,   164,     8,    -1,    11,    12,    12,    -1,    14,    16,
      17,    18,    19,     7,     8,     9,    10,     4,     5,    26,
      27,     8,    -1,    29,    31,    12,    32,    14,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    32,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   159,     7,     8,     9,    10,    -1,   165,    -1,
      -1,    15,   169,   170,   171,   172,   173,    -1,    -1,    -1,
     159,    -1,   179,   180,   181,   182,   165,    -1,    -1,    -1,
     169,   170,   171,   172,   173,     7,     8,     9,    10,    -1,
     179,   180,   181,   182,     7,     8,     9,    10,    20,    21,
      22,    23,    24,    25,    -1,   165,    -1,    -1,    -1,   169,
     170,   171,   172,   173,    -1,     7,     8,     9,    10,   179,
     180,   181,   182,    15,     7,     8,     9,    10,     7,     8,
       9,    10,    15,    -1,    13,    62,    63,    64,    65,    -1,
      67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     8,    12,    14,    32,    34,    35,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    51,    52,    53,    55,    57,    61,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    77,    80,    84,    11,
      12,    16,    17,    18,    19,    26,    27,    31,    55,    77,
      55,    15,    55,     5,    12,    12,    12,    12,     5,    55,
      12,    12,    12,    12,    12,    12,    12,    12,     0,    52,
       7,     8,     9,    10,    15,    36,    15,    55,    85,    55,
      55,    55,    55,     3,    13,    15,    11,    13,    58,    62,
      55,    81,    15,    13,     6,    76,    76,    76,    76,    76,
      13,    76,    55,    55,    55,    55,    60,    55,    87,    55,
      33,    54,    55,    54,    15,    12,    13,    13,    13,    13,
      13,    13,    28,    78,    88,    86,    59,    20,    21,    22,
      23,    24,    25,    63,    64,    82,    52,    79,    30,    13,
      13,    55,    55,    55,    55,    55,    55,    13,    54,     5,
      83,    29,    52,    87,    78,    78,    15,    13,    30,    65,
      78,     5,     4,     5,     8,    12,    56,    74,    84,    11,
      16,    17,    18,    19,    26,    27,    31,    55,    56,     7,
       8,     9,    10,    66,    56,    56,    56,    56,    56,     3,
      13,    56,    56,    56,    56,    13,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    58,    59,
      57,    60,    57,    62,    63,    61,    64,    65,    66,    61,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    81,    82,    80,    83,    83,    83,    85,    86,    84,
      87,    87,    88,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     3,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     4,     1,     3,     1,     1,     3,     1,     3,     3,
       3,     3,     2,     3,     2,     2,     3,     3,     3,     3,
       1,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       2,     3,     2,     2,     3,     3,     3,     3,     0,     0,
       7,     0,     4,     0,     0,     7,     0,     0,     0,    12,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     3,     4,     3,     1,     3,     3,     1,
       2,     0,     0,     8,     0,     1,     3,     0,     0,     6,
       0,     1,     0,     4
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
#line 74 "compila.y" /* yacc.c:1646  */
    { AddInstr(PRN, (OPERANDO) {NUM, 0}); }
#line 1452 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "compila.y" /* yacc.c:1646  */
    {
		 	AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			AddInstr(RET, (OPERANDO) {NUM, 0});
 			}
#line 1461 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "compila.y" /* yacc.c:1646  */
    {
		 	   AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			   AddInstr(RET, (OPERANDO) {NUM, 0});
 			}
#line 1470 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 92 "compila.y" /* yacc.c:1646  */
    { AddInstr(LT,   (OPERANDO) {NUM, 0});}
#line 1476 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "compila.y" /* yacc.c:1646  */
    { AddInstr(GT,   (OPERANDO) {NUM, 0});}
#line 1482 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "compila.y" /* yacc.c:1646  */
    { AddInstr(LE,   (OPERANDO) {NUM, 0});}
#line 1488 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "compila.y" /* yacc.c:1646  */
    { AddInstr(GE,   (OPERANDO) {NUM, 0});}
#line 1494 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "compila.y" /* yacc.c:1646  */
    { AddInstr(EQ,   (OPERANDO) {NUM, 0});}
#line 1500 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "compila.y" /* yacc.c:1646  */
    { AddInstr(NE,   (OPERANDO) {NUM, 0});}
#line 1506 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "compila.y" /* yacc.c:1646  */
    { AddInstr(PUSH, (OPERANDO) {NUM, 1});}
#line 1512 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 111 "compila.y" /* yacc.c:1646  */
    {  AddInstr(PUSH, (OPERANDO) {NUM, (yyvsp[0].val)});}
#line 1518 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 112 "compila.y" /* yacc.c:1646  */
    {
						symrec *s = putsym((yyvsp[-2].cod)); 
						AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
						}
#line 1527 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[0].cod));
			if (s==0) s = putsym((yyvsp[0].cod)); 
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
#line 1537 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-2].cod));
			if (s==0) s = putsym((yyvsp[-2].cod)); 
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1547 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(ATR, (OPERANDO) {NUM, (yyvsp[0].num)}); 
  	 		}
#line 1558 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "compila.y" /* yacc.c:1646  */
    { AddInstr(ADD,  (OPERANDO) {NUM, 0});}
#line 1564 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 136 "compila.y" /* yacc.c:1646  */
    { AddInstr(SUB,  (OPERANDO) {NUM, 0});}
#line 1570 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 137 "compila.y" /* yacc.c:1646  */
    { AddInstr(MUL,  (OPERANDO) {NUM, 0});}
#line 1576 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 138 "compila.y" /* yacc.c:1646  */
    { AddInstr(DIV,  (OPERANDO) {NUM, 0});}
#line 1582 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "compila.y" /* yacc.c:1646  */
    { AddInstr(NEG,  (OPERANDO) {NUM, 0}); }
#line 1588 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr(PUSH, (OPERANDO) {NUM, 1});
			AddInstr(ADD, (OPERANDO) {NUM, 0});
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1601 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 149 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr(PUSH, (OPERANDO) {NUM, 1});
			AddInstr(SUB, (OPERANDO) {NUM, 0});
			AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1614 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 157 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(ADD, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1626 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  	 	AddInstr(SUB, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1638 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 171 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(MUL, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1650 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 178 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr(DIV, (OPERANDO) {NUM, 0});
	  		AddInstr(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1662 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 191 "compila.y" /* yacc.c:1646  */
    {  AddInstr2(PUSH, (OPERANDO) {NUM, (yyvsp[0].val)});}
#line 1668 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[0].cod));
			if (s==0) s = putsym((yyvsp[0].cod)); 
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
	       }
#line 1678 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-2].cod));
			if (s==0) s = putsym((yyvsp[-2].cod)); 
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1688 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  	 	AddInstr2(ATR, (OPERANDO) {NUM, (yyvsp[0].num)}); 
  	 		}
#line 1699 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "compila.y" /* yacc.c:1646  */
    { AddInstr2(ADD,  (OPERANDO) {NUM, 0});}
#line 1705 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 211 "compila.y" /* yacc.c:1646  */
    { AddInstr2(SUB,  (OPERANDO) {NUM, 0});}
#line 1711 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 212 "compila.y" /* yacc.c:1646  */
    { AddInstr2(MUL,  (OPERANDO) {NUM, 0});}
#line 1717 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 213 "compila.y" /* yacc.c:1646  */
    { AddInstr2(DIV,  (OPERANDO) {NUM, 0});}
#line 1723 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "compila.y" /* yacc.c:1646  */
    { AddInstr(NEG,  (OPERANDO) {NUM, 0}); }
#line 1729 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			AddInstr2(ADD, (OPERANDO) {NUM, 0});
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1742 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 224 "compila.y" /* yacc.c:1646  */
    {
	        symrec *s = getsym((yyvsp[-1].cod));
			if (s==0) s = putsym((yyvsp[-1].cod)); /* não definida */
			AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val});
			AddInstr2(PUSH, (OPERANDO) {NUM, 1});
			AddInstr2(SUB, (OPERANDO) {NUM, 0});
			AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
 		 	}
#line 1755 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 232 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(ADD, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1767 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 239 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(SUB, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1779 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 246 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(MUL, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1791 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 253 "compila.y" /* yacc.c:1646  */
    { 
	        symrec *s = getsym((yyvsp[-2].cod)); 
	  		if (s==0) s = putsym((yyvsp[-2].cod));  
	  		AddInstr2(RCL, (OPERANDO) {NUM, mem + s->val}); 
	  		AddInstr2(DIV, (OPERANDO) {NUM, 0});
	  		AddInstr2(STO, (OPERANDO) {NUM, mem + s->val});
  	 		}
#line 1803 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 263 "compila.y" /* yacc.c:1646  */
    {
				AddInstr(PUSH, (OPERANDO) {NUM, 0});}
#line 1810 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 264 "compila.y" /* yacc.c:1646  */
    {
  	  	 	   	salva_end(ip);
			   	AddInstr(JIF,  (OPERANDO) {NUM, 0});
 		 		}
#line 1819 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 268 "compila.y" /* yacc.c:1646  */
    {
		 		AddInstr(PUSH, (OPERANDO) {NUM, 1});
		   		prog[pega_end()].op.valor.n = ip;
		 		}
#line 1828 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 272 "compila.y" /* yacc.c:1646  */
    {
				salva_end(ip); 
				AddInstr(JIT, (OPERANDO) {NUM, 0}); 
				}
#line 1837 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "compila.y" /* yacc.c:1646  */
    { prog[pega_end()].op.valor.n = ip; }
#line 1843 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 283 "compila.y" /* yacc.c:1646  */
    { salva_end(ip); }
#line 1849 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 284 "compila.y" /* yacc.c:1646  */
    {
	  		salva_end(ip); 
	  		AddInstr(JIF, (OPERANDO) {NUM, 0});
	  		}
#line 1858 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 288 "compila.y" /* yacc.c:1646  */
    {
			int tmp = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[tmp].op.valor.n = ip;
			}
#line 1868 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 293 "compila.y" /* yacc.c:1646  */
    { salva_end(ip); }
#line 1874 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 294 "compila.y" /* yacc.c:1646  */
    { 	
			salva_end(ip); 
			AddInstr(JIF, (OPERANDO) {NUM, 0});
			}
#line 1883 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 298 "compila.y" /* yacc.c:1646  */
    { 	
		 	salva_end(ip2); 
		 	while(ip2 > 0)
		 		push(prog2[--ip2]);
		 	}
#line 1893 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 303 "compila.y" /* yacc.c:1646  */
    { 
		 	int a = pega_end();
		 	for (int i = 0; i < a; i++) 
		 		prog[ip++] = pop();
			int tmp = pega_end();
			AddInstr(JMP, (OPERANDO) {NUM, pega_end()});
			prog[tmp].op.valor.n = ip;
			}
#line 1906 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 327 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, MOV});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1915 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 333 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, REC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1924 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 339 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, DEP});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1933 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 345 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, ATQ});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1942 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 350 "compila.y" /* yacc.c:1646  */
    { 
								   AddInstr(PUSH, (OPERANDO) {ACAO, JGC});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
								}
#line 1951 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 356 "compila.y" /* yacc.c:1646  */
    {
								   AddInstr(PUSH, (OPERANDO) {ACAO, VER});
								   AddInstr(SYS, (OPERANDO) {NUM, 0});
									}
#line 1960 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 362 "compila.y" /* yacc.c:1646  */
    { AddInstr(RCM, (OPERANDO) {NUM, 0});}
#line 1966 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 365 "compila.y" /* yacc.c:1646  */
    { 
						AddInstr(PUSH, (OPERANDO) {ACAO, KMK});
						AddInstr(SYS, (OPERANDO) {NUM, 0});
						}
#line 1975 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 371 "compila.y" /* yacc.c:1646  */
    { AddInstr(PUSH, (OPERANDO) {VAR, (yyvsp[0].direc)}); }
#line 1981 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 377 "compila.y" /* yacc.c:1646  */
    {AddInstr(RCL, (OPERANDO) {NUM, 8}); }
#line 1987 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 388 "compila.y" /* yacc.c:1646  */
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
#line 2003 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 398 "compila.y" /* yacc.c:1646  */
    { newtab(lastval()); }
#line 2009 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 399 "compila.y" /* yacc.c:1646  */
    {
			AddInstr(LEAVE, (OPERANDO) {NUM, 0});
			AddInstr(RET, (OPERANDO) {NUM, 0});
			prog[pega_end()].op.valor.n = ip;
			deltab();
	  	}
#line 2020 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 409 "compila.y" /* yacc.c:1646  */
    { putsym((yyvsp[0].cod)); }
#line 2026 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 410 "compila.y" /* yacc.c:1646  */
    { putsym((yyvsp[0].cod)); }
#line 2032 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 414 "compila.y" /* yacc.c:1646  */
    { parmcnt = mem; }
#line 2038 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 415 "compila.y" /* yacc.c:1646  */
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
#line 2055 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 431 "compila.y" /* yacc.c:1646  */
    { parmcnt++;}
#line 2061 "compila.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 432 "compila.y" /* yacc.c:1646  */
    { parmcnt++;}
#line 2067 "compila.tab.c" /* yacc.c:1646  */
    break;


#line 2071 "compila.tab.c" /* yacc.c:1646  */
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
#line 435 "compila.y" /* yacc.c:1906  */

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
