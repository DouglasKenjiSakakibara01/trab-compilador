%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"lex.yy.c"

void yyerror(const char *s);
int yylex();
//int yywrap();
void add(char);
void insert_type();
int search(char *);

struct data {
        int line;
        char * name;
        char * data_type;
        char * type;
        
} symbol_table[40];

int count=0; // quantidade de estruturas presentes no codigo
int query;
char type[10];
extern int count_line; // representa a linha do codigo analisada 
%}

%define parse.error verbose

%token TK_TIPO TK_IDENTIFICADOR TK_PONTO_VIRGULA TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INTEIRO TK_TIPO_STRING TK_PARA TK_ENQUANTO TK_NUMERO
TK_SE TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_IGUALDADE TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE TK_FLOAT TK_VERDADEIRO TK_FALSO
TK_LEIA TK_CARACTER TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE TK_CABECALHO TK_TIPO_VAZIO TK_CLASSE TK_COMENTARIO
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR 

%start prog

%%
/*
program: headers main '(' ')' '{' body return '}';


headers: headers headers 
| TK_CABECALHO
;

main: type TK_IDENTIFICADOR /*{add('f');}
;
*/
/*
prog: TK_TIPO TK_IDENTIFICADOR '(' listVar ')' '{' corpoFunc '}'
    | TK_TIPO_VAZIO TK_IDENTIFICADOR '(' listVar ')' '{' corpoFunc '}' {clear();} prog
    | '#' TK_INCLUDE biblioteca prog 
    | {$$ = NULL}
    ;
*/
prog: TK_TIPO TK_IDENTIFICADOR '(' ')' '{' '}'
    | TK_TIPO TK_IDENTIFICADOR '('  ')' '{' '}' prog
    | TK_INCLUDE prog 
    ;
/*
biblioteca:'\"' TK_IDENTIFICADOR '\"' 
          | '\"' TK_IDENTIFICADOR  '.' TK_IDENTIFICADOR '\"'
          ;
*/
chamaVar: TK_IDENTIFICADOR 
        | TK_IDENTIFICADOR'[' expr ']' 
   | TK_IDENTIFICADOR '=' expr 
   | TK_IDENTIFICADOR'[' expr ']' '=' '{' expr '}' 
        | TK_IDENTIFICADOR',' chamaVar 
        | TK_IDENTIFICADOR'[' expr ']' ',' chamaVar 
        | TK_IDENTIFICADOR'=' expr ',' chamaVar 
   | TK_IDENTIFICADOR'[' expr ']' '=' '{' expr '}' ',' chamaVar 
   ;
body: statement ';' 
|TK_PARA /*{ add('k'); }*/  '(' statement ';' condition ';' statement ')' '{' body '}'
| TK_SE /*{ add('k'); }*/ '(' condition ')' '{' body '}' else
//| statement ';' 
| body // corrigir para n dar o loop
| TK_ESCREVA /*{ add('k'); }*/ '(' TK_STRING ')' ';'
| TK_LEIA /*{ add('k'); }*/ '(' TK_STRING ',' '&' TK_IDENTIFICADOR ')' ';'
;

else: TK_SENAO /*{ add('k'); }*/ '{' body '}' ;

condition: value op value 
| TK_VERDADEIRO 
| TK_FALSO
;


value: TK_NUMERO /*{ add('c');}*/
| TK_FLOAT /*{ add('c');}*/
| TK_CARACTER /*{ add('c');}*/
| TK_IDENTIFICADOR
;  


statement: type TK_IDENTIFICADOR /*{ add('v'); }*/ 
| type TK_IDENTIFICADOR /*{ add('v');}*/ '=' expr 
| TK_IDENTIFICADOR '=' expr
| statement '=' expr    
| TK_IDENTIFICADOR op expr
|
;


op: TK_MAIOR
| TK_MAIOR_IGUAL
| TK_IGUALDADE
| TK_MENOR
| TK_MENOR_IGUAL
| TK_DIFERENTE
;

type: 
    TK_TIPO_CHAR
| TK_TIPO_FLOAT
| TK_TIPO_INTEIRO
| TK_TIPO_STRING  
|
;

expr:
    value        //{ $$ = $1; }
| expr '+' expr  //{ $$ = $1 + $3; }
| expr '-' expr  //{ $$ = $1 - $3; }
| expr '*' expr  //{ $$ = $1 * $3; }
| expr '/' expr  //{ $$ = $1 / $3; }
| '(' expr ')'   //{ $$ = $2; }
;

return: TK_RETORNE /*{ add('k'); }*/ value ';' 
;
%%

int main() {
    yyparse();
    for(int i=0; i<count; i++) {
      printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line);
    }
    for(int i=0;i<count;i++) {
      free(symbol_table[i].name);
      free(symbol_table[i].type);
    }
    printf("\n\n");
  }

int search(char *type) {
      int i;
      for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].name, type)==0) {
          return -1;
          break;
        }
      }
      return 0;
    }
    /*
    h — headers
    k — Keywords
    v — Variables
    c — Constants(value)
    f — Functions
    */
    void add(char c) {
      query=search(yytext);
      if(!query) {
        if(c == 'h') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("header");
          count++;
        }
        else if(c == 'k') {
          symbol_table[count].name=strdup(yytext);
          //symbol_table[count].data_type=strdup("N/A");
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("keyword\t");
          count++;
        }
        else if(c == 'v') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("variable");
          count++;
        }
        else if(c == 'c') {
          symbol_table[count].name=strdup(yytext);
          //symbol_table[count].data_type=strdup("CONST");
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("constant");
          count++;
        }
        else if(c == 'f') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("function");
          count++;
        }
      }
      else{
        printf("");
      }
    }
void insert_type() {
      strcpy(type, yytext);
}

void yyerror(const char* msg) {
        fprintf(stderr, "%s\n", msg);
}