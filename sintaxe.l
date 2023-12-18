
%{

#include <stdio.h>

%}

%option noyywrap
%option yylineno

%%

[ \t\n]        ; // ignora espaços em branco, tabulações e quebras de linha
[0-9]     { printf("[%s]TOKEN_NUMERO\n", yytext); }
[a-z_][a-z0-9_]* { printf("[%s]: TOKEN_IDENTIFICADOR\n", yytext); }
"("            { printf("[%s]: TOKEN_ABRE_PARENTESES\n",yytext); }
")"            { printf("[%s]: TOKEN_FECHA_PARENTESES\n,yytext"); }
"{"            { printf("[%s]: TOKEN_ABRE_CHAVES\n",yytext); }
"}"            { printf("[%s]: TOKEN_FECHA_CHAVES\n,yytext"); }
":="           { printf("[%s]: TOKEN_ATRIBUICAO\n",yytext); }
"="            { printf("[%s]: TOKEN_IGUALDADE\n",yytext); }
";"            { printf("[%s]:TOKEN_PONTO_VIRGULA\n",yytext); }
.           { printf("Erro de sintaxe na linha %d: %s\n", yylineno, yytext);} //qualquer outro caractere que nao esteja definido na gramatica

%%

int main(){
    yylex();
    return 0;
}