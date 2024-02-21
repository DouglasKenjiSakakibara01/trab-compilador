/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_ID = 258,                   /* TK_ID  */
    TK_TIPO_CHAR = 259,            /* TK_TIPO_CHAR  */
    TK_TIPO_FLOAT = 260,           /* TK_TIPO_FLOAT  */
    TK_TIPO_INT = 261,             /* TK_TIPO_INT  */
    TK_TIPO_STRING = 262,          /* TK_TIPO_STRING  */
    TK_PARA = 263,                 /* TK_PARA  */
    TK_INT = 264,                  /* TK_INT  */
    TK_SE = 265,                   /* TK_SE  */
    TK_SENAO = 266,                /* TK_SENAO  */
    TK_MAIOR = 267,                /* TK_MAIOR  */
    TK_MAIOR_IGUAL = 268,          /* TK_MAIOR_IGUAL  */
    TK_MENOR = 269,                /* TK_MENOR  */
    TK_MENOR_IGUAL = 270,          /* TK_MENOR_IGUAL  */
    TK_DIFERENTE = 271,            /* TK_DIFERENTE  */
    TK_FLOAT = 272,                /* TK_FLOAT  */
    TK_VERDADEIRO = 273,           /* TK_VERDADEIRO  */
    TK_FALSO = 274,                /* TK_FALSO  */
    TK_LEIA = 275,                 /* TK_LEIA  */
    TK_CHAR = 276,                 /* TK_CHAR  */
    TK_STRING = 277,               /* TK_STRING  */
    TK_ESCREVA = 278,              /* TK_ESCREVA  */
    TK_INCLUDE = 279,              /* TK_INCLUDE  */
    TK_RETORNE = 280,              /* TK_RETORNE  */
    TK_TIPO_VAZIO = 281,           /* TK_TIPO_VAZIO  */
    TK_CLASSE = 282,               /* TK_CLASSE  */
    TK_SOMA = 283,                 /* TK_SOMA  */
    TK_SUBTRACAO = 284,            /* TK_SUBTRACAO  */
    TK_MULTIPLICACAO = 285,        /* TK_MULTIPLICACAO  */
    TK_DIVISAO = 286,              /* TK_DIVISAO  */
    TK_AND = 287,                  /* TK_AND  */
    TK_OR = 288,                   /* TK_OR  */
    TK_NOME_CLASSE = 289,          /* TK_NOME_CLASSE  */
    TK_IGUALDADE = 290,            /* TK_IGUALDADE  */
    TK_CLASSE_PRINCIPAL = 291,     /* TK_CLASSE_PRINCIPAL  */
    TK_METODO_MAIN = 292           /* TK_METODO_MAIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_ID 258
#define TK_TIPO_CHAR 259
#define TK_TIPO_FLOAT 260
#define TK_TIPO_INT 261
#define TK_TIPO_STRING 262
#define TK_PARA 263
#define TK_INT 264
#define TK_SE 265
#define TK_SENAO 266
#define TK_MAIOR 267
#define TK_MAIOR_IGUAL 268
#define TK_MENOR 269
#define TK_MENOR_IGUAL 270
#define TK_DIFERENTE 271
#define TK_FLOAT 272
#define TK_VERDADEIRO 273
#define TK_FALSO 274
#define TK_LEIA 275
#define TK_CHAR 276
#define TK_STRING 277
#define TK_ESCREVA 278
#define TK_INCLUDE 279
#define TK_RETORNE 280
#define TK_TIPO_VAZIO 281
#define TK_CLASSE 282
#define TK_SOMA 283
#define TK_SUBTRACAO 284
#define TK_MULTIPLICACAO 285
#define TK_DIVISAO 286
#define TK_AND 287
#define TK_OR 288
#define TK_NOME_CLASSE 289
#define TK_IGUALDADE 290
#define TK_CLASSE_PRINCIPAL 291
#define TK_METODO_MAIN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "sintatica_semantica.y"
 
	
    struct node_type { 
		char name[50]; 
		struct node* nd;
	} node_struct; 

    struct node_type2 { 
		char name[50]; 
		struct node* nd;
        char type[5];
	} node_struct2;

#line 155 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
