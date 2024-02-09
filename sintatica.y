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
    void print_tree(struct node *);
    struct node* add_node(struct node *left, struct node *right, char *tk);


    struct data {
            int line;
            char * name;
            char * data_type;
            char * type;
            
    } symbol_table[40];
    
    struct node { 
        struct node *left; 
        struct node *right; 
        char *tk; 
    };
    int count=0; // quantidade de estruturas presentes no codigo
    int query;
    char type[10];
    extern int count_line; // representa a linha do codigo analisada 
    struct node *head; // comeco da arvore
    

    
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
TK_LEIA TK_CHAR TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE  TK_TIPO_VAZIO TK_CLASSE 
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR  TK_NOME_CLASSE TK_IGUALDADE

%type <node_struct> program headers method class class_atributes class_body parameters 
return body else statement statement_atributes op condition arithmetic value type expression

%%

program: headers program {$$.nd = add_node($1.nd, $2.nd, "program"); head = $$.nd;}
| class program {$$.nd = add_node($1.nd, $2.nd, "program"); }
|{ $$.nd = NULL; };
;

headers: TK_INCLUDE {add('h');} {$$.nd = add_node(NULL, NULL, "INCLUDE");}
|TK_INCLUDE {add('h');} headers {$$.nd = add_node($3.nd, NULL, "INCLUDE2");}
;

class: TK_CLASSE TK_NOME_CLASSE {add('s');} '{' class_body '}'  {$$.nd = add_node($5.nd, NULL, "class");}
;

class_body: class_atributes class_body {$$.nd = add_node($1.nd, $2.nd, "class_body_atributes");}
|  TK_NOME_CLASSE TK_ID {add('o');}'=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';' class_body {$$.nd = add_node($1.nd, $2.nd, "class_body_object");}
|  method '(' parameters ')' '{' body return '}' class_body{
   struct node *aux = add_node($6.nd, $7.nd, "class_body_method_aux");
   struct node *aux2 = add_node(&*aux, $9.nd, "class_body_method_aux2");
   struct node *aux3 = add_node($1.nd, $3.nd, "class_body_method_aux3");
   $$.nd = add_node(aux3, aux2, "class_body_method");
}
|  {$$.nd = NULL;}
;

class_atributes: statement_atributes ';' {$$.nd = add_node($1.nd, NULL, "class_atributes");}
;

statement_atributes:  type TK_ID {add('a');} '=' expression {$$.nd = add_node($1.nd, $5.nd, "statement_atributes2");}
| type TK_ID {add('a');} {$$.nd = add_node($1.nd, NULL, "statement_atributes2");}
;

method: type TK_ID {add('m');} {$$.nd = add_node($1.nd, NULL, "method");}
;


parameters: type TK_ID',' parameters {$$.nd = add_node($1.nd, $4.nd, "parameters");}
| type TK_ID {$$.nd = add_node($1.nd, NULL, "parameters2");}
| {$$.nd = NULL;}
;

//tentar tirar essa recursao a esquerda 
body: TK_PARA {add('k');} '(' statement ';' condition ';' statement ')' '{' body '}'{
  struct node *aux = add_node($6.nd, $8.nd, "body_for_aux"); 
  struct node *aux2 = add_node($4.nd, aux, "body_for_aux2"); 
  $$.nd = add_node(aux2, $11.nd, "body_for"); 
}
/*
| TK_SE {add('k');} '(' condition ')' '{' body '}' else {
  struct node *aux = add_node($4.nd, $7.nd, "body_if_aux"); 
  $$.nd = add_node(aux, $9.nd, "body_if");
}
*/
| TK_SE {add('k');} '(' condition ')' '{' body '}' {$$.nd = add_node($4.nd, $7.nd, "body_if");}
| else {  $$.nd = add_node($1.nd, NULL, "body_if");} 
| statement ';' {$$.nd = add_node($1.nd, NULL, "body_statement");}
| TK_NOME_CLASSE TK_ID {add('o');} '=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';' {$$.nd = add_node(NULL, NULL, "body_object");}
| body body  {$$.nd = add_node($1.nd, $2.nd, "body");}
| TK_ESCREVA {add('k');} '(' TK_STRING ')' ';' {$$.nd = add_node(NULL, NULL, "body_printf");}
| TK_LEIA {add('k');} '(' TK_STRING ',' '&' TK_ID ')' ';' {$$.nd = add_node(NULL, NULL, "body_scanf");}
;

else: TK_SENAO {add('k');} '{' body '}' {$$.nd = add_node($4.nd, NULL, "else_body");}
| {$$.nd = NULL;}
;


statement: type TK_ID {add('v');} {$$.nd = add_node($1.nd, NULL, "statement1");}
| type TK_ID  {add('v');} '=' expression  {$$.nd = add_node($1.nd, $5.nd, "statement2");}
| TK_ID '=' expression {$$.nd = add_node($3.nd, NULL, "statement3");}
| TK_ID op expression {$$.nd = add_node($2.nd, $3.nd, "statement4");}
;


type: TK_TIPO_INT {insert_type();} {$$.nd = add_node(NULL, NULL, "type_int");}
| TK_TIPO_FLOAT {insert_type();} {$$.nd = add_node(NULL, NULL, "type_float");}
| TK_TIPO_CHAR {insert_type();} {$$.nd = add_node(NULL, NULL, "type_char");}
| TK_TIPO_STRING {insert_type();} {$$.nd = add_node(NULL, NULL, "type_string");}
| TK_TIPO_VAZIO {insert_type();} {$$.nd = add_node(NULL, NULL, "type_void");}
;


condition: value op value  {
  struct node *aux = add_node($2.nd, $3.nd, "condition_aux"); 
  $$.nd = add_node($1.nd, aux, "condition");
}
| TK_VERDADEIRO {add('k');} {$$.nd = add_node(NULL, NULL, "condition_true");}
| TK_FALSO {add('k');} {$$.nd = add_node(NULL, NULL, "condition_false");}
| expression TK_IGUALDADE expression {$$.nd = add_node($1.nd, $3.nd, "condition_equal");}
;

//tentar tirar a recursao a esquerda
expression: expression arithmetic expression {
  struct node *aux = add_node($2.nd, $3.nd, "expression1_aux"); 
  $$.nd = add_node($1.nd, aux, "expression1");
}
| '(' expression arithmetic expression ')'{
  struct node *aux = add_node($3.nd, $4.nd, "expression2_aux"); 
  $$.nd = add_node($2.nd, aux, "expression2");
}
| value {$$.nd = add_node($1.nd, NULL, "expresion3");}
| expression TK_AND expression {add_node($1.nd, $3.nd, "expresion4");}
| expression TK_OR expression {add_node($1.nd, $3.nd, "expresion5");}
| '(' value ')' {add_node($2.nd, NULL, "expresion6");}
;

arithmetic: TK_SOMA {$$.nd = add_node(NULL, NULL, "arithmetic_sum");}
| TK_SUBTRACAO  {$$.nd = add_node(NULL, NULL, "arithmetic_sub");}
| TK_MULTIPLICACAO {$$.nd = add_node(NULL, NULL, "arithmetic_mult");}
| TK_DIVISAO {$$.nd = add_node(NULL, NULL, "arithmetic_div");}
;

op: TK_MAIOR {$$.nd = add_node(NULL, NULL, "op_>");}
| TK_MAIOR_IGUAL {$$.nd = add_node(NULL, NULL, "op_>=");}
| TK_MENOR {$$.nd = add_node(NULL, NULL, "op_<");}
| TK_MENOR_IGUAL {$$.nd = add_node(NULL, NULL, "op_<=");}
| TK_DIFERENTE {$$.nd = add_node(NULL, NULL, "op_!=");}
;

value: TK_INT {add('c');} {$$.nd = add_node(NULL, NULL, "value_int");}
| TK_FLOAT {add('c');} {$$.nd = add_node(NULL, NULL, "value_float");}
| TK_CHAR {add('c');} {$$.nd = add_node(NULL, NULL, "value_char");}
| TK_ID  
;

return: TK_RETORNE {add('k');} value ';' {$$.nd = add_node($3.nd, NULL, "return");}
| {$$.nd = NULL;}
;

%%

// falta tratar para rodar com mais de um arquivo 
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
    print_tree(head);
    printf("\n\n");
    
  }

int search(char *name) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)==0) {
			return -1;
			break;
		}
	}
	return 0;
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
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("header");
          count++;
        }
        else if(c == 'k') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup("N/A");
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("keyword\t");
          count++;
        }
        else if(c == 'v') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("variable");
          count++;
        }
        else if(c == 'c') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup("CONST");
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("constant");
          count++;
        }
        else if(c == 'm') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("method");
          count++;
        }
        else if(c == 's') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("class");
          count++;
        }

        else if(c == 'a') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("attribute");
          count++;
        }
        else if(c == 'p') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("parameter");
          count++;
        }
        else if(c == 'o') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("object");
          count++;
        }
      }
      
    }
    
void insert_type() {
      //strcpy(type, yytext);
      strcpy(type, yylval.node_struct.name);
}


struct node* add_node(struct node *left, struct node *right, char *tk) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(tk)+1);
	strcpy(newstr, tk);
	newnode->left = left;
	newnode->right = right;
	newnode->tk = newstr;
	return(newnode);
}
// percorre a arvore usando a forma in-ordem
void print_tree(struct node *tree) {
	int i;
	if (tree->left) {
		print_tree(tree->left);
	}
	printf("%s, ", tree->tk);
	if (tree->right) {
		print_tree(tree->right);
	}
}


void yyerror(const char* msg) {
        fprintf(stderr, "%s\n", msg);
}