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
#line 1 "src/lang.y" /* yacc.c:339  */

#include <string.h>
#include <stdio.h>
#include "utile.h"
#include "Table_des_registres.h"
#include "Table_des_fonctions.h"
#include "semact_decl.h"
#include "semact_exp.h"
#include "semact_bool.h"
#include "semact_fun.h"
#include "semact_aff.h"
#include "semact_app.h"
  
#define YYDEBUG 1

#define MAX_ARGLIST_LENGTH 1000
  
  void yyerror (char* s) {
    printf ("%s\n",s);
  }

  void yywrap () {

  }

  int yylex();

  static int scope = 0;
  static int has_ret = 0;
  static reg_type ret_type = R_VOID;

#line 98 "src/lang.tab.c" /* yacc.c:339  */

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
   by #include "lang.tab.h".  */
#ifndef YY_YY_SRC_LANG_TAB_H_INCLUDED
# define YY_YY_SRC_LANG_TAB_H_INCLUDED
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
    CONSTANTI = 258,
    CONSTANTF = 259,
    ID = 260,
    IF = 261,
    ELSE = 262,
    INT = 263,
    FLOAT = 264,
    VOID = 265,
    VIR = 266,
    PV = 267,
    AO = 268,
    AF = 269,
    PO = 270,
    PF = 271,
    UNTIL = 272,
    DO = 273,
    WHILE = 274,
    RETURN = 275,
    PLUS = 276,
    MOINS = 277,
    STAR = 278,
    DIV = 279,
    EQ = 280,
    INF = 281,
    EQUAL = 282,
    SUP = 283,
    DIFF = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    UNA = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "src/lang.y" /* yacc.c:355  */

  int n;
  float f;
  registre reg;
  reg_type r_type;
  type_and_ptr t_p;
  int n_ptr;
  char * sid;
  label lab;
  f_decl f_d;
  elem_reg * reg_list;
  struct elem_fun * fun_list;
  elem * list;
  p_list p_l;
  f_head f_h;

#line 189 "src/lang.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_LANG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "src/lang.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   105,   107,   109,   111,   111,   111,   115,
     116,   118,   120,   122,   124,   125,   127,   130,   131,   135,
     136,   137,   140,   141,   144,   145,   148,   149,   151,   154,
     155,   155,   156,   157,   158,   159,   160,   162,   162,   163,
     166,   167,   169,   171,   172,   174,   174,   175,   177,   179,
     180,   183,   184,   187,   190,   192,   195,   196,   197,   198,
     199,   199,   200,   200,   201,   202,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTI", "CONSTANTF", "ID", "IF",
  "ELSE", "INT", "FLOAT", "VOID", "VIR", "PV", "AO", "AF", "PO", "PF",
  "UNTIL", "DO", "WHILE", "RETURN", "PLUS", "MOINS", "STAR", "DIV", "EQ",
  "INF", "EQUAL", "SUP", "DIFF", "AND", "OR", "NOT", "UNA", "$accept",
  "lcc", "return_list_fun", "return_list_reg", "return_list", "block",
  "decl", "var_decl", "fun_decl", "fun", "fun_head", "fun_body", "type",
  "typename", "pointer", "param_list", "vlist", "vir", "inst", "$@1",
  "loop", "$@2", "while", "do", "fun_app", "args", "arglist", "$@3", "aff",
  "ret", "cond", "bool_cond", "if", "else", "bool", "$@4", "$@5", "exp",
  "free_lists", YY_NULLPTR
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
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -48

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,    17,   -64,   -64,   -64,   101,   -64,   -64,    34,   -64,
     -64,   -64,   -64,   -64,   -64,    53,   -64,   -64,     9,    53,
     -64,   101,    11,   -64,    27,    13,   101,   -64,    25,    35,
     -64,   -64,   -64,   -64,    40,    48,    73,    53,   101,    65,
     137,   -64,   119,   -64,   -64,   -64,   -64,    66,    80,   -64,
      75,    13,   -64,   -64,     5,   101,     5,    79,   -64,    53,
      53,    53,    53,    84,    92,   -64,   124,    81,   -64,   -64,
     154,   101,   -64,   -64,    91,   -64,     5,     5,    -1,   128,
     103,     3,   111,    50,    50,   -64,   -64,   113,   -64,   -64,
     -64,   -64,   120,     0,   112,   -64,    12,   106,    46,   121,
     -64,   -64,    53,    53,    53,    53,   118,   -64,   -64,    79,
      73,   -64,   -64,    55,   -64,   -64,   -64,     5,     5,   144,
     144,   144,   144,   123,   -64,   -64,   139,   156,   -64,   141,
       5,   -64,   101,    22,   158,   161,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     4,     1,     5,     8,    73,    74,    72,    54,
      19,    20,    21,    36,    30,     0,    41,    40,     0,     0,
      76,     8,     0,    10,     0,    18,     8,    33,     0,     0,
      75,    34,    35,    32,     0,     0,    44,     0,     8,    72,
       0,    49,     0,    66,     2,     6,     9,    27,     0,    13,
      11,    23,    17,     7,     0,     8,     0,     0,    29,     0,
       0,     0,     0,    45,     0,    43,     0,     0,    71,    50,
       0,     8,    12,    28,     0,    22,     0,     0,     0,     0,
       0,     0,    51,    67,    68,    69,    70,     0,    42,    48,
      31,    14,     0,     0,     0,    26,     0,     0,    64,     0,
      60,    62,     0,     0,     0,     0,     0,    53,    55,     0,
       0,    25,    15,     0,    16,    65,    37,     0,     0,    56,
      58,    57,    59,     0,    52,    46,     0,     0,    61,    63,
       0,    24,     8,     0,     0,     0,    38,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -64,   -20,   -64,   -64,   -64,   -64,
     -64,   -64,   -63,   -64,   125,   -64,   -64,    82,   -55,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,    64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -51,   -64,   -64,   -15,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,     5,    20,    21,    22,    23,    48,
      49,    72,    24,    25,    52,    93,    50,    74,    26,    38,
      27,   127,    28,    29,    30,    64,    65,    87,    31,    32,
      33,    57,    34,   109,    78,   117,   118,    35,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    45,    82,    42,    43,    81,    53,    92,     6,     7,
      39,    73,     6,     7,    39,    99,   112,     3,    67,   107,
      76,    41,    66,    46,    15,    96,    98,    19,   115,   100,
     101,    19,    47,   100,   101,    80,    51,    77,   135,    79,
      54,    79,   100,   101,    83,    84,    85,    86,    55,    36,
     126,    94,   100,   101,   124,    56,     6,     7,    39,    37,
      58,    97,    79,    10,    11,    12,   128,   129,    15,    59,
      60,    61,    62,    61,    62,    19,   100,   101,    63,   133,
      36,    70,     6,     7,     8,     9,    73,   119,   120,   121,
     122,    13,    14,    71,    15,    90,    95,    16,    17,    18,
     -47,    19,    79,    79,     6,     7,     8,     9,    88,    10,
      11,    12,   134,    13,    14,    79,    15,   106,   108,    16,
      17,    18,    68,    19,   110,   111,   114,    59,    60,    61,
      62,    69,   102,   103,   104,   105,    89,   123,   130,   116,
      59,    60,    61,    62,   131,    59,    60,    61,    62,    59,
      60,    61,    62,    68,   102,   103,   104,   105,    59,    60,
      61,    62,    10,    11,    12,    59,    60,    61,    62,   132,
      91,   100,   136,   137,   125,   113,    75
};

static const yytype_uint8 yycheck[] =
{
      15,    21,    57,    18,    19,    56,    26,    70,     3,     4,
       5,    11,     3,     4,     5,    16,    16,     0,    38,    16,
      15,    12,    37,    12,    15,    76,    77,    22,    16,    30,
      31,    22,     5,    30,    31,    55,    23,    32,    16,    54,
      15,    56,    30,    31,    59,    60,    61,    62,    13,    15,
     113,    71,    30,    31,   109,    15,     3,     4,     5,    25,
      12,    76,    77,     8,     9,    10,   117,   118,    15,    21,
      22,    23,    24,    23,    24,    22,    30,    31,     5,   130,
      15,    15,     3,     4,     5,     6,    11,   102,   103,   104,
     105,    12,    13,    13,    15,    14,     5,    18,    19,    20,
      16,    22,   117,   118,     3,     4,     5,     6,    16,     8,
       9,    10,   132,    12,    13,   130,    15,    14,     7,    18,
      19,    20,    16,    22,    11,     5,    14,    21,    22,    23,
      24,    12,    26,    27,    28,    29,    12,    19,    15,    18,
      21,    22,    23,    24,     5,    21,    22,    23,    24,    21,
      22,    23,    24,    16,    26,    27,    28,    29,    21,    22,
      23,    24,     8,     9,    10,    21,    22,    23,    24,    13,
      16,    30,    14,    12,   110,    93,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    36,     0,    37,    38,     3,     4,     5,     6,
       8,     9,    10,    12,    13,    15,    18,    19,    20,    22,
      39,    40,    41,    42,    46,    47,    52,    54,    56,    57,
      58,    62,    63,    64,    66,    71,    15,    25,    53,     5,
      71,    12,    71,    71,    72,    39,    12,     5,    43,    44,
      50,    23,    48,    39,    15,    13,    15,    65,    12,    21,
      22,    23,    24,     5,    59,    60,    71,    39,    16,    12,
      15,    13,    45,    11,    51,    48,    15,    32,    68,    71,
      39,    68,    52,    71,    71,    71,    71,    61,    16,    12,
      14,    16,    46,    49,    39,     5,    68,    71,    68,    16,
      30,    31,    26,    27,    28,    29,    14,    16,     7,    67,
      11,     5,    16,    51,    14,    16,    18,    69,    70,    71,
      71,    71,    71,    19,    52,    60,    46,    55,    68,    68,
      15,     5,    13,    68,    39,    16,    14,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    38,    39,    39,    39,    40,
      40,    41,    42,    43,    44,    44,    45,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      53,    52,    52,    52,    52,    52,    52,    55,    54,    54,
      56,    57,    58,    59,    59,    61,    60,    60,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    68,    68,    68,
      69,    68,    70,    68,    68,    68,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     0,     0,     2,     2,     0,     2,
       1,     2,     3,     1,     3,     4,     3,     2,     1,     1,
       1,     1,     2,     1,     4,     2,     3,     1,     1,     2,
       0,     4,     1,     1,     1,     1,     1,     0,     9,     9,
       1,     1,     4,     1,     0,     0,     4,     1,     4,     2,
       3,     3,     5,     3,     1,     1,     3,     3,     3,     3,
       0,     4,     0,     4,     2,     3,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     0
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
        case 3:
#line 105 "src/lang.y" /* yacc.c:1646  */
    {(yyval.fun_list) = return_list_fun(); }
#line 1385 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 107 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg_list) = return_list_reg(); }
#line 1391 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "src/lang.y" /* yacc.c:1646  */
    {(yyval.list) = return_list(); }
#line 1397 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "src/lang.y" /* yacc.c:1646  */
    {ret_type = R_VOID; }
#line 1403 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "src/lang.y" /* yacc.c:1646  */
    {ret_type = (yyvsp[-1].t_p).type; (yyval.f_h) = (yyvsp[0].f_h); scope += 1; fun_decl((yyvsp[-1].t_p), (yyval.f_h), scope); }
#line 1409 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "src/lang.y" /* yacc.c:1646  */
    {(yyval.f_h).name = (yyvsp[-2].sid); (yyval.f_h).p_l.cpt = 0; }
#line 1415 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "src/lang.y" /* yacc.c:1646  */
    {(yyval.f_h).name = (yyvsp[-3].sid); (yyval.f_h).p_l = (yyvsp[-1].p_l); }
#line 1421 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "src/lang.y" /* yacc.c:1646  */
    {if (! has_ret) printf("ret void\n"); has_ret=0; printf("}\n"); remove_str(scope); remove_reg(scope); scope -= 1; }
#line 1427 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "src/lang.y" /* yacc.c:1646  */
    {(yyval.t_p).type = (yyvsp[-1].r_type); (yyval.t_p).n_ptr = (yyvsp[0].n_ptr);}
#line 1433 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "src/lang.y" /* yacc.c:1646  */
    {(yyval.t_p).type = (yyvsp[0].r_type); (yyval.t_p).n_ptr = 0; }
#line 1439 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 135 "src/lang.y" /* yacc.c:1646  */
    {(yyval.r_type) = R_INT; }
#line 1445 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "src/lang.y" /* yacc.c:1646  */
    {(yyval.r_type) = R_FLOAT; }
#line 1451 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 137 "src/lang.y" /* yacc.c:1646  */
    {(yyval.r_type) = R_VOID; }
#line 1457 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "src/lang.y" /* yacc.c:1646  */
    {(yyval.n_ptr) = (yyvsp[0].n_ptr) + 1; }
#line 1463 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "src/lang.y" /* yacc.c:1646  */
    {(yyval.n_ptr) = 1; }
#line 1469 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "src/lang.y" /* yacc.c:1646  */
    {(yyval.p_l).args[(yyval.p_l).cpt].t_p = (yyvsp[-1].t_p) ; (yyval.p_l).args[(yyval.p_l).cpt].name = (yyvsp[0].sid); (yyval.p_l).cpt = (yyvsp[-3].p_l).cpt + 1; }
#line 1475 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 145 "src/lang.y" /* yacc.c:1646  */
    {(yyval.p_l).args[(yyval.p_l).cpt].t_p = (yyvsp[-1].t_p); (yyval.p_l).args[(yyval.p_l).cpt].name = (yyvsp[0].sid); (yyval.p_l).cpt += 1; }
#line 1481 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "src/lang.y" /* yacc.c:1646  */
    {alloc((yyvsp[0].sid), (yyvsp[-3].t_p).type, (yyvsp[-3].t_p).n_ptr, scope); }
#line 1487 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 149 "src/lang.y" /* yacc.c:1646  */
    {alloc((yyvsp[0].sid), (yyvsp[-1].t_p).type, (yyvsp[-1].t_p).n_ptr, scope); }
#line 1493 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "src/lang.y" /* yacc.c:1646  */
    {scope += 1 ; }
#line 1499 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 155 "src/lang.y" /* yacc.c:1646  */
    {remove_str(scope); remove_reg(scope); scope -= 1; }
#line 1505 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "src/lang.y" /* yacc.c:1646  */
    {printf("L%i:\n", (yyvsp[-2].lab).one);}
#line 1511 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 162 "src/lang.y" /* yacc.c:1646  */
    {printf("br label %%L%i\n", (yyvsp[-8].lab).one); bool_label_false((yyvsp[-6].lab));}
#line 1517 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 163 "src/lang.y" /* yacc.c:1646  */
    {bool_label_true((yyvsp[-2].lab)); printf("br label %%L%i\n", (yyvsp[-8].lab).one); bool_label_false((yyvsp[-2].lab));}
#line 1523 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 166 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = new_label(); printf("L%i:\n", (yyval.lab).one);}
#line 1529 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 167 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = new_label(); printf("L%i:\n", (yyval.lab).one);}
#line 1535 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 169 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = fun_app((yyvsp[-3].sid)); }
#line 1541 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 174 "src/lang.y" /* yacc.c:1646  */
    {fun_app_arg((yyvsp[0].sid)); }
#line 1547 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 175 "src/lang.y" /* yacc.c:1646  */
    {fun_app_arg((yyvsp[0].sid)); }
#line 1553 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 177 "src/lang.y" /* yacc.c:1646  */
    {aff((yyvsp[-1].reg), (yyvsp[-3].sid));}
#line 1559 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 179 "src/lang.y" /* yacc.c:1646  */
    {printf("ret void\n"); has_ret = 1; }
#line 1565 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 180 "src/lang.y" /* yacc.c:1646  */
    {fun_ret((yyvsp[-1].reg), ret_type); has_ret = 1; }
#line 1571 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 183 "src/lang.y" /* yacc.c:1646  */
    {bool_label_false((yyvsp[-1].lab));}
#line 1577 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 184 "src/lang.y" /* yacc.c:1646  */
    {bool_label_true((yyvsp[-4].lab));}
#line 1583 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 187 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab)=(yyvsp[-1].lab); bool_label_true((yyvsp[-1].lab)); }
#line 1589 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 190 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = new_label(); }
#line 1595 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 192 "src/lang.y" /* yacc.c:1646  */
    {printf("br label %%L%i\n", (yyvsp[(-2) - (1)].lab).one); printf("L%i:\n", (yyvsp[(-1) - (1)].lab).two);}
#line 1601 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_inf((yyvsp[-2].reg),(yyvsp[0].reg)); }
#line 1607 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 196 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_sup((yyvsp[-2].reg),(yyvsp[0].reg)); }
#line 1613 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 197 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_eq((yyvsp[-2].reg),(yyvsp[0].reg)); }
#line 1619 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 198 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_diff((yyvsp[-2].reg),(yyvsp[0].reg)); }
#line 1625 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "src/lang.y" /* yacc.c:1646  */
    {bool_label_true((yyvsp[-1].lab));}
#line 1631 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 199 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_and((yyvsp[-3].lab),(yyvsp[0].lab)); }
#line 1637 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 200 "src/lang.y" /* yacc.c:1646  */
    {bool_label_false((yyvsp[-1].lab));}
#line 1643 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 200 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_or((yyvsp[-3].lab),(yyvsp[0].lab)); }
#line 1649 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 201 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = bool_not((yyvsp[0].lab)); }
#line 1655 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 202 "src/lang.y" /* yacc.c:1646  */
    {(yyval.lab) = (yyvsp[-1].lab);}
#line 1661 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 205 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_neg((yyvsp[0].reg)); }
#line 1667 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 206 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_add((yyvsp[-2].reg), (yyvsp[0].reg)); }
#line 1673 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 207 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_sub((yyvsp[-2].reg), (yyvsp[0].reg)); }
#line 1679 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 208 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_mul((yyvsp[-2].reg), (yyvsp[0].reg)); }
#line 1685 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 209 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_div((yyvsp[-2].reg), (yyvsp[0].reg)); }
#line 1691 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 210 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg)=(yyvsp[-1].reg); }
#line 1697 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_id((yyvsp[0].sid), scope); }
#line 1703 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_csti((yyvsp[0].n)); }
#line 1709 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = exp_cstf((yyvsp[0].f)); }
#line 1715 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "src/lang.y" /* yacc.c:1646  */
    {(yyval.reg) = (yyvsp[0].reg); }
#line 1721 "src/lang.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 217 "src/lang.y" /* yacc.c:1646  */
    {delete_list((yyvsp[(-1) - (0)].list)); delete_list_reg((yyvsp[(-2) - (0)].reg_list)); delete_list_fun((yyvsp[(-3) - (0)].fun_list));}
#line 1727 "src/lang.tab.c" /* yacc.c:1646  */
    break;


#line 1731 "src/lang.tab.c" /* yacc.c:1646  */
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
#line 219 "src/lang.y" /* yacc.c:1906  */

int main () {
  return yyparse();
}
