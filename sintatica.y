%{
#include <stdlib.h>
#include <string.h>
#include <math.h>

int yylex();
int yyparse();
void yyerror(const char *);
    
%}
%union{
  double 			num;
	char*   		str;
}

%token TK_TIPO TK_IDENTIFICADOR TK_PONTO_VIRGULA TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INTEIRO TK_TIPO_STRING


%%
declaracao_tipo: tipo TK_IDENTIFICADOR TK_PONTO_VIRGULA {adicionar variavel};
tipo: 
    TK_TIPO_CHAR
  |TK_TIPO_FLOAT
  |TK_TIPO_INTEIRO
  |TK_TIPO_STRING  
  ;

expr:
    TK_NUMERO        { $$ = $1; }
  | expr '+' expr  { $$ = $1 + $3; }
  | expr '-' expr  { $$ = $1 - $3; }
  | expr '*' expr  { $$ = $1 * $3; }
  | expr '/' expr  { $$ = $1 / $3; }
  | '(' expr ')'   { $$ = $2; }
  ;

var:
    TK_IDENTIFICADOR {$$= endereco da variavel}
	| TK_IDENTIFICADOR ',' var{}
  | TK_IDENTIFICADOR '=' expr {}
  ;


%%