%{
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
%}

%union {
    int ival;
    double num;
    char *str;
}

%token INT_TYPE FLOAT_TYPE DOUBLE_TYPE CHAR_TYPE VOID_TYPE STRUCT_TYPE ENUM_TYPE
%token IF ELSE_IF ELSE SWITCH CASE DEFAULT WHILE DO_WHILE FOR BREAK CONTINUE RETURN
%token MAIN FUNC_DEF FUNC_CALL SUM MULTIPLY DIVISION EVEN_ODD FACTORIAL POWER PRIME PALINDROME LEAP_YEAR SIN COS TAN
%token PRINTF SCANF
%token PLUS MINUS STAR SLASH ASSIGN EQ NEQ LT GT LE GE AND_OP OR_OP BIT_AND BIT_OR BIT_XOR BIT_NOT SHIFT_L SHIFT_R INC DEC
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET SEMI COMMA COLON ARROW_R ARROW_L

%token <num> INTEGER_LIT FLOAT_LIT CHAR_LIT
%token <str> STRING_LIT IDENTIFIER

%type <num> expression assignment_expr logical_or_expr logical_and_expr equality_expr relational_expr additive_expr multiplicative_expr unary_expr postfix_expr primary_expr built_in_function
%type <ival> type_specifier

%start program

%%

program:
    elements
    ;

elements:
    element
    | elements element
    ;

element:
    declaration
    | MAIN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: MAIN program\n"); }
    | function_def
    ;

declaration:
    type_specifier IDENTIFIER SEMI {
        declare_symbol($2, $1, 0);
        if (mode_intermediate == 1) printf("Parsed: Variable Declaration\n");
      }
    | type_specifier IDENTIFIER ASSIGN expression SEMI {
        int idx = declare_symbol($2, $1, $4);
        if (idx >= 0 && (symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR) && fabs($4 - floor($4)) > 1e-9) {
            fprintf(stderr, "Semantic Warning (line %d): implicit narrowing conversion for '%s'\n", yylineno, $2);
        }
        if (idx >= 0 && (symtab[idx].type == TYPE_INT || symtab[idx].type == TYPE_CHAR)) {
            symtab[idx].value = (long long)$4;
        }
        if (mode_intermediate == 1) printf("Parsed: Variable Declaration with Initialization\n");
      }
    | type_specifier IDENTIFIER LPAREN RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: Variable/Function Declaration\n"); }
    | type_specifier SEMI { if (mode_intermediate == 1) printf("Parsed: Struct/Enum Forward Declaration\n"); }
    ;

function_def:
    FUNC_DEF type_specifier IDENTIFIER LPAREN parameters RPAREN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: Function Definition\n"); }
    ;

type_specifier:
    INT_TYPE { $$ = TYPE_INT; }
    | FLOAT_TYPE { $$ = TYPE_FLOAT; }
    | DOUBLE_TYPE { $$ = TYPE_DOUBLE; }
    | CHAR_TYPE { $$ = TYPE_CHAR; }
    | VOID_TYPE { $$ = TYPE_VOID; }
    | STRUCT_TYPE { $$ = TYPE_STRUCT; }
    | ENUM_TYPE { $$ = TYPE_ENUM; }
    ;

parameters:
    /* empty */
    | parameter_list
    ;

parameter_list:
    type_specifier IDENTIFIER {
        declare_symbol($2, $1, 0);
    }
    | parameter_list COMMA type_specifier IDENTIFIER {
        declare_symbol($4, $3, 0);
    }
    ;

statements:
    /* empty */
    | statements statement
    ;

statement:
    expression SEMI { if (mode_intermediate == 1) printf("Parsed: Expression Statement\n"); }
    | declaration
    | IF LPAREN expression RPAREN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: IF Statement\n"); }
        | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE_IF LPAREN expression RPAREN LBRACE statements RBRACE {
                if (mode_intermediate == 1) printf("Parsed: IF-ELSEIF Statement\n");
            }
        | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE_IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE {
                if (mode_intermediate == 1) printf("Parsed: IF-ELSEIF-ELSE Statement\n");
            }
    | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: IF-ELSE Statement\n"); }
    | WHILE LPAREN expression RPAREN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: WHILE Loop\n"); }
    | DO_WHILE LBRACE statements RBRACE WHILE LPAREN expression RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: DO-WHILE Loop\n"); }
    | FOR LPAREN expression SEMI expression SEMI expression RPAREN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: FOR Loop\n"); }
    | FOR LPAREN declaration expression SEMI expression RPAREN LBRACE statements RBRACE { if (mode_intermediate == 1) printf("Parsed: FOR Loop with declaration\n"); }
    | SWITCH LPAREN expression RPAREN LBRACE cases RBRACE { if (mode_intermediate == 1) printf("Parsed: SWITCH Statement\n"); }
    | PRINTF LPAREN STRING_LIT RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: Printf Statement\n");
        if (mode_output == 1) printf("Output: %s\n", $3); }
    | PRINTF LPAREN expression RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: Printf Statement\n");
        if (mode_output == 1) printf("Output: %g\n", $3); }
    | SCANF LPAREN STRING_LIT RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: Scanf Statement\n"); }
    | SCANF LPAREN expression RPAREN SEMI { if (mode_intermediate == 1) printf("Parsed: Scanf Statement\n"); }
    | BREAK SEMI { if (mode_intermediate == 1) printf("Parsed: Break Statement\n"); }
    | CONTINUE SEMI { if (mode_intermediate == 1) printf("Parsed: Continue Statement\n"); }
    | RETURN expression SEMI { if (mode_intermediate == 1) printf("Parsed: Return Statement\n"); }
    | RETURN SEMI { if (mode_intermediate == 1) printf("Parsed: Return Statement (Void)\n"); }
    ;

cases:
    case_stmt
    | cases case_stmt
    ;

case_stmt:
    CASE expression COLON statements { if (mode_intermediate == 1) printf("Parsed: Case Block\n"); }
    | DEFAULT COLON statements { if (mode_intermediate == 1) printf("Parsed: Default Block\n"); }
    ;

expression:
    assignment_expr { $$ = $1; }
    ;

assignment_expr:
    logical_or_expr { $$ = $1; }
    | IDENTIFIER ASSIGN assignment_expr {
        set_symbol_value($1, $3);
        if (mode_intermediate == 1) printf("Parsed: Assignment\n");
        $$ = $3;
      }
    ;

logical_or_expr:
    logical_and_expr { $$ = $1; }
    | logical_or_expr OR_OP logical_and_expr { if (mode_intermediate == 1) printf("Parsed: Logical OR\n"); $$ = $1 || $3; }
    ;

logical_and_expr:
    equality_expr { $$ = $1; }
    | logical_and_expr AND_OP equality_expr { if (mode_intermediate == 1) printf("Parsed: Logical AND\n"); $$ = $1 && $3; }
    ;

equality_expr:
    relational_expr { $$ = $1; }
    | equality_expr EQ relational_expr { if (mode_intermediate == 1) printf("Parsed: Equality\n"); $$ = $1 == $3; }
    | equality_expr NEQ relational_expr { if (mode_intermediate == 1) printf("Parsed: Inequality\n"); $$ = $1 != $3; }
    ;

relational_expr:
    additive_expr { $$ = $1; }
    | relational_expr LT additive_expr { if (mode_intermediate == 1) printf("Parsed: Less Than\n"); $$ = $1 < $3; }
    | relational_expr GT additive_expr { if (mode_intermediate == 1) printf("Parsed: Greater Than\n"); $$ = $1 > $3; }
    | relational_expr LE additive_expr { if (mode_intermediate == 1) printf("Parsed: Less or Equal\n"); $$ = $1 <= $3; }
    | relational_expr GE additive_expr { if (mode_intermediate == 1) printf("Parsed: Greater or Equal\n"); $$ = $1 >= $3; }
    ;

additive_expr:
    multiplicative_expr { $$ = $1; }
    | additive_expr PLUS multiplicative_expr { if (mode_intermediate == 1) printf("Parsed: Addition\n"); $$ = $1 + $3; }
    | additive_expr MINUS multiplicative_expr { if (mode_intermediate == 1) printf("Parsed: Subtraction\n"); $$ = $1 - $3; }
    ;

multiplicative_expr:
    unary_expr { $$ = $1; }
    | multiplicative_expr STAR unary_expr { if (mode_intermediate == 1) printf("Parsed: Multiplication\n"); $$ = $1 * $3; }
    | multiplicative_expr SLASH unary_expr { if (mode_intermediate == 1) printf("Parsed: Division\n"); $$ = $1 / $3; }
    ;

unary_expr:
    postfix_expr { $$ = $1; }
    | INC unary_expr { if (mode_intermediate == 1) printf("Parsed: Pre-increment\n"); $$ = $2 + 1; }
    | DEC unary_expr { if (mode_intermediate == 1) printf("Parsed: Pre-decrement\n"); $$ = $2 - 1; }
    | MINUS unary_expr { if (mode_intermediate == 1) printf("Parsed: Unary Minus\n"); $$ = -$2; }
    | BIT_NOT unary_expr { if (mode_intermediate == 1) printf("Parsed: Bitwise NOT\n"); $$ = (double)(~((long long)$2)); }
    ;

postfix_expr:
    primary_expr { $$ = $1; }
    | postfix_expr INC { if (mode_intermediate == 1) printf("Parsed: Post-increment\n"); $$ = $1; }
    | postfix_expr DEC { if (mode_intermediate == 1) printf("Parsed: Post-decrement\n"); $$ = $1; }
    ;

primary_expr:
    IDENTIFIER { $$ = get_symbol_value($1); }
    | INTEGER_LIT { $$ = $1; }
    | FLOAT_LIT { $$ = $1; }
    | CHAR_LIT { $$ = $1; }
    | LPAREN expression RPAREN { $$ = $2; }
    | built_in_function { $$ = $1; }
    | FUNC_CALL LPAREN primary_expr RPAREN { if (mode_intermediate == 1) printf("Parsed: Function Call\n"); $$ = 0; }
    | IDENTIFIER LPAREN argument_list_opt RPAREN { if (mode_intermediate == 1) printf("Parsed: Function Call\n"); $$ = 0; }
    ;

argument_list_opt:
    /* empty */
    | argument_list
    ;

argument_list:
    expression
    | argument_list COMMA expression
    ;

built_in_function:
    SUM LPAREN expression COMMA expression RPAREN { $$ = $3 + $5; if (mode_intermediate == 1) printf("Parsed: sum() Function\n");
        if (mode_output == 1) printf("Execution: Add result = %g\n", $$); }
    | MULTIPLY LPAREN expression COMMA expression RPAREN { $$ = $3 * $5; if (mode_intermediate == 1) printf("Parsed: multiply() Function\n");
        if (mode_output == 1) printf("Execution: Mult result = %g\n", $$); }
    | DIVISION LPAREN expression COMMA expression RPAREN {
        if ($5 == 0) {
            $$ = 0;
            if (mode_output == 1) printf("Execution: Division by zero is invalid\n");
        } else {
            $$ = $3 / $5;
            if (mode_output == 1) printf("Execution: Div result = %g\n", $$);
        }
        if (mode_intermediate == 1) printf("Parsed: division() Function\n");
      }
    | EVEN_ODD LPAREN expression RPAREN { $$ = ((long long)$3) % 2 == 0; if (mode_intermediate == 1) printf("Parsed: even/odd Function\n");
        if (mode_output == 1) printf("Execution: Is Even = %s\n", $$ ? "true" : "false"); }
    | FACTORIAL LPAREN expression RPAREN {
        int n = (int)$3;
        if (n < 0) {
            $$ = 0;
            if (mode_output == 1) printf("Execution: Factorial undefined for negative numbers\n");
        } else {
            $$ = fact(n);
            if (mode_output == 1) printf("Execution: Factorial of %d = %.0f\n", n, $$);
        }
        if (mode_intermediate == 1) printf("Parsed: factorial Function\n");
      }
    | POWER LPAREN expression COMMA expression RPAREN { $$ = pow($3, $5); if (mode_intermediate == 1) printf("Parsed: power Function\n");
        if (mode_output == 1) printf("Execution: Power result = %g\n", $$); }
    | PRIME LPAREN expression RPAREN { 
        int n = (int)$3;
        int p = 1;
        if(n <= 1) p = 0;
        for(int i = 2; i * i <= n; i++) { if(n % i == 0) { p = 0; break; } }
        $$ = p;
        if (mode_intermediate == 1) printf("Parsed: prime Function\n");
        if (mode_output == 1) printf("Execution: Is Prime = %s\n", $$ ? "true" : "false"); 
      }
    | PALINDROME LPAREN expression RPAREN {
        int n = (int)$3;
        int x = n < 0 ? -n : n;
        int rev = 0;
        int tmp = x;
        while (tmp > 0) {
            rev = rev * 10 + (tmp % 10);
            tmp /= 10;
        }
        $$ = (x == rev);
        if (mode_intermediate == 1) printf("Parsed: palindrome Function\n");
        if (mode_output == 1) printf("Execution: Is Palindrome = %s\n", $$ ? "true" : "false");
      }
        | PALINDROME LPAREN STRING_LIT RPAREN {
                $$ = is_palindrome_str($3);
                if (mode_intermediate == 1) printf("Parsed: palindrome Function\n");
                if (mode_output == 1) printf("Execution: Is Palindrome = %s\n", $$ ? "true" : "false");
            }
        | LEAP_YEAR LPAREN expression RPAREN {
                int y = (int)$3;
                $$ = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
                if (mode_intermediate == 1) printf("Parsed: leap_year Function\n");
                if (mode_output == 1) printf("Execution: Is Leap Year = %s\n", $$ ? "true" : "false");
            }
    | SIN LPAREN expression RPAREN { $$ = sin(deg_to_rad($3)); if (mode_intermediate == 1) printf("Parsed: sin Function\n");
        if (mode_output == 1) printf("Execution: Sin(%g deg) = %.6f\n", $3, $$); }
    | COS LPAREN expression RPAREN { $$ = cos(deg_to_rad($3)); if (mode_intermediate == 1) printf("Parsed: cos Function\n");
        if (mode_output == 1) printf("Execution: Cos(%g deg) = %.6f\n", $3, $$); }
    | TAN LPAREN expression RPAREN { $$ = tan(deg_to_rad($3)); if (mode_intermediate == 1) printf("Parsed: tan Function\n");
        if (mode_output == 1) printf("Execution: Tan(%g deg) = %.6f\n", $3, $$); }
    ;

%%

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
