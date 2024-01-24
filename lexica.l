
%{

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int count_line=0;

%}

%option noyywrap
%option yylineno

pontuacao "("|")"|"{"|"}"|";"
%%

[ \t]         ; // ignora espaços em branco e tabulações 
{pontuacao}   {printf("[%s]: Delimitador\n",yytext);}
[-]?[0-9]+          { printf("[%s]: TK_NUMERO\n",yytext); return TK_NUMERO; }
[-]?[0-9]+\.[0-9]{1,6}   { printf("[%s]: TK_FLOAT\n",yytext); return TK_FLOAT; }
["].*["]        { printf("[%s]: TK_STRING\n",yytext); return TK_STRING; }
['].[']         { printf("[%s]: TK_CARACTER\n",yytext); return TK_CARACTER; }
[a-z_][a-z0-9_]* { printf("[%s]: TK_IDENTIFICADOR\n",yytext); return TK_IDENTIFICADOR; }
"="             { printf("[%s]: Atribuicao\n",yytext);}
"=="            { printf("[%s]: TK_IGUALDADE\n",yytext); return TK_IGUALDADE; }
">"            { printf("[%s]: TK_MAIOR\n",yytext); return TK_MAIOR; }
"<"            { printf("[%s]: TK_MENOR\n",yytext); return TK_MENOR; }
">="           { printf("[%s]: TK_MAIOR_IGUAL\n",yytext); return TK_MAIOR_IGUAL; }
"<="           { printf("[%s]: TK_MENOR_IGUAL\n",yytext); return TK_MENOR_IGUAL; }
"!="           { printf("[%s]: TK_DIFERENTE\n",yytext); return TK_DIFERENTE; }
"INT"          { printf("[%s]: TK_TIPO_INTEIRO\n",yytext); return TK_TIPO_INTEIRO; }
"FLOAT"        { printf("[%s]: TK_TIPO_FLOAT\n",yytext); return TK_TIPO_FLOAT; }
"CHAR"         { printf("[%s]: TK_TIPO_CHAR\n",yytext); return TK_TIPO_CHAR; }
"STRING"       { printf("[%s]: TK_TIPO_STRING\n",yytext); return TK_TIPO_STRING;}
"VAZIO"        { printf("[%s]: TK_TIPO_VAZIO\n",yytext); return TK_TIPO_VAZIO; }
"//"           { printf("[%s]: TK_COMENTARIO\n",yytext); return TK_COMENTARIO; }
"CLASSE"        { printf("[%s]: TK_CLASSE\n",yytext); return TK_CLASSE; }
"PARA"        { printf("[%s]: TK_PARA\n",yytext); return TK_PARA; }
"ENQUANTO"        { printf("[%s]: TK_ENQUANTO\n",yytext); return TK_ENQUANTO; }
"ESCREVA"        { printf("[%s]: TK_ESCREVA\n",yytext); return TK_ESCREVA; }
"SE"        { printf("[%s]: TK_SE\n",yytext); return TK_SE; }
"SENAO"        { printf("[%s]: TK_SENAO\n",yytext); return TK_SENAO; }
"RETORNE"        { printf("[%s]: TK_RETORNE\n",yytext); return TK_RETORNE; }
"LEIA"        { printf("[%s]: TK_LEIA\n",yytext); return TK_LEIA; }
"VERDADEIRO"        { printf("[%s]: TK_VERDADEIRO\n",yytext); return TK_VERDADEIRO; }
"FALSO"        { printf("[%s]: TK_FALSO\n",yytext); return TK_FALSO; }
^"#INCLUDE"[ ]*<.+\.h>           { printf("[%s]: TK_CABECALHO\n",yytext); return TK_CABECALHO; }
[/n]           {count_line++;}

.              { printf("Erro lexico na linha %d: %s\n", yylineno, yytext);} //qualquer outro caractere que nao esteja definido na gramatica
%%
