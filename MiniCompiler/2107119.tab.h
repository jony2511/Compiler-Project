/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_2107119_TAB_H_INCLUDED
# define YY_YY_2107119_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_TYPE = 258,                /* INT_TYPE  */
    FLOAT_TYPE = 259,              /* FLOAT_TYPE  */
    DOUBLE_TYPE = 260,             /* DOUBLE_TYPE  */
    CHAR_TYPE = 261,               /* CHAR_TYPE  */
    VOID_TYPE = 262,               /* VOID_TYPE  */
    STRUCT_TYPE = 263,             /* STRUCT_TYPE  */
    ENUM_TYPE = 264,               /* ENUM_TYPE  */
    IF = 265,                      /* IF  */
    ELSE_IF = 266,                 /* ELSE_IF  */
    ELSE = 267,                    /* ELSE  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    WHILE = 271,                   /* WHILE  */
    DO_WHILE = 272,                /* DO_WHILE  */
    FOR = 273,                     /* FOR  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    RETURN = 276,                  /* RETURN  */
    MAIN = 277,                    /* MAIN  */
    FUNC_DEF = 278,                /* FUNC_DEF  */
    FUNC_CALL = 279,               /* FUNC_CALL  */
    SUM = 280,                     /* SUM  */
    MULTIPLY = 281,                /* MULTIPLY  */
    DIVISION = 282,                /* DIVISION  */
    EVEN_ODD = 283,                /* EVEN_ODD  */
    FACTORIAL = 284,               /* FACTORIAL  */
    POWER = 285,                   /* POWER  */
    PRIME = 286,                   /* PRIME  */
    PALINDROME = 287,              /* PALINDROME  */
    LEAP_YEAR = 288,               /* LEAP_YEAR  */
    SIN = 289,                     /* SIN  */
    COS = 290,                     /* COS  */
    TAN = 291,                     /* TAN  */
    PRINTF = 292,                  /* PRINTF  */
    SCANF = 293,                   /* SCANF  */
    PLUS = 294,                    /* PLUS  */
    MINUS = 295,                   /* MINUS  */
    STAR = 296,                    /* STAR  */
    SLASH = 297,                   /* SLASH  */
    ASSIGN = 298,                  /* ASSIGN  */
    EQ = 299,                      /* EQ  */
    NEQ = 300,                     /* NEQ  */
    LT = 301,                      /* LT  */
    GT = 302,                      /* GT  */
    LE = 303,                      /* LE  */
    GE = 304,                      /* GE  */
    AND_OP = 305,                  /* AND_OP  */
    OR_OP = 306,                   /* OR_OP  */
    BIT_AND = 307,                 /* BIT_AND  */
    BIT_OR = 308,                  /* BIT_OR  */
    BIT_XOR = 309,                 /* BIT_XOR  */
    BIT_NOT = 310,                 /* BIT_NOT  */
    SHIFT_L = 311,                 /* SHIFT_L  */
    SHIFT_R = 312,                 /* SHIFT_R  */
    INC = 313,                     /* INC  */
    DEC = 314,                     /* DEC  */
    LBRACE = 315,                  /* LBRACE  */
    RBRACE = 316,                  /* RBRACE  */
    LPAREN = 317,                  /* LPAREN  */
    RPAREN = 318,                  /* RPAREN  */
    LBRACKET = 319,                /* LBRACKET  */
    RBRACKET = 320,                /* RBRACKET  */
    SEMI = 321,                    /* SEMI  */
    COMMA = 322,                   /* COMMA  */
    COLON = 323,                   /* COLON  */
    ARROW_R = 324,                 /* ARROW_R  */
    ARROW_L = 325,                 /* ARROW_L  */
    INTEGER_LIT = 326,             /* INTEGER_LIT  */
    FLOAT_LIT = 327,               /* FLOAT_LIT  */
    CHAR_LIT = 328,                /* CHAR_LIT  */
    STRING_LIT = 329,              /* STRING_LIT  */
    IDENTIFIER = 330               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 100 "2107119.y"

    int ival;
    double num;
    char *str;

#line 145 "2107119.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_2107119_TAB_H_INCLUDED  */
