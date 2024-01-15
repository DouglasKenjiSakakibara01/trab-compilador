
%{

#include <stdio.h>
#include <stdlib.h>
#include "sintatica.tab.h"

%}

%option noyywrap
%option yylineno


%%

[ \t\n]        ; // ignora espaços em branco, tabulações e quebras de linha
[0-9]+          { printf("[%s]: TK_NUMERO\n",yytext.num);}
[a-z_][a-z0-9_]* { printf("[%s]: TK_IDENTIFICADOR\n",yytext);}
"("            { printf("[%s]: TK_ABRE_PARENTESES\n",yytext);}
")"            { printf("[%s]: TK_FECHA_PARENTESES\n",yytext);}
"{"            { printf("[%s]: TK_ABRE_CHAVES\n",yytext); }
"}"            { printf("[%s]: TK_FECHA_PARENTESES\n",yytext); }
"="           { printf("[%s]: TK_ATRIBUICAO\n",yytext);}
"=="            { printf("[%s]: TK_IGUALDADE\n",yytext);}
";"            { printf("[%s]: TK_PONTO_VIRGULA\n",yytext); }
">"            { printf("[%s]: TK_MAIOR\n",yytext);}
"<"            { printf("[%s]: TK_MENOR\n",yytext);}
">="           { printf("[%s]: TK_MAIOR_IGUAL\n",yytext);}
"<="           { printf("[%s]: TK_MENOR_IGUAL\n",yytext);}
"TIPO"           { printf("[%s]: TK_TIPO\n",yytext);}
"INT"          { printf("[%s]: TK_TIPO_INTEIRO\n",yytext);}
"FLOAT"        { printf("[%s]: TK_TIPO_FLOAT\n",yytext);}
"CHAR"         { printf("[%s]: TK_TIPO_CHAR\n",yytext);}
"STRING"       { printf("[%s]: TK_TIPO_STRING\n",yytext);}
"//"           { printf("[%s]: TK_COMENTARIO\n",yytext);}
"CLASSE"        { printf("[%s]: TK_CLASSE\n",yytext);}
.              { printf("Erro de sintaxe na linha %d: %s\n", yylineno, yytext);} //qualquer outro caractere que nao esteja definido na gramatica

%%
int main() {
    yylex()
    return 0;
}
