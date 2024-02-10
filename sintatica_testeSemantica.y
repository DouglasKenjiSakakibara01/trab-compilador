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
    void check_declaration(char *);
    void check_return(char *);
    int check_type(char *, char *);
    char *get_type(char *);
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
    //int label=0;
    char buffer[100];
    int count_errors=0;
    char errors[50][100];
    int ic_idx=0;
    char icg[50][100];

    
%}
%union { 
	struct node_type { 
		char name[100]; 
		struct node* nd;
	} node_struct; 

  struct node_type2 { 
		char name[100]; 
		struct node* nd;
    char type[5];
	} node_struct2; 

} 
%define parse.error verbose
%token <node_struct> TK_ID  TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INT TK_TIPO_STRING TK_PARA TK_INT
TK_SE TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE TK_FLOAT TK_VERDADEIRO TK_FALSO
TK_LEIA TK_CHAR TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE  TK_TIPO_VAZIO TK_CLASSE 
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR  TK_NOME_CLASSE TK_IGUALDADE 

%type <node_struct> program headers method class class_atributes class_body parameters 
return body else statement statement_atributes op condition arithmetic type 

%type <node_struct2> value expression

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
| type TK_ID  {add('v');} '=' expression  /*{ 
	$2.nd = add_node(NULL, NULL, $2.name); 
	int t = check_type($1.name, $5.type); 
  if (t==0){
      $$.nd = add_node($2.nd, $5.nd, "statement2"); 
  }    
  sprintf(icg[ic_idx++], "%s = %s\n", $2.name, $5.name);
}*/
| TK_ID { check_declaration($1.name); } '=' expression /*{
	$1.nd = add_node(NULL, NULL, $1.name); 
	char *id_type = get_type($1.name); 
	//int t = check_type(id_type, $4.type); 
  if(!strcmp(id_type, $4.type)){
	  $$.nd = add_node($1.nd, $4.nd, "statement3"); 
    sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $4.name);
  }
}*/
| TK_ID { check_declaration($1.name); } op expression //{$1.nd = add_node(NULL, NULL, $1.name); $$.nd = add_node($1.nd, $4.nd, "statement4");}
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
expression: expression arithmetic expression /*{
  if(!strcmp($1.type, $3.type)) {
		sprintf($$.type, $1.type);
		$$.nd = add_node($1.nd, $3.nd, $2.name); 
	}
  else{
		sprintf(errors[count_errors], "Linha %d: as expressoes possuem tipos diferentes\n", count_line+1);    
  }
  sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
}*/
| '(' expression arithmetic expression ')'/*{
  if(!strcmp($2.type, $4.type)) {
		sprintf($$.type, $2.type);
		$$.nd = add_node($2.nd, $4.nd, $2.name); 
	}
  else{
		sprintf(errors[count_errors], "Linha %d: as expressoes possuem tipos diferentes\n", count_line+1);    
  }
}*/
| value //{ $$.nd = $1.nd; sprintf($$.type, $1.type); strcpy($$.name, $1.name); }
| expression TK_AND expression //{add_node($1.nd, $3.nd, "expresion4");}
| expression TK_OR expression //{add_node($1.nd, $3.nd, "expresion5");}

| '(' value ')' //{ $$.nd = $2.nd; sprintf($$.type, $2.type); strcpy($$.name, $2.name); }
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
| TK_DIFERENTE 
;

value: TK_INT {add('c');} //{ strcpy($$.name, $1.name); sprintf($$.type, "INT"); $$.nd = add_node(NULL, NULL, $1.name); }
| TK_FLOAT {add('c');} //{ strcpy($$.name, $1.name); sprintf($$.type, "FLOAT"); $$.nd = add_node(NULL, NULL, $1.name); }
| TK_CHAR {add('c');} //{ strcpy($$.name, $1.name); sprintf($$.type, "CHAR"); $$.nd = add_node(NULL, NULL, $1.name); }
| TK_STRING {add('c');} //{ strcpy($$.name, $1.name); sprintf($$.type, "STRING"); $$.nd = add_node(NULL, NULL, $1.name); }
| TK_ID  {check_declaration($1.name);} //{ strcpy($$.name, $1.name); char *id_type = get_type($1.name); sprintf($$.type, id_type);$$.nd = add_node(NULL, NULL, $1.name); }
;

return: TK_RETORNE {add('k');} value ';' //{ check_return($3.name); $1.nd = add_node(NULL, NULL, "RETURN"); $$.nd = add_node($1.nd, $3.nd, "RETURN"); }
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
    
    printf(" Quantidade de erros:%d\n",count_errors);
    for(int i=0; i<count_errors; i++)
      printf("%s\n",errors[i]);
  }
void check_declaration(char *c) {    
    query = search(c);    
    if(!query) {        
        sprintf(errors[count_errors], "Linha %d: variavel ou atributo %s nao foi declarada\n", count_line, c);    
        count_errors++;    
    }
}  

int check_type(char *type1, char *type2){
	
	if(!strcmp(type2, "null"))
		return -1;

	if(!strcmp(type1, type2))
		return 0;
  if(!strcmp(type1, "FLOAT") && !strcmp(type2, "INT"))
    sprintf(errors[count_errors], "Linha %d: esperado tipo float porem recebeu tipo int\n", count_line);    
    count_errors++;  
		
	if(!strcmp(type1, "INT") && !strcmp(type2, "FLOAT"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo int porem recebeu tipo float\n", count_line);    
    count_errors++;  

	if(!strcmp(type1, "INT") && !strcmp(type2, "CHAR"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo int porem recebeu tipo char\n", count_line);    
    count_errors++;  

	if(!strcmp(type1, "CHAR") && !strcmp(type2, "INT"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo char porem recebeu tipo int\n", count_line);    
    count_errors++;  

	if(!strcmp(type1, "FLOAT") && !strcmp(type2, "CHAR"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo float porem recebeu tipo char\n", count_line);    
    count_errors++;  

	if(!strcmp(type1, "CHAR") && !strcmp(type2, "FLOAT"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo char porem recebeu tipo float\n", count_line);    
    count_errors++;  

  if(!strcmp(type1, "INT") && !strcmp(type2, "STRING"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo int porem recebeu tipo string\n", count_line);    
    count_errors++;  

  if(!strcmp(type1, "CHAR") && !strcmp(type2, "STRING"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo float porem recebeu tipo int\n", count_line);    
    count_errors++;  

  if(!strcmp(type1, "FLOAT") && !strcmp(type2, "STRING"))
		sprintf(errors[count_errors], "Linha %d: esperado tipo float porem recebeu tipo int\n", count_line);    
    count_errors++;  
 

}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		if(!strcmp(symbol_table[i].name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void check_return(char *value) {
	char *main_datatype = get_type("method");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "INT") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[count_errors], "Linha %d: retorno nao esperado\n", count_line);
		count_errors++;
	}
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
      //query=search(yytext);
      query=search(yylval.node_struct.name);

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
      // caso a variavel/atributo ja tenha sido adicionada
      else if((c == 'v' || c == 'a') && query) {
        
        sprintf(errors[count_errors], "Linha %d: a variavel/atributo %s ja foi declarada \n", count_line, yylval.node_struct.name);

		    count_errors++;
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