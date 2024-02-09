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

"INT"                  { strcpy(yylval.node_struct.name,(yytext));printf("[%s]: TK_TIPO_INT\n",yytext); return TK_TIPO_INT; }
"FLOAT"                     {strcpy(yylval.node_struct.name,(yytext));  printf("[%s]: TK_TIPO_FLOAT\n",yytext); return TK_TIPO_FLOAT; }
"CHAR"                      { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_TIPO_CHAR\n",yytext) ; return TK_TIPO_CHAR; }
"VAZIO"                      { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_TIPO_VAZIO\n",yytext); return TK_TIPO_VAZIO; }
"STRING"                     { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_TIPO_STRING\n",yytext); return TK_TIPO_STRING; }
"CLASSE"                     { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_CLASSE\n",yytext); return TK_CLASSE; }
"ESCREVA"                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_ESCREVA\n",yytext); return TK_ESCREVA; }
"LEIA"                     { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_LEIA\n",yytext); return TK_LEIA; }
"RETORNE"                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_RETORNE\n",yytext); return TK_RETORNE; }
"PARA"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_PARA\n",yytext); return TK_PARA; }
"SE"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_SE\n",yytext); return TK_SE; }
"SENAO"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_TIPO_SENAO\n",yytext); return TK_SENAO; }
^"#INCLUDE"[ ]*<.+\.h>      { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_TIPO_INCLUDE\n",yytext); return TK_INCLUDE; }
"VERDADEIRO"                      { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_VERDADEIRO\n",yytext); return TK_VERDADEIRO; }
"FALSO"                     { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_ESCREVA\n",yytext); return TK_FALSO; }
[-]?{digito}+                { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_INT\n",yytext); return TK_INT; }
[-]?{digito}+\.{digito}{1,6}  { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_FLOAT\n",yytext); return TK_FLOAT; }
["].*["]                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_STRING\n",yytext); return TK_STRING; }
['].[']                     { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_CHAR\n",yytext); return TK_CHAR; }
{alfabeto_mai}{alfabeto_min}*                        { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_NOME_CLASSE\n",yytext); return TK_NOME_CLASSE; }
{alfabeto_min}({alfabeto_min}|{digito}|[_])*   { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_ID\n",yytext); return TK_ID; }
"<="                        { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_MENOR_IGUAL\n",yytext); return TK_MENOR_IGUAL; }
">="                        { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_MAIOR_IGUAL\n",yytext); return TK_MAIOR_IGUAL; }
"=="                        { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_IGUALDADE\n",yytext); return TK_IGUALDADE; }
"!="                        { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_DIFERENTE\n",yytext); return TK_DIFERENTE; }
">"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_MAIOR\n",yytext); return TK_MAIOR; }
"<"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_MENOR\n",yytext); return TK_MENOR; }
"&&"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_AND\n",yytext); return TK_AND; }
"||"	                    { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_OR\n",yytext); return TK_OR; }
"+"                         { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_SOMA\n",yytext); return TK_SOMA; }
"-"                         { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_SUBTRACAO\n",yytext); return TK_SUBTRACAO; }
"/"                         { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_DIVISAO\n",yytext); return TK_DIVISAO; }
"*"                         { strcpy(yylval.node_struct.name,(yytext)); printf("[%s]: TK_MULTIPLICACAO\n",yytext); return TK_MULTIPLICACAO; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { count_line++; }
.	                    { return *yytext; } 


%%
/*
int yywrap() {
    return 1;
}
*/