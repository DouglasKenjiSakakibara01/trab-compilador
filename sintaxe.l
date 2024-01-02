
%{

#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap
%option yylineno

%{
#define TOKEN_ABRE_PARENTESES 1
#define TOKEN_FECHA_PARENTESES 2
#define TOKEN_ABRE_CHAVES 3
#define TOKEN_FECHA_CHAVES 4
#define TOKEN_IGUALDADE 5
#define TOKEN_ATRIBUICAO 6
#define TOKEN_CLASS 7
#define TOKEN_COMENTARIO 8
#define TOKEN_IDENTIFICADOR 9
#define TOKEN_MAIOR 10
#define TOKEN_MENOR 11
#define TOKEN_MAIOR_IGUAL 12
#define TOKEN_MENOR_IGUAL 13
#define TOKEN_TIPO_INTEIRO 14
#define TOKEN_TIPO_FLOAT 15
#define TOKEN_TIPO_CHAR 16
#define TOKEN_TIPO_STRING 17
#define TOKEN_PONTO_VIRGULA 18
#define TOKEN_DIGITO 19







%}

%%

[ \t\n]        ; // ignora espaços em branco, tabulações e quebras de linha
[0-9]+          { printf("[%s]: TOKEN_DIGITO\n",yytext); return TOKEN_DIGITO; }
[a-z_][a-z0-9_]* { printf("[%s]: TOKEN_IDENTIFICADOR\n",yytext); return TOKEN_IDENTIFICADOR; }
"("            { printf("[%s]: TOKEN_ABRE_PARENTESES\n",yytext); return TOKEN_ABRE_PARENTESES; }
")"            { printf("[%s]: TOKEN_FECHA_PARENTESES\n",yytext); return TOKEN_FECHA_PARENTESES; }
"{"            { printf("[%s]: TOKEN_ABRE_CHAVES\n",yytext); return TOKEN_ABRE_CHAVES; }
"}"            { printf("[%s]: TOKEN_FECHA_PARENTESES\n",yytext); return TOKEN_FECHA_CHAVES; }
":="           { printf("[%s]: TOKEN_ATRIBUICAO\n",yytext); return TOKEN_ATRIBUICAO; }
"="            { printf("[%s]: TOKEN_IGUALDADE\n",yytext); return TOKEN_IGUALDADE; }
";"            { printf("[%s]: TOKEN_PONTO_VIRGULA\n",yytext); return TOKEN_PONTO_VIRGULA; }
">"            { printf("[%s]: TOKEN_MAIOR\n",yytext); return TOKEN_MAIOR; }
"<"            { printf("[%s]: TOKEN_MENOR\n",yytext); return TOKEN_MENOR; }
">="           { printf("[%s]: TOKEN_MAIOR_IGUAL\n",yytext); return TOKEN_MAIOR_IGUAL; }
"<="           { printf("[%s]: TOKEN_MENOR_IGUAL\n",yytext); return TOKEN_MENOR_IGUAL; }
"INT"          { printf("[%s]: TOKEN_TIPO_INTEIRO\n",yytext); return TOKEN_TIPO_INTEIRO;}
"FLOAT"        { printf("[%s]: TOKEN_TIPO_FLOAT\n",yytext); return TOKEN_TIPO_FLOAT; }
"CHAR"         { printf("[%s]: TOKEN_TIPO_CHAR\n",yytext); return TOKEN_TIPO_CHAR; }
"STRING"       { printf("[%s]: TOKEN_TIPO_STRING\n",yytext); return TOKEN_TIPO_STRING;  }
"//"           { printf("[%s]: TOKEN_COMENTARIO\n",yytext); return TOKEN_COMENTARIO;   }
"CLASS"        { printf("[%s]: TOKEN_CLASS\n",yytext); return TOKEN_CLASS;  }
.              { printf("Erro de sintaxe na linha %d: %s\n", yylineno, yytext);} //qualquer outro caractere que nao esteja definido na gramatica
%%

int main(){
    yylex();
    return 0;
}