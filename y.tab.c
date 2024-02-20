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
  

    struct data {
            int line;
            char * name;
            char * data_type;
            char * type;
            int scope;
            
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
    char buffer[100];
    int count_errors=0;
    char errors[50][100];
    int count_scope = 0;
    int count_scope_class = 0;
    

    

#line 121 "y.tab.c"

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
#line 50 "sintatica_semantica.y"
 
	
    struct node_type { 
		char name[50]; 
		struct node* nd;
	} node_struct; 

    struct node_type2 { 
		char name[50]; 
		struct node* nd;
        char type[5];
	} node_struct2;

#line 262 "y.tab.c"

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
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_headers = 49,                   /* headers  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_class = 52,                     /* class  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_class_body_main = 54,           /* class_body_main  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_class_body = 56,                /* class_body  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_class_atributes = 58,           /* class_atributes  */
  YYSYMBOL_statement_atributes = 59,       /* statement_atributes  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_method = 62,                    /* method  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_body = 65,                      /* body  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_else = 71,                      /* else  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_77_19 = 77,                     /* $@19  */
  YYSYMBOL_type = 78,                      /* type  */
  YYSYMBOL_79_20 = 79,                     /* $@20  */
  YYSYMBOL_80_21 = 80,                     /* $@21  */
  YYSYMBOL_81_22 = 81,                     /* $@22  */
  YYSYMBOL_82_23 = 82,                     /* $@23  */
  YYSYMBOL_83_24 = 83,                     /* $@24  */
  YYSYMBOL_condition = 84,                 /* condition  */
  YYSYMBOL_85_25 = 85,                     /* $@25  */
  YYSYMBOL_86_26 = 86,                     /* $@26  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_arithmetic = 88,                /* arithmetic  */
  YYSYMBOL_op = 89,                        /* op  */
  YYSYMBOL_value = 90,                     /* value  */
  YYSYMBOL_91_27 = 91,                     /* $@27  */
  YYSYMBOL_92_28 = 92,                     /* $@28  */
  YYSYMBOL_93_29 = 93,                     /* $@29  */
  YYSYMBOL_94_30 = 94,                     /* $@30  */
  YYSYMBOL_return = 95,                    /* return  */
  YYSYMBOL_96_31 = 96                      /* $@31  */
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
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      40,    41,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    76,    76,    77,    78,    78,    79,    82,    82,    83,
      83,    84,    87,    87,    90,    90,    92,    93,    93,    94,
     100,   103,   106,   106,   107,   107,   110,   110,   114,   115,
     116,   120,   120,   131,   131,   132,   133,   134,   134,   135,
     136,   136,   137,   137,   140,   140,   141,   145,   145,   146,
     146,   147,   147,   148,   148,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   160,   164,   164,   165,   165,
     166,   170,   174,   178,   179,   180,   181,   184,   185,   186,
     187,   190,   191,   192,   193,   194,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   204,   204,   205
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
  "TK_METODO_MAIN", "'{'", "'}'", "'('", "')'", "'='", "';'", "','", "'&'",
  "$accept", "program", "$@1", "headers", "$@2", "$@3", "class", "$@4",
  "class_body_main", "$@5", "class_body", "$@6", "class_atributes",
  "statement_atributes", "$@7", "$@8", "method", "$@9", "parameters",
  "body", "$@10", "$@11", "$@12", "$@13", "$@14", "else", "$@15",
  "statement", "$@16", "$@17", "$@18", "$@19", "type", "$@20", "$@21",
  "$@22", "$@23", "$@24", "condition", "$@25", "$@26", "expression",
  "arithmetic", "op", "value", "$@27", "$@28", "$@29", "$@30", "return",
  "$@31", YY_NULLPTR
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
      40,    41,    61,    59,    44,    38
};
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,  -121,    -1,    45,   -11,   -19,  -121,    29,  -121,  -121,
     -27,  -121,  -121,  -121,    28,  -121,    83,    32,  -121,  -121,
    -121,  -121,  -121,    20,    22,    83,    30,    31,    73,    14,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,    14,
       1,    40,    55,    51,    54,    93,    56,  -121,  -121,  -121,
    -121,    70,    63,    58,    25,    65,    69,   219,    14,  -121,
    -121,  -121,  -121,  -121,    25,   218,  -121,    14,    81,    68,
    -121,  -121,  -121,  -121,  -121,   110,   194,  -121,    94,   135,
    -121,  -121,  -121,  -121,  -121,   218,    99,  -121,  -121,  -121,
    -121,    25,    25,    25,   100,   102,   104,    23,   116,   117,
     121,   120,   122,  -121,  -121,   219,   124,  -121,   123,    25,
    -121,   218,   218,   218,   128,   118,    25,  -121,  -121,  -121,
    -121,  -121,    25,    78,     8,   219,   146,   147,   129,    97,
      83,  -121,   139,   103,   219,    83,   218,   218,   141,  -121,
    -121,   145,   203,    23,    52,   138,   149,   158,   148,  -121,
      25,  -121,   119,  -121,     8,  -121,  -121,   150,    25,    97,
    -121,   142,   151,   159,  -121,   218,  -121,   153,   219,   218,
    -121,   204,  -121,   166,    78,   144,   168,   170,   171,  -121,
     167,   172,   175,  -121,  -121,   219,   169,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     7,     0,     0,     6,     6,     8,    11,    12,     1,
       0,     2,     3,    10,     0,     4,    20,     0,    59,    57,
      55,    61,    63,     0,     0,    20,     0,     0,     0,     0,
      60,    58,    56,    62,    64,    17,    13,    16,    21,    30,
      22,     0,     0,     0,     0,     0,     0,    25,    27,     5,
      14,     0,     0,    29,     0,     0,     0,    46,    30,    94,
      86,    88,    90,    92,     0,    23,    73,    30,     0,    53,
      31,    33,    44,    42,    40,     0,    46,    35,     0,     0,
      28,    87,    89,    91,    93,     0,    73,    77,    78,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    95,    39,     0,    36,    47,     0,
      76,    74,    75,    71,     0,     0,     0,    81,    82,    83,
      84,    85,     0,     0,     0,    46,     0,     0,     0,     0,
      20,    48,     0,     0,    46,    20,    52,    54,     0,    66,
      68,     0,     0,    73,     0,     0,     0,     0,     0,    19,
       0,    72,     0,    18,     0,    67,    69,     0,     0,     0,
      45,     0,     0,     0,    96,    50,    15,     0,    46,    70,
      65,     0,    41,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,    43,    38,    46,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,    27,  -121,   209,  -121,  -121,  -121,  -121,  -121,  -121,
     -23,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -52,   -57,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -120,  -121,  -121,
    -121,  -121,   -15,  -121,  -121,  -121,  -121,  -121,    64,  -121,
    -121,   -42,   136,    98,   -60,  -121,  -121,  -121,  -121,  -121,
    -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    17,     4,     6,     7,     5,    14,    41,    55,
      24,    43,    25,    26,    46,    47,    27,    48,    44,   105,
      98,    99,   128,   102,   101,    77,   100,    78,   131,   132,
      96,    97,    79,    32,    31,    30,    33,    34,   141,   155,
     156,   142,    93,   122,    66,    81,    82,    83,    84,   106,
     129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    28,    37,   138,    86,     1,    80,     8,     2,    15,
      28,    59,    65,     1,    42,    94,    10,    60,    18,    19,
      20,    21,    85,    35,    45,    61,   139,   140,    59,    62,
      63,    11,    12,     8,    60,   117,   118,   119,   120,   121,
      22,   -26,    61,    45,   -24,     9,    62,    63,    64,   111,
     112,   113,    45,     1,   178,    69,    18,    19,    20,    21,
      70,    36,    71,    72,   143,    64,    16,   133,   144,   148,
      29,    39,    73,    38,   136,    74,    40,   152,    22,    49,
     137,    69,    18,    19,    20,    21,    75,    18,    19,    20,
      21,   160,    50,    51,   143,    52,    53,    56,    54,   170,
      59,    57,    58,    68,    22,    67,    60,   149,   165,    22,
     -51,   175,   153,   103,    61,    28,   169,    23,    62,    63,
      28,    95,    69,    18,    19,    20,    21,    70,   186,    71,
      72,    87,    88,    89,    90,    91,    92,   107,   108,    73,
     110,   114,    74,   115,   151,    22,   116,    69,    18,    19,
      20,    21,    70,    75,    71,    72,   123,   124,   166,   125,
     126,   135,   127,   130,    73,   -49,   134,    74,   145,   146,
      22,   147,    69,    18,    19,    20,    21,    70,    75,    71,
      72,   150,   161,   179,   154,   163,   157,   171,   168,    73,
     162,   164,    74,   173,   172,    22,   174,    69,    18,    19,
      20,    21,    70,    75,    71,    72,   177,   176,   187,   180,
     183,   181,   182,   185,    73,   184,    13,    74,   167,   104,
      22,   109,    69,    18,    19,    20,    21,    70,    75,    71,
      72,    87,    88,    89,    90,    91,    92,     0,   158,    73,
       0,   159,    74,     0,     0,    22,    87,    88,    89,    90,
      91,    92,     0,    75
};

static const yytype_int16 yycheck[] =
{
      57,    16,    25,   123,    64,    24,    58,    34,    27,    36,
      25,     3,    54,    24,    29,    67,    27,     9,     4,     5,
       6,     7,    64,     3,    39,    17,    18,    19,     3,    21,
      22,     4,     5,    34,     9,    12,    13,    14,    15,    16,
      26,    40,    17,    58,    43,     0,    21,    22,    40,    91,
      92,    93,    67,    24,   174,     3,     4,     5,     6,     7,
       8,    39,    10,    11,   124,    40,    38,   109,   125,   129,
      38,    40,    20,    43,   116,    23,     3,   134,    26,    39,
     122,     3,     4,     5,     6,     7,    34,     4,     5,     6,
       7,    39,    37,    42,   154,    41,     3,    27,    42,   159,
       3,    38,    44,    34,    26,    40,     9,   130,   150,    26,
      42,   168,   135,     3,    17,   130,   158,    34,    21,    22,
     135,    40,     3,     4,     5,     6,     7,     8,   185,    10,
      11,    28,    29,    30,    31,    32,    33,    43,     3,    20,
      41,    41,    23,    41,    41,    26,    42,     3,     4,     5,
       6,     7,     8,    34,    10,    11,    40,    40,    39,    38,
      40,    43,    40,    39,    20,    42,    38,    23,    22,    22,
      26,    42,     3,     4,     5,     6,     7,     8,    34,    10,
      11,    42,    44,    39,    43,    27,    41,    45,    38,    20,
      41,    43,    23,    34,    43,    26,    43,     3,     4,     5,
       6,     7,     8,    34,    10,    11,    40,     3,    39,    41,
      43,    41,    41,    38,    20,    43,     7,    23,   154,    25,
      26,    85,     3,     4,     5,     6,     7,     8,    34,    10,
      11,    28,    29,    30,    31,    32,    33,    -1,    35,    20,
      -1,   143,    23,    -1,    -1,    26,    28,    29,    30,    31,
      32,    33,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    27,    47,    49,    52,    50,    51,    34,     0,
      27,    47,    47,    49,    53,    36,    38,    48,     4,     5,
       6,     7,    26,    34,    56,    58,    59,    62,    78,    38,
      81,    80,    79,    82,    83,     3,    39,    56,    43,    40,
       3,    54,    78,    57,    64,    78,    60,    61,    63,    39,
      37,    42,    41,     3,    42,    55,    27,    38,    44,     3,
       9,    17,    21,    22,    40,    87,    90,    40,    34,     3,
       8,    10,    11,    20,    23,    34,    65,    71,    73,    78,
      64,    91,    92,    93,    94,    87,    90,    28,    29,    30,
      31,    32,    33,    88,    64,    40,    76,    77,    66,    67,
      72,    70,    69,     3,    25,    65,    95,    43,     3,    88,
      41,    87,    87,    87,    41,    41,    42,    12,    13,    14,
      15,    16,    89,    40,    40,    38,    40,    40,    68,    96,
      39,    74,    75,    87,    38,    43,    87,    87,    73,    18,
      19,    84,    87,    90,    65,    22,    22,    42,    90,    56,
      42,    41,    65,    56,    43,    85,    86,    41,    35,    89,
      39,    44,    41,    27,    43,    87,    39,    84,    38,    87,
      90,    45,    43,    34,    43,    65,     3,    40,    73,    39,
      41,    41,    41,    43,    43,    38,    65,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    47,    47,    50,    49,    51,
      49,    49,    53,    52,    55,    54,    56,    57,    56,    56,
      56,    58,    60,    59,    61,    59,    63,    62,    64,    64,
      64,    66,    65,    67,    65,    65,    65,    68,    65,    65,
      69,    65,    70,    65,    72,    71,    71,    74,    73,    75,
      73,    76,    73,    77,    73,    79,    78,    80,    78,    81,
      78,    82,    78,    83,    78,    84,    85,    84,    86,    84,
      84,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    91,    90,    92,    90,
      93,    90,    94,    90,    90,    96,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     7,     0,     0,     2,     0,
       3,     0,     0,     6,     0,     9,     2,     0,    10,     9,
       0,     2,     0,     5,     0,     3,     0,     3,     4,     2,
       0,     0,    12,     0,     8,     1,     2,     0,     9,     2,
       0,     6,     0,     9,     0,     5,     0,     0,     3,     0,
       5,     0,     4,     0,     4,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     3,     0,     2,     0,     2,
       3,     3,     5,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     0,     2,
       0,     2,     0,     2,     1,     0,     4,     0
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
#line 76 "sintatica_semantica.y"
                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "program"); head = (yyval.node_struct).nd;}
#line 1762 "y.tab.c"
    break;

  case 3: /* program: class program  */
#line 77 "sintatica_semantica.y"
                {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "program"); }
#line 1768 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 78 "sintatica_semantica.y"
                                       {add('s');}
#line 1774 "y.tab.c"
    break;

  case 6: /* program: %empty  */
#line 79 "sintatica_semantica.y"
 { (yyval.node_struct).nd = NULL; }
#line 1780 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 82 "sintatica_semantica.y"
                    {add('h');}
#line 1786 "y.tab.c"
    break;

  case 8: /* headers: TK_INCLUDE $@2  */
#line 82 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node(NULL, NULL, "INCLUDE");}
#line 1792 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 83 "sintatica_semantica.y"
            {add('h');}
#line 1798 "y.tab.c"
    break;

  case 10: /* headers: TK_INCLUDE $@3 headers  */
#line 83 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL, "INCLUDE2");}
#line 1804 "y.tab.c"
    break;

  case 11: /* headers: %empty  */
#line 84 "sintatica_semantica.y"
 {(yyval.node_struct).nd = NULL;}
#line 1810 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 87 "sintatica_semantica.y"
                                {add('s');}
#line 1816 "y.tab.c"
    break;

  case 13: /* class: TK_CLASSE TK_NOME_CLASSE $@4 '{' class_body '}'  */
#line 87 "sintatica_semantica.y"
                                                                {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "class");}
#line 1822 "y.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 90 "sintatica_semantica.y"
                                     {add('m');}
#line 1828 "y.tab.c"
    break;

  case 16: /* class_body: class_atributes class_body  */
#line 92 "sintatica_semantica.y"
                                       {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "class_body_atributes");}
#line 1834 "y.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 93 "sintatica_semantica.y"
                        {add('o');}
#line 1840 "y.tab.c"
    break;

  case 18: /* class_body: TK_NOME_CLASSE TK_ID $@6 '=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';' class_body  */
#line 93 "sintatica_semantica.y"
                                                                                       {(yyval.node_struct).nd = add_node((yyvsp[-9].node_struct).nd, (yyvsp[-8].node_struct).nd, "class_body_object");}
#line 1846 "y.tab.c"
    break;

  case 19: /* class_body: method '(' parameters ')' '{' body return '}' class_body  */
#line 94 "sintatica_semantica.y"
                                                           {
   struct node *aux = add_node((yyvsp[-3].node_struct).nd, (yyvsp[-2].node_struct).nd, "class_body_method_aux");
   struct node *aux2 = add_node(&*aux, (yyvsp[0].node_struct).nd, "class_body_method_aux2");
   struct node *aux3 = add_node((yyvsp[-8].node_struct).nd, (yyvsp[-6].node_struct).nd, "class_body_method_aux3");
   (yyval.node_struct).nd = add_node(aux3, aux2, "class_body_method");
}
#line 1857 "y.tab.c"
    break;

  case 20: /* class_body: %empty  */
#line 100 "sintatica_semantica.y"
   {(yyval.node_struct).nd = NULL;}
#line 1863 "y.tab.c"
    break;

  case 21: /* class_atributes: statement_atributes ';'  */
#line 103 "sintatica_semantica.y"
                                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "class_atributes");}
#line 1869 "y.tab.c"
    break;

  case 22: /* $@7: %empty  */
#line 106 "sintatica_semantica.y"
                                 {add('a');}
#line 1875 "y.tab.c"
    break;

  case 23: /* statement_atributes: type TK_ID $@7 '=' expression  */
#line 106 "sintatica_semantica.y"
                                                            {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[0].node_struct2).nd, "statement_atributes2");}
#line 1881 "y.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 107 "sintatica_semantica.y"
             {add('a');}
#line 1887 "y.tab.c"
    break;

  case 25: /* statement_atributes: type TK_ID $@8  */
#line 107 "sintatica_semantica.y"
                         {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "statement_atributes2");}
#line 1893 "y.tab.c"
    break;

  case 26: /* $@9: %empty  */
#line 110 "sintatica_semantica.y"
                   {add('m');}
#line 1899 "y.tab.c"
    break;

  case 27: /* method: type TK_ID $@9  */
#line 110 "sintatica_semantica.y"
                               {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "method");}
#line 1905 "y.tab.c"
    break;

  case 28: /* parameters: type TK_ID ',' parameters  */
#line 114 "sintatica_semantica.y"
                                     {(yyval.node_struct).nd = add_node((yyvsp[-3].node_struct).nd, (yyvsp[0].node_struct).nd, "parameters");}
#line 1911 "y.tab.c"
    break;

  case 29: /* parameters: type TK_ID  */
#line 115 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "parameters2");}
#line 1917 "y.tab.c"
    break;

  case 30: /* parameters: %empty  */
#line 116 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 1923 "y.tab.c"
    break;

  case 31: /* $@10: %empty  */
#line 120 "sintatica_semantica.y"
              {add('k');}
#line 1929 "y.tab.c"
    break;

  case 32: /* body: TK_PARA $@10 '(' statement ';' condition ';' statement ')' '{' body '}'  */
#line 120 "sintatica_semantica.y"
                                                                                    {
  struct node *aux = add_node((yyvsp[-6].node_struct).nd, (yyvsp[-4].node_struct).nd, "body_for_aux"); 
  struct node *aux2 = add_node((yyvsp[-8].node_struct).nd, aux, "body_for_aux2"); 
  (yyval.node_struct).nd = add_node(aux2, (yyvsp[-1].node_struct).nd, "body_for"); 
}
#line 1939 "y.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 131 "sintatica_semantica.y"
        {add('k');}
#line 1945 "y.tab.c"
    break;

  case 34: /* body: TK_SE $@11 '(' condition ')' '{' body '}'  */
#line 131 "sintatica_semantica.y"
                                                   {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[-1].node_struct).nd, "body_if");}
#line 1951 "y.tab.c"
    break;

  case 35: /* body: else  */
#line 132 "sintatica_semantica.y"
       {  (yyval.node_struct).nd = add_node((yyvsp[0].node_struct).nd, NULL, "body_if");}
#line 1957 "y.tab.c"
    break;

  case 36: /* body: statement ';'  */
#line 133 "sintatica_semantica.y"
                {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "body_statement");}
#line 1963 "y.tab.c"
    break;

  case 37: /* $@12: %empty  */
#line 134 "sintatica_semantica.y"
                       {add('o');}
#line 1969 "y.tab.c"
    break;

  case 38: /* body: TK_NOME_CLASSE TK_ID $@12 '=' TK_CLASSE TK_NOME_CLASSE '(' ')' ';'  */
#line 134 "sintatica_semantica.y"
                                                                            {(yyval.node_struct).nd = add_node(NULL, NULL, "body_object");}
#line 1975 "y.tab.c"
    break;

  case 39: /* body: body body  */
#line 135 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct).nd, "body");}
#line 1981 "y.tab.c"
    break;

  case 40: /* $@13: %empty  */
#line 136 "sintatica_semantica.y"
             {add('k');}
#line 1987 "y.tab.c"
    break;

  case 41: /* body: TK_ESCREVA $@13 '(' TK_STRING ')' ';'  */
#line 136 "sintatica_semantica.y"
                                               {(yyval.node_struct).nd = add_node(NULL, NULL, "body_printf");}
#line 1993 "y.tab.c"
    break;

  case 42: /* $@14: %empty  */
#line 137 "sintatica_semantica.y"
          {add('k');}
#line 1999 "y.tab.c"
    break;

  case 43: /* body: TK_LEIA $@14 '(' TK_STRING ',' '&' TK_ID ')' ';'  */
#line 137 "sintatica_semantica.y"
                                                          {(yyval.node_struct).nd = add_node(NULL, NULL, "body_scanf");}
#line 2005 "y.tab.c"
    break;

  case 44: /* $@15: %empty  */
#line 140 "sintatica_semantica.y"
               {add('k');}
#line 2011 "y.tab.c"
    break;

  case 45: /* else: TK_SENAO $@15 '{' body '}'  */
#line 140 "sintatica_semantica.y"
                                        {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, NULL, "else_body");}
#line 2017 "y.tab.c"
    break;

  case 46: /* else: %empty  */
#line 141 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 2023 "y.tab.c"
    break;

  case 47: /* $@16: %empty  */
#line 145 "sintatica_semantica.y"
                      {add('v');}
#line 2029 "y.tab.c"
    break;

  case 48: /* statement: type TK_ID $@16  */
#line 145 "sintatica_semantica.y"
                                  {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct).nd, NULL, "statement1");}
#line 2035 "y.tab.c"
    break;

  case 49: /* $@17: %empty  */
#line 146 "sintatica_semantica.y"
              {add('v');}
#line 2041 "y.tab.c"
    break;

  case 50: /* statement: type TK_ID $@17 '=' expression  */
#line 146 "sintatica_semantica.y"
                                          {(yyval.node_struct).nd = add_node((yyvsp[-4].node_struct).nd, (yyvsp[0].node_struct2).nd, "statement2"); check_type((yyvsp[-3].node_struct).name);}
#line 2047 "y.tab.c"
    break;

  case 51: /* $@18: %empty  */
#line 147 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2053 "y.tab.c"
    break;

  case 52: /* statement: TK_ID $@18 '=' expression  */
#line 147 "sintatica_semantica.y"
                                                     {(yyval.node_struct).nd = add_node((yyvsp[0].node_struct2).nd, NULL, "statement3"); check_type((yyvsp[-3].node_struct).name);}
#line 2059 "y.tab.c"
    break;

  case 53: /* $@19: %empty  */
#line 148 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2065 "y.tab.c"
    break;

  case 54: /* statement: TK_ID $@19 op expression  */
#line 148 "sintatica_semantica.y"
                                                    {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct).nd, (yyvsp[-1].node_struct).nd, "statement4");}
#line 2071 "y.tab.c"
    break;

  case 55: /* $@20: %empty  */
#line 152 "sintatica_semantica.y"
                  {insert_type();}
#line 2077 "y.tab.c"
    break;

  case 56: /* type: TK_TIPO_INT $@20  */
#line 152 "sintatica_semantica.y"
                                   {(yyval.node_struct).nd = add_node(NULL, NULL, "type_int");}
#line 2083 "y.tab.c"
    break;

  case 57: /* $@21: %empty  */
#line 153 "sintatica_semantica.y"
                {insert_type();}
#line 2089 "y.tab.c"
    break;

  case 58: /* type: TK_TIPO_FLOAT $@21  */
#line 153 "sintatica_semantica.y"
                                 {(yyval.node_struct).nd = add_node(NULL, NULL, "type_float");}
#line 2095 "y.tab.c"
    break;

  case 59: /* $@22: %empty  */
#line 154 "sintatica_semantica.y"
               {insert_type();}
#line 2101 "y.tab.c"
    break;

  case 60: /* type: TK_TIPO_CHAR $@22  */
#line 154 "sintatica_semantica.y"
                                {(yyval.node_struct).nd = add_node(NULL, NULL, "type_char");}
#line 2107 "y.tab.c"
    break;

  case 61: /* $@23: %empty  */
#line 155 "sintatica_semantica.y"
                 {insert_type();}
#line 2113 "y.tab.c"
    break;

  case 62: /* type: TK_TIPO_STRING $@23  */
#line 155 "sintatica_semantica.y"
                                  {(yyval.node_struct).nd = add_node(NULL, NULL, "type_string");}
#line 2119 "y.tab.c"
    break;

  case 63: /* $@24: %empty  */
#line 156 "sintatica_semantica.y"
                {insert_type();}
#line 2125 "y.tab.c"
    break;

  case 64: /* type: TK_TIPO_VAZIO $@24  */
#line 156 "sintatica_semantica.y"
                                 {(yyval.node_struct).nd = add_node(NULL, NULL, "type_void");}
#line 2131 "y.tab.c"
    break;

  case 65: /* condition: value op value  */
#line 160 "sintatica_semantica.y"
                           {
  struct node *aux = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct2).nd, "condition_aux"); 
  (yyval.node_struct).nd = add_node((yyvsp[-2].node_struct2).nd, aux, "condition");
}
#line 2140 "y.tab.c"
    break;

  case 66: /* $@25: %empty  */
#line 164 "sintatica_semantica.y"
                {add('k');}
#line 2146 "y.tab.c"
    break;

  case 67: /* condition: TK_VERDADEIRO $@25  */
#line 164 "sintatica_semantica.y"
                            {(yyval.node_struct).nd = add_node(NULL, NULL, "condition_true");}
#line 2152 "y.tab.c"
    break;

  case 68: /* $@26: %empty  */
#line 165 "sintatica_semantica.y"
           {add('k');}
#line 2158 "y.tab.c"
    break;

  case 69: /* condition: TK_FALSO $@26  */
#line 165 "sintatica_semantica.y"
                       {(yyval.node_struct).nd = add_node(NULL, NULL, "condition_false");}
#line 2164 "y.tab.c"
    break;

  case 70: /* condition: expression TK_IGUALDADE expression  */
#line 166 "sintatica_semantica.y"
                                     {(yyval.node_struct).nd = add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "condition_equal");}
#line 2170 "y.tab.c"
    break;

  case 71: /* expression: expression arithmetic expression  */
#line 170 "sintatica_semantica.y"
                                             {
  struct node *aux = add_node((yyvsp[-1].node_struct).nd, (yyvsp[0].node_struct2).nd, "expression1_aux"); 
  (yyval.node_struct2).nd = add_node((yyvsp[-2].node_struct2).nd, aux, "expression1");
}
#line 2179 "y.tab.c"
    break;

  case 72: /* expression: '(' expression arithmetic expression ')'  */
#line 174 "sintatica_semantica.y"
                                          {
  struct node *aux = add_node((yyvsp[-2].node_struct).nd, (yyvsp[-1].node_struct2).nd, "expression2_aux"); 
  (yyval.node_struct2).nd = add_node((yyvsp[-3].node_struct2).nd, aux, "expression2");
}
#line 2188 "y.tab.c"
    break;

  case 73: /* expression: value  */
#line 178 "sintatica_semantica.y"
        {(yyval.node_struct2).nd = add_node((yyvsp[0].node_struct2).nd, NULL, "expresion3");}
#line 2194 "y.tab.c"
    break;

  case 74: /* expression: expression TK_AND expression  */
#line 179 "sintatica_semantica.y"
                               {add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "expresion4");}
#line 2200 "y.tab.c"
    break;

  case 75: /* expression: expression TK_OR expression  */
#line 180 "sintatica_semantica.y"
                              {add_node((yyvsp[-2].node_struct2).nd, (yyvsp[0].node_struct2).nd, "expresion5");}
#line 2206 "y.tab.c"
    break;

  case 76: /* expression: '(' value ')'  */
#line 181 "sintatica_semantica.y"
                {add_node((yyvsp[-1].node_struct2).nd, NULL, "expresion6");}
#line 2212 "y.tab.c"
    break;

  case 77: /* arithmetic: TK_SOMA  */
#line 184 "sintatica_semantica.y"
                    {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_sum");}
#line 2218 "y.tab.c"
    break;

  case 78: /* arithmetic: TK_SUBTRACAO  */
#line 185 "sintatica_semantica.y"
                {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_sub");}
#line 2224 "y.tab.c"
    break;

  case 79: /* arithmetic: TK_MULTIPLICACAO  */
#line 186 "sintatica_semantica.y"
                   {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_mult");}
#line 2230 "y.tab.c"
    break;

  case 80: /* arithmetic: TK_DIVISAO  */
#line 187 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node(NULL, NULL, "arithmetic_div");}
#line 2236 "y.tab.c"
    break;

  case 81: /* op: TK_MAIOR  */
#line 190 "sintatica_semantica.y"
             {(yyval.node_struct).nd = add_node(NULL, NULL, "op_>");}
#line 2242 "y.tab.c"
    break;

  case 82: /* op: TK_MAIOR_IGUAL  */
#line 191 "sintatica_semantica.y"
                 {(yyval.node_struct).nd = add_node(NULL, NULL, "op_>=");}
#line 2248 "y.tab.c"
    break;

  case 83: /* op: TK_MENOR  */
#line 192 "sintatica_semantica.y"
           {(yyval.node_struct).nd = add_node(NULL, NULL, "op_<");}
#line 2254 "y.tab.c"
    break;

  case 84: /* op: TK_MENOR_IGUAL  */
#line 193 "sintatica_semantica.y"
                 {(yyval.node_struct).nd = add_node(NULL, NULL, "op_<=");}
#line 2260 "y.tab.c"
    break;

  case 85: /* op: TK_DIFERENTE  */
#line 194 "sintatica_semantica.y"
               {(yyval.node_struct).nd = add_node(NULL, NULL, "op_!=");}
#line 2266 "y.tab.c"
    break;

  case 86: /* $@27: %empty  */
#line 197 "sintatica_semantica.y"
              {add('c');}
#line 2272 "y.tab.c"
    break;

  case 87: /* value: TK_INT $@27  */
#line 197 "sintatica_semantica.y"
                          {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_int");}
#line 2278 "y.tab.c"
    break;

  case 88: /* $@28: %empty  */
#line 198 "sintatica_semantica.y"
           {add('c');}
#line 2284 "y.tab.c"
    break;

  case 89: /* value: TK_FLOAT $@28  */
#line 198 "sintatica_semantica.y"
                       {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_float");}
#line 2290 "y.tab.c"
    break;

  case 90: /* $@29: %empty  */
#line 199 "sintatica_semantica.y"
          {add('c');}
#line 2296 "y.tab.c"
    break;

  case 91: /* value: TK_CHAR $@29  */
#line 199 "sintatica_semantica.y"
                      {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_char");}
#line 2302 "y.tab.c"
    break;

  case 92: /* $@30: %empty  */
#line 200 "sintatica_semantica.y"
            {add('c');}
#line 2308 "y.tab.c"
    break;

  case 93: /* value: TK_STRING $@30  */
#line 200 "sintatica_semantica.y"
                        {(yyval.node_struct2).nd = add_node(NULL, NULL, "value_string");}
#line 2314 "y.tab.c"
    break;

  case 94: /* value: TK_ID  */
#line 201 "sintatica_semantica.y"
        {check_declaration((yyvsp[0].node_struct).name);}
#line 2320 "y.tab.c"
    break;

  case 95: /* $@31: %empty  */
#line 204 "sintatica_semantica.y"
                   {add('k');}
#line 2326 "y.tab.c"
    break;

  case 96: /* return: TK_RETORNE $@31 value ';'  */
#line 204 "sintatica_semantica.y"
                                         {(yyval.node_struct).nd = add_node((yyvsp[-1].node_struct2).nd, NULL, "return"); check_return();}
#line 2332 "y.tab.c"
    break;

  case 97: /* return: %empty  */
#line 205 "sintatica_semantica.y"
  {(yyval.node_struct).nd = NULL;}
#line 2338 "y.tab.c"
    break;


#line 2342 "y.tab.c"

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

#line 208 "sintatica_semantica.y"


// falta tratar para rodar com mais de um arquivo , classe principal, objetos(atributos), parametros, retorno da funcao
int main() {
    yyparse();
    printf("-*-*-*-*-*-* Tabela de simbolos -*-*-*-*-**-*-*--*-\n");
    for(int i=0; i<count; i++) {
      printf("%s\t%s\t%s\t%d\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i]. scope, symbol_table[i].line);
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

void check_declaration(const char *c) {    
    query = search(c);    
    if(!query) {        
        sprintf(errors[count_errors], "Linha %d: estrutura %s nao foi declarada\n", count_line, c);    
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


int search(const char *name) {
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

// verifica se as declaracoes de variaveis estao no mesmo escopo
int check_scope(const char *name){
  int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].name, name)== 0) {
      if(symbol_table[i].scope == count_scope){
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
          count++;
          count_scope++;
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
