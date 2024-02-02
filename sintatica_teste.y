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
    struct node *head; // comeco da arvore
    struct node { 
        struct node *left; 
        struct node *right; 
        char *tk; 
    };
%}
%union { 
	struct node_type { 
		char name[100]; 
		struct node* nd;
	} node_struct; 
} 
%define parse.error verbose
%token <node_struct> TK_ID  TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INT TK_TIPO_STRING TK_PARA TK_INT
TK_SE TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE TK_FLOAT TK_VERDADEIRO TK_FALSO
TK_LEIA TK_CHAR TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE  TK_TIPO_VAZIO TK_CLASSE TK_COMENTARIO
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR TK_IGUALDADE TK_NOME_CLASSE
%%

program: headers program
| class program
|
;

headers: TK_INCLUDE {add('h');}
|TK_INCLUDE {add('h');} headers
;

class: TK_CLASSE TK_NOME_CLASSE {add('s');} '{' class_body '}'
;

class_body: class_atributes class_body
|  TK_NOME_CLASSE TK_ID {add('o');}'=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';' class_body 
|  method '(' parameters ')' '{' body return '}' class_body
|
;

class_atributes: statement_atributes ';' 
;

statement_atributes:  type TK_ID {add('a');}
| type TK_ID {add('a');}'=' expression // nao esta inserindo as variaveis dentro do metodo na tabela de simbolo
;

method: type TK_ID {add('m');}
;


parameters: type TK_ID',' parameters
| type TK_ID 
|
;

body: TK_PARA {add('c');} '(' statement ';' condition ';' statement ')' '{' body '}'
| TK_SE {add('c');} '(' condition ')' '{' body '}' else
| statement ';'
| TK_NOME_CLASSE TK_ID {add('o');} '=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';'
| body body   //tentar tirar essa recursao a esquerda
| TK_ESCREVA {add('c');} '(' TK_STRING ')' ';'
| TK_LEIA {add('c');} '(' TK_STRING ',' '&' TK_ID ')' ';'
;

else: TK_SENAO {add('c');} '{' body '}'
|
;


statement: type TK_ID {add('v');}
| type TK_ID  {add('v');} '=' expression 
| TK_ID '=' expression 
| TK_ID op expression
;


type: TK_TIPO_INT {insert_type();}
| TK_TIPO_FLOAT {insert_type();}
| TK_TIPO_CHAR {insert_type();}
| TK_TIPO_STRING {insert_type();}
| TK_TIPO_VAZIO {insert_type();}
;


condition: value op value 
| TK_VERDADEIRO {add('k');}
| TK_FALSO {add('k');}
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

value: TK_INT {add('c');}
| TK_FLOAT {add('c');}
| TK_CHAR {add('c');}
| TK_ID 
;

return: TK_RETORNE {add('k');} value ';' 
|
;

%%



int main() {
    yyparse();
    printf("-*-*-*-*-*-* Tabela de simbolos -*-*-*-*-**-*-*--*-\n");
    for(int i=0; i<count; i++) {
      printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line);
    }
    for(int i=0;i<count;i++) {
      free(symbol_table[i].name);
      free(symbol_table[i].type);
    }
    printf("\n\n");

	printf("-*-*-*-*-*-* Arvore sintatica -*-*-*-*-**-*-*--*-\n\n");
	printtree(head); 
	printf("\n\n");
  }
    /*
    h - headers
    k - keywords
    v - variables
    c - constants(value)
    m - methods
    s - class
    a - attribute
    p - parameters
    o - objects
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
          symbol_table[count].data_type=strdup("N/A");
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
          symbol_table[count].data_type=strdup("CONST");
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("constant");
          count++;
        }
        else if(c == 'm') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("method");
          count++;
        }
        else if(c == 's') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("class");
          count++;
        }

        else if(c == 'a') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("attribute");
          count++;
        }
        else if(c == 'p') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("parameter");
          count++;
        }
        else if(c == 'o') {
          symbol_table[count].name=strdup(yytext);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("object");
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
struct node* add_node(struct node *left, struct node *right, char *tk) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->tk = newstr;
	return(newnode);
}
/*
void printtree(struct node* tree) {
	printf("\n\n Inorder traversal of the Parse Tree: \n\n");
	printInorder(tree);
	printf("\n\n");
}
*/

void print_tree(struct node *tree) {
	int i;
	if (tree->left) {
		print_tree(tree->left);
	}
	printf("%s, ", tree->token);
	if (tree->right) {
		print_tree(tree->right);
	}
}

void yyerror(const char* msg) {
        fprintf(stderr, "%s\n", msg);
}