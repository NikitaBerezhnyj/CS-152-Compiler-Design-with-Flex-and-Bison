/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int yylex();
void yyerror(const char *s);

struct CodeNode {
    std::string code;
    std::string name;
};

struct Loop {
    int id;
    std::string begin_label;
    std::string end_label;
    std::string body_label;
};

std::vector<Loop> loops;

enum Type { Integer, Array };

struct Symbol {
    std::string name;
    Type type;
};

struct Function {
    std::string name;
    std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;

Function *get_function() {
    int last = symbol_table.size() - 1;
    if (last < 0) {
        printf("***Error. Attempt to call get_function with an empty symbol table\n");
        printf("Create a 'Function' object using 'add_function_to_symbol_table' before\n");
        printf("calling 'find' or 'add_variable_to_symbol_table'");
        exit(1);
    }
    return &symbol_table[last];
}

bool find(std::string &value) {
    Function *f = get_function();
    for (int i = 0; i < f->declarations.size(); i++) {
        Symbol *s = &f->declarations[i];
        if (s->name == value) {
            return true;
        }
    }
    return false;
}

void add_function_to_symbol_table(std::string &value) {
    Function f;
    f.name = value;
    symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string &value, Type t) {
    Symbol s;
    s.name = value;
    s.type = t;
    Function *f = get_function();
    f->declarations.push_back(s);
}

void print_symbol_table(void) {
    printf("symbol table:\n");
    printf("--------------------\n");
    for (int i = 0; i < symbol_table.size(); i++) {
        printf("function: %s\n", symbol_table[i].name.c_str());
        for (int j = 0; j < symbol_table[i].declarations.size(); j++) {
            printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
        }
    }
    printf("--------------------\n");
}


#line 159 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNC = 3,                       /* FUNC  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_INPUT = 6,                      /* INPUT  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELIF = 8,                       /* ELIF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_LPAR = 13,                      /* LPAR  */
  YYSYMBOL_RPAR = 14,                      /* RPAR  */
  YYSYMBOL_LCURLY = 15,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 16,                    /* RCURLY  */
  YYSYMBOL_LBRACK = 17,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 18,                    /* RBRACK  */
  YYSYMBOL_EQUAL = 19,                     /* EQUAL  */
  YYSYMBOL_INCREMENT = 20,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 21,                 /* DECREMENT  */
  YYSYMBOL_LESS = 22,                      /* LESS  */
  YYSYMBOL_LESSEQUAL = 23,                 /* LESSEQUAL  */
  YYSYMBOL_EQUALEQUAL = 24,                /* EQUALEQUAL  */
  YYSYMBOL_NOTEQUAL = 25,                  /* NOTEQUAL  */
  YYSYMBOL_MOREEQUAL = 26,                 /* MOREEQUAL  */
  YYSYMBOL_MORE = 27,                      /* MORE  */
  YYSYMBOL_IDENT = 28,                     /* IDENT  */
  YYSYMBOL_NUMBER = 29,                    /* NUMBER  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MULT = 35,                      /* MULT  */
  YYSYMBOL_DIVISION = 36,                  /* DIVISION  */
  YYSYMBOL_DIVISIONREM = 37,               /* DIVISIONREM  */
  YYSYMBOL_COMA = 38,                      /* COMA  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_functions = 42,                 /* functions  */
  YYSYMBOL_function_header = 43,           /* function_header  */
  YYSYMBOL_function = 44,                  /* function  */
  YYSYMBOL_params = 45,                    /* params  */
  YYSYMBOL_param = 46,                     /* param  */
  YYSYMBOL_arguments = 47,                 /* arguments  */
  YYSYMBOL_argument = 48,                  /* argument  */
  YYSYMBOL_elif_statements = 49,           /* elif_statements  */
  YYSYMBOL_elif_statement = 50,            /* elif_statement  */
  YYSYMBOL_conditions = 51,                /* conditions  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_for_loop_action = 53,           /* for_loop_action  */
  YYSYMBOL_statements = 54,                /* statements  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_variable = 56,                  /* variable  */
  YYSYMBOL_operation_sign = 57,            /* operation_sign  */
  YYSYMBOL_equal_sign = 58,                /* equal_sign  */
  YYSYMBOL_condition_sign = 59             /* condition_sign  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   157,   157,   162,   169,   174,   180,   191,   198,   204,
     209,   220,   227,   233,   238,   245,   252,   257,   268,   276,
     288,   297,   305,   311,   317,   326,   333,   338,   348,   359,
     365,   371,   376,   381,   386,   393,   404,   417,   430,   442,
     454,   466,   478,   496,   543,   556,   573,   589,   598,   607,
     614,   615,   617,   618,   619,   620,   621,   623,   624,   625,
     626,   627,   628,   630,   631
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUNC", "VAR", "PRINT",
  "INPUT", "IF", "ELIF", "ELSE", "FOR", "WHILE", "RETURN", "LPAR", "RPAR",
  "LCURLY", "RCURLY", "LBRACK", "RBRACK", "EQUAL", "INCREMENT",
  "DECREMENT", "LESS", "LESSEQUAL", "EQUALEQUAL", "NOTEQUAL", "MOREEQUAL",
  "MORE", "IDENT", "NUMBER", "OR", "AND", "NOT", "PLUS", "MINUS", "MULT",
  "DIVISION", "DIVISIONREM", "COMA", "SEMICOLON", "$accept", "program",
  "functions", "function_header", "function", "params", "param",
  "arguments", "argument", "elif_statements", "elif_statement",
  "conditions", "condition", "for_loop_action", "statements", "statement",
  "variable", "operation_sign", "equal_sign", "condition_sign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,     8,    52,   -73,    41,    11,   -73,   -73,    34,   -73,
     -73,    50,    38,    69,    34,     1,   -73,    67,    84,    86,
      46,    92,    46,    54,    25,    82,     1,    -2,    72,    87,
     -73,   -73,    54,    88,    57,    45,    74,    90,    68,    54,
      77,    61,    70,    71,   -73,   -73,    93,    -3,   -73,    13,
      73,   -73,     1,   -73,   -73,    46,   -73,   -73,   -73,   -73,
     -73,   -73,    54,    94,     1,   -73,   100,    79,   -73,    97,
      18,    14,   -73,   -73,   102,   106,    22,    89,    95,   -73,
     107,   -73,   -73,    54,   109,    91,    54,   103,    54,    54,
     -73,   -73,   -73,   -73,   -73,   -73,    54,    98,   112,   -73,
      54,   -73,   111,    83,    96,   -73,   -73,   -73,     4,   117,
     114,    99,   101,   104,   105,   120,   121,    85,   113,   126,
     108,   110,   115,   -73,   -73,   -73,   -73,   116,     1,    46,
     127,   -73,    45,   131,   -73,   -73,   -73,   -73,   130,   133,
       1,    54,   118,   -73,     1,   134,   119,   -73,   135,   -73,
     124,   -73,    60,   138,   128,   -73,   -73,     1,   -14,   143,
      54,   -73,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     0,     4,     5,     1,     9,     3,
      10,     0,     8,     0,     9,    26,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
      50,    51,     0,     0,    18,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     6,    25,     0,     0,    35,     0,
       0,    21,    26,    63,    64,     0,    57,    58,    59,    60,
      61,    62,     0,     0,    26,    49,     0,    12,    14,     0,
      50,     0,    32,    33,     0,     0,     0,     0,     0,    29,
       0,    19,    20,     0,     0,     0,    13,     0,    13,     0,
      52,    53,    54,    55,    56,    31,     0,     0,     0,    36,
       0,    27,     0,    44,     0,    42,    48,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    39,    38,    37,     0,    26,     0,
       0,    15,     0,     0,    41,    47,    40,    28,     0,     0,
      26,     0,     0,    46,    26,     0,     0,    34,     0,    45,
       0,    17,     0,     0,     0,    22,    23,    26,     0,     0,
       0,    43,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   155,   -73,   -73,   147,   -73,   -45,   -73,   -73,
     -73,   -21,   -73,   -73,   -24,   -73,   -23,   -72,    30,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    11,    12,    66,    67,   117,
     131,    33,    34,   153,    25,    26,    35,    96,    62,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    37,    45,    75,   100,    17,    18,    19,    20,    51,
     119,    21,    22,    23,     1,    46,    68,    47,    71,    90,
      91,    92,    93,    94,    76,    30,    31,    77,    80,    24,
      78,    88,    30,    31,    81,    89,     6,    48,    39,    82,
      84,   107,    40,   109,    41,    42,    43,    90,    91,    92,
      93,    94,     7,    95,     8,    90,    91,    92,    93,    94,
     104,    99,    10,    68,    13,    68,   110,    56,    57,    58,
      59,    60,    61,   111,    30,    31,    14,   114,    32,   154,
     155,   156,    30,    31,    15,   120,   160,    53,    54,    70,
      31,   -16,   116,   129,   130,    27,    36,    28,    44,    29,
      49,    50,    63,    52,   138,    64,    69,    65,   139,    72,
      73,    74,    79,    83,    85,    87,   145,    86,   146,    98,
     148,    97,   108,   103,   102,   105,   113,   112,   101,   115,
     106,   121,   122,   159,   127,   118,   128,   162,   123,   133,
     124,   132,   140,   125,   126,   142,   143,   134,   144,   135,
     149,   151,   152,   157,   136,   137,   158,   147,   150,   161,
       9,    16,   141
};

static const yytype_uint8 yycheck[] =
{
      23,    22,    26,     6,    76,     4,     5,     6,     7,    32,
       6,    10,    11,    12,     3,    17,    39,    19,    41,    33,
      34,    35,    36,    37,    47,    28,    29,    14,    52,    28,
      17,    13,    28,    29,    55,    17,    28,    39,    13,    62,
      64,    86,    17,    88,    19,    20,    21,    33,    34,    35,
      36,    37,     0,    39,    13,    33,    34,    35,    36,    37,
      83,    39,    28,    86,    14,    88,    89,    22,    23,    24,
      25,    26,    27,    96,    28,    29,    38,   100,    32,    19,
      20,    21,    28,    29,    15,   108,   158,    30,    31,    28,
      29,     8,     9,     8,     9,    28,     4,    13,    16,    13,
      28,    14,    28,    15,   128,    15,    29,    39,   129,    39,
      39,    18,    39,    19,    14,    18,   140,    38,   141,    13,
     144,    19,    19,    16,    29,    16,    14,    29,    39,    18,
      39,    14,    18,   157,    14,    39,    15,   160,    39,    13,
      39,    28,    15,    39,    39,    14,    16,    39,    15,    39,
      16,    16,    28,    15,    39,    39,    28,    39,    39,    16,
       5,    14,   132
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    42,    43,    44,    28,     0,    13,    42,
      28,    45,    46,    14,    38,    15,    45,     4,     5,     6,
       7,    10,    11,    12,    28,    54,    55,    28,    13,    13,
      28,    29,    32,    51,    52,    56,     4,    51,    56,    13,
      17,    19,    20,    21,    16,    54,    17,    19,    39,    28,
      14,    56,    15,    30,    31,    59,    22,    23,    24,    25,
      26,    27,    58,    28,    15,    39,    47,    48,    56,    29,
      28,    56,    39,    39,    18,     6,    56,    14,    17,    39,
      54,    51,    56,    19,    54,    14,    38,    18,    13,    17,
      33,    34,    35,    36,    37,    39,    57,    19,    13,    39,
      57,    39,    29,    16,    56,    16,    39,    47,    19,    47,
      56,    56,    29,    14,    56,    18,     9,    49,    39,     6,
      56,    14,    18,    39,    39,    39,    39,    14,    15,     8,
       9,    50,    28,    13,    39,    39,    39,    39,    54,    51,
      15,    58,    14,    16,    15,    54,    56,    39,    54,    16,
      39,    16,    28,    53,    19,    20,    21,    15,    28,    54,
      57,    16,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    45,    45,    45,
      46,    47,    47,    47,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     7,     3,     1,     0,
       1,     3,     1,     0,     1,     2,     0,     5,     1,     3,
       3,     2,     2,     2,     5,     2,     0,     5,     8,     4,
       6,     4,     3,     3,     9,     3,     5,     7,     7,     7,
       7,     7,     5,    14,     5,    10,     9,     7,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: functions  */
#line 157 "parser.y"
                   {
    struct CodeNode *functions = (yyvsp[0].code_node);
    printf("%s\n", functions->code.c_str());
}
#line 1576 "parser.cpp"
    break;

  case 3: /* functions: function functions  */
#line 162 "parser.y"
                              {
    struct CodeNode *function = (yyvsp[-1].code_node);
    struct CodeNode *functions = (yyvsp[0].code_node);
    struct CodeNode *node = new CodeNode;
    node->code = function->code + functions->code;
    (yyval.code_node) = node;
}
#line 1588 "parser.cpp"
    break;

  case 4: /* functions: %empty  */
#line 169 "parser.y"
         {
    struct CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1597 "parser.cpp"
    break;

  case 5: /* function_header: FUNC IDENT  */
#line 174 "parser.y"
                            {
    std::string function_name = (yyvsp[0].op_value);
    add_function_to_symbol_table(function_name);
    (yyval.op_value) = (yyvsp[0].op_value);
}
#line 1607 "parser.cpp"
    break;

  case 6: /* function: function_header LPAR params RPAR LCURLY statements RCURLY  */
#line 180 "parser.y"
                                                                    {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *params = (yyvsp[-4].code_node);
    struct CodeNode *statements = (yyvsp[-1].code_node);
    node->code = std::string("func ") + std::string((yyvsp[-6].op_value)) + std::string("\n");
    node->code += params->code;
    node->code += statements->code;
    node->code += std::string("endfunc\n\n");
    (yyval.code_node) = node;
}
#line 1622 "parser.cpp"
    break;

  case 7: /* params: param COMA params  */
#line 191 "parser.y"
                          {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *param = (yyvsp[-2].code_node);
    struct CodeNode *params = (yyvsp[0].code_node);
    node->code = param->code + params->code;
    (yyval.code_node) = node;
}
#line 1634 "parser.cpp"
    break;

  case 8: /* params: param  */
#line 198 "parser.y"
        {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *param = (yyvsp[0].code_node);
    node->code = param->code;
    (yyval.code_node) = node;
}
#line 1645 "parser.cpp"
    break;

  case 9: /* params: %empty  */
#line 204 "parser.y"
         {
    struct CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1654 "parser.cpp"
    break;

  case 10: /* param: IDENT  */
#line 209 "parser.y"
             {
    struct CodeNode *node = new CodeNode;
    std::string param = (yyvsp[0].op_value);
    node->name = param;
    node->code = std::string(". ") + param + std::string("\n");
    int param_index = symbol_table.back().declarations.size();
    node->code += std::string("= ") + param + std::string(", $") + std::to_string(param_index) + std::string("\n");
    add_variable_to_symbol_table(param, Integer);
    (yyval.code_node) = node;
}
#line 1669 "parser.cpp"
    break;

  case 11: /* arguments: argument COMA arguments  */
#line 220 "parser.y"
                                   {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *argument = (yyvsp[-2].code_node);
    struct CodeNode *arguments = (yyvsp[0].code_node);
    node->code = argument->code + arguments->code;
    (yyval.code_node) = node;
}
#line 1681 "parser.cpp"
    break;

  case 12: /* arguments: argument  */
#line 227 "parser.y"
           {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *argument = (yyvsp[0].code_node);
    node->code = argument->code;
    (yyval.code_node) = node;
}
#line 1692 "parser.cpp"
    break;

  case 13: /* arguments: %empty  */
#line 233 "parser.y"
         {
    struct CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1701 "parser.cpp"
    break;

  case 14: /* argument: variable  */
#line 238 "parser.y"
                   {
    struct CodeNode *node = new CodeNode;
    std::string argument = (yyvsp[0].op_value);
    node->code = std::string("param ") + argument + std::string("\n");
    (yyval.code_node) = node;
}
#line 1712 "parser.cpp"
    break;

  case 15: /* elif_statements: elif_statements elif_statement  */
#line 245 "parser.y"
                                                {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *elif_statements = (yyvsp[-1].code_node);
    struct CodeNode *elif_statement = (yyvsp[0].code_node);
    node->code = elif_statements->code + elif_statement->code;
    (yyval.code_node) = node;
}
#line 1724 "parser.cpp"
    break;

  case 16: /* elif_statements: %empty  */
#line 252 "parser.y"
         {
    struct CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1733 "parser.cpp"
    break;

  case 17: /* elif_statement: ELIF conditions LCURLY statements RCURLY  */
#line 257 "parser.y"
                                                         {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *conditions = (yyvsp[-3].code_node);
    struct CodeNode *statements = (yyvsp[-1].code_node);
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= endelse\n");
    (yyval.code_node) = node;
}
#line 1748 "parser.cpp"
    break;

  case 18: /* conditions: condition  */
#line 268 "parser.y"
                      {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *condition = (yyvsp[0].code_node);
    node->code = condition->code;
    node->code += std::string("?:= condition_true, temp\n");
    node->code += std::string(":= condition_false\n");
    (yyval.code_node) = node;
}
#line 1761 "parser.cpp"
    break;

  case 19: /* conditions: condition condition_sign conditions  */
#line 276 "parser.y"
                                      {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *condition1 = (yyvsp[-2].code_node);
    std::string condition_sign = (yyvsp[-1].op_value);
    struct CodeNode *conditions = (yyvsp[0].code_node);
    node->code = condition1->code + std::string(condition_sign) + std::string(" temp, temp, temp\n");
    node->code += conditions->code;
    node->code += std::string("?:= condition_true, temp\n");
    node->code += std::string(":= condition_false\n");
    (yyval.code_node) = node;
}
#line 1777 "parser.cpp"
    break;

  case 20: /* condition: variable equal_sign variable  */
#line 288 "parser.y"
                                        {
    struct CodeNode *node = new CodeNode;
    std::string var1 = (yyvsp[-2].op_value);
    std::string equal_sign = (yyvsp[-1].op_value);
    std::string var2 = (yyvsp[0].op_value);
    node->code += std::string(". temp\n");
    node->code += std::string(equal_sign) + std::string(" temp, ") + var1 + std::string(", ") + var2 + std::string("\n");
    (yyval.code_node) = node;
}
#line 1791 "parser.cpp"
    break;

  case 21: /* condition: NOT variable  */
#line 297 "parser.y"
               {
    struct CodeNode *node = new CodeNode;
    std::string var = (yyvsp[0].op_value);
    node->code = std::string(". temp\n");
    node->code += std::string("! temp, ") + var + std::string("\n");
    (yyval.code_node) = node;
}
#line 1803 "parser.cpp"
    break;

  case 22: /* for_loop_action: IDENT INCREMENT  */
#line 305 "parser.y"
                                 {
    struct CodeNode *node = new CodeNode;
    std::string var = (yyvsp[-1].op_value);
    node->code += std::string("+ ") + std::string(var) + std::string(", ") + std::string(var) + std::string(", 1\n");
    (yyval.code_node) = node;
}
#line 1814 "parser.cpp"
    break;

  case 23: /* for_loop_action: IDENT DECREMENT  */
#line 311 "parser.y"
                  {
    struct CodeNode *node = new CodeNode;
    std::string var = (yyvsp[-1].op_value);
    node->code += std::string("- ") + std::string(var) + std::string(", ") + std::string(var) + std::string(", 1\n");
    (yyval.code_node) = node;
}
#line 1825 "parser.cpp"
    break;

  case 24: /* for_loop_action: IDENT EQUAL IDENT operation_sign variable  */
#line 317 "parser.y"
                                            {
    struct CodeNode *node = new CodeNode;
    std::string var = (yyvsp[-4].op_value);
    std::string operation_sign = (yyvsp[-1].op_value);
    std::string operation_value = (yyvsp[0].op_value);
    node->code += std::string(operation_sign) + std::string(" ") + std::string(var) + std::string(", ") + std::string(var) + std::string(",") + std::string(operation_value) + std::string("\n");
    (yyval.code_node) = node;
}
#line 1838 "parser.cpp"
    break;

  case 25: /* statements: statement statements  */
#line 326 "parser.y"
                                 {
    struct CodeNode *statement = (yyvsp[-1].code_node);
    struct CodeNode *statements = (yyvsp[0].code_node);
    struct CodeNode *node = new CodeNode;
    node->code = statement->code + statements->code;
    (yyval.code_node) = node;
}
#line 1850 "parser.cpp"
    break;

  case 26: /* statements: %empty  */
#line 333 "parser.y"
         {
    struct CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1859 "parser.cpp"
    break;

  case 27: /* statement: PRINT LPAR IDENT RPAR SEMICOLON  */
#line 338 "parser.y"
                                           {
    std::string variable_name = (yyvsp[-2].op_value);
    if (!find(variable_name)) {
        yyerror("Undeclared variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".> ") + std::string((yyvsp[-2].op_value)) + std::string("\n");
    (yyval.code_node) = node;
}
#line 1874 "parser.cpp"
    break;

  case 28: /* statement: PRINT LPAR IDENT LBRACK NUMBER RBRACK RPAR SEMICOLON  */
#line 348 "parser.y"
                                                       {
    std::string variable_name = (yyvsp[-5].op_value);
    std::string item_index = (yyvsp[-3].op_value);
    if (!find(variable_name)) {
        yyerror("Undeclared variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[]> ") + variable_name + std::string(", ") + item_index + std::string("\n");
    (yyval.code_node) = node;
}
#line 1890 "parser.cpp"
    break;

  case 29: /* statement: INPUT LPAR RPAR SEMICOLON  */
#line 359 "parser.y"
                            {
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". temp\n");
    node->code += std::string(".< temp\n");
    (yyval.code_node) = node;
}
#line 1901 "parser.cpp"
    break;

  case 30: /* statement: IDENT EQUAL variable operation_sign variable SEMICOLON  */
#line 365 "parser.y"
                                                         {
    struct CodeNode *node = new CodeNode;
    std::string operation_sign = (yyvsp[-2].op_value);
    node->code = std::string(operation_sign) + std::string(" ") + std::string((yyvsp[-5].op_value)) + std::string(", ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + std::string((yyvsp[-1].op_value)) + std::string("\n");
    (yyval.code_node) = node;
}
#line 1912 "parser.cpp"
    break;

  case 31: /* statement: IDENT EQUAL variable SEMICOLON  */
#line 371 "parser.y"
                                 {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("= ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + std::string((yyvsp[-1].op_value)) + std::string("\n");
    (yyval.code_node) = node;
}
#line 1922 "parser.cpp"
    break;

  case 32: /* statement: IDENT INCREMENT SEMICOLON  */
#line 376 "parser.y"
                            {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("+ ") + std::string((yyvsp[-2].op_value)) + std::string(", ") + std::string((yyvsp[-2].op_value)) + std::string(", 1\n");
    (yyval.code_node) = node;
}
#line 1932 "parser.cpp"
    break;

  case 33: /* statement: IDENT DECREMENT SEMICOLON  */
#line 381 "parser.y"
                            {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("- ") + std::string((yyvsp[-2].op_value)) + std::string(", ") + std::string((yyvsp[-2].op_value)) + std::string(", 1\n");
    (yyval.code_node) = node;
}
#line 1942 "parser.cpp"
    break;

  case 34: /* statement: IDENT LBRACK NUMBER RBRACK EQUAL INPUT LPAR RPAR SEMICOLON  */
#line 386 "parser.y"
                                                             {
    std::string variable_name = (yyvsp[-8].op_value);
    std::string item_index = (yyvsp[-6].op_value);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[]< ") + variable_name + std::string(", ") + item_index + "\n";
    (yyval.code_node) = node;
}
#line 1954 "parser.cpp"
    break;

  case 35: /* statement: VAR IDENT SEMICOLON  */
#line 393 "parser.y"
                      {
    std::string variable_name = (yyvsp[-1].op_value);
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + std::string("\n");
    (yyval.code_node) = node;
}
#line 1970 "parser.cpp"
    break;

  case 36: /* statement: VAR IDENT EQUAL variable SEMICOLON  */
#line 404 "parser.y"
                                     {
    std::string variable_name = (yyvsp[-3].op_value);
    std::string variable_val = (yyvsp[-1].op_value);
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + std::string("\n");
    node->code += std::string("= ") + variable_name + std::string(", ") + variable_val + std::string("\n");
    (yyval.code_node) = node;
}
#line 1988 "parser.cpp"
    break;

  case 37: /* statement: VAR IDENT EQUAL variable operation_sign variable SEMICOLON  */
#line 417 "parser.y"
                                                             {
    std::string variable_name = (yyvsp[-5].op_value);
    std::string operation_sign = (yyvsp[-2].op_value);
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
node->code = std::string(". ") + variable_name + std::string("\n");
node->code += std::string(operation_sign) + std::string(" ") + variable_name + std::string(", ") + std::string((yyvsp[-3].op_value)) + std::string(", ") + std::string((yyvsp[-1].op_value)) + std::string("\n");
(yyval.code_node) = node;
}
#line 2006 "parser.cpp"
    break;

  case 38: /* statement: VAR IDENT EQUAL INPUT LPAR RPAR SEMICOLON  */
#line 430 "parser.y"
                                            {
    std::string variable_name = (yyvsp[-5].op_value);
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + "\n";
    node->code += std::string(".< ") + variable_name + "\n";
    (yyval.code_node) = node;
}
#line 2023 "parser.cpp"
    break;

  case 39: /* statement: VAR IDENT LBRACK RBRACK EQUAL NUMBER SEMICOLON  */
#line 442 "parser.y"
                                                 {
    std::string array_name = (yyvsp[-5].op_value);
    int array_size = atoi((yyvsp[-1].op_value));
    if (find(array_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(array_name, Array);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[] ") + array_name + std::string(", ") + std::to_string(array_size) + std::string("\n");
    (yyval.code_node) = node;
}
#line 2040 "parser.cpp"
    break;

  case 40: /* statement: IDENT EQUAL IDENT LBRACK variable RBRACK SEMICOLON  */
#line 454 "parser.y"
                                                     {
    std::string dst = (yyvsp[-6].op_value);
    std::string src = (yyvsp[-4].op_value);
    int index = atoi((yyvsp[-2].op_value));
    if (!find(dst) || !find(src)) {
        yyerror("Unknown variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string("=[] ") + dst + std::string(", ") + src + std::string(", ") + std::to_string(index) + std::string("\n");
    (yyval.code_node) = node;
}
#line 2057 "parser.cpp"
    break;

  case 41: /* statement: IDENT LBRACK NUMBER RBRACK EQUAL variable SEMICOLON  */
#line 466 "parser.y"
                                                      {
    std::string dst = (yyvsp[-6].op_value);
    int index = atoi((yyvsp[-4].op_value));
    std::string src = (yyvsp[-1].op_value);
    if (!find(dst)) {
        yyerror("Unknown variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string("[]= ") + dst + std::string(", ") + std::to_string(index) + std::string(", ") + src + std::string("\n");
    (yyval.code_node) = node;
}
#line 2074 "parser.cpp"
    break;

  case 42: /* statement: WHILE conditions LCURLY statements RCURLY  */
#line 478 "parser.y"
                                            {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *conditions = (yyvsp[-3].code_node);
    struct CodeNode *statements = (yyvsp[-1].code_node);
    int loop_id = loops.size();
    std::string begin_label = "beginloop" + std::to_string(loop_id);
    std::string end_label = "endloop" + std::to_string(loop_id);
    Loop loop = {loop_id, begin_label, end_label, ""};
    loops.push_back(loop);
    node->code += std::string(": ") + begin_label + "\n";
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= ") + begin_label + "\n";
    node->code += std::string(": condition_false\n");
    node->code += std::string(": ") + end_label + "\n";
    (yyval.code_node) = node;
}
#line 2097 "parser.cpp"
    break;

  case 43: /* statement: FOR VAR IDENT EQUAL variable SEMICOLON IDENT equal_sign variable SEMICOLON for_loop_action LCURLY statements RCURLY  */
#line 496 "parser.y"
                                                                                                                      {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *statements = (yyvsp[-1].code_node);
    std::string var = (yyvsp[-11].op_value);
    std::string start_val = (yyvsp[-9].op_value);
    std::string equal_sign = (yyvsp[-6].op_value);
    std::string current_val = (yyvsp[-5].op_value);
    struct CodeNode *for_loop_action = (yyvsp[-3].code_node);
    if (find(var)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(var, Integer);
    int loop_id = loops.size();
    std::string begin_label = "beginloop" + std::to_string(loop_id);
    std::string end_label = "endloop" + std::to_string(loop_id);
    std::string body_label = "loopbody" + std::to_string(loop_id);
    Loop loop = {loop_id, begin_label, end_label, body_label};
    loops.push_back(loop);
    node->code += std::string(". ") + var + std::string("\n");
    node->code += std::string("= ") + var + std::string(", ") + start_val + std::string("\n");
    node->code += std::string(": ") + begin_label + "\n";
    node->code += std::string(". temp\n");
    node->code += std::string(equal_sign) + std::string(" temp, ") + std::string(var) + std::string(", ") + std::string(current_val) + std::string("\n");
    node->code += std::string("?:= ") + body_label + std::string(", temp\n");
    node->code += std::string(":= ") + end_label + "\n";
    node->code += std::string(": ") + body_label + "\n";
    
    // Додаємо змінну циклу до таблиці символів перед виконанням тіла циклу
    add_variable_to_symbol_table(var, Integer);
    
    node->code += statements->code;
    
    // Видаляємо змінну циклу з таблиці символів після виконання тіла циклу
    Function *f = get_function();
    for (int i = 0; i < f->declarations.size(); i++) {
        if (f->declarations[i].name == var) {
            f->declarations.erase(f->declarations.begin() + i);
            break;
        }
    }
    
    node->code += for_loop_action->code;
    node->code += std::string(":= ") + begin_label + "\n";
    node->code += std::string(": ") + end_label + "\n";
    (yyval.code_node) = node;
}
#line 2149 "parser.cpp"
    break;

  case 44: /* statement: IF conditions LCURLY statements RCURLY  */
#line 543 "parser.y"
                                         {
    struct CodeNode *conditions = (yyvsp[-3].code_node);
    struct CodeNode *statements = (yyvsp[-1].code_node);
    struct CodeNode *node = new CodeNode;
    node->code += std::string(": condition_start\n");
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_false\n");
    node->code += std::string(": condition_end\n");
    (yyval.code_node) = node;
}
#line 2167 "parser.cpp"
    break;

  case 45: /* statement: IF conditions LCURLY statements RCURLY elif_statements ELSE LCURLY statements RCURLY  */
#line 556 "parser.y"
                                                                                       {
    struct CodeNode *conditions = (yyvsp[-8].code_node);
    struct CodeNode *statementsIF = (yyvsp[-6].code_node);
    struct CodeNode *elif_statements = (yyvsp[-4].code_node);
    struct CodeNode *statementsELSE = (yyvsp[-1].code_node);
    struct CodeNode *node = new CodeNode;
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statementsIF->code;
    node->code += std::string(":= endelse\n");
    node->code += elif_statements->code;
    node->code += std::string(": condition_false\n");
    node->code += statementsELSE->code;
    node->code += std::string(":= endelse\n");
    node->code += std::string(": endelse\n");
    (yyval.code_node) = node;
}
#line 2189 "parser.cpp"
    break;

  case 46: /* statement: IF conditions LCURLY statements RCURLY ELSE LCURLY statements RCURLY  */
#line 573 "parser.y"
                                                                       {
    struct CodeNode *conditions = (yyvsp[-7].code_node);
    struct CodeNode *statementsIF = (yyvsp[-5].code_node);
    struct CodeNode *statementsELSE = (yyvsp[-1].code_node);
    struct CodeNode *node = new CodeNode;
    node->code += std::string(": condition_start\n");
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statementsIF->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_false\n");
    node->code += statementsELSE->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_end\n");
    (yyval.code_node) = node;
}
#line 2210 "parser.cpp"
    break;

  case 47: /* statement: IDENT EQUAL IDENT LPAR arguments RPAR SEMICOLON  */
#line 589 "parser.y"
                                                  {
    std::string var = (yyvsp[-6].op_value);
    std::string func = (yyvsp[-4].op_value);
    struct CodeNode *arguments = (yyvsp[-2].code_node);
    struct CodeNode *node = new CodeNode;
    node->code = arguments->code;
    node->code += std::string("call ") + func + std::string(", ") + var + std::string("\n");
    (yyval.code_node) = node;
}
#line 2224 "parser.cpp"
    break;

  case 48: /* statement: IDENT LPAR arguments RPAR SEMICOLON  */
#line 598 "parser.y"
                                      {
    std::string func = (yyvsp[-4].op_value);
    struct CodeNode *arguments = (yyvsp[-2].code_node);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". temp\n");
    node->code += arguments->code;
    node->code += std::string("call ") + func + std::string(", temp\n");
    (yyval.code_node) = node;
}
#line 2238 "parser.cpp"
    break;

  case 49: /* statement: RETURN variable SEMICOLON  */
#line 607 "parser.y"
                            {
    std::string var = (yyvsp[-1].op_value);
    struct CodeNode *node = new CodeNode;
    node->code = std::string("ret ") + var + std::string("\n");
    (yyval.code_node) = node;
}
#line 2249 "parser.cpp"
    break;

  case 50: /* variable: IDENT  */
#line 614 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2255 "parser.cpp"
    break;

  case 51: /* variable: NUMBER  */
#line 615 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2261 "parser.cpp"
    break;

  case 52: /* operation_sign: PLUS  */
#line 617 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2267 "parser.cpp"
    break;

  case 53: /* operation_sign: MINUS  */
#line 618 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2273 "parser.cpp"
    break;

  case 54: /* operation_sign: MULT  */
#line 619 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2279 "parser.cpp"
    break;

  case 55: /* operation_sign: DIVISION  */
#line 620 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2285 "parser.cpp"
    break;

  case 56: /* operation_sign: DIVISIONREM  */
#line 621 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2291 "parser.cpp"
    break;

  case 57: /* equal_sign: LESS  */
#line 623 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2297 "parser.cpp"
    break;

  case 58: /* equal_sign: LESSEQUAL  */
#line 624 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2303 "parser.cpp"
    break;

  case 59: /* equal_sign: EQUALEQUAL  */
#line 625 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2309 "parser.cpp"
    break;

  case 60: /* equal_sign: NOTEQUAL  */
#line 626 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2315 "parser.cpp"
    break;

  case 61: /* equal_sign: MOREEQUAL  */
#line 627 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2321 "parser.cpp"
    break;

  case 62: /* equal_sign: MORE  */
#line 628 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2327 "parser.cpp"
    break;

  case 63: /* condition_sign: OR  */
#line 630 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2333 "parser.cpp"
    break;

  case 64: /* condition_sign: AND  */
#line 631 "parser.y"
                                {(yyval.op_value) = (yyvsp[0].op_value);}
#line 2339 "parser.cpp"
    break;


#line 2343 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 633 "parser.y"


int main(void) {
    yyparse();
    print_symbol_table();
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
