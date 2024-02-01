
%{

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int count_line=0;

%}

%option noyywrap
%option yylineno

/*pontuacao "("|")"|";"|"{"|"}"|"#"*/
pontuacao "("|")"|";"|"{"|"}"|"#"
tipo INT|FLOAT|CHAR

%%

[ \t]         ; // ignora espaços em branco e tabulações 
{pontuacao}   {printf("[%s]: Delimitador\n",yytext); yytext[0];}
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
"&&"	       { printf("[%s]: TK_AND\n",yytext); return TK_AND; }
"||"	       { printf("[%s]: TK_OR\n",yytext); return TK_OR; }
"+"            { printf("[%s]: TK_SOMA\n",yytext); return TK_SOMA; }
"-"            { printf("[%s]: TK_SUBTRACAO\n",yytext); return TK_SUBTRACAO; }
"/"            { printf("[%s]: TK_DIVISAO\n",yytext); return TK_DIVISAO; }
"*"            { printf("[%s]: TK_MULTIPLICACAO\n",yytext); return TK_MULTIPLICACAO; }
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
"#include"        { printf("[%s]: TK_INCLUDE\n",yytext); return TK_INCLUDE; }
{tipo}        { printf("[%s]: TK_TIPO\n",yytext); return TK_TIPO; }


[/n]           {count_line++;}

.              { printf("Erro lexico na linha %d: %s\n", yylineno, yytext);} //qualquer outro caractere que nao esteja definido na gramatica
%%
/*
int yywrap() {
    return 1;
}
*/