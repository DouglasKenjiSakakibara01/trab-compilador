%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    //int yywrap();
%}
%define parse.error verbose
%token TK_ID  TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INT TK_TIPO_STRING TK_PARA TK_INT
TK_SE TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE TK_FLOAT TK_VERDADEIRO TK_FALSO
TK_LEIA TK_CHAR TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE  TK_TIPO_VAZIO TK_CLASSE TK_COMENTARIO
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR TK_IGUALDADE TK_NOME_CLASSE
%%
/*
program: headers main '(' ')' '{' body return '}'
| headers main '(' ')' '{' body return '}' main
;


main: type TK_ID
;


body: TK_PARA'(' statement ';' condition ';' statement ')' '{' body '}'
| TK_SE '(' condition ')' '{' body '}' else
| statement ';' 
| body body
| TK_ESCREVA '(' TK_STRING ')' ';'
| TK_LEIA '(' TK_STRING ',' '&' TK_ID ')' ';'
;

else: TK_SENAO '{' body '}'
|
;
*/
program: headers program
| class program
|
;

class: TK_CLASSE TK_NOME_CLASSE '{' class_body '}'
;

class_body: class_atributes class_body
|  method '(' method_atributs ')' '{' body return '}' class_body
|
;

method: type TK_ID 
;


method_atributs: type TK_ID ',' method_atributs
| type TK_ID
|
;

class_atributes: statement_atributes ';' 
;

statement_atributes:  type TK_ID 
| type TK_ID '=' expression 
;

body: TK_PARA'(' statement ';' condition ';' statement ')' '{' body '}'
| TK_SE '(' condition ')' '{' body '}' else
| statement ';'
| TK_NOME_CLASSE TK_ID'=' TK_CLASSE TK_NOME_CLASSE '(' ')' 
| body body
| TK_ESCREVA '(' TK_STRING ')' ';'
| TK_LEIA '(' TK_STRING ',' '&' TK_ID ')' ';'
;

else: TK_SENAO '{' body '}'
|
;

headers: TK_INCLUDE
|TK_INCLUDE headers
;
statement: type TK_ID
| type TK_ID '=' expression  
| TK_ID '=' expression 
| TK_ID op expression
;


type: TK_TIPO_INT
| TK_TIPO_FLOAT 
| TK_TIPO_CHAR
| TK_TIPO_VAZIO
;


condition: value op value 
| TK_VERDADEIRO 
| TK_FALSO
;


expression: expression arithmetic expression
| '(' expression arithmetic expression ')'
| value
| '(' value ')'
;

arithmetic: TK_SOMA
| TK_SUBTRACAO 
| TK_MULTIPLICACAO
| TK_DIVISAO
;

op: TK_MAIOR
| TK_MAIOR_IGUAL
| TK_MENOR
| TK_MENOR_IGUAL
| TK_IGUALDADE
| TK_DIFERENTE
;

value: TK_INT
| TK_FLOAT
| TK_CHAR
| TK_ID
;

return: TK_RETORNE value ';' 
|
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}