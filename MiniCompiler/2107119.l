%{
#include "2107119.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap yylineno

%%

[ \t\n\r]+              { /* Ignore whitespace */ }
"//"[\^\n]*           { /* Single-line comment: // ... */ }
"/*"([^*]|[*]+[^*/])*[*]+"/" { /* Multi-line comment: /* ... */ }

"num"                   { return INT_TYPE; }
"dec"                   { return FLOAT_TYPE; }
"huge"                  { return DOUBLE_TYPE; }
"letter"                { return CHAR_TYPE; }
"empty"                 { return VOID_TYPE; }
"schema"                { return STRUCT_TYPE; }
"choices"               { return ENUM_TYPE; }

"maybe"                 { return IF; }
"alt"                   { return ELSE_IF; }
"otherwise"             { return ELSE; }
"match"                 { return SWITCH; }
"option"                { return CASE; }
"fallback"              { return DEFAULT; }
"repeat"                { return WHILE; }
"do_repeat"             { return DO_WHILE; }
"loop"                  { return FOR; }
"stop"                  { return BREAK; }
"next"                  { return CONTINUE; }
"giveback"              { return RETURN; }

"nubula"                { return MAIN; }
"task"                  { return FUNC_DEF; }
"call"                  { return FUNC_CALL; }

"add"                   { return SUM; }
"mult"                  { return MULTIPLY; }
"div"                   { return DIVISION; }
"is_even"               { return EVEN_ODD; }
"calc_fact"             { return FACTORIAL; }
"calc_pow"              { return POWER; }
"is_prime"              { return PRIME; }
"is_palin"              { return PALINDROME; }
"is_leap"               { return LEAP_YEAR; }
"calc_sin"              { return SIN; }
"calc_cos"              { return COS; }
"calc_tan"              { return TAN; }

"display"               { return PRINTF; }
"intake"                { return SCANF; }

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return STAR; }
"/"                     { return SLASH; }
"="                     { return ASSIGN; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"<"                     { return LT; }
">"                     { return GT; }
"<="                    { return LE; }
">="                    { return GE; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }
"&"                     { return BIT_AND; }
"|"                     { return BIT_OR; }
"^"                     { return BIT_XOR; }
"!"                     { return BIT_NOT; }
"<<"                    { return SHIFT_L; }
">>"                    { return SHIFT_R; }
"++"                    { return INC; }
"--"                    { return DEC; }

"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"["                     { return LBRACKET; }
"]"                     { return RBRACKET; }
";"                     { return SEMI; }
","                     { return COMMA; }
":"                     { return COLON; }
"~>"                    { return ARROW_R; }
"<~"                    { return ARROW_L; }

[0-9]+                  { yylval.num = (double)atoi(yytext); return INTEGER_LIT; }
[0-9]+"."[0-9]+         { yylval.num = atof(yytext); return FLOAT_LIT; }
\'[^\']\'               { yylval.num = yytext[1]; return CHAR_LIT; }
\"[^\"]*\"              { 
                            char tmp[256];
                            strncpy(tmp, yytext+1, strlen(yytext)-2);
                            tmp[strlen(yytext)-2] = '\0';
                            yylval.str = strdup(tmp); 
                            return STRING_LIT; 
                        }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }

.                       { fprintf(stderr, "Lexical Error (line %d): unknown token '%s'\n", yylineno, yytext); }

%%
