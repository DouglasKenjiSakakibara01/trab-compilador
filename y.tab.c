/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica_semantica.y"

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

    struct data {
            int line;
            char * name;
            char * data_type;
            char * type;
            int scope;
            int scope_class;
            
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
    int index_object = 0;
    

    

#line 131 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 60 "sintatica_semantica.y"
 
	
    struct node_type { 
		char name[50]; 
		struct node* nd;
	} node_struct; 

    struct node_type2 { 
		char name[50]; 
		struct node* nd;
        char type[5];
	} node_struct2;

#line 272 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ID = 3,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_CHAR = 4,               /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_FLOAT = 5,              /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_INT = 6,                /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_STRING = 7,             /* TK_TIPO_STRING  */
  YYSYMBOL_TK_PARA = 8,                    /* TK_PARA  */
  YYSYMBOL_TK_INT = 9,                     /* TK_INT  */
  YYSYMBOL_TK_SE = 10,                     /* TK_SE  */
  YYSYMBOL_TK_SENAO = 11,                  /* TK_SENAO  */
  YYSYMBOL_TK_MAIOR = 12,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MAIOR_IGUAL = 13,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR = 14,                  /* TK_MENOR  */
  YYSYMBOL_TK_MENOR_IGUAL = 15,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 16,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_FLOAT = 17,                  /* TK_FLOAT  */
  YYSYMBOL_TK_VERDADEIRO = 18,             /* TK_VERDADEIRO  */
  YYSYMBOL_TK_FALSO = 19,                  /* TK_FALSO  */
  YYSYMBOL_TK_LEIA = 20,                   /* TK_LEIA  */
  YYSYMBOL_TK_CHAR = 21,                   /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 22,                 /* TK_STRING  */
  YYSYMBOL_TK_ESCREVA = 23,                /* TK_ESCREVA  */
  YYSYMBOL_TK_INCLUDE = 24,                /* TK_INCLUDE  */
  YYSYMBOL_TK_RETORNE = 25,                /* TK_RETORNE  */
  YYSYMBOL_TK_TIPO_VAZIO = 26,             /* TK_TIPO_VAZIO  */
  YYSYMBOL_TK_CLASSE = 27,                 /* TK_CLASSE  */
  YYSYMBOL_TK_SOMA = 28,                   /* TK_SOMA  */
  YYSYMBOL_TK_SUBTRACAO = 29,              /* TK_SUBTRACAO  */
  YYSYMBOL_TK_MULTIPLICACAO = 30,          /* TK_MULTIPLICACAO  */
  YYSYMBOL_TK_DIVISAO = 31,                /* TK_DIVISAO  */
  YYSYMBOL_TK_AND = 32,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 33,                     /* TK_OR  */
  YYSYMBOL_TK_NOME_CLASSE = 34,            /* TK_NOME_CLASSE  */
  YYSYMBOL_TK_IGUALDADE = 35,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_CLASSE_PRINCIPAL = 36,       /* TK_CLASSE_PRINCIPAL  */
  YYSYMBOL_TK_METODO_MAIN = 37,            /* TK_METODO_MAIN  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_headers = 50,                   /* headers  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_class = 53,                     /* class  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_class_body_main = 55,           /* class_body_main  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_class_body = 57,                /* class_body  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_class_atributes = 60,           /* class_atributes  */
  YYSYMBOL_statement_atributes = 61,       /* statement_atributes  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_method = 64,                    /* method  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_body = 68,                      /* body  */
  YYSYMBOL_69_12 = 69,                     /* $@12  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_73_16 = 73,                     /* $@16  */
  YYSYMBOL_74_17 = 74,                     /* $@17  */
  YYSYMBOL_75_18 = 75,                     /* $@18  */
  YYSYMBOL_76_19 = 76,                     /* $@19  */
  YYSYMBOL_77_20 = 77,                     /* $@20  */
  YYSYMBOL_78_21 = 78,                     /* $@21  */
  YYSYMBOL_else = 79,                      /* else  */
  YYSYMBOL_80_22 = 80,                     /* $@22  */
  YYSYMBOL_statement = 81,                 /* statement  */
  YYSYMBOL_82_23 = 82,                     /* $@23  */
  YYSYMBOL_83_24 = 83,                     /* $@24  */
  YYSYMBOL_84_25 = 84,                     /* $@25  */
  YYSYMBOL_85_26 = 85,                     /* $@26  */
  YYSYMBOL_type = 86,                      /* type  */
  YYSYMBOL_87_27 = 87,                     /* $@27  */
  YYSYMBOL_88_28 = 88,                     /* $@28  */
  YYSYMBOL_89_29 = 89,                     /* $@29  */
  YYSYMBOL_90_30 = 90,                     /* $@30  */
  YYSYMBOL_91_31 = 91,                     /* $@31  */
  YYSYMBOL_condition = 92,                 /* condition  */
  YYSYMBOL_93_32 = 93,                     /* $@32  */
  YYSYMBOL_94_33 = 94,                     /* $@33  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_arithmetic = 96,                /* arithmetic  */
  YYSYMBOL_op = 97,                        /* op  */
  YYSYMBOL_value = 98,                     /* value  */
  YYSYMBOL_99_34 = 99,                     /* $@34  */
  YYSYMBOL_100_35 = 100,                   /* $@35  */
  YYSYMBOL_101_36 = 101,                   /* $@36  */
  YYSYMBOL_102_37 = 102,                   /* $@37  */
  YYSYMBOL_return = 103,                   /* return  */
  YYSYMBOL_104_38 = 104                    /* $@38  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,     2,
      40,    41,     2,     2,    44,     2,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    88,    89,    89,    90,    93,    93,    94,
      94,    95,    98,    98,   101,   101,   103,   104,   104,   104,
     105,   111,   114,   117,   117,   118,   118,   121,   121,   125,
     125,   126,   127,   131,   131,   142,   142,   143,   144,   145,
     145,   145,   146,   146,   146,   147,   147,   147,   148,   149,
     149,   150,   150,   153,   153,   154,   158,   158,   159,   159,
     160,   160,   161,   161,   165,   165,   166,   166,   167,   167,
     168,   168,   169,   169,   173,   177,   177,   178,   178,   179,
     183,   187,   191,   192,   193,   194,   197,   198,   199,   200,
     203,   204,   205,   206,   207,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   217,   217,   218
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_ID",
  "TK_TIPO_CHAR", "TK_TIPO_FLOAT", "TK_TIPO_INT", "TK_TIPO_STRING",
  "TK_PARA", "TK_INT", "TK_SE", "TK_SENAO", "TK_MAIOR", "TK_MAIOR_IGUAL",
  "TK_MENOR", "TK_MENOR_IGUAL", "TK_DIFERENTE", "TK_FLOAT",
  "TK_VERDADEIRO", "TK_FALSO", "TK_LEIA", "TK_CHAR", "TK_STRING",
  "TK_ESCREVA", "TK_INCLUDE", "TK_RETORNE", "TK_TIPO_VAZIO", "TK_CLASSE",
  "TK_SOMA", "TK_SUBTRACAO", "TK_MULTIPLICACAO", "TK_DIVISAO", "TK_AND",
  "TK_OR", "TK_NOME_CLASSE", "TK_IGUALDADE", "TK_CLASSE_PRINCIPAL",
  "TK_METODO_MAIN", "'{'", "'}'", "'('", "')'", "';'", "'='", "','", "'.'",
  "'&'", "$accept", "program", "$@1", "headers", "$@2", "$@3", "class",
  "$@4", "class_body_main", "$@5", "class_body", "$@6", "$@7",
  "class_atributes", "statement_atributes", "$@8", "$@9", "method", "$@10",
  "parameters", "$@11", "body", "$@12", "$@13", "$@14", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "else", "$@22", "statement",
  "$@23", "$@24", "$@25", "$@26", "type", "$@27", "$@28", "$@29", "$@30",
  "$@31", "condition", "$@32", "$@33", "expression", "arithmetic", "op",
  "value", "$@34", "$@35", "$@36", "$@37", "return", "$@38", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   123,   125,
      40,    41,    59,    61,    44,    46,    38
};
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,  -122,   -21,    14,     5,  -122,  -122,    -6,  -122,  -122,
     -28,  -122,  -122,    -7,  -122,    15,     9,  -122,  -122,  -122,
    -122,  -122,  -122,    16,    15,    11,     8,    54,    30,  -122,
    -122,  -122,  -122,  -122,    58,  -122,  -122,  -122,    30,     2,
      23,    28,  -122,    29,    66,    31,  -122,  -122,  -122,  -122,
      39,    51,    50,    42,    63,    15,   232,    60,  -122,  -122,
    -122,  -122,  -122,    42,   231,  -122,    30,  -122,     7,  -122,
    -122,  -122,  -122,  -122,  -122,   207,  -122,    65,   102,    30,
    -122,  -122,  -122,  -122,   231,    75,  -122,  -122,  -122,  -122,
      42,    42,    42,    76,    68,    73,    81,   160,    85,    90,
      91,    92,    93,   128,  -122,   232,   112,  -122,    98,  -122,
      42,  -122,   231,   231,   231,   106,   150,   151,    42,  -122,
    -122,  -122,  -122,  -122,    42,    72,     6,   232,   134,   135,
    -122,   105,    15,  -122,   126,   216,   232,  -122,  -122,   231,
     231,   127,   136,  -122,  -122,   138,    55,   160,    89,   137,
     141,   142,   152,  -122,    42,  -122,   132,   153,   154,     6,
    -122,  -122,   161,    42,   105,  -122,   155,   156,  -122,  -122,
     231,  -122,  -122,    42,   158,   232,   231,  -122,   200,  -122,
     117,    72,   157,   163,  -122,   165,  -122,   167,   169,  -122,
     232,   182,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     7,     0,     0,     6,     3,     8,    11,    12,     1,
       0,     2,    10,     0,     4,    21,     0,    68,    66,    64,
      70,    72,    17,     0,    21,     0,     0,     0,     0,    69,
      67,    65,    71,    73,     0,    13,    16,    22,    32,    23,
       0,     0,    18,     0,     0,     0,    26,    28,     5,    14,
       0,     0,    29,     0,     0,    21,    55,     0,   103,    95,
      97,    99,   101,     0,    24,    82,    32,    19,    62,    33,
      35,    53,    51,    49,    39,    55,    37,     0,     0,    32,
      96,    98,   100,   102,     0,    82,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,    48,     0,    38,    56,    30,
       0,    85,    83,    84,    80,     0,     0,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,    55,     0,     0,
      40,     0,    21,    57,     0,     0,    55,    43,    46,    61,
      63,    62,     0,    75,    77,     0,     0,    82,     0,     0,
       0,     0,     0,    20,     0,    81,     0,     0,     0,     0,
      76,    78,     0,     0,     0,    54,     0,     0,    41,   105,
      59,    15,    44,     0,     0,    55,    79,    74,     0,    50,
       0,     0,     0,     0,    47,     0,    36,     0,     0,    52,
      55,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,   215,  -122,   213,  -122,  -122,  -122,  -122,  -122,  -122,
     -22,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   -49,
    -122,   -56,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -121,  -122,  -122,  -122,  -122,   -12,
    -122,  -122,  -122,  -122,  -122,    64,  -122,  -122,   -52,   140,
      78,   -58,  -122,  -122,  -122,  -122,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    16,     4,     6,     7,     5,    13,    40,    54,
      23,    34,    50,    24,    25,    45,    46,    26,    47,    43,
      57,   105,    98,    99,   103,   151,    94,   157,    95,   158,
     102,   101,    76,   100,    77,   133,   134,    96,    97,    78,
      31,    30,    29,    32,    33,   145,   160,   161,   146,    92,
     124,    65,    80,    81,    82,    83,   106,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    64,    36,    27,   142,    85,     8,     1,    14,    58,
       2,    84,    27,     8,     9,    59,    41,    93,     1,    17,
      18,    19,    20,    60,   143,   144,    44,    61,    62,     1,
     109,    15,    10,    67,    17,    18,    19,    20,   112,   113,
     114,    21,   -27,    27,   -25,    58,    63,    28,    38,    22,
     -60,    59,   -42,    37,    44,    35,    21,    39,   135,    60,
     185,    42,    48,    61,    62,    49,   139,    44,   147,    52,
      51,   148,   140,   152,    53,   141,    17,    18,    19,    20,
     156,    55,    63,    86,    87,    88,    89,    90,    91,    56,
     163,   -31,    68,    17,    18,    19,    20,    69,    21,    70,
      71,   147,   170,    66,    79,   108,   177,   107,    58,    72,
     153,   176,    73,   116,    59,    21,   111,   115,   117,   182,
      27,   180,    60,    74,   118,   125,    61,    62,   165,   127,
     126,   130,   128,   129,   191,    68,    17,    18,    19,    20,
      69,   -58,    70,    71,   136,    86,    87,    88,    89,    90,
      91,   132,    72,   137,   138,    73,   149,   150,    21,   184,
      68,    17,    18,    19,    20,    69,    74,    70,    71,   154,
     -60,   171,   119,   120,   121,   122,   123,    72,   159,   162,
      73,   166,   167,    21,   168,    68,    17,    18,    19,    20,
      69,    74,    70,    71,   169,   172,   186,   173,   179,   175,
     181,   178,    72,   183,   187,    73,   188,   190,    21,   189,
      68,    17,    18,    19,    20,    69,    74,    70,    71,    11,
      12,   192,     0,   174,   110,   164,     0,    72,     0,     0,
      73,     0,   104,    21,     0,    68,    17,    18,    19,    20,
      69,    74,    70,    71,    86,    87,    88,    89,    90,    91,
       0,     0,    72,     0,     0,    73,     0,   155,    21,    86,
      87,    88,    89,    90,    91,     0,    74
};

static const yytype_int16 yycheck[] =
{
      56,    53,    24,    15,   125,    63,    34,    24,    36,     3,
      27,    63,    24,    34,     0,     9,    28,    66,    24,     4,
       5,     6,     7,    17,    18,    19,    38,    21,    22,    24,
      79,    38,    27,    55,     4,     5,     6,     7,    90,    91,
      92,    26,    40,    55,    42,     3,    40,    38,    40,    34,
      43,     9,    45,    42,    66,    39,    26,     3,   110,    17,
     181,     3,    39,    21,    22,    37,   118,    79,   126,     3,
      41,   127,   124,   131,    43,     3,     4,     5,     6,     7,
     136,    42,    40,    28,    29,    30,    31,    32,    33,    38,
      35,    41,     3,     4,     5,     6,     7,     8,    26,    10,
      11,   159,   154,    40,    44,     3,   164,    42,     3,    20,
     132,   163,    23,    45,     9,    26,    41,    41,    45,   175,
     132,   173,    17,    34,    43,    40,    21,    22,    39,    38,
      40,     3,    40,    40,   190,     3,     4,     5,     6,     7,
       8,    43,    10,    11,    38,    28,    29,    30,    31,    32,
      33,    39,    20,     3,     3,    23,    22,    22,    26,    42,
       3,     4,     5,     6,     7,     8,    34,    10,    11,    43,
      43,    39,    12,    13,    14,    15,    16,    20,    42,    41,
      23,    44,    41,    26,    42,     3,     4,     5,     6,     7,
       8,    34,    10,    11,    42,    42,    39,    43,    42,    38,
      42,    46,    20,     3,    41,    23,    41,    38,    26,    42,
       3,     4,     5,     6,     7,     8,    34,    10,    11,     4,
       7,    39,    -1,   159,    84,   147,    -1,    20,    -1,    -1,
      23,    -1,    25,    26,    -1,     3,     4,     5,     6,     7,
       8,    34,    10,    11,    28,    29,    30,    31,    32,    33,
      -1,    -1,    20,    -1,    -1,    23,    -1,    41,    26,    28,
      29,    30,    31,    32,    33,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    27,    48,    50,    53,    51,    52,    34,     0,
      27,    48,    50,    54,    36,    38,    49,     4,     5,     6,
       7,    26,    34,    57,    60,    61,    64,    86,    38,    89,
      88,    87,    90,    91,    58,    39,    57,    42,    40,     3,
      55,    86,     3,    66,    86,    62,    63,    65,    39,    37,
      59,    41,     3,    43,    56,    42,    38,    67,     3,     9,
      17,    21,    22,    40,    95,    98,    40,    57,     3,     8,
      10,    11,    20,    23,    34,    68,    79,    81,    86,    44,
      99,   100,   101,   102,    95,    98,    28,    29,    30,    31,
      32,    33,    96,    66,    73,    75,    84,    85,    69,    70,
      80,    78,    77,    71,    25,    68,   103,    42,     3,    66,
      96,    41,    95,    95,    95,    41,    45,    45,    43,    12,
      13,    14,    15,    16,    97,    40,    40,    38,    40,    40,
       3,   104,    39,    82,    83,    95,    38,     3,     3,    95,
      95,     3,    81,    18,    19,    92,    95,    98,    68,    22,
      22,    72,    98,    57,    43,    41,    68,    74,    76,    42,
      93,    94,    41,    35,    97,    39,    44,    41,    42,    42,
      95,    39,    42,    43,    92,    38,    95,    98,    46,    42,
      95,    42,    68,     3,    42,    81,    39,    41,    41,    42,
      38,    68,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    48,    48,    51,    50,    52,
      50,    50,    54,    53,    56,    55,    57,    58,    59,    57,
      57,    57,    60,    62,    61,    63,    61,    65,    64,    67,
      66,    66,    66,    69,    68,    70,    68,    68,    68,    71,
      72,    68,    73,    74,    68,    75,    76,    68,    68,    77,
      68,    78,    68,    80,    79,    79,    82,    81,    83,    81,
      84,    81,    85,    81,    87,    86,    88,    86,    89,    86,
      90,    86,    91,    86,    92,    93,    92,    94,    92,    92,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    99,    98,   100,    98,   101,
      98,   102,    98,    98,   104,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     7,     0,     0,     2,     0,
       3,     0,     0,     6,     0,     9,     2,     0,     0,     6,
       9,     0,     2,     0,     5,     0,     3,     0,     3,     0,
       5,     2,     0,     0,    12,     0,     8,     1,     2,     0,
       0,     5,     0,     0,     6,     0,     0,     8,     2,     0,
       6,     0,     9,     0,     5,     0,     0,     3,     0,     5,
       0,     4,     0,     4,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     3,     0,     2,     0,     2,     3,
       3,     5,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     1,     0,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: headers program  */
#line 86 "sintatica_semantica.y"
                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "program"); head = (yyval.node_struct).nd;}
#line 1788 "y.tab.c"
    break;

  case 3: /* program: class  */
#line 88 "sintatica_semantica.y"
        {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL , "program"); }
#line 1794 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 89 "sintatica_semantica.y"
                                        {add('s');}
#line 1800 "y.tab.c"
    break;

  case 5: /* program: headers TK_CLASSE TK_CLASSE_PRINCIPAL $@1 '{' class_body_main '}'  */
#line 89 "sintatica_semantica.y"
                                                                            {(yyval.node_struct).nd = add_node((yyvsp[-6].node_struct).nd, (yyvsp[-1].node_struct).nd, "program"); }
#line 1806 "y.tab.c"
    break;

  case 6: /* program: %empty  */
#line 90 "sintatica_semantica.y"
 { (yyval.node_struct).nd = NULL; }
#line 1812 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 93 "sintatica_semantica.y"
                    {add('h');}
#line 1818 "y.tab.c"
    break;

  case 8: /* headers: TK_INCLUDE $@2  */
#line 93 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node(NULL, NULL, "INCLUDE");}
#line 1824 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 94 "sintatica_semantica.y"
            {add('h');}
#line 1830 "y.tab.c"
    break;

  case 10: /* headers: TK_INCLUDE $@3 headers  */
#line 94 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL, "INCLUDE2");}
#line 1836 "y.tab.c"
    break;

  case 11: /* headers: %empty  */
#line 95 "sintatica_semantica.y"
 {(yyval.node_struct).nd = NULL;}
#line 1842 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 98 "sintatica_semantica.y"
                                {add('s');}
#line 1848 "y.tab.c"
    break;

  case 13: /* class: TK_CLASSE TK_NOME_CLASSE $@4 '{' class_body '}'  */
#line 98 "sintatica_semantica.y"
                                                                {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "class");}
#line 1854 "y.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 101 "sintatica_semantica.y"
                                     {add('m');}
#line 1860 "y.tab.c"
    break;

  case 16: /* class_body: class_atributes class_body  */
#line 103 "sintatica_semantica.y"
                                       {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "class_body_atributes");}
#line 1866 "y.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 104 "sintatica_semantica.y"
                  {aux_check_class();}
#line 1872 "y.tab.c"
    break;

  case 18: /* $@7: %empty  */
#line 104 "sintatica_semantica.y"
                                             {add('o');}
#line 1878 "y.tab.c"
    break;

  case 19: /* class_body: TK_NOME_CLASSE $@6 TK_ID $@7 ';' class_body  */
#line 104 "sintatica_semantica.y"
                                                                        {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL, "class_body_object");}
#line 1884 "y.tab.c"
    break;

  case 20: /* class_body: method '(' parameters ')' '{' body return '}' class_body  */
#line 105 "sintatica_semantica.y"
                                                           {
   struct node *aux = add_node((yyvsp[-3].node_struct).nd, (yyvsp[-2].node_struct).nd, "class_body_method_aux");
   struct node *aux2 = add_node(&*aux, (yyvsp[0].node_struct).nd, "class_body_method_aux2");
   struct node *aux3 = add_node((yyvsp[-8].node_struct).nd, (yyvsp[-6].node_struct).nd, "class_body_method_aux3");
   (yyval.node_struct).nd = add_node(aux3, aux2, "class_body_method");
}
#line 1895 "y.tab.c"
    break;

  case 21: /* class_body: %empty  */
#line 111 "sintatica_semantica.y"
   {(yyval.node_struct).nd = NULL;}
#line 1901 "y.tab.c"
    break;

  case 22: /* class_atributes: statement_atributes ';'  */
#line 114 "sintatica_semantica.y"
                                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "class_atributes");}
#line 1907 "y.tab.c"
    break;

  case 23: /* $@8: %empty  */
#line 117 "sintatica_semantica.y"
                                 {add('a');}
#line 1913 "y.tab.c"
    break;

  case 24: /* statement_atributes: type TK_ID $@8 '=' expression  */
#line 117 "sintatica_semantica.y"
                                                            {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[0].node_struct2).nd, "statement_atributes2");}
#line 1919 "y.tab.c"
    break;

  case 25: /* $@9: %empty  */
#line 118 "sintatica_semantica.y"
             {add('a');}
#line 1925 "y.tab.c"
    break;

  case 26: /* statement_atributes: type TK_ID $@9  */
#line 118 "sintatica_semantica.y"
                         {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "statement_atributes2");}
#line 1931 "y.tab.c"
    break;

  case 27: /* $@10: %empty  */
#line 121 "sintatica_semantica.y"
                   {add('m');}
#line 1937 "y.tab.c"
    break;

  case 28: /* method: type TK_ID $@10  */
#line 121 "sintatica_semantica.y"
                               {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "method");}
#line 1943 "y.tab.c"
    break;

  case 29: /* $@11: %empty  */
#line 125 "sintatica_semantica.y"
                       {add('p');}
#line 1949 "y.tab.c"
    break;

  case 30: /* parameters: type TK_ID $@11 ',' parameters  */
#line 125 "sintatica_semantica.y"
                                                  {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[0].node_struct).nd, "parameters");}
#line 1955 "y.tab.c"
    break;

  case 31: /* parameters: type TK_ID  */
#line 126 "sintatica_semantica.y"
             {add('p'); (yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "parameters2");}
#line 1961 "y.tab.c"
    break;

  case 32: /* parameters: %empty  */
#line 127 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 1967 "y.tab.c"
    break;

  case 33: /* $@12: %empty  */
#line 131 "sintatica_semantica.y"
              {add('k');}
#line 1973 "y.tab.c"
    break;

  case 34: /* body: TK_PARA $@12 '(' statement ';' condition ';' statement ')' '{' body '}'  */
#line 131 "sintatica_semantica.y"
                                                                                    {
  struct node *aux = add_node((yyvsp[-6].node_struct).nd, (yyvsp[-4].node_struct).nd, "body_for_aux"); 
  struct node *aux2 = add_node((yyvsp[-8].node_struct).nd, aux, "body_for_aux2"); 
  (yyval.node_struct).nd = add_node(aux2, (yyvsp[-1].node_struct).nd, "body_for"); 
}
#line 1983 "y.tab.c"
    break;

  case 35: /* $@13: %empty  */
#line 142 "sintatica_semantica.y"
        {add('k');}
#line 1989 "y.tab.c"
    break;

  case 36: /* body: TK_SE $@13 '(' condition ')' '{' body '}'  */
#line 142 "sintatica_semantica.y"
                                                   {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[-1].node_struct).nd, "body_if");}
#line 1995 "y.tab.c"
    break;

  case 37: /* body: else  */
#line 143 "sintatica_semantica.y"
       {  (yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL, "body_if");}
#line 2001 "y.tab.c"
    break;

  case 38: /* body: statement ';'  */
#line 144 "sintatica_semantica.y"
                {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "body_statement");}
#line 2007 "y.tab.c"
    break;

  case 39: /* $@14: %empty  */
#line 145 "sintatica_semantica.y"
                 {aux_check_class();}
#line 2013 "y.tab.c"
    break;

  case 40: /* $@15: %empty  */
#line 145 "sintatica_semantica.y"
                                            {add('o');}
#line 2019 "y.tab.c"
    break;

  case 41: /* body: TK_NOME_CLASSE $@14 TK_ID $@15 ';'  */
#line 145 "sintatica_semantica.y"
                                                            {(yyval.node_struct).nd = add_node(NULL, NULL, "body_object");}
#line 2025 "y.tab.c"
    break;

  case 42: /* $@16: %empty  */
#line 146 "sintatica_semantica.y"
        { check_declaration((yyvsp[0].node_struct).name); }
#line 2031 "y.tab.c"
    break;

  case 43: /* $@17: %empty  */
#line 146 "sintatica_semantica.y"
                                                  {check_declaration2((yyvsp[0].node_struct).name);}
#line 2037 "y.tab.c"
    break;

  case 45: /* $@18: %empty  */
#line 147 "sintatica_semantica.y"
        { check_declaration((yyvsp[0].node_struct).name); }
#line 2043 "y.tab.c"
    break;

  case 46: /* $@19: %empty  */
#line 147 "sintatica_semantica.y"
                                                  {check_declaration2((yyvsp[0].node_struct).name);}
#line 2049 "y.tab.c"
    break;

  case 48: /* body: body body  */
#line 148 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "body");}
#line 2055 "y.tab.c"
    break;

  case 49: /* $@20: %empty  */
#line 149 "sintatica_semantica.y"
             {add('k');}
#line 2061 "y.tab.c"
    break;

  case 50: /* body: TK_ESCREVA $@20 '(' TK_STRING ')' ';'  */
#line 149 "sintatica_semantica.y"
                                               {(yyval.node_struct).nd = add_node(NULL, NULL, "body_printf");}
#line 2067 "y.tab.c"
    break;

  case 51: /* $@21: %empty  */
#line 150 "sintatica_semantica.y"
          {add('k');}
#line 2073 "y.tab.c"
    break;

  case 52: /* body: TK_LEIA $@21 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 150 "sintatica_semantica.y"
                                                          {(yyval.node_struct).nd = add_node(NULL, NULL, "body_scanf");}
#line 2079 "y.tab.c"
    break;

  case 53: /* $@22: %empty  */
#line 153 "sintatica_semantica.y"
               {add('k');}
#line 2085 "y.tab.c"
    break;

  case 54: /* else: TK_SENAO $@22 '{' body '}'  */
#line 153 "sintatica_semantica.y"
                                        {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "else_body");}
#line 2091 "y.tab.c"
    break;

  case 55: /* else: %empty  */
#line 154 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 2097 "y.tab.c"
    break;

  case 56: /* $@23: %empty  */
#line 158 "sintatica_semantica.y"
                      {add('v');}
#line 2103 "y.tab.c"
    break;

  case 57: /* statement: type TK_ID $@23  */
#line 158 "sintatica_semantica.y"
                                  {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "statement1");}
#line 2109 "y.tab.c"
    break;

  case 58: /* $@24: %empty  */
#line 159 "sintatica_semantica.y"
              {add('v');}
#line 2115 "y.tab.c"
    break;

  case 59: /* statement: type TK_ID $@24 '=' expression  */
#line 159 "sintatica_semantica.y"
                                          {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[0].node_struct2).nd, "statement2"); check_type((yyvsp[-3].node_struct).name);}
#line 2121 "y.tab.c"
    break;

  case 60: /* $@25: %empty  */
#line 160 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2127 "y.tab.c"
    break;

  case 61: /* statement: TK_ID $@25 '=' expression  */
#line 160 "sintatica_semantica.y"
                                                     {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct2).nd, NULL, "statement3"); check_type((yyvsp[-3].node_struct).name);}
#line 2133 "y.tab.c"
    break;

  case 62: /* $@26: %empty  */
#line 161 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2139 "y.tab.c"
    break;

  case 63: /* statement: TK_ID $@26 op expression  */
#line 161 "sintatica_semantica.y"
                                                    {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[-1].node_struct).nd, "statement4");}
#line 2145 "y.tab.c"
    break;

  case 64: /* $@27: %empty  */
#line 165 "sintatica_semantica.y"
                  {insert_type();}
#line 2151 "y.tab.c"
    break;

  case 65: /* type: TK_TIPO_INT $@27  */
#line 165 "sintatica_semantica.y"
                                   {(yyval.node_struct).nd = add_node(NULL, NULL, "type_int");}
#line 2157 "y.tab.c"
    break;

  case 66: /* $@28: %empty  */
#line 166 "sintatica_semantica.y"
                {insert_type();}
#line 2163 "y.tab.c"
    break;

  case 67: /* type: TK_TIPO_FLOAT $@28  */
#line 166 "sintatica_semantica.y"
                                 {(yyval.node_struct).nd = add_node(NULL, NULL, "type_float");}
#line 2169 "y.tab.c"
    break;

  case 68: /* $@29: %empty  */
#line 167 "sintatica_semantica.y"
               {insert_type();}
#line 2175 "y.tab.c"
    break;

  case 69: /* type: TK_TIPO_CHAR $@29  */
#line 167 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node(NULL, NULL, "type_char");}
#line 2181 "y.tab.c"
    break;

  case 70: /* $@30: %empty  */
#line 168 "sintatica_semantica.y"
                 {insert_type();}
#line 2187 "y.tab.c"
    break;

  case 71: /* type: TK_TIPO_STRING $@30  */
#line 168 "sintatica_semantica.y"
                                  {(yyval.node_struct).nd = add_node(NULL, NULL, "type_string");}
#line 2193 "y.tab.c"
    break;

  case 72: /* $@31: %empty  */
#line 169 "sintatica_semantica.y"
                {insert_type();}
#line 2199 "y.tab.c"
    break;

  case 73: /* type: TK_TIPO_VAZIO $@31  */
#line 169 "sintatica_semantica.y"
                                 {(yyval.node_struct).nd = add_node(NULL, NULL, "type_void");}
#line 2205 "y.tab.c"
    break;

  case 74: /* condition: value op value  */
#line 173 "sintatica_semantica.y"
                           {
  struct node *aux = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct2).nd, "condition_aux"); 
  (yyval.node_struct).nd = add_node((yyvsp[-2].node_struct2).nd, aux, "condition");
}
#line 2214 "y.tab.c"
    break;

  case 75: /* $@32: %empty  */
#line 177 "sintatica_semantica.y"
                {add('k');}
#line 2220 "y.tab.c"
    break;

  case 76: /* condition: TK_VERDADEIRO $@32  */
#line 177 "sintatica_semantica.y"
                            {(yyval.node_struct).nd = add_node(NULL, NULL, "condition_true");}
#line 2226 "y.tab.c"
    break;

  case 77: /* $@33: %empty  */
#line 178 "sintatica_semantica.y"
           {add('k');}
#line 2232 "y.tab.c"
    break;

  case 78: /* condition: TK_FALSO $@33  */
#line 178 "sintatica_semantica.y"
                       {(yyval.node_struct).nd = add_node(NULL, NULL, "condition_false");}
#line 2238 "y.tab.c"
    break;

  case 79: /* condition: expression TK_IGUALDADE expression  */
#line 179 "sintatica_semantica.y"
                                     {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "condition_equal");}
#line 2244 "y.tab.c"
    break;

  case 80: /* expression: expression arithmetic expression  */
#line 183 "sintatica_semantica.y"
                                             {
  struct node *aux = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct2).nd, "expression1_aux"); 
  (yyval.node_struct2).nd = add_node((yyvsp[-2].node_struct2).nd, aux, "expression1");
}
#line 2253 "y.tab.c"
    break;

  case 81: /* expression: '(' expression arithmetic expression ')'  */
#line 187 "sintatica_semantica.y"
                                          {
  struct node *aux = add_node((yyvsp[-2].node_struct).nd, (yyvsp[-1].node_struct2).nd, "expression2_aux"); 
  (yyval.node_struct2).nd = add_node((yyvsp[-3].node_struct2).nd, aux, "expression2");
}
#line 2262 "y.tab.c"
    break;

  case 82: /* expression: value  */
#line 191 "sintatica_semantica.y"
        {(yyval.node_struct2).nd = add_node((yyvsp[0].node_struct2).nd, NULL, "expresion3");}
#line 2268 "y.tab.c"
    break;

  case 83: /* expression: expression TK_AND expression  */
#line 192 "sintatica_semantica.y"
                               {add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "expresion4");}
#line 2274 "y.tab.c"
    break;

  case 84: /* expression: expression TK_OR expression  */
#line 193 "sintatica_semantica.y"
                              {add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "expresion5");}
#line 2280 "y.tab.c"
    break;

  case 85: /* expression: '(' value ')'  */
#line 194 "sintatica_semantica.y"
                {add_node((yyvsp[-1].node_struct2).nd, NULL, "expresion6");}
#line 2286 "y.tab.c"
    break;

  case 86: /* arithmetic: TK_SOMA  */
#line 197 "sintatica_semantica.y"
                    {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_sum");}
#line 2292 "y.tab.c"
    break;

  case 87: /* arithmetic: TK_SUBTRACAO  */
#line 198 "sintatica_semantica.y"
                {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_sub");}
#line 2298 "y.tab.c"
    break;

  case 88: /* arithmetic: TK_MULTIPLICACAO  */
#line 199 "sintatica_semantica.y"
                   {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_mult");}
#line 2304 "y.tab.c"
    break;

  case 89: /* arithmetic: TK_DIVISAO  */
#line 200 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_div");}
#line 2310 "y.tab.c"
    break;

  case 90: /* op: TK_MAIOR  */
#line 203 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node(NULL, NULL, "op_>");}
#line 2316 "y.tab.c"
    break;

  case 91: /* op: TK_MAIOR_IGUAL  */
#line 204 "sintatica_semantica.y"
                 {(yyval.node_struct).nd = add_node(NULL, NULL, "op_>=");}
#line 2322 "y.tab.c"
    break;

  case 92: /* op: TK_MENOR  */
#line 205 "sintatica_semantica.y"
           {(yyval.node_struct).nd = add_node(NULL, NULL, "op_<");}
#line 2328 "y.tab.c"
    break;

  case 93: /* op: TK_MENOR_IGUAL  */
#line 206 "sintatica_semantica.y"
                 {(yyval.node_struct).nd = add_node(NULL, NULL, "op_<=");}
#line 2334 "y.tab.c"
    break;

  case 94: /* op: TK_DIFERENTE  */
#line 207 "sintatica_semantica.y"
               {(yyval.node_struct).nd = add_node(NULL, NULL, "op_!=");}
#line 2340 "y.tab.c"
    break;

  case 95: /* $@34: %empty  */
#line 210 "sintatica_semantica.y"
              {add('c');}
#line 2346 "y.tab.c"
    break;

  case 96: /* value: TK_INT $@34  */
#line 210 "sintatica_semantica.y"
                          {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_int");}
#line 2352 "y.tab.c"
    break;

  case 97: /* $@35: %empty  */
#line 211 "sintatica_semantica.y"
           {add('c');}
#line 2358 "y.tab.c"
    break;

  case 98: /* value: TK_FLOAT $@35  */
#line 211 "sintatica_semantica.y"
                       {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_float");}
#line 2364 "y.tab.c"
    break;

  case 99: /* $@36: %empty  */
#line 212 "sintatica_semantica.y"
          {add('c');}
#line 2370 "y.tab.c"
    break;

  case 100: /* value: TK_CHAR $@36  */
#line 212 "sintatica_semantica.y"
                      {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_char");}
#line 2376 "y.tab.c"
    break;

  case 101: /* $@37: %empty  */
#line 213 "sintatica_semantica.y"
            {add('c');}
#line 2382 "y.tab.c"
    break;

  case 102: /* value: TK_STRING $@37  */
#line 213 "sintatica_semantica.y"
                        {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_string");}
#line 2388 "y.tab.c"
    break;

  case 103: /* value: TK_ID  */
#line 214 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2394 "y.tab.c"
    break;

  case 104: /* $@38: %empty  */
#line 217 "sintatica_semantica.y"
                   {add('k');}
#line 2400 "y.tab.c"
    break;

  case 105: /* return: TK_RETORNE $@38 value ';'  */
#line 217 "sintatica_semantica.y"
                                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct2).nd, NULL, "return"); check_return();}
#line 2406 "y.tab.c"
    break;

  case 106: /* return: %empty  */
#line 218 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 2412 "y.tab.c"
    break;


#line 2416 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 221 "sintatica_semantica.y"


// falta tratar para rodar com mais de um arquivo , classe principal
int main() {
    yyparse();
    printf("-*-*-*-*-*-* Tabela de simbolos -*-*-*-*-**-*-*--*-\n");
    for(int i=0; i<count; i++) {
      printf("%s\t%s\t%s\t%d\t%d\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].scope, symbol_table[i].scope_class, symbol_table[i].line);
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
    for(int i=0; i<count_errors; i++) {
      printf("%s\n",errors[i]);
    } 
  }
// usado para verificar a declaracao de variaveis e atributos   
void check_declaration(const char *c) {    
    query = search(c);    
    if(query == -1) {        
        sprintf(errors[count_errors], "Linha %d: A estrutura %s nao foi declarada\n", count_line, c);    
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
        sprintf(errors[count_errors], "Linha %d: A estrutura %s sendo acessado pelo objeto nao foi declarada\n", count_line, c);    
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
      sprintf(errors[count_errors], "Linha %d: A estrutura %s do tipo %s recebe um valor do tipo %s\n", count_line, symbol_table[index_var].name, symbol_table[index_var].data_type, symbol_table[index_value].data_type);    
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
  sprintf(errors[count_errors], "Linha %d: A classe referenciada pelo objeto nao foi existe \n", count_line);    
  count_errors++;  

	return -1;

}

// procura uma variavel no determinado escopo
int search(const char *name) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)==0) {
      if(symbol_table[i].scope == count_scope){
			  return i;
			  break;
		}
    } 
	}
	return -1;
} 
// verifica se o atributo sendo acessado atraves do objeto foi declarado
int search2(const char *name) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)==0) {
      if(index_object !=0){
        if(symbol_table[index_object].scope_class == symbol_table[i].scope_class){
          index_object = 0;
          return i;
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

      /*Caso ja tenha esse nome no mesmo escopo(tambem já trata que funcoes nao tenha o mesmo nome em uma classe) ou esse nome já seja um atributo da classe(caso seja de outra classe pode ser utilizado) 
      */
      if(symbol_table[i].scope == count_scope || (strcmp(symbol_table[i].type, "attribute") == 0 && symbol_table[i].scope_class == count_scope_class)){ 
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
    sprintf(errors[count_errors], "Linha %d: A funcao %s do tipo %s retorna um valor do tipo %s\n", count_line, symbol_table[index_method].name, symbol_table[index_method].data_type, symbol_table[count-1].data_type);    
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
          //symbol_table[count].scope_class=count_scope_class;
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
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line=count_line;
            symbol_table[count].type=strdup("object");
            symbol_table[count].scope=count_scope;
            symbol_table[count].scope_class=count_scope_class;
            count++;
           }
        }
      }
    
    
      else{
        sprintf(errors[count_errors], "Linha %d: A estrutura %s ja foi declarada \n", count_line, yylval.node_struct.name);
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
