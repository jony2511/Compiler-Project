%{
   #include <stdio.h>
   #include <string.h>
   #include <math.h>
   #include <stdlib.h>
%}

variable [a-zA-Z][a-zA-Z0-9]*
single_line_comment "//".*
multiple_line_comment [/][*][A-Za-z0-9. \n]*[*][/]

%%
"#INCLUDE"		{}
"ASSIGN" {printf("=");}
"INT" {printf("integer");}
"FLOAT" {printf("float");}
"CHAR" {printf("char");}
"STRING" {printf("string");}
"BOOL" {printf("boolean");}
{single_line_comment} {
	printf("This is single line comment\n");
}
{multiple_line_comment} {
	printf("This is multiple line comment\n");
}
[-+]?[0-9]+ { 
   int n = atoi(yytext);
   printf("%d", n);
}
[-+]?[0-9]*"."[0-9]+ { 
   float n = atof(yytext);
   printf("%f", n);
}
"SWITCH"  { printf("switch statement"); }
"CASE"    { printf("case statement");  }
"LOOP" {printf("loop statement"); } 
"DEFAULT"  { printf("default of switch-case"); }
"SHOW"    { printf("display"); }
"PLUS" {printf("+");}
"DIV" {printf("/");}
"MULT" {printf("*");}
"MINUS" {printf("-");}
"SUM"         {printf("sum of numbers");}
"Multiply"         {printf("multiply of numbers");}
"EO" {printf("even odd checking");}
"EITHER" {printf("if statement");}
"OR" {printf("else if statement");}
"OTHERWISE" {printf("else statement"); }
"EXIT" {printf("break loop"); }
"WHILE" {printf("while loop");}
"YEAR" { printf("return the year"); }
"DIVISION"  {printf("Division of numbers"); }
"FACTORIAL"         {printf("!");}
"POWER" 	{printf("power sign ^");}
"SIN" {printf("sine operation");}
"COS" {printf("cos operation");}
"TAN" {printf("tan operation");}
"LP" {printf("(");}
"RP" {printf(")");}
"BEGIN" {printf("{");}
"FINISH" {printf("}");}
"CM" {printf(",");}
"SM" {printf(";");}
"CC" {printf(":");}
"LT" {printf("<");}
"GT" {printf(">");}
"INCRE" {printf("++"); }
"DECRE" {printf("--");}
"GTEQ" {printf(">="); }
"LTEQ" {printf("<="); }
"ORR"  {  printf("logical or ||"); }
"AND" {printf("logical and &&"); }
"EQUAL" {printf("=="); }
"NOTEQUAL" {printf("!="); }
"void HORROR" {printf("main function"); }
"RETURN"	{printf("return"); }
"~>"   {printf("end");}
"<~"  {printf("start");}
\"[^\"]*\" { printf("%s", yytext); }
[a-zA-Z] { printf("%s", yytext); }
{variable} { printf("%s",yytext);}
[ ]* { printf(" ");}
[\n]* { printf("\n");}
. { printf(" syntex error ");}
%%

int yywrap(){ return 1; }
int main(){
   yyin = freopen("input.txt","r",stdin);
   yyout = freopen("output.txt","w",stdout);
   yylex();
}
