%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    int count_line=1;
%}

%option yylineno
%option noyywrap
alfabeto_min [a-z]
alfabeto_mai [A-Z]
digito [0-9]

%%

"INT"                  { printf("[%s]: TK_TIPO_INT\n",yytext); return TK_TIPO_INT; }
"FLOAT"                     { printf("[%s]: TK_TIPO_FLOAT\n",yytext); return TK_TIPO_FLOAT; }
"CHAR"                      { printf("[%s]: TK_TIPO_CHAR\n",yytext) ; return TK_TIPO_CHAR; }
"VAZIO"                      { printf("[%s]: TK_TIPO_VAZIO\n",yytext); return TK_TIPO_VAZIO; }
"STRING"                     { printf("[%s]: TK_TIPO_STRING\n",yytext); return TK_TIPO_STRING; }
"CLASSE"                     { printf("[%s]: TK_CLASSE\n",yytext); return TK_CLASSE; }
"ESCREVA"                    { printf("[%s]: TK_ESCREVA\n",yytext); return TK_ESCREVA; }
"LEIA"                     { printf("[%s]: TK_LEIA\n",yytext); return TK_LEIA; }
"RETORNE"                    { printf("[%s]: TK_RETORN\n",yytext); return TK_RETORNE; }
"PARA"	                    { printf("[%s]: TK_PARA\n",yytext); return TK_PARA; }
"SE"	                    { printf("[%s]: TK_SE\n",yytext); return TK_SE; }
"SENAO"	                    { printf("[%s]: TK_TIPO_SENAO\n",yytext); return TK_SENAO; }
^"#INCLUDE"[ ]*<.+\.h>      { printf("[%s]: TK_TIPO_INCLUDE\n",yytext); return TK_INCLUDE; }
"VERDADEIRO"                      { printf("[%s]: TK_VERDADEIRO\n",yytext); return TK_VERDADEIRO; }
"FALSO"                     { printf("[%s]: TK_ESCREVA\n",yytext); return TK_FALSO; }
[-]?{digito}+                { printf("[%s]: TK_INT\n",yytext); return TK_INT; }
[-]?{digito}+\.{digito}{1,6}  { printf("[%s]: TK_FLOAT\n",yytext); return TK_FLOAT; }
["].*["]                    { printf("[%s]: TK_STRING\n",yytext); return TK_STRING; }
['].[']                     { printf("[%s]: TK_CHAR\n",yytext); return TK_CHAR; }
{alfabeto_mai}{alfabeto_min}*                        { printf("[%s]: TK_NOME_CLASSE\n",yytext); return TK_NOME_CLASSE; }
{alfabeto_min}({alfabeto_min}|{digito}|[_])*   { printf("[%s]: TK_ID\n",yytext); return TK_ID; }
"<="                        { printf("[%s]: TK_MENOR_IGUAL\n",yytext); return TK_MENOR_IGUAL; }
">="                        { printf("[%s]: TK_MAIOR_IGUAL\n",yytext); return TK_MAIOR_IGUAL; }
"=="                        { printf("[%s]: TK_IGUALDADE\n",yytext); return TK_IGUALDADE; }
"!="                        { printf("[%s]: TK_DIFERENTE\n",yytext); return TK_DIFERENTE; }
">"	                    { printf("[%s]: TK_MAIOR\n",yytext); return TK_MAIOR; }
"<"	                    { printf("[%s]: TK_MENOR\n",yytext); return TK_MENOR; }
"&&"	                    { printf("[%s]: TK_AND\n",yytext); return TK_AND; }
"||"	                    { printf("[%s]: TK_OR\n",yytext); return TK_OR; }
"+"                         { printf("[%s]: TK_SOMA\n",yytext); return TK_SOMA; }
"-"                         { printf("[%s]: TK_SUBTRACAO\n",yytext); return TK_SUBTRACAO; }
"/"                         { printf("[%s]: TK_DIVISAO\n",yytext); return TK_DIVISAO; }
"*"                         { printf("[%s]: TK_MULTIPLICACAO\n",yytext); return TK_MULTIPLICACAO; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { count_line++; }
.	                    { return *yytext; } 


%%