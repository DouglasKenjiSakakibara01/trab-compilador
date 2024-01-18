%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"lex.yy.c"

void yyerror(const char *s);
int yylex();

    
%}


%token TK_TIPO TK_IDENTIFICADOR TK_PONTO_VIRGULA TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INTEIRO TK_TIPO_STRING TK_PARA TK_ENQUANTO TK_NUMERO
TK_PARA TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_IGUALDADE TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE


%%
body: TK_PARA '(' statement ';' condition ';' statement ')' '{' body '}'
| TK_SE '(' condition ')' '{' body '}' else
| statement ';' 
| body body
| TK_ESCREVA '(' TK_STRING ')' ';'
| TK_LEIA '(' TK_STRING ',' '&' TK_IDENTIFICADOR ')' ';'
;

else: TK_SENAO '{' body '}'
|
;

condition: value relop value 
| TK_VERDADEIRO 
| TK_FALSO
;

value: TK_NUMERO
| FLOAT_NUM
| TK_CARACTER
| TK_IDENTIFICADOR
;  
statement: 
    tipo TK_IDENTIFICADOR 
  ;
statement: datatype ID init/tipo TK_IDENTIFICADOR 
  |TK_IDENTIFICADOR '=' expr
  |statement '=' expr    
  |TK_IDENTIFICADOR op expr
  |ID UNARY 
  |UNARY ID
;

init: '=' value 
|
;

op: TK_MAIOR
| TK_MAIOR_IGUAL
| TK_IGUALDADE
| TK_MENOR
| TK_MENOR_IGUAL
| TK_DIFERENTE
;


tipo: 
    TK_TIPO_CHAR
  |TK_TIPO_FLOAT
  |TK_TIPO_INTEIRO
  |TK_TIPO_STRING  
  ;

expr:
    value        { $$ = $1; }
  | expr '+' expr  { $$ = $1 + $3; }
  | expr '-' expr  { $$ = $1 - $3; }
  | expr '*' expr  { $$ = $1 * $3; }
  | expr '/' expr  { $$ = $1 / $3; }
  | '(' expr ')'   { $$ = $2; }
  ;


%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}