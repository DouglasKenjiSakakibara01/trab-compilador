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

#ifndef YY_YY_SINTATICA_TAB_H_INCLUDED
# define YY_YY_SINTATICA_TAB_H_INCLUDED
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
    TK_TIPO = 258,                 /* TK_TIPO  */
    TK_IDENTIFICADOR = 259,        /* TK_IDENTIFICADOR  */
    TK_PONTO_VIRGULA = 260,        /* TK_PONTO_VIRGULA  */
    TK_TIPO_CHAR = 261,            /* TK_TIPO_CHAR  */
    TK_TIPO_FLOAT = 262,           /* TK_TIPO_FLOAT  */
    TK_TIPO_INTEIRO = 263,         /* TK_TIPO_INTEIRO  */
    TK_TIPO_STRING = 264,          /* TK_TIPO_STRING  */
    TK_PARA = 265,                 /* TK_PARA  */
    TK_ENQUANTO = 266,             /* TK_ENQUANTO  */
    TK_NUMERO = 267,               /* TK_NUMERO  */
    TK_SE = 268,                   /* TK_SE  */
    TK_SENAO = 269,                /* TK_SENAO  */
    TK_MAIOR = 270,                /* TK_MAIOR  */
    TK_MAIOR_IGUAL = 271,          /* TK_MAIOR_IGUAL  */
    TK_IGUALDADE = 272,            /* TK_IGUALDADE  */
    TK_MENOR = 273,                /* TK_MENOR  */
    TK_MENOR_IGUAL = 274,          /* TK_MENOR_IGUAL  */
    TK_DIFERENTE = 275,            /* TK_DIFERENTE  */
    TK_FLOAT = 276,                /* TK_FLOAT  */
    TK_VERDADEIRO = 277,           /* TK_VERDADEIRO  */
    TK_FALSO = 278,                /* TK_FALSO  */
    TK_LEIA = 279,                 /* TK_LEIA  */
    TK_CARACTER = 280,             /* TK_CARACTER  */
    TK_STRING = 281,               /* TK_STRING  */
    TK_ESCREVA = 282,              /* TK_ESCREVA  */
    TK_INCLUDE = 283,              /* TK_INCLUDE  */
    TK_RETORNE = 284,              /* TK_RETORNE  */
    TK_CABECALHO = 285,            /* TK_CABECALHO  */
    TK_TIPO_VAZIO = 286,           /* TK_TIPO_VAZIO  */
    TK_CLASSE = 287,               /* TK_CLASSE  */
    TK_COMENTARIO = 288            /* TK_COMENTARIO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICA_TAB_H_INCLUDED  */
