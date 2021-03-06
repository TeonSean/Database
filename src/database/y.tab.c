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
#line 1 "parser.y" /* yacc.c:339  */

#include "Include.h"
#include "Database.h"

Database* instance = Database::getInstance();

extern "C"
{
    void yyerror(const char *s);
    extern int yylex(void);
    extern int yywrap(void);
}


#line 81 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    DATABASE = 258,
    DATABASES = 259,
    TABLE = 260,
    TABLES = 261,
    SHOW = 262,
    CREATE = 263,
    DROP = 264,
    USE = 265,
    PRIMARY = 266,
    KEY = 267,
    NOT = 268,
    NULL_ = 269,
    UNIQUE = 270,
    INSERT = 271,
    INTO = 272,
    VALUES = 273,
    DELETE = 274,
    FROM = 275,
    WHERE = 276,
    DENSITY = 277,
    UPDATE = 278,
    SET = 279,
    SELECT = 280,
    IS = 281,
    INT_ = 282,
    VARCHAR_ = 283,
    DESC = 284,
    INDEX = 285,
    AND = 286,
    DATE_ = 287,
    FLOAT_ = 288,
    FOREIGN = 289,
    REFERENCES = 290,
    IDENTIFIER = 291,
    VALUE_STRING = 292,
    VALUE_INT = 293,
    VALUE_FLOAT = 294,
    NOT_EQUAL = 295,
    GREATER_EQUAL = 296,
    LESS_EQUAL = 297
  };
#endif
/* Tokens.  */
#define DATABASE 258
#define DATABASES 259
#define TABLE 260
#define TABLES 261
#define SHOW 262
#define CREATE 263
#define DROP 264
#define USE 265
#define PRIMARY 266
#define KEY 267
#define NOT 268
#define NULL_ 269
#define UNIQUE 270
#define INSERT 271
#define INTO 272
#define VALUES 273
#define DELETE 274
#define FROM 275
#define WHERE 276
#define DENSITY 277
#define UPDATE 278
#define SET 279
#define SELECT 280
#define IS 281
#define INT_ 282
#define VARCHAR_ 283
#define DESC 284
#define INDEX 285
#define AND 286
#define DATE_ 287
#define FLOAT_ 288
#define FOREIGN 289
#define REFERENCES 290
#define IDENTIFIER 291
#define VALUE_STRING 292
#define VALUE_INT 293
#define VALUE_FLOAT 294
#define NOT_EQUAL 295
#define GREATER_EQUAL 296
#define LESS_EQUAL 297

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      44,    45,    51,    52,    46,    53,    47,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      48,    50,    49,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    48,    49,    52,    55,
      56,    57,    58,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    73,    74,    77,    78,    81,    82,    83,
      84,    87,    88,    89,    90,    91,    94,    95,    98,    99,
     102,   103,   104,   105,   108,   109,   110,   111,   112,   115,
     116,   119,   120,   121,   122,   123,   124,   127,   128,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   145,   146,   149,   150,   153,   154,   157,   158,   161,
     164,   167
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATABASE", "DATABASES", "TABLE",
  "TABLES", "SHOW", "CREATE", "DROP", "USE", "PRIMARY", "KEY", "NOT",
  "NULL_", "UNIQUE", "INSERT", "INTO", "VALUES", "DELETE", "FROM", "WHERE",
  "DENSITY", "UPDATE", "SET", "SELECT", "IS", "INT_", "VARCHAR_", "DESC",
  "INDEX", "AND", "DATE_", "FLOAT_", "FOREIGN", "REFERENCES", "IDENTIFIER",
  "VALUE_STRING", "VALUE_INT", "VALUE_FLOAT", "NOT_EQUAL", "GREATER_EQUAL",
  "LESS_EQUAL", "';'", "'('", "')'", "','", "'.'", "'<'", "'>'", "'='",
  "'*'", "'+'", "'-'", "'/'", "$accept", "program", "stmt", "sysStmt",
  "Stmt", "tbStmt", "idxStmt", "fieldList", "field", "type", "valueLists",
  "valueList", "value", "whereClause", "col", "op", "setClause",
  "setRValue", "selector", "colList", "tableList", "columnList", "Name",
  "tbName", "colName", YY_NULLPTR
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
     295,   296,   297,    59,    40,    41,    44,    46,    60,    62,
      61,    42,    43,    45,    47
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -81

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -79,    33,   -79,    22,     9,    24,   -18,    13,    27,    15,
      42,    15,   -79,    12,    16,    18,    51,   -79,   -79,   -18,
      15,    55,    15,   -18,    15,    15,   -79,   -79,    15,    15,
     -79,    72,    53,   -79,   -79,    86,    62,    83,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,    84,    15,    87,   -79,   -79,
      88,   115,   113,    99,    15,   100,    99,    65,    93,    99,
      99,    94,   100,   -79,   -12,    89,   -11,   -79,   -79,   -79,
     128,   129,    38,   -79,    70,    99,    97,    98,    30,   101,
     114,    69,   100,    99,    36,   100,    15,   102,   104,   -79,
      65,   105,   106,   -79,   -79,   131,   108,   130,   -79,   -79,
     -79,   -79,   -79,    59,   -79,   110,   100,   107,   -79,   -79,
     -79,   -79,   -79,   -79,    43,   114,   109,    71,   -79,    61,
     114,   -79,    99,    99,   -79,   117,   118,   137,   135,   116,
     -79,    30,    30,   -79,   144,   -79,   -79,   -79,    36,    99,
      99,    36,    36,    36,    36,    77,   -79,   119,   120,   121,
     -79,   124,   123,   -79,    81,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,    99,   127,
     -79,   -79,   125,   126,   -79,   -79,    15,   132,   -79,   134,
     -79,    99,   136,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     8,    12,     0,
       0,     0,     0,     0,     0,     0,    79,    11,     0,     0,
      80,     0,    81,    71,    74,     0,    72,     0,    50,    15,
       4,     5,     6,     7,     9,     0,     0,     0,    10,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,    75,    73,    49,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,    32,     0,    34,    35,    27,     0,    20,    24,    43,
      41,    40,    42,     0,    38,     0,     0,     0,    52,    54,
      53,    55,    56,    51,     0,    18,     0,    59,    57,    60,
      19,    76,     0,     0,    26,     0,     0,     0,    21,     0,
      36,     0,     0,    48,     0,    46,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
      28,     0,     0,    39,     0,    47,    58,    70,    69,    67,
      63,    65,    61,    66,    62,    68,    64,    29,     0,     0,
      31,    33,     0,     0,    37,    78,     0,     0,    22,     0,
      23,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,    79,   -79,
     -79,    40,   -78,   -60,    -7,   -79,   -79,    32,   -79,   -79,
     -79,   -79,    -2,    -9,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    72,    73,    95,
      79,   103,   104,    80,    81,   114,    64,   118,    35,    36,
      66,   145,    27,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    65,    39,    34,    69,    74,   117,    76,    77,    82,
      85,    45,    19,    47,    20,    49,    50,    44,    26,    51,
      52,    48,   115,    96,    21,   120,    17,    23,    18,    24,
      28,   116,   119,     2,    83,    86,   136,    58,    74,    22,
       3,     4,     5,     6,    99,    67,   133,    29,    68,     7,
      99,    30,     8,   153,    25,    40,     9,    99,    10,    41,
     117,    42,    11,   159,   161,   163,   165,   100,   101,   102,
     146,   147,    63,   100,   101,   102,    70,   121,    32,    32,
     100,   101,   102,    89,    90,    46,   119,   157,   158,   160,
     162,   164,   166,    33,    43,   107,    53,    91,    92,    71,
     -80,    63,    93,    94,   130,   131,    54,   137,    55,   108,
     109,   110,   141,   142,   143,   144,   175,   111,   112,   113,
     134,   135,   167,   168,   139,   140,   174,   131,    57,   182,
      56,    59,    60,    61,    62,    63,    32,    75,    78,    84,
      87,    88,    97,    98,   127,   106,   122,   105,   123,   125,
     126,   150,   129,   128,   132,   148,   149,   151,   155,   138,
     152,   173,   176,   177,   169,   170,   171,   179,   172,   124,
     156,   178,   154,     0,     0,     0,     0,   180,   181,     0,
       0,   183
};

static const yytype_int16 yycheck[] =
{
       9,    53,    11,    10,    56,    57,    84,    59,    60,    21,
      21,    20,     3,    22,     5,    24,    25,    19,    36,    28,
      29,    23,    82,    75,    15,    85,     4,     3,     6,     5,
      17,    83,    84,     0,    46,    46,   114,    46,    90,    30,
       7,     8,     9,    10,    14,    54,   106,    20,    55,    16,
      14,    36,    19,   131,    30,    43,    23,    14,    25,    43,
     138,    43,    29,   141,   142,   143,   144,    37,    38,    39,
     122,   123,    36,    37,    38,    39,    11,    86,    36,    36,
      37,    38,    39,    45,    46,    30,   138,   139,   140,   141,
     142,   143,   144,    51,    43,    26,    24,    27,    28,    34,
      47,    36,    32,    33,    45,    46,    20,   114,    46,    40,
      41,    42,    51,    52,    53,    54,   168,    48,    49,    50,
      13,    14,    45,    46,    53,    54,    45,    46,    44,   181,
      47,    44,    44,    18,    21,    36,    36,    44,    44,    50,
      12,    12,    45,    45,    13,    31,    44,    46,    44,    44,
      44,    14,    22,    45,    44,    38,    38,    22,    14,    50,
      44,    38,    35,    38,    45,    45,    45,   176,    44,    90,
     138,    45,   132,    -1,    -1,    -1,    -1,    45,    44,    -1,
      -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,     0,     7,     8,     9,    10,    16,    19,    23,
      25,    29,    57,    58,    59,    60,    61,     4,     6,     3,
       5,    15,    30,     3,     5,    30,    36,    77,    17,    20,
      36,    78,    36,    51,    69,    73,    74,    78,    79,    78,
      43,    43,    43,    43,    77,    78,    30,    78,    77,    78,
      78,    78,    78,    24,    20,    46,    47,    44,    78,    44,
      44,    18,    21,    36,    71,    79,    75,    78,    69,    79,
      11,    34,    62,    63,    79,    44,    79,    79,    44,    65,
      68,    69,    21,    46,    50,    21,    46,    12,    12,    45,
      46,    27,    28,    32,    33,    64,    79,    45,    45,    14,
      37,    38,    39,    66,    67,    46,    31,    26,    40,    41,
      42,    48,    49,    50,    70,    68,    79,    67,    72,    79,
      68,    78,    44,    44,    63,    44,    44,    13,    45,    22,
      45,    46,    44,    68,    13,    14,    67,    69,    50,    53,
      54,    51,    52,    53,    54,    76,    79,    79,    38,    38,
      14,    22,    44,    67,    66,    14,    72,    79,    79,    67,
      79,    67,    79,    67,    79,    67,    79,    45,    46,    45,
      45,    45,    44,    38,    45,    79,    35,    38,    45,    78,
      45,    44,    79,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     2,     2,     3,
       3,     2,     2,     6,     3,     2,     5,     5,     6,     6,
       6,     7,    10,    11,     6,     1,     3,     2,     4,     5,
      10,     4,     1,     4,     1,     1,     3,     5,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     1,     1,     3,     1,     3,     1,
       1,     1
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
        case 2:
#line 42 "parser.y" /* yacc.c:1646  */
    {}
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "parser.y" /* yacc.c:1646  */
    {}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "parser.y" /* yacc.c:1646  */
    {}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 47 "parser.y" /* yacc.c:1646  */
    {}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "parser.y" /* yacc.c:1646  */
    {}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "parser.y" /* yacc.c:1646  */
    {}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "parser.y" /* yacc.c:1646  */
    { instance->showDatabases(); }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 55 "parser.y" /* yacc.c:1646  */
    { instance->createDatabase((yyvsp[0].m_string)); }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 56 "parser.y" /* yacc.c:1646  */
    { instance->dropDatabase((yyvsp[0].m_string)); }
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "parser.y" /* yacc.c:1646  */
    { instance->useDatabase((yyvsp[0].m_string)); }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "parser.y" /* yacc.c:1646  */
    { instance->showTables(); }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 61 "parser.y" /* yacc.c:1646  */
    { instance->createTable((yyvsp[-3].m_string)); }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "parser.y" /* yacc.c:1646  */
    { instance->dropTable((yyvsp[0].m_string)); }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "parser.y" /* yacc.c:1646  */
    { instance->describeTable((yyvsp[0].m_string)); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 64 "parser.y" /* yacc.c:1646  */
    { instance->insert((yyvsp[-2].m_string)); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 65 "parser.y" /* yacc.c:1646  */
    { instance->remove((yyvsp[-2].m_string)); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 66 "parser.y" /* yacc.c:1646  */
    { instance->update((yyvsp[-4].m_string)); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 67 "parser.y" /* yacc.c:1646  */
    { instance->select((yyvsp[-4].m_bool)); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 70 "parser.y" /* yacc.c:1646  */
    { instance->createIndex((yyvsp[-3].m_string), (yyvsp[-1].m_string), false, 1); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "parser.y" /* yacc.c:1646  */
    { instance->createIndex((yyvsp[-3].m_string), (yyvsp[-1].m_string), true, 1); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 72 "parser.y" /* yacc.c:1646  */
    { instance->createIndex((yyvsp[-7].m_string), (yyvsp[-5].m_string), false, (yyvsp[-1].m_int)); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 73 "parser.y" /* yacc.c:1646  */
    { instance->createIndex((yyvsp[-7].m_string), (yyvsp[-5].m_string), true, (yyvsp[-1].m_int)); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 74 "parser.y" /* yacc.c:1646  */
    { instance->dropIndex((yyvsp[-3].m_string), (yyvsp[-1].m_string)); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 77 "parser.y" /* yacc.c:1646  */
    {}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 78 "parser.y" /* yacc.c:1646  */
    {}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 81 "parser.y" /* yacc.c:1646  */
    { instance->addPendingField((yyvsp[-1].m_string), (yyvsp[0].m_type).type, true, (yyvsp[0].m_type).extra); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 82 "parser.y" /* yacc.c:1646  */
    { instance->addPendingField((yyvsp[-3].m_string), (yyvsp[-2].m_type).type, false, (yyvsp[-2].m_type).extra); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 83 "parser.y" /* yacc.c:1646  */
    {}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 84 "parser.y" /* yacc.c:1646  */
    { Foreign f; f.field = (yyvsp[-6].m_string); f.table = (yyvsp[-3].m_string); f.column = (yyvsp[-1].m_string); instance->addPendingForeign(f); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyval.m_type).type = Type::INT; (yyval.m_type).extra = (yyvsp[-1].m_int); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval.m_type).type = Type::INT; (yyval.m_type).extra = 0; }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.m_type).type = Type::VARCHAR; (yyval.m_type).extra = (yyvsp[-1].m_int); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.m_type).type = Type::DATE; (yyval.m_type).extra = 0; }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.m_type).type = Type::FLOAT; (yyval.m_type).extra = 0; }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 94 "parser.y" /* yacc.c:1646  */
    { instance->addPendingValueList(); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 95 "parser.y" /* yacc.c:1646  */
    { instance->addPendingValueList(); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 98 "parser.y" /* yacc.c:1646  */
    { instance->addPendingValue((yyvsp[0].m_value)); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 99 "parser.y" /* yacc.c:1646  */
    { instance->addPendingValue((yyvsp[0].m_value)); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.m_value).type = 1; (yyval.m_value).v_int = (yyvsp[0].m_int); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.m_value).type = 2; (yyval.m_value).v_str = (yyvsp[0].m_string); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.m_value).type = 3; (yyval.m_value).v_float = (yyvsp[0].m_float); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.m_value).type = 0; }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.m_where).type = 2; (yyval.m_where).op = (yyvsp[-1].m_int); (yyval.m_where).opCol = false; (yyval.m_where).left = (yyvsp[-2].m_col); (yyval.m_where).val_r = (yyvsp[0].m_value); instance->addPendingWhere((yyval.m_where)); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.m_where).type = 2; (yyval.m_where).op = (yyvsp[-1].m_int); (yyval.m_where).opCol = true; (yyval.m_where).left = (yyvsp[-2].m_col); (yyval.m_where).col_r = (yyvsp[0].m_col); instance->addPendingWhere((yyval.m_where)); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.m_where).type = 0; (yyval.m_where).left = (yyvsp[-2].m_col); instance->addPendingWhere((yyval.m_where)); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.m_where).type = 1; (yyval.m_where).left = (yyvsp[-3].m_col); instance->addPendingWhere((yyval.m_where)); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 112 "parser.y" /* yacc.c:1646  */
    {}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.m_col).table = (yyvsp[-2].m_string); (yyval.m_col).field = (yyvsp[0].m_string); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.m_col).table = ""; (yyval.m_col).field = (yyvsp[0].m_string); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 0; }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 5; }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 1; }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 2; }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 3; }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.m_int) = 4; }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.m_set).field = (yyvsp[-2].m_string); (yyval.m_set).rvalue = (yyvsp[0].m_rvalue); instance->addPendingSet((yyval.m_set)); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.m_set).field = (yyvsp[-2].m_string); (yyval.m_set).rvalue = (yyvsp[0].m_rvalue); instance->addPendingSet((yyval.m_set)); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 1; (yyval.m_rvalue).value = (yyvsp[0].m_value); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 2; (yyval.m_rvalue).col = (yyvsp[0].m_string); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 3; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).col2 = (yyvsp[0].m_string); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 4; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).col2 = (yyvsp[0].m_string); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 5; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).col2 = (yyvsp[0].m_string); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 6; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).col2 = (yyvsp[0].m_string); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 7; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).value = (yyvsp[0].m_value); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 8; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).value = (yyvsp[0].m_value); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 9; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).value = (yyvsp[0].m_value); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 10; (yyval.m_rvalue).col = (yyvsp[-2].m_string); (yyval.m_rvalue).value = (yyvsp[0].m_value); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 11; (yyval.m_rvalue).col = (yyvsp[0].m_string); (yyval.m_rvalue).value = (yyvsp[-2].m_value); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.m_rvalue).type = 12; (yyval.m_rvalue).col = (yyvsp[0].m_string); (yyval.m_rvalue).value = (yyvsp[-2].m_value); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.m_bool) = true; }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.m_bool) = false; }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 149 "parser.y" /* yacc.c:1646  */
    { instance->addPendingCol((yyvsp[0].m_col)); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 150 "parser.y" /* yacc.c:1646  */
    { instance->addPendingCol((yyvsp[0].m_col)); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 153 "parser.y" /* yacc.c:1646  */
    { instance->addPendingTable((yyvsp[0].m_string)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 154 "parser.y" /* yacc.c:1646  */
    { instance->addPendingTable((yyvsp[0].m_string)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 157 "parser.y" /* yacc.c:1646  */
    { instance->addPendingColumn((yyvsp[0].m_string)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 158 "parser.y" /* yacc.c:1646  */
    { instance->addPendingColumn((yyvsp[0].m_string)); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.m_string) = (yyvsp[0].m_string); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.m_string) = (yyvsp[0].m_string); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.m_string) = (yyvsp[0].m_string); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1891 "y.tab.c" /* yacc.c:1646  */
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
#line 170 "parser.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    cerr<<s<<endl;
    yywrap();
}

