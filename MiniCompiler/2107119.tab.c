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
#line 1 "2107119.y"

#include <stdio.h>

int mode_intermediate = 0;
int mode_output = 0;

#include <stdlib.h>
#include <string.h>
#include <math.h>

extern FILE *yyin;
extern int yylex();
void yyerror(const char *s);
extern int yylineno;
extern char *yytext;

enum { TYPE_INT = 1, TYPE_FLOAT = 2, TYPE_DOUBLE = 3, TYPE_CHAR = 4, TYPE_VOID = 5, TYPE_STRUCT = 6, TYPE_ENUM = 7 };

#define MAX_SYMBOLS 256
typedef struct {
    char name[64];
    double value;
    int type;
    int declared;
} Symbol;

static Symbol symtab[MAX_SYMBOLS];
static int symcount = 0;

static int find_symbol(const char *name) {
    for (int i = 0; i < symcount; i++) {
        if (strcmp(symtab[i].name, name) == 0) return i;
    }
    return -1;
}

static int declare_symbol(const char *name, int type, double initv) {
    int idx = find_symbol(name);
    if (idx >= 0) {
        symtab[idx].type = type;
        symtab[idx].value = initv;
        symtab[idx].declared = 1;
        return idx;
    }
    if (symcount >= MAX_SYMBOLS) return -1;
    strncpy(symtab[symcount].name, name, sizeof(symtab[symcount].name) - 1);
    symtab[symcount].name[sizeof(symtab[symcount].name) - 1] = '\0';
    symtab[symcount].type = type;
    symtab[symcount].value = initv;
    symtab[symcount].declared = 1;
    return symcount++;
}

static double get_symbol_value(const char *name) {
    int idx = find_symbol(name);
    if (idx < 0 || !symtab[idx].declared) {
        fprintf(stderr, "Semantic Error (line %d): undeclared variable '%s'\n", yylineno, name);
        return 0;
    }
    return symtab[idx].value;
}

static void set_symbol_value(const char *name, double v) {
    int idx = find_symbol(name);
    if (idx < 0 || !symtab[idx].declared) {
        fprintf(stderr, "Semantic Error (line %d): assignment to undeclared variable '%s'\n", yylineno, name);
        return;
    }
    if ((symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR) && fabs(v - floor(v)) > 1e-9) {
        fprintf(stderr, "Semantic Warning (line %d): implicit narrowing conversion for '%s'\n", yylineno, name);
    }
    if (symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR) {
        symtab[idx].value = (long long)v;
    } else {
        symtab[idx].value = v;
    }
}

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

static double deg_to_rad(double d) {
    return d * (acos(-1.0) / 180.0);
}

static int is_palindrome_str(const char *s) {
    int i = 0;
    int j = (int)strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

#line 170 "2107119.tab.c"

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

#include "2107119.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_TYPE = 3,                   /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 4,                 /* FLOAT_TYPE  */
  YYSYMBOL_DOUBLE_TYPE = 5,                /* DOUBLE_TYPE  */
  YYSYMBOL_CHAR_TYPE = 6,                  /* CHAR_TYPE  */
  YYSYMBOL_VOID_TYPE = 7,                  /* VOID_TYPE  */
  YYSYMBOL_STRUCT_TYPE = 8,                /* STRUCT_TYPE  */
  YYSYMBOL_ENUM_TYPE = 9,                  /* ENUM_TYPE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE_IF = 11,                   /* ELSE_IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO_WHILE = 17,                  /* DO_WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_FUNC_DEF = 23,                  /* FUNC_DEF  */
  YYSYMBOL_FUNC_CALL = 24,                 /* FUNC_CALL  */
  YYSYMBOL_SUM = 25,                       /* SUM  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_DIVISION = 27,                  /* DIVISION  */
  YYSYMBOL_EVEN_ODD = 28,                  /* EVEN_ODD  */
  YYSYMBOL_FACTORIAL = 29,                 /* FACTORIAL  */
  YYSYMBOL_POWER = 30,                     /* POWER  */
  YYSYMBOL_PRIME = 31,                     /* PRIME  */
  YYSYMBOL_PALINDROME = 32,                /* PALINDROME  */
  YYSYMBOL_LEAP_YEAR = 33,                 /* LEAP_YEAR  */
  YYSYMBOL_SIN = 34,                       /* SIN  */
  YYSYMBOL_COS = 35,                       /* COS  */
  YYSYMBOL_TAN = 36,                       /* TAN  */
  YYSYMBOL_PRINTF = 37,                    /* PRINTF  */
  YYSYMBOL_SCANF = 38,                     /* SCANF  */
  YYSYMBOL_PLUS = 39,                      /* PLUS  */
  YYSYMBOL_MINUS = 40,                     /* MINUS  */
  YYSYMBOL_STAR = 41,                      /* STAR  */
  YYSYMBOL_SLASH = 42,                     /* SLASH  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_NEQ = 45,                       /* NEQ  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LE = 48,                        /* LE  */
  YYSYMBOL_GE = 49,                        /* GE  */
  YYSYMBOL_AND_OP = 50,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 51,                     /* OR_OP  */
  YYSYMBOL_BIT_AND = 52,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 53,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 54,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 55,                   /* BIT_NOT  */
  YYSYMBOL_SHIFT_L = 56,                   /* SHIFT_L  */
  YYSYMBOL_SHIFT_R = 57,                   /* SHIFT_R  */
  YYSYMBOL_INC = 58,                       /* INC  */
  YYSYMBOL_DEC = 59,                       /* DEC  */
  YYSYMBOL_LBRACE = 60,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 61,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 62,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 63,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 64,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 65,                  /* RBRACKET  */
  YYSYMBOL_SEMI = 66,                      /* SEMI  */
  YYSYMBOL_COMMA = 67,                     /* COMMA  */
  YYSYMBOL_COLON = 68,                     /* COLON  */
  YYSYMBOL_ARROW_R = 69,                   /* ARROW_R  */
  YYSYMBOL_ARROW_L = 70,                   /* ARROW_L  */
  YYSYMBOL_INTEGER_LIT = 71,               /* INTEGER_LIT  */
  YYSYMBOL_FLOAT_LIT = 72,                 /* FLOAT_LIT  */
  YYSYMBOL_CHAR_LIT = 73,                  /* CHAR_LIT  */
  YYSYMBOL_STRING_LIT = 74,                /* STRING_LIT  */
  YYSYMBOL_IDENTIFIER = 75,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_program = 77,                   /* program  */
  YYSYMBOL_elements = 78,                  /* elements  */
  YYSYMBOL_element = 79,                   /* element  */
  YYSYMBOL_declaration = 80,               /* declaration  */
  YYSYMBOL_function_def = 81,              /* function_def  */
  YYSYMBOL_type_specifier = 82,            /* type_specifier  */
  YYSYMBOL_parameters = 83,                /* parameters  */
  YYSYMBOL_parameter_list = 84,            /* parameter_list  */
  YYSYMBOL_statements = 85,                /* statements  */
  YYSYMBOL_statement = 86,                 /* statement  */
  YYSYMBOL_cases = 87,                     /* cases  */
  YYSYMBOL_case_stmt = 88,                 /* case_stmt  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_assignment_expr = 90,           /* assignment_expr  */
  YYSYMBOL_logical_or_expr = 91,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 92,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 93,             /* equality_expr  */
  YYSYMBOL_relational_expr = 94,           /* relational_expr  */
  YYSYMBOL_additive_expr = 95,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 96,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 97,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 98,              /* postfix_expr  */
  YYSYMBOL_primary_expr = 99,              /* primary_expr  */
  YYSYMBOL_argument_list_opt = 100,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 101,            /* argument_list  */
  YYSYMBOL_built_in_function = 102         /* built_in_function  */
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
typedef yytype_int16 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   128,   129,   133,   134,   135,   139,   143,
     153,   154,   158,   162,   163,   164,   165,   166,   167,   168,
     171,   173,   177,   180,   185,   187,   191,   192,   193,   194,
     197,   200,   201,   202,   203,   204,   205,   206,   208,   210,
     211,   212,   213,   214,   215,   219,   220,   224,   225,   229,
     233,   234,   242,   243,   247,   248,   252,   253,   254,   258,
     259,   260,   261,   262,   266,   267,   268,   272,   273,   274,
     278,   279,   280,   281,   282,   286,   287,   288,   292,   293,
     294,   295,   296,   297,   298,   299,   302,   304,   308,   309,
     313,   315,   317,   327,   329,   340,   342,   351,   364,   369,
     375,   377,   379
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_TYPE",
  "FLOAT_TYPE", "DOUBLE_TYPE", "CHAR_TYPE", "VOID_TYPE", "STRUCT_TYPE",
  "ENUM_TYPE", "IF", "ELSE_IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "WHILE", "DO_WHILE", "FOR", "BREAK", "CONTINUE", "RETURN", "MAIN",
  "FUNC_DEF", "FUNC_CALL", "SUM", "MULTIPLY", "DIVISION", "EVEN_ODD",
  "FACTORIAL", "POWER", "PRIME", "PALINDROME", "LEAP_YEAR", "SIN", "COS",
  "TAN", "PRINTF", "SCANF", "PLUS", "MINUS", "STAR", "SLASH", "ASSIGN",
  "EQ", "NEQ", "LT", "GT", "LE", "GE", "AND_OP", "OR_OP", "BIT_AND",
  "BIT_OR", "BIT_XOR", "BIT_NOT", "SHIFT_L", "SHIFT_R", "INC", "DEC",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "SEMI",
  "COMMA", "COLON", "ARROW_R", "ARROW_L", "INTEGER_LIT", "FLOAT_LIT",
  "CHAR_LIT", "STRING_LIT", "IDENTIFIER", "$accept", "program", "elements",
  "element", "declaration", "function_def", "type_specifier", "parameters",
  "parameter_list", "statements", "statement", "cases", "case_stmt",
  "expression", "assignment_expr", "logical_or_expr", "logical_and_expr",
  "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "postfix_expr", "primary_expr",
  "argument_list_opt", "argument_list", "built_in_function", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -51,    36,
      14,    29,   -75,   -75,   -75,   -55,   -75,   -56,   -75,   -75,
     -75,   -39,   202,   -32,  1200,   -15,   -75,    -6,     0,    15,
      21,    38,    17,    42,    63,    50,    51,    52,    53,    54,
      55,    57,    58,    61,    62,    65,    69,    70,    71,    75,
    1252,  1252,  1252,  1252,   -75,  1200,   -75,   -75,   -75,   -38,
     -75,   -75,    73,   -75,    -1,    90,   -37,    12,   -18,   -16,
     -75,   -30,   -75,   -75,    36,    76,    77,  1200,  1200,  1200,
     -75,   992,   -75,   -75,   -75,    78,  1269,  1200,  1200,  1200,
    1200,  1200,  1200,  1200,  1044,  1200,  1200,  1200,  1200,  1096,
    1148,    79,   -75,   -75,   -75,   -75,    82,  1200,  1200,   -75,
    1252,  1252,  1252,  1252,  1252,  1252,  1252,  1252,  1252,  1252,
    1252,  1252,   -75,   -75,    72,    83,    81,   -75,   -75,    86,
      87,    88,   275,  1200,    94,   -75,    89,    96,    97,    98,
      91,    93,    99,   104,   105,   106,   108,   109,   111,   115,
     116,   118,   120,   121,   -75,   -75,   -75,   122,   119,    90,
     -37,    12,    12,   -18,   -18,   -18,   -18,   -16,   -16,   -75,
     -75,   -75,   127,    36,   129,   130,   131,   137,   128,  1200,
     -75,  1200,  1200,  1200,   -75,   -75,  1200,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   132,   133,   134,   136,   -75,  1200,
     -75,   138,   -75,    32,   -75,   135,  1200,   148,   141,   153,
     154,   161,   -75,   -75,   -75,   -75,   -75,   348,   -75,   421,
    1200,   125,   -12,   -75,   494,  1200,   178,  1200,   -75,   -75,
     -75,   -75,   -75,    68,   175,   -75,   -75,   -75,   -75,   181,
     185,   183,   186,   187,   -75,   932,   184,   -75,   189,  1200,
     -75,   932,   -75,   567,   -75,   188,   640,   -75,   713,   192,
     -75,   -75,   -75,   786,   241,   194,   -75,   859,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     2,     3,     5,     7,     0,    24,     0,     1,     4,
      11,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    79,    80,    81,    78,
      27,    25,     0,    49,    50,    52,    54,    56,    59,    64,
      67,    70,    75,    83,    20,     0,     0,     0,     0,     0,
      24,     0,    41,    42,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    73,    74,    71,    72,     0,     0,    86,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,     0,     0,    21,     9,    10,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    51,    88,     0,    87,    53,
      55,    57,    58,    60,    61,    62,    63,    65,    66,    68,
      69,    22,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,    93,    94,     0,    96,    98,    97,
      99,   100,   101,   102,     0,     0,     0,     0,    85,     0,
      24,     0,    24,     0,    24,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    89,     0,    23,     0,
       0,     0,     0,    45,     0,     0,     0,     0,    90,    91,
      92,    95,    12,    28,     0,    24,    36,    46,    32,     0,
       0,     0,     0,     0,    24,    48,     0,    24,     0,     0,
      24,    47,    33,     0,    24,     0,     0,    35,     0,     0,
      31,    34,    24,     0,    29,     0,    24,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   244,     1,   -75,     4,   -75,   -75,   -74,
     -75,   -75,   -27,   -24,   149,   -75,   152,   147,   -11,   -10,
      -8,   -35,   -75,   173,   -75,   -75,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    60,    14,    15,   125,   126,    22,
      61,   222,   223,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   157,   158,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    13,   220,   221,    24,   107,   132,   112,   113,    16,
      85,    20,    13,    17,    18,   102,   103,   104,   105,    23,
      21,   118,   119,    25,   108,   120,   121,    26,   122,   123,
      74,   106,     1,     2,     3,     4,     5,     6,     7,     1,
       2,     3,     4,     5,     6,     7,   220,   221,    76,   236,
     110,     8,     9,   129,   130,   131,    77,   134,   114,   115,
     116,   117,    78,   137,   138,   139,   140,   141,   142,   143,
     145,   146,   147,   148,   149,   151,   153,    79,   124,   242,
     243,    80,   133,    82,   156,   169,   170,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      81,   161,   162,    50,   163,   164,   165,   166,    83,   178,
     167,   168,    86,    87,    88,    89,    90,    91,    51,    92,
      93,    52,    53,    94,    95,    55,   217,    96,   219,    84,
     224,    97,    98,    99,    56,    57,    58,   100,    59,   109,
     111,   108,   127,   128,   135,   154,   172,   171,   173,   174,
     175,   176,   180,   205,   184,   207,   185,   208,   209,   210,
     179,   245,   211,   181,   182,   183,   186,   187,   188,   189,
     251,   190,   191,   253,   192,   216,   256,   201,   193,   194,
     258,   195,   226,   196,   197,   198,   199,   200,   263,   202,
     203,   204,   267,   235,   206,   237,   234,   225,   212,   213,
     214,   239,   215,   241,   228,     1,     2,     3,     4,     5,
       6,     7,    27,   218,   227,    28,   229,   230,    29,    30,
      31,    32,    33,    34,   231,   255,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   240,    50,   244,   246,   247,   248,   250,   249,   254,
     252,   259,   262,   265,   266,    19,   155,    51,   160,   136,
      52,    53,   159,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,    59,     1,     2,
       3,     4,     5,     6,     7,    27,     0,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    52,    53,     0,   177,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,    58,     0,
      59,     1,     2,     3,     4,     5,     6,     7,    27,     0,
       0,    28,     0,     0,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    52,    53,     0,   232,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,    58,     0,    59,     1,     2,     3,     4,     5,     6,
       7,    27,     0,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
      53,     0,   233,    55,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,    58,     0,    59,     1,     2,     3,
       4,     5,     6,     7,    27,     0,     0,    28,     0,     0,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    52,    53,     0,   238,    55,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    58,     0,    59,
       1,     2,     3,     4,     5,     6,     7,    27,     0,     0,
      28,     0,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,    53,     0,   257,    55,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      58,     0,    59,     1,     2,     3,     4,     5,     6,     7,
      27,     0,     0,    28,     0,     0,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    52,    53,
       0,   260,    55,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,    59,     1,     2,     3,     4,
       5,     6,     7,    27,     0,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    52,    53,     0,   261,    55,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,     0,    59,     1,
       2,     3,     4,     5,     6,     7,    27,     0,     0,    28,
       0,     0,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,    53,     0,   264,    55,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,    59,     1,     2,     3,     4,     5,     6,     7,    27,
       0,     0,    28,     0,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    52,    53,     0,
     268,    55,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,     0,    59,     1,     2,     3,     4,     5,
       6,     7,    27,     0,     0,    28,     0,     0,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,    53,     0,     0,    55,     1,     2,     3,     4,     5,
       6,     7,     0,    56,    57,    58,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,    53,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,    59,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    52,    53,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    58,   144,    59,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,    53,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
     150,    59,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    52,    53,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,    58,   152,    59,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    52,    53,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,    59,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,    50,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    51,     0,     0,
      52,    53,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,   101,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,     0,   101
};

static const yytype_int16 yycheck[] =
{
      24,     0,    14,    15,    43,    43,    80,    44,    45,    60,
      34,    66,    11,     9,     0,    50,    51,    52,    53,    75,
      75,    39,    40,    62,    62,    41,    42,    66,    58,    59,
      62,    55,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,    14,    15,    63,    61,
      51,    22,    23,    77,    78,    79,    62,    81,    46,    47,
      48,    49,    62,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    62,    74,    11,
      12,    60,    81,    66,   108,   120,   121,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      62,   112,   113,    40,   114,   115,   116,   117,    66,   133,
     118,   119,    62,    62,    62,    62,    62,    62,    55,    62,
      62,    58,    59,    62,    62,    62,   200,    62,   202,    66,
     204,    62,    62,    62,    71,    72,    73,    62,    75,    66,
      50,    62,    66,    66,    66,    63,    63,    75,    67,    63,
      63,    63,    63,    16,    63,   179,    63,   181,   182,   183,
      66,   235,   186,    67,    67,    67,    67,    63,    63,    63,
     244,    63,    63,   247,    63,   199,   250,   173,    63,    63,
     254,    63,   206,    63,    63,    63,    67,    60,   262,    60,
      60,    60,   266,    68,    66,   222,   220,    62,    66,    66,
      66,   225,    66,   227,    63,     3,     4,     5,     6,     7,
       8,     9,    10,    75,    66,    13,    63,    63,    16,    17,
      18,    19,    20,    21,    63,   249,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    63,    40,    68,    63,    60,    63,    60,    62,    60,
      66,    63,    60,    12,    60,    11,   107,    55,   111,    86,
      58,    59,   110,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      75,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    -1,    75,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    -1,    75,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,
      16,    17,    18,    19,    20,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    -1,    75,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    -1,    75,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    -1,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    -1,    75,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    55,    -1,    -1,
      58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    22,    23,
      77,    78,    79,    80,    81,    82,    60,    82,     0,    79,
      66,    75,    85,    75,    43,    62,    66,    10,    13,    16,
      17,    18,    19,    20,    21,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      40,    55,    58,    59,    61,    62,    71,    72,    73,    75,
      80,    86,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   102,    62,    89,    63,    62,    62,    62,
      60,    62,    66,    66,    66,    89,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    75,    97,    97,    97,    97,    89,    43,    62,    66,
      51,    50,    44,    45,    46,    47,    48,    49,    39,    40,
      41,    42,    58,    59,    82,    83,    84,    66,    66,    89,
      89,    89,    85,    80,    89,    66,    99,    89,    89,    89,
      89,    89,    89,    89,    74,    89,    89,    89,    89,    89,
      74,    89,    74,    89,    63,    90,    89,   100,   101,    92,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      97,    75,    63,    67,    63,    63,    63,    61,    89,    66,
      63,    67,    67,    67,    63,    63,    67,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    67,
      60,    82,    60,    60,    60,    16,    66,    89,    89,    89,
      89,    89,    66,    66,    66,    66,    89,    85,    75,    85,
      14,    15,    87,    88,    85,    62,    89,    66,    63,    63,
      63,    63,    61,    61,    89,    68,    61,    88,    61,    89,
      63,    89,    11,    12,    68,    85,    63,    60,    63,    62,
      60,    85,    66,    85,    60,    89,    85,    61,    85,    63,
      61,    61,    60,    85,    61,    12,    60,    85,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    80,    80,
      80,    80,    81,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     4,     1,     3,     5,
       5,     2,     9,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     4,     0,     2,     2,     1,     7,    14,
      18,    11,     7,     9,    11,    10,     7,     5,     5,     5,
       5,     2,     2,     3,     2,     1,     2,     4,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     2,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     3,     1,     4,     4,     0,     1,     1,     3,
       6,     6,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4
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
  case 6: /* element: MAIN LBRACE statements RBRACE  */
#line 134 "2107119.y"
                                    { if (mode_intermediate == 1) printf("Parsed: MAIN program\n"); }
#line 1649 "2107119.tab.c"
    break;

  case 8: /* declaration: type_specifier IDENTIFIER SEMI  */
#line 139 "2107119.y"
                                   {
        declare_symbol((yyvsp[-1].str), (yyvsp[-2].ival), 0);
        if (mode_intermediate == 1) printf("Parsed: Variable Declaration\n");
      }
#line 1658 "2107119.tab.c"
    break;

  case 9: /* declaration: type_specifier IDENTIFIER ASSIGN expression SEMI  */
#line 143 "2107119.y"
                                                       {
        int idx = declare_symbol((yyvsp[-3].str), (yyvsp[-4].ival), (yyvsp[-1].num));
        if (idx >= 0 && (symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR) && fabs((yyvsp[-1].num) - floor((yyvsp[-1].num))) > 1e-9) {
            fprintf(stderr, "Semantic Warning (line %d): implicit narrowing conversion for '%s'\n", yylineno, (yyvsp[-3].str));
        }
        if (idx >= 0 && (symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR)) {
            symtab[idx].value = (long long)(yyvsp[-1].num);
        }
        if (mode_intermediate == 1) printf("Parsed: Variable Declaration with Initialization\n");
      }
#line 1673 "2107119.tab.c"
    break;

  case 10: /* declaration: type_specifier IDENTIFIER LPAREN RPAREN SEMI  */
#line 153 "2107119.y"
                                                   { if (mode_intermediate == 1) printf("Parsed: Variable/Function Declaration\n"); }
#line 1679 "2107119.tab.c"
    break;

  case 11: /* declaration: type_specifier SEMI  */
#line 154 "2107119.y"
                          { if (mode_intermediate == 1) printf("Parsed: Struct/Enum Forward Declaration\n"); }
#line 1685 "2107119.tab.c"
    break;

  case 12: /* function_def: FUNC_DEF type_specifier IDENTIFIER LPAREN parameters RPAREN LBRACE statements RBRACE  */
#line 158 "2107119.y"
                                                                                         { if (mode_intermediate == 1) printf("Parsed: Function Definition\n"); }
#line 1691 "2107119.tab.c"
    break;

  case 13: /* type_specifier: INT_TYPE  */
#line 162 "2107119.y"
             { (yyval.ival) = TYPE_INT; }
#line 1697 "2107119.tab.c"
    break;

  case 14: /* type_specifier: FLOAT_TYPE  */
#line 163 "2107119.y"
                 { (yyval.ival) = TYPE_FLOAT; }
#line 1703 "2107119.tab.c"
    break;

  case 15: /* type_specifier: DOUBLE_TYPE  */
#line 164 "2107119.y"
                  { (yyval.ival) = TYPE_DOUBLE; }
#line 1709 "2107119.tab.c"
    break;

  case 16: /* type_specifier: CHAR_TYPE  */
#line 165 "2107119.y"
                { (yyval.ival) = TYPE_CHAR; }
#line 1715 "2107119.tab.c"
    break;

  case 17: /* type_specifier: VOID_TYPE  */
#line 166 "2107119.y"
                { (yyval.ival) = TYPE_VOID; }
#line 1721 "2107119.tab.c"
    break;

  case 18: /* type_specifier: STRUCT_TYPE  */
#line 167 "2107119.y"
                  { (yyval.ival) = TYPE_STRUCT; }
#line 1727 "2107119.tab.c"
    break;

  case 19: /* type_specifier: ENUM_TYPE  */
#line 168 "2107119.y"
                { (yyval.ival) = TYPE_ENUM; }
#line 1733 "2107119.tab.c"
    break;

  case 22: /* parameter_list: type_specifier IDENTIFIER  */
#line 177 "2107119.y"
                              {
        declare_symbol((yyvsp[0].str), (yyvsp[-1].ival), 0);
    }
#line 1741 "2107119.tab.c"
    break;

  case 23: /* parameter_list: parameter_list COMMA type_specifier IDENTIFIER  */
#line 180 "2107119.y"
                                                     {
        declare_symbol((yyvsp[0].str), (yyvsp[-1].ival), 0);
    }
#line 1749 "2107119.tab.c"
    break;

  case 26: /* statement: expression SEMI  */
#line 191 "2107119.y"
                    { if (mode_intermediate == 1) printf("Parsed: Expression Statement\n"); }
#line 1755 "2107119.tab.c"
    break;

  case 28: /* statement: IF LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 193 "2107119.y"
                                                           { if (mode_intermediate == 1) printf("Parsed: IF Statement\n"); }
#line 1761 "2107119.tab.c"
    break;

  case 29: /* statement: IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE_IF LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 194 "2107119.y"
                                                                                                                         {
                if (mode_intermediate == 1) printf("Parsed: IF-ELSEIF Statement\n");
            }
#line 1769 "2107119.tab.c"
    break;

  case 30: /* statement: IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE_IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE  */
#line 197 "2107119.y"
                                                                                                                                                       {
                if (mode_intermediate == 1) printf("Parsed: IF-ELSEIF-ELSE Statement\n");
            }
#line 1777 "2107119.tab.c"
    break;

  case 31: /* statement: IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE  */
#line 200 "2107119.y"
                                                                                         { if (mode_intermediate == 1) printf("Parsed: IF-ELSE Statement\n"); }
#line 1783 "2107119.tab.c"
    break;

  case 32: /* statement: WHILE LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 201 "2107119.y"
                                                              { if (mode_intermediate == 1) printf("Parsed: WHILE Loop\n"); }
#line 1789 "2107119.tab.c"
    break;

  case 33: /* statement: DO_WHILE LBRACE statements RBRACE WHILE LPAREN expression RPAREN SEMI  */
#line 202 "2107119.y"
                                                                            { if (mode_intermediate == 1) printf("Parsed: DO-WHILE Loop\n"); }
#line 1795 "2107119.tab.c"
    break;

  case 34: /* statement: FOR LPAREN expression SEMI expression SEMI expression RPAREN LBRACE statements RBRACE  */
#line 203 "2107119.y"
                                                                                            { if (mode_intermediate == 1) printf("Parsed: FOR Loop\n"); }
#line 1801 "2107119.tab.c"
    break;

  case 35: /* statement: FOR LPAREN declaration expression SEMI expression RPAREN LBRACE statements RBRACE  */
#line 204 "2107119.y"
                                                                                        { if (mode_intermediate == 1) printf("Parsed: FOR Loop with declaration\n"); }
#line 1807 "2107119.tab.c"
    break;

  case 36: /* statement: SWITCH LPAREN expression RPAREN LBRACE cases RBRACE  */
#line 205 "2107119.y"
                                                          { if (mode_intermediate == 1) printf("Parsed: SWITCH Statement\n"); }
#line 1813 "2107119.tab.c"
    break;

  case 37: /* statement: PRINTF LPAREN STRING_LIT RPAREN SEMI  */
#line 206 "2107119.y"
                                           { if (mode_intermediate == 1) printf("Parsed: Printf Statement\n");
        if (mode_output == 1) printf("Output: %s\n", (yyvsp[-2].str)); }
#line 1820 "2107119.tab.c"
    break;

  case 38: /* statement: PRINTF LPAREN expression RPAREN SEMI  */
#line 208 "2107119.y"
                                           { if (mode_intermediate == 1) printf("Parsed: Printf Statement\n");
        if (mode_output == 1) printf("Output: %g\n", (yyvsp[-2].num)); }
#line 1827 "2107119.tab.c"
    break;

  case 39: /* statement: SCANF LPAREN STRING_LIT RPAREN SEMI  */
#line 210 "2107119.y"
                                          { if (mode_intermediate == 1) printf("Parsed: Scanf Statement\n"); }
#line 1833 "2107119.tab.c"
    break;

  case 40: /* statement: SCANF LPAREN expression RPAREN SEMI  */
#line 211 "2107119.y"
                                          { if (mode_intermediate == 1) printf("Parsed: Scanf Statement\n"); }
#line 1839 "2107119.tab.c"
    break;

  case 41: /* statement: BREAK SEMI  */
#line 212 "2107119.y"
                 { if (mode_intermediate == 1) printf("Parsed: Break Statement\n"); }
#line 1845 "2107119.tab.c"
    break;

  case 42: /* statement: CONTINUE SEMI  */
#line 213 "2107119.y"
                    { if (mode_intermediate == 1) printf("Parsed: Continue Statement\n"); }
#line 1851 "2107119.tab.c"
    break;

  case 43: /* statement: RETURN expression SEMI  */
#line 214 "2107119.y"
                             { if (mode_intermediate == 1) printf("Parsed: Return Statement\n"); }
#line 1857 "2107119.tab.c"
    break;

  case 44: /* statement: RETURN SEMI  */
#line 215 "2107119.y"
                  { if (mode_intermediate == 1) printf("Parsed: Return Statement (Void)\n"); }
#line 1863 "2107119.tab.c"
    break;

  case 47: /* case_stmt: CASE expression COLON statements  */
#line 224 "2107119.y"
                                     { if (mode_intermediate == 1) printf("Parsed: Case Block\n"); }
#line 1869 "2107119.tab.c"
    break;

  case 48: /* case_stmt: DEFAULT COLON statements  */
#line 225 "2107119.y"
                               { if (mode_intermediate == 1) printf("Parsed: Default Block\n"); }
#line 1875 "2107119.tab.c"
    break;

  case 49: /* expression: assignment_expr  */
#line 229 "2107119.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 1881 "2107119.tab.c"
    break;

  case 50: /* assignment_expr: logical_or_expr  */
#line 233 "2107119.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 1887 "2107119.tab.c"
    break;

  case 51: /* assignment_expr: IDENTIFIER ASSIGN assignment_expr  */
#line 234 "2107119.y"
                                        {
        set_symbol_value((yyvsp[-2].str), (yyvsp[0].num));
        if (mode_intermediate == 1) printf("Parsed: Assignment\n");
        (yyval.num) = (yyvsp[0].num);
      }
#line 1897 "2107119.tab.c"
    break;

  case 52: /* logical_or_expr: logical_and_expr  */
#line 242 "2107119.y"
                     { (yyval.num) = (yyvsp[0].num); }
#line 1903 "2107119.tab.c"
    break;

  case 53: /* logical_or_expr: logical_or_expr OR_OP logical_and_expr  */
#line 243 "2107119.y"
                                             { if (mode_intermediate == 1) printf("Parsed: Logical OR\n"); (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 1909 "2107119.tab.c"
    break;

  case 54: /* logical_and_expr: equality_expr  */
#line 247 "2107119.y"
                  { (yyval.num) = (yyvsp[0].num); }
#line 1915 "2107119.tab.c"
    break;

  case 55: /* logical_and_expr: logical_and_expr AND_OP equality_expr  */
#line 248 "2107119.y"
                                            { if (mode_intermediate == 1) printf("Parsed: Logical AND\n"); (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 1921 "2107119.tab.c"
    break;

  case 56: /* equality_expr: relational_expr  */
#line 252 "2107119.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 1927 "2107119.tab.c"
    break;

  case 57: /* equality_expr: equality_expr EQ relational_expr  */
#line 253 "2107119.y"
                                       { if (mode_intermediate == 1) printf("Parsed: Equality\n"); (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 1933 "2107119.tab.c"
    break;

  case 58: /* equality_expr: equality_expr NEQ relational_expr  */
#line 254 "2107119.y"
                                        { if (mode_intermediate == 1) printf("Parsed: Inequality\n"); (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 1939 "2107119.tab.c"
    break;

  case 59: /* relational_expr: additive_expr  */
#line 258 "2107119.y"
                  { (yyval.num) = (yyvsp[0].num); }
#line 1945 "2107119.tab.c"
    break;

  case 60: /* relational_expr: relational_expr LT additive_expr  */
#line 259 "2107119.y"
                                       { if (mode_intermediate == 1) printf("Parsed: Less Than\n"); (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 1951 "2107119.tab.c"
    break;

  case 61: /* relational_expr: relational_expr GT additive_expr  */
#line 260 "2107119.y"
                                       { if (mode_intermediate == 1) printf("Parsed: Greater Than\n"); (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 1957 "2107119.tab.c"
    break;

  case 62: /* relational_expr: relational_expr LE additive_expr  */
#line 261 "2107119.y"
                                       { if (mode_intermediate == 1) printf("Parsed: Less or Equal\n"); (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 1963 "2107119.tab.c"
    break;

  case 63: /* relational_expr: relational_expr GE additive_expr  */
#line 262 "2107119.y"
                                       { if (mode_intermediate == 1) printf("Parsed: Greater or Equal\n"); (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 1969 "2107119.tab.c"
    break;

  case 64: /* additive_expr: multiplicative_expr  */
#line 266 "2107119.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 1975 "2107119.tab.c"
    break;

  case 65: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 267 "2107119.y"
                                             { if (mode_intermediate == 1) printf("Parsed: Addition\n"); (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1981 "2107119.tab.c"
    break;

  case 66: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 268 "2107119.y"
                                              { if (mode_intermediate == 1) printf("Parsed: Subtraction\n"); (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1987 "2107119.tab.c"
    break;

  case 67: /* multiplicative_expr: unary_expr  */
#line 272 "2107119.y"
               { (yyval.num) = (yyvsp[0].num); }
#line 1993 "2107119.tab.c"
    break;

  case 68: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 273 "2107119.y"
                                          { if (mode_intermediate == 1) printf("Parsed: Multiplication\n"); (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1999 "2107119.tab.c"
    break;

  case 69: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 274 "2107119.y"
                                           { if (mode_intermediate == 1) printf("Parsed: Division\n"); (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 2005 "2107119.tab.c"
    break;

  case 70: /* unary_expr: postfix_expr  */
#line 278 "2107119.y"
                 { (yyval.num) = (yyvsp[0].num); }
#line 2011 "2107119.tab.c"
    break;

  case 71: /* unary_expr: INC unary_expr  */
#line 279 "2107119.y"
                     { if (mode_intermediate == 1) printf("Parsed: Pre-increment\n"); (yyval.num) = (yyvsp[0].num) + 1; }
#line 2017 "2107119.tab.c"
    break;

  case 72: /* unary_expr: DEC unary_expr  */
#line 280 "2107119.y"
                     { if (mode_intermediate == 1) printf("Parsed: Pre-decrement\n"); (yyval.num) = (yyvsp[0].num) - 1; }
#line 2023 "2107119.tab.c"
    break;

  case 73: /* unary_expr: MINUS unary_expr  */
#line 281 "2107119.y"
                       { if (mode_intermediate == 1) printf("Parsed: Unary Minus\n"); (yyval.num) = -(yyvsp[0].num); }
#line 2029 "2107119.tab.c"
    break;

  case 74: /* unary_expr: BIT_NOT unary_expr  */
#line 282 "2107119.y"
                         { if (mode_intermediate == 1) printf("Parsed: Bitwise NOT\n"); (yyval.num) = (double)(~((long long)(yyvsp[0].num))); }
#line 2035 "2107119.tab.c"
    break;

  case 75: /* postfix_expr: primary_expr  */
#line 286 "2107119.y"
                 { (yyval.num) = (yyvsp[0].num); }
#line 2041 "2107119.tab.c"
    break;

  case 76: /* postfix_expr: postfix_expr INC  */
#line 287 "2107119.y"
                       { if (mode_intermediate == 1) printf("Parsed: Post-increment\n"); (yyval.num) = (yyvsp[-1].num); }
#line 2047 "2107119.tab.c"
    break;

  case 77: /* postfix_expr: postfix_expr DEC  */
#line 288 "2107119.y"
                       { if (mode_intermediate == 1) printf("Parsed: Post-decrement\n"); (yyval.num) = (yyvsp[-1].num); }
#line 2053 "2107119.tab.c"
    break;

  case 78: /* primary_expr: IDENTIFIER  */
#line 292 "2107119.y"
               { (yyval.num) = get_symbol_value((yyvsp[0].str)); }
#line 2059 "2107119.tab.c"
    break;

  case 79: /* primary_expr: INTEGER_LIT  */
#line 293 "2107119.y"
                  { (yyval.num) = (yyvsp[0].num); }
#line 2065 "2107119.tab.c"
    break;

  case 80: /* primary_expr: FLOAT_LIT  */
#line 294 "2107119.y"
                { (yyval.num) = (yyvsp[0].num); }
#line 2071 "2107119.tab.c"
    break;

  case 81: /* primary_expr: CHAR_LIT  */
#line 295 "2107119.y"
               { (yyval.num) = (yyvsp[0].num); }
#line 2077 "2107119.tab.c"
    break;

  case 82: /* primary_expr: LPAREN expression RPAREN  */
#line 296 "2107119.y"
                               { (yyval.num) = (yyvsp[-1].num); }
#line 2083 "2107119.tab.c"
    break;

  case 83: /* primary_expr: built_in_function  */
#line 297 "2107119.y"
                        { (yyval.num) = (yyvsp[0].num); }
#line 2089 "2107119.tab.c"
    break;

  case 84: /* primary_expr: FUNC_CALL LPAREN primary_expr RPAREN  */
#line 298 "2107119.y"
                                           { if (mode_intermediate == 1) printf("Parsed: Function Call\n"); (yyval.num) = 0; }
#line 2095 "2107119.tab.c"
    break;

  case 85: /* primary_expr: IDENTIFIER LPAREN argument_list_opt RPAREN  */
#line 299 "2107119.y"
                                                 { if (mode_intermediate == 1) printf("Parsed: Function Call\n"); (yyval.num) = 0; }
#line 2101 "2107119.tab.c"
    break;

  case 90: /* built_in_function: SUM LPAREN expression COMMA expression RPAREN  */
#line 313 "2107119.y"
                                                  { (yyval.num) = (yyvsp[-3].num) + (yyvsp[-1].num); if (mode_intermediate == 1) printf("Parsed: sum() Function\n");
        if (mode_output == 1) printf("Execution: Add result = %g\n", (yyval.num)); }
#line 2108 "2107119.tab.c"
    break;

  case 91: /* built_in_function: MULTIPLY LPAREN expression COMMA expression RPAREN  */
#line 315 "2107119.y"
                                                         { (yyval.num) = (yyvsp[-3].num) * (yyvsp[-1].num); if (mode_intermediate == 1) printf("Parsed: multiply() Function\n");
        if (mode_output == 1) printf("Execution: Mult result = %g\n", (yyval.num)); }
#line 2115 "2107119.tab.c"
    break;

  case 92: /* built_in_function: DIVISION LPAREN expression COMMA expression RPAREN  */
#line 317 "2107119.y"
                                                         {
        if ((yyvsp[-1].num) == 0) {
            (yyval.num) = 0;
            if (mode_output == 1) printf("Execution: Division by zero is invalid\n");
        } else {
            (yyval.num) = (yyvsp[-3].num) / (yyvsp[-1].num);
            if (mode_output == 1) printf("Execution: Div result = %g\n", (yyval.num));
        }
        if (mode_intermediate == 1) printf("Parsed: division() Function\n");
      }
#line 2130 "2107119.tab.c"
    break;

  case 93: /* built_in_function: EVEN_ODD LPAREN expression RPAREN  */
#line 327 "2107119.y"
                                        { (yyval.num) = ((long long)(yyvsp[-1].num)) % 2 == 0; if (mode_intermediate == 1) printf("Parsed: even/odd Function\n");
        if (mode_output == 1) printf("Execution: Is Even = %s\n", (yyval.num) ? "true" : "false"); }
#line 2137 "2107119.tab.c"
    break;

  case 94: /* built_in_function: FACTORIAL LPAREN expression RPAREN  */
#line 329 "2107119.y"
                                         {
        int n = (int)(yyvsp[-1].num);
        if (n < 0) {
            (yyval.num) = 0;
            if (mode_output == 1) printf("Execution: Factorial undefined for negative numbers\n");
        } else {
            (yyval.num) = fact(n);
            if (mode_output == 1) printf("Execution: Factorial of %d = %.0f\n", n, (yyval.num));
        }
        if (mode_intermediate == 1) printf("Parsed: factorial Function\n");
      }
#line 2153 "2107119.tab.c"
    break;

  case 95: /* built_in_function: POWER LPAREN expression COMMA expression RPAREN  */
#line 340 "2107119.y"
                                                      { (yyval.num) = pow((yyvsp[-3].num), (yyvsp[-1].num)); if (mode_intermediate == 1) printf("Parsed: power Function\n");
        if (mode_output == 1) printf("Execution: Power result = %g\n", (yyval.num)); }
#line 2160 "2107119.tab.c"
    break;

  case 96: /* built_in_function: PRIME LPAREN expression RPAREN  */
#line 342 "2107119.y"
                                     { 
        int n = (int)(yyvsp[-1].num);
        int p = 1;
        if(n <= 1) p = 0;
        for(int i = 2; i * i <= n; i++) { if(n % i == 0) { p = 0; break; } }
        (yyval.num) = p;
        if (mode_intermediate == 1) printf("Parsed: prime Function\n");
        if (mode_output == 1) printf("Execution: Is Prime = %s\n", (yyval.num) ? "true" : "false"); 
      }
#line 2174 "2107119.tab.c"
    break;

  case 97: /* built_in_function: PALINDROME LPAREN expression RPAREN  */
#line 351 "2107119.y"
                                          {
        int n = (int)(yyvsp[-1].num);
        int x = n < 0 ? -n : n;
        int rev = 0;
        int tmp = x;
        while (tmp > 0) {
            rev = rev * 10 + (tmp % 10);
            tmp /= 10;
        }
        (yyval.num) = (x == rev);
        if (mode_intermediate == 1) printf("Parsed: palindrome Function\n");
        if (mode_output == 1) printf("Execution: Is Palindrome = %s\n", (yyval.num) ? "true" : "false");
      }
#line 2192 "2107119.tab.c"
    break;

  case 98: /* built_in_function: PALINDROME LPAREN STRING_LIT RPAREN  */
#line 364 "2107119.y"
                                              {
                (yyval.num) = is_palindrome_str((yyvsp[-1].str));
                if (mode_intermediate == 1) printf("Parsed: palindrome Function\n");
                if (mode_output == 1) printf("Execution: Is Palindrome = %s\n", (yyval.num) ? "true" : "false");
            }
#line 2202 "2107119.tab.c"
    break;

  case 99: /* built_in_function: LEAP_YEAR LPAREN expression RPAREN  */
#line 369 "2107119.y"
                                             {
                int y = (int)(yyvsp[-1].num);
                (yyval.num) = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
                if (mode_intermediate == 1) printf("Parsed: leap_year Function\n");
                if (mode_output == 1) printf("Execution: Is Leap Year = %s\n", (yyval.num) ? "true" : "false");
            }
#line 2213 "2107119.tab.c"
    break;

  case 100: /* built_in_function: SIN LPAREN expression RPAREN  */
#line 375 "2107119.y"
                                   { (yyval.num) = sin(deg_to_rad((yyvsp[-1].num))); if (mode_intermediate == 1) printf("Parsed: sin Function\n");
        if (mode_output == 1) printf("Execution: Sin(%g deg) = %.6f\n", (yyvsp[-1].num), (yyval.num)); }
#line 2220 "2107119.tab.c"
    break;

  case 101: /* built_in_function: COS LPAREN expression RPAREN  */
#line 377 "2107119.y"
                                   { (yyval.num) = cos(deg_to_rad((yyvsp[-1].num))); if (mode_intermediate == 1) printf("Parsed: cos Function\n");
        if (mode_output == 1) printf("Execution: Cos(%g deg) = %.6f\n", (yyvsp[-1].num), (yyval.num)); }
#line 2227 "2107119.tab.c"
    break;

  case 102: /* built_in_function: TAN LPAREN expression RPAREN  */
#line 379 "2107119.y"
                                   { (yyval.num) = tan(deg_to_rad((yyvsp[-1].num))); if (mode_intermediate == 1) printf("Parsed: tan Function\n");
        if (mode_output == 1) printf("Execution: Tan(%g deg) = %.6f\n", (yyvsp[-1].num), (yyval.num)); }
#line 2234 "2107119.tab.c"
    break;


#line 2238 "2107119.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 383 "2107119.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error (line %d): %s near '%s'\n", yylineno, s, yytext ? yytext : "EOF");
}

int main(int argc, char **argv) {
    int choice;
    printf("1. Intermediate code generation\n");
    printf("2. Output\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        choice = 2; // Default to output if read fails
    }
    
    if (choice == 1) {
        mode_intermediate = 1;
    } else if (choice == 2) {
        mode_output = 1;
    }
    
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    }
    yyparse();
    if(yyin) fclose(yyin);
    return 0;
}
