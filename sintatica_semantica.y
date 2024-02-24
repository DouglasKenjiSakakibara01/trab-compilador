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
    int search(const char *);
    void print_tree(struct node *);
    struct node* add_node(struct node *left, struct node *right, char *tk);
    void check_declaration(const char *);
    void check_return();
    void check_type(const char *);
    char *get_type(const char *);
    void aux_check_class();
    int search2(const char *name);
    void check_declaration2(const char *c);
    void aux_name_attribute(const char *c);

    struct data {
            int line;
            char * name;
            char * data_type;
            char * type;
            int scope;
            int scope_class;
            char * name_class;
            
    } symbol_table[100];
    
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
    char buffer[100];
    int count_errors=0;
    char errors[50][100];
    int count_scope = 0;
    int count_scope_class = 0;
    char class_name[30]; // usado para auxiliar na verificacao da classe de um objeto
    char object_name[30]; // usado para auxiliar o acesso a um tributo do objeto
    int index_object = -1;
    char file_name_current[30];
    char name_attribute[30];
    

    
%}
%union { 
	
    struct node_type { 
		char name[50]; 
		struct node* nd;
	} node_struct; 

    struct node_type2 { 
		char name[50]; 
		struct node* nd;
        char type[5];
	} node_struct2;
} 

%define parse.error verbose
%token <node_struct> TK_ID  TK_TIPO_CHAR TK_TIPO_FLOAT TK_TIPO_INT TK_TIPO_STRING TK_PARA TK_INT
TK_SE TK_SENAO TK_MAIOR TK_MAIOR_IGUAL TK_MENOR TK_MENOR_IGUAL TK_DIFERENTE TK_FLOAT TK_VERDADEIRO TK_FALSO
TK_LEIA TK_CHAR TK_STRING TK_ESCREVA TK_INCLUDE TK_RETORNE  TK_TIPO_VAZIO TK_CLASSE 
TK_SOMA, TK_SUBTRACAO, TK_MULTIPLICACAO, TK_DIVISAO TK_AND TK_OR  TK_NOME_CLASSE TK_IGUALDADE TK_CLASSE_PRINCIPAL TK_METODO_MAIN TK_VETOR

%type <node_struct> program headers method class class_atributes class_body parameters 
return body else statement statement_atributes op condition arithmetic  type class_body_main statement_aux
statement_aux2

%type <node_struct2> value expression
%%

program: headers program {$$.nd = add_node($1.nd, $2.nd, "program"); head = $$.nd;}
//| class program {$$.nd = add_node($1.nd, $2.nd, "program"); }
| class {$$.nd = add_node($1.nd, NULL , "program");  head = $$.nd; }
| headers TK_CLASSE_PRINCIPAL {add('s');} '{' class_body_main '}' {
  $2.nd = add_node($5.nd, NULL, "program");//
  $$.nd = add_node($1.nd, $5.nd, "program");  
  head = $$.nd;
}
|{ $$.nd = NULL; }
;

headers: TK_INCLUDE {add('h');} {$$.nd = add_node(NULL, NULL, "INCLUDE");}
|TK_INCLUDE {add('h');} headers {$$.nd = add_node($3.nd, NULL, "INCLUDE");}
|{$$.nd = NULL;}
;

class_body_main: TK_METODO_MAIN {add('m');} '(' parameters ')' '{' body '}' {$$.nd = add_node($4.nd, $7.nd, "class_main");};

class: TK_CLASSE TK_NOME_CLASSE {add('s');} '{' class_body '}'  {$$.nd = add_node($5.nd, NULL, "class");}
;


class_body: class_atributes class_body {$$.nd = add_node($1.nd, $2.nd, "attribute");}
//|  TK_NOME_CLASSE {aux_check_class();} TK_ID {add('o');} ';' class_body {$$.nd = add_node($6.nd, NULL, "object_declaration");}
|  method '(' parameters ')' '{' body return '}' class_body{
   struct node *aux = add_node($6.nd, $7.nd, "body_method");
   struct node *aux2 = add_node(&*aux, $9.nd, "body_method");
   struct node *aux3 = add_node($1.nd, $3.nd, "body_method");
   $$.nd = add_node(aux3, aux2, "class_body_method");
}
|  {$$.nd = NULL;}
;

class_atributes: statement_atributes ';' {$$.nd = add_node($1.nd, NULL, "attributes_declaration");}
;

statement_atributes: TK_NOME_CLASSE {aux_check_class();} TK_ID {add('ao'); $$.nd = add_node(NULL, NULL, "declaration");}
| type TK_ID {add('a');} {$$.nd = add_node($1.nd, NULL, "declaration");}
| type TK_VETOR TK_ID {add('a'); $$.nd = add_node($1.nd, NULL, "declaration"); } 
;

method: type TK_ID {add('m');} {$$.nd = add_node($1.nd, NULL, "method");}
;


parameters: type TK_ID {add('p');} ',' parameters {$$.nd = add_node($1.nd, $5.nd, "parameters");}
| type TK_ID {add('p'); $$.nd = add_node($1.nd, NULL, "parameters");}
| {$$.nd = NULL;}
;

//tentar tirar essa recursao a esquerda 
body: TK_PARA {add('k');} '(' statement ';' condition ';' statement ')' '{' body '}'{
  struct node *aux = add_node($6.nd, $8.nd, "statement_for"); 
  struct node *aux2 = add_node($4.nd, aux, "condition_for"); 
  $$.nd = add_node(aux2, $11.nd, "for"); 
}
/*
| TK_SE {add('k');} '(' condition ')' '{' body '}' else {
  struct node *aux = add_node($4.nd, $7.nd, "body_if_aux"); 
  $$.nd = add_node(aux, $9.nd, "body_if");
}
*/
| TK_SE {add('k');} '(' condition ')' '{' body '}' {$$.nd = add_node($4.nd, $7.nd, "if");}
| else {  $$.nd = add_node($1.nd, NULL, "else");} 
| statement ';' {$$.nd = add_node($1.nd, NULL, "statement");}
| TK_NOME_CLASSE {aux_check_class();} TK_ID {add('o');} ';' {$$.nd = add_node(NULL, NULL, "object");} // declaracao objeto
| body body  {$$.nd = add_node($1.nd, $2.nd, "body");}
| TK_ESCREVA {add('k');} '(' TK_STRING ')' ';' {$$.nd = add_node(NULL, NULL, "printf");}
| TK_LEIA {add('k');} '(' TK_STRING ',' '&' TK_ID ')' ';' {$$.nd = add_node(NULL, NULL, "scanf");}
;

else: TK_SENAO {add('k');} '{' body '}' {$$.nd = add_node($4.nd, NULL, "body_else");}
| {$$.nd = NULL;}
;


statement: type TK_ID {add('v');} {$$.nd = add_node($1.nd, NULL, "statement_id");}
| type TK_ID  {add('v');} '=' expression  {$$.nd = add_node($1.nd, $5.nd, "attribuition_id"); check_type($2.name);}
| type TK_VETOR TK_ID {add('v'); $$.nd = add_node($1.nd, NULL, "statement_array"); } 
| type TK_VETOR TK_ID {add('v');} '=' expression {$$.nd = add_node($1.nd, $6.nd, "attribuition_array"); } 

| TK_ID {check_declaration($1.name);} '=' expression {$$.nd = add_node($4.nd, NULL, "attribuition_id"); check_type($1.name);}
| TK_ID {check_declaration($1.name);} op expression {$$.nd = add_node($3.nd, $4.nd, "expression_logic");}
| TK_ID {check_declaration($1.name);} '['TK_INT']' statement_aux2{$$.nd = add_node($6.nd, NULL, "array");}
| TK_ID { check_declaration($1.name); } '.' TK_ID {check_declaration2($4.name); strcpy(name_attribute, $4.name);} statement_aux {$$.nd = add_node($6.nd, NULL, "acess_object");}
;

statement_aux: '=' expression { $$.nd = add_node($2.nd, NULL, "attribuition_object"); check_type(name_attribute); }
|'(' parameters ')'  {$$.nd = add_node($2.nd, NULL, "acess_method_object");}
| op expression  {$$.nd = add_node($1.nd, $2.nd, "expression_logic_object");}
|'(' parameters ')' op expression {
  struct node *aux = add_node($2.nd, $5.nd, "expression_logic"); 
  $$.nd = add_node(aux, $4.nd, "expression_logic_object");
}
| {$$.nd = NULL;}
;

statement_aux2:'=' expression {$$.nd = add_node($2.nd, NULL, "attribuition_array");}
| op expression {$$.nd = add_node($1.nd, $2.nd, "array_logic");}
| {$$.nd = NULL;}
;


type: TK_TIPO_INT {insert_type();} 
| TK_TIPO_FLOAT {insert_type();} 
| TK_TIPO_CHAR {insert_type();} 
| TK_TIPO_STRING {insert_type();} 
| TK_TIPO_VAZIO {insert_type();} 
;


condition: value op value  {
  struct node *aux = add_node($2.nd, $3.nd, "expression_condition"); 
  $$.nd = add_node($1.nd, aux, "expression_condition");
}
| TK_VERDADEIRO {add('k'); $$.nd = NULL;}
| TK_FALSO {add('k'); $$.nd = NULL;}
| expression TK_IGUALDADE expression {$$.nd = add_node($1.nd, $3.nd, "condition_equal");}
;


expression: expression arithmetic expression {
  struct node *aux = add_node($2.nd, $3.nd, "expression_arithmetic"); 
  $$.nd = add_node($1.nd, aux, "expression1");
}
| '(' expression arithmetic expression ')'{
  struct node *aux = add_node($3.nd, $4.nd, "expression_arithmetic"); 
  $$.nd = add_node($2.nd, aux, "expression2");
}
| value {$$.nd = add_node($1.nd, NULL, "value");}
| expression TK_AND expression {add_node($1.nd, $3.nd, "expresion_and");}
| expression TK_OR expression {add_node($1.nd, $3.nd, "expresion_or");}
| '(' value ')' {add_node($2.nd, NULL, "value");}
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

value: TK_INT {add('c');} {$$.nd = add_node(NULL, NULL, "value_int");}
| TK_FLOAT {add('c');} {$$.nd = add_node(NULL, NULL, "value_float");}
| TK_CHAR {add('c');} {$$.nd = add_node(NULL, NULL, "value_char");}
| TK_STRING {add('c');} {$$.nd = add_node(NULL, NULL, "value_string");}
| TK_ID {check_declaration($1.name);} 
;

return: TK_RETORNE {add('k');} value ';' {$$.nd = add_node($3.nd, NULL, "return"); check_return();}
| {$$.nd = NULL;}
;

%%

int main(int argc, char **argv) {
    int i;
    printf("%s\n", argv[i]);
    for (i = 1; i < argc; i++) {
        strcpy(file_name_current, argv[i]);
        FILE *fp = fopen(argv[i], "r");
        count_line=1;
        if (fp == NULL) {
            printf("Erro: O arquivo %s nao pode ser aberto\n", argv[i]);
            return 1;
          }
          
          
        // yyin é uma variavel do tipo FILE* and aponta para o arquivo de entrada
        yyin = fp;

        yyparse();

        fclose(fp);
        printf("\n\n");
        printf("-*-*-*-*-*-* Arvore sintatica - %s -*-*-*-*-**-*-*--*-\n\n", argv[i]);
        print_tree(head);
        printf("\n\n");
    }
    
    
    printf("-*-*-*-*-*-* Tabela de simbolos -*-*-*-*-**-*-*--*-\n");
    for(int i=0; i<count; i++) {
      printf("%-30s\t%-10s\t%-10s\t%-10d\t%-10d\t%-10d\t%-30s\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].scope, symbol_table[i].scope_class, symbol_table[i].line, symbol_table[i].name_class);
    }
    for(int i=0;i<count;i++) {
      free(symbol_table[i].name);
      free(symbol_table[i].type);
    }
   
    printf("Quantidade de erros:%d\n",count_errors);
    for(int i=0; i<count_errors; i++) {
      printf("%s\n",errors[i]);
    } 
    
    
  }
// usado para verificar a declaracao de variaveis e atributos   
void check_declaration(const char *c) {    
    query = search(c);    
    if(query == -1) {        
        sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A estrutura %s nao foi declarada\n", file_name_current, count_line, c);    
        count_errors++;    
    }
    else{
      if(strcmp(symbol_table[query].type, "object") == 0){
        index_object = query;

      }
      
    }
}
// usado para verificar a declaracao metodos e atributos de uma classe referenciado por um objeto 
void check_declaration2(const char *c) {    
    query = search2(c);    
    if(query ==-1) {        
        sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A estrutura %s sendo acessado pelo objeto nao foi declarada\n", file_name_current, count_line, c);    
        count_errors++;    
    }
}
// utilizada somente para auxiliar a funcao de adicionar informacoes na tabela de simbolos
int check_value(const char *c){
  int v_float=-1;
  for (int i = 1; i < 50; i++) {
        if (c[i] == '.') {
            v_float=1;
            break;
        }
    }
  if(c[0] =='\''){
    return 0;
  }
  else if(c[0] == '"'){
    return 1;
  }
  else if(v_float == 1){
    return 2;
  }
  else{
    return 3;
  }
}
void check_type(const char * c1){
  int i;
  int index_var=-1;
  int index_value=count-1;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, c1)==0) {
      index_var=i;
		}
	}
  if(index_var!=-1){
    if(strcmp(symbol_table[index_var].data_type, symbol_table[index_value].data_type)){
      sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A estrutura %s do tipo %s recebe um valor do tipo %s\n", file_name_current, count_line, symbol_table[index_var].name, symbol_table[index_var].data_type, symbol_table[index_value].data_type);    
      count_errors++;  
    }
  }
}

void aux_check_class() {
  strcpy(class_name, yylval.node_struct.name);
}

int check_class(){
  int i;

  for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, class_name )==0) {
      return i;
		}
	}
  sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A classe referenciada pelo objeto nao existe \n", file_name_current, count_line);    
  count_errors++;  

	return -1;

}

// procura um nome na tabela de simbolos
int search(const char *name) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)==0) {
      if(symbol_table[i].scope == count_scope || strcmp(symbol_table[i].type, "attribute") == 0){
			  return i;
			  break;
		}
    } 
	}
	return -1;
} 
// verifica se o atributo/metodo sendo acessado atraves do objeto foi declarado
int search2(const char *name) {
 	int index_class=-1;
  for(int i=count-1; i>=0; i--){
    if(strcmp(symbol_table[i].name, symbol_table[index_object].name_class)==0){
     index_class=i;
    }
  }
	for(int j=count-1; j>=0; j--) {
		if(strcmp(symbol_table[j].name, name)==0) {
      if(index_object !=-1 && index_class !=-1){
        // verifica se atributo ou metodo acessado está no objeto da classe e nao em outra 
        if((strcmp(symbol_table[j].type, "attribute") == 0) || (strcmp(symbol_table[j].type, "method") == 0) && symbol_table[index_class].scope_class == symbol_table[j].scope_class){
          index_object = 0;
          return j;
        }
      }
      
      
    } 
	}
	return -1;
} 
 

// verifica se as declaracoes de variaveis estao no mesmo escopo e que uma variavel nao tenha o mesmo nome de um atributo
int check_scope(const char *name){
  int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)== 0) { // verfica se existe esse nome na tabela

      /*Caso já tenha uma classe com o mesmo nome ou ja tenha esse nome no mesmo 
      escopo(tambem já trata que funcoes nao tenha o mesmo nome em uma classe) 
      ou esse nome já seja um atributo da classe(caso seja de outra classe pode ser utilizado) 
      */
      if((strcmp(symbol_table[i].type, "class") == 0) || symbol_table[i].scope == count_scope || (strcmp(symbol_table[i].type, "attribute") == 0 && symbol_table[i].scope_class == count_scope_class)){ 
			  return -1;
			  break;
      }
    }
	}
	return 0;
}

void check_return(){
  int index_method = -1;
  for(int i=count-1; i>=0; i--) {
    if(strcmp(symbol_table[i].type, "method") == 0){
      index_method = i;

    }
  }
  if(symbol_table[index_method].data_type!="VAZIO" && strcmp(symbol_table[count-1].data_type,symbol_table[index_method].data_type )){
    sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A funcao %s do tipo %s retorna um valor do tipo %s\n", file_name_current,count_line, symbol_table[index_method].name, symbol_table[index_method].data_type, symbol_table[count-1].data_type);    
    count_errors++;  

  }

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
    ao - attribute is a object
    
*/
void add(char c) {
      //query = search(yylval.node_struct.name);
      int result = check_scope(yylval.node_struct.name);
      if(!result){
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
          symbol_table[count].scope=count_scope;
          count++;
        }
        else if(c == 'c') {
          char *v = strdup(yylval.node_struct.name);
          int result = check_value(v);
          if(result == 0){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("CHAR");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("constant");
            count++;

          }
          else if(result == 1){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("STRING");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("constant");
            count++;

          }

          else if(result == 2){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("FLOAT");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("constant");
            count++;
            
          }

          else if(result == 3){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("INT");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("constant");
            count++;
            
          }
        }
        else if(c == 'm') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("method");
          symbol_table[count].scope=count_scope+1;
          symbol_table[count].scope_class=count_scope_class;
          count_scope++;
          count++;

        }
        else if(c == 's') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("class");
          symbol_table[count].scope_class=count_scope_class+1;
          count++;
          count_scope_class++;
        }

        else if(c == 'a') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("attribute");
          symbol_table[count].scope=count_scope;
          symbol_table[count].scope_class=count_scope_class;
          count++;
          }
        else if(c == 'p') {
          symbol_table[count].name=strdup(yylval.node_struct.name);
          symbol_table[count].data_type=strdup(type);
          symbol_table[count].line=count_line;
          symbol_table[count].type=strdup("parameter");
          symbol_table[count].scope=count_scope;
          count++;
        }
        else if(c == 'o') {
          int result = check_class();
          if(result!=-1){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("object");
            symbol_table[count].scope=count_scope;
            symbol_table[count].scope_class=count_scope_class;
            symbol_table[count].name_class=class_name;
            count++;
           }
        }

        else if(c == 'ao') {
          int result = check_class();
          if(result!=-1){
            symbol_table[count].name=strdup(yylval.node_struct.name);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("attribute");
            symbol_table[count].scope=count_scope;
            symbol_table[count].scope_class=count_scope_class;
            symbol_table[count].name_class=class_name;
            count++;
           }
        }
        
      
      }
    
      else{
        sprintf(errors[count_errors], "Arquivo(%s) - Linha %d: A estrutura %s ja foi declarada \n", file_name_current,count_line, yylval.node_struct.name);
		    count_errors++;
    }
}      

    
void insert_type() {
      
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