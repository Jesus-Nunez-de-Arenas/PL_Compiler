/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "interpreter.y"

#include <iostream>
#include <string>

/*******************************************/
/* NEW in example 5 */
/* pow */
#include <math.h>
/*******************************************/

/*******************************************/
/* NEW in example 6 */
/* Use for recovery of runtime errors */
#include <setjmp.h>
#include <signal.h>
/*******************************************/

/* Error recovery functions */
#include "../error/error.hpp"

/* Macros for the screen */
#include "../includes/macros.hpp"


/*******************************************/
/* 
  NEW in example 16
  AST class
  IMPORTANT: this file must be before init.hpp
*/
#include "../ast/ast.hpp"


/*******************************************/
/* NEW in example 7 */
/* Table of symbol */
#include "../table/table.hpp"
/*******************************************/

/*******************************************/
#include "../table/numericVariable.hpp"
/*******************************************/

/* NEW in example 15 */
#include "../table/logicalVariable.hpp"

/*******************************************/
/* NEW in example 11 */
#include "../table/numericConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 15 */
#include "../table/logicalConstant.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 13 */
#include "../table/builtinParameter1.hpp"
/*******************************************/

/*******************************************/
/* NEW in example 14 */
#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter2.hpp"
/*******************************************/


/*******************************************/
/* NEW in example 10 */
#include "../table/init.hpp"
/*******************************************/

/*! 
	\brief  Lexical or scanner function
	\return int
	\note   C++ requires that yylex returns an int value
	\sa     yyparser
*/
int yylex();


extern int lineNumber; //!< External line counter


/* NEW in example 15 */
extern bool interactiveMode; //!< Control the interactive mode of execution of the interpreter

/* New in example 17 */
extern int control; //!< External: to control the interactive mode in "if" and "while" sentences 




/***********************************************************/
/* NEW in example 2 */
extern std::string progname; //!<  Program name
/***********************************************************/

/*******************************************/
/* NEW in example 6 */
/*
 jhmp_buf
    This is an array type capable of storing the information of a calling environment to be restored later.
   This information is filled by calling macro setjmp and can be restored by calling function longjmp.
*/
jmp_buf begin; //!<  It enables recovery of runtime errors 
/*******************************************/


/*******************************************/
/* NEW in example 7 */
extern lp::Table table; //!< Extern Table of Symbols

/*******************************************/
/* NEW in example 16 */
extern lp::AST *root; //!< External root of the abstract syntax tree AST


#line 191 "interpreter.tab.c"

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

#include "interpreter.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_READ_STRING = 9,                /* READ_STRING  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_END_IF = 11,                    /* END_IF  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_END_WHILE = 13,                 /* END_WHILE  */
  YYSYMBOL_REPEAT = 14,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 15,                     /* UNTIL  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_END_FOR = 17,                   /* END_FOR  */
  YYSYMBOL_FROM = 18,                      /* FROM  */
  YYSYMBOL_STEP = 19,                      /* STEP  */
  YYSYMBOL_CASE = 20,                      /* CASE  */
  YYSYMBOL_VALUE = 21,                     /* VALUE  */
  YYSYMBOL_DEFAULT = 22,                   /* DEFAULT  */
  YYSYMBOL_END_CASE = 23,                  /* END_CASE  */
  YYSYMBOL_CLEAN = 24,                     /* CLEAN  */
  YYSYMBOL_PLACE = 25,                     /* PLACE  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_LETFCURLYBRACKET = 27,          /* LETFCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 28,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_ASSIGNMENT = 29,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_NUMBER = 31,                    /* NUMBER  */
  YYSYMBOL_BOOL = 32,                      /* BOOL  */
  YYSYMBOL_VARIABLE = 33,                  /* VARIABLE  */
  YYSYMBOL_UNDEFINED = 34,                 /* UNDEFINED  */
  YYSYMBOL_CONSTANT = 35,                  /* CONSTANT  */
  YYSYMBOL_BUILTIN = 36,                   /* BUILTIN  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_GREATER_OR_EQUAL = 40,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 41,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 42,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 43,                 /* LESS_THAN  */
  YYSYMBOL_EQUAL = 44,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 45,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_PLUS = 47,                      /* PLUS  */
  YYSYMBOL_MINUS = 48,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 49,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 50,                  /* DIVISION  */
  YYSYMBOL_MODULO = 51,                    /* MODULO  */
  YYSYMBOL_INTEGER_DIVISION = 52,          /* INTEGER_DIVISION  */
  YYSYMBOL_CONCATENATION = 53,             /* CONCATENATION  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_UNARY = 56,                     /* UNARY  */
  YYSYMBOL_POWER = 57,                     /* POWER  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_stmtlist = 60,                  /* stmtlist  */
  YYSYMBOL_stmt = 61,                      /* stmt  */
  YYSYMBOL_block = 62,                     /* block  */
  YYSYMBOL_controlSymbol = 63,             /* controlSymbol  */
  YYSYMBOL_if = 64,                        /* if  */
  YYSYMBOL_while = 65,                     /* while  */
  YYSYMBOL_do = 66,                        /* do  */
  YYSYMBOL_repeat = 67,                    /* repeat  */
  YYSYMBOL_for = 68,                       /* for  */
  YYSYMBOL_case = 69,                      /* case  */
  YYSYMBOL_values = 70,                    /* values  */
  YYSYMBOL_default = 71,                   /* default  */
  YYSYMBOL_cond = 72,                      /* cond  */
  YYSYMBOL_clear = 73,                     /* clear  */
  YYSYMBOL_place = 74,                     /* place  */
  YYSYMBOL_asgn = 75,                      /* asgn  */
  YYSYMBOL_print = 76,                     /* print  */
  YYSYMBOL_read = 77,                      /* read  */
  YYSYMBOL_read_string = 78,               /* read_string  */
  YYSYMBOL_exp = 79,                       /* exp  */
  YYSYMBOL_listOfExp = 80,                 /* listOfExp  */
  YYSYMBOL_restOfListOfExp = 81            /* restOfListOfExp  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   245,   245,   259,   264,   287,   298,   303,   308,   313,
     319,   326,   333,   339,   345,   351,   357,   363,   369,   375,
     383,   391,   399,   409,   420,   431,   440,   449,   458,   466,
     473,   480,   486,   492,   499,   506,   513,   519,   526,   531,
     537,   544,   551,   557,   564,   570,   576,   582,   588,   594,
     600,   606,   612,   618,   624,   630,   636,   643,   649,   655,
     662,   709,   715,   721,   727,   733,   739,   745,   751,   757,
     767,   772,   783,   788
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "PRINT",
  "READ", "IF", "ELSE", "WHILE", "READ_STRING", "THEN", "END_IF", "DO",
  "END_WHILE", "REPEAT", "UNTIL", "FOR", "END_FOR", "FROM", "STEP", "CASE",
  "VALUE", "DEFAULT", "END_CASE", "CLEAN", "PLACE", "COLON",
  "LETFCURLYBRACKET", "RIGHTCURLYBRACKET", "ASSIGNMENT", "COMMA", "NUMBER",
  "BOOL", "VARIABLE", "UNDEFINED", "CONSTANT", "BUILTIN", "STRING", "OR",
  "AND", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "GREATER_THAN", "LESS_THAN",
  "EQUAL", "NOT_EQUAL", "NOT", "PLUS", "MINUS", "MULTIPLICATION",
  "DIVISION", "MODULO", "INTEGER_DIVISION", "CONCATENATION", "LPAREN",
  "RPAREN", "UNARY", "POWER", "$accept", "program", "stmtlist", "stmt",
  "block", "controlSymbol", "if", "while", "do", "repeat", "for", "case",
  "values", "default", "cond", "clear", "place", "asgn", "print", "read",
  "read_string", "exp", "listOfExp", "restOfListOfExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,     2,   209,   -43,   -43,   -43,    57,   -41,   -43,   -43,
     -20,   -43,   -43,    19,   -43,    50,     3,   -43,    27,    29,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
      56,    68,    76,    77,   -43,   -43,   -43,     6,   -43,    57,
      57,    57,    57,   705,   -28,    33,    33,     0,   539,   341,
      63,    35,   -43,    57,   374,   608,   608,   -43,   -43,   -43,
     -43,    57,   -33,    34,    34,   625,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    40,    41,    57,    87,    86,    44,    45,   -43,
     -43,    57,    57,    25,   -43,    27,    29,   -43,   705,   -43,
     705,   585,    51,   -43,   724,   742,   760,   760,   760,   760,
     760,   760,   600,   600,   -25,   -25,   -25,    34,    34,    34,
     -43,   -43,   645,   -43,   -43,   -43,   -43,    33,    33,   127,
     665,    57,    57,   -43,   -43,   -43,   308,   407,    86,   -43,
      57,    88,   685,   585,   -43,   -43,   -43,   154,    57,     8,
     104,   -43,   440,    57,   541,    57,    89,    91,   -43,   -43,
      96,   -43,   561,   -43,   -43,   -43,   242,   -43,   473,   -43,
     275,   506,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     5,     6,     0,     0,    21,    21,
       0,     3,     3,     0,    21,     0,     0,     3,     0,     0,
       4,    17,    11,    12,    14,    15,    13,    16,    18,    19,
       0,     0,     0,     0,    45,    58,    59,     0,    46,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     7,     8,     9,
      10,    70,    69,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      21,     0,     0,     0,    20,    58,    59,    37,    36,    39,
      38,    72,     0,    53,    68,    67,    62,    64,    61,    63,
      65,    66,    48,    49,    50,    51,    56,    52,    47,    57,
      41,    42,     0,     3,     3,    43,    44,     0,     0,     0,
       0,     0,     0,    71,    60,    33,     0,     0,    25,    26,
       0,     0,     0,    72,     3,    22,    24,     0,     0,    32,
       0,    73,     0,     0,     0,     0,     0,     0,    35,    23,
       0,     3,     0,     3,    28,    21,     0,     3,     0,     3,
       0,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -11,   -43,   -43,    -6,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -42,   -43,   -43,   -34,   -43,   -43,
     -43,   -30,   -43,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    20,    21,    45,    22,    23,    24,    25,
      26,    27,   149,   157,    85,    28,    29,    30,    31,    32,
      33,    43,   102,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,     3,    46,    86,    82,    54,    83,    51,    62,
      63,    64,    65,    44,    74,    75,    76,    77,    78,    79,
      80,    97,    99,    93,    81,    98,   100,    79,    80,   155,
     156,   101,    81,    87,    47,    88,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    50,    52,   122,   131,    55,    53,    56,    57,
      61,   129,   130,    66,    67,    68,    69,    70,    71,    72,
      73,    58,    74,    75,    76,    77,    78,    79,    80,    59,
      60,    91,    81,   127,   128,   138,   139,    84,    34,    92,
      35,    81,    36,    37,    38,   120,   121,   123,   124,   125,
     126,   142,   143,    39,    40,    41,   134,   158,   165,   148,
     147,    42,   136,   137,   164,   163,   151,     0,   154,     0,
       0,     0,     0,   160,     0,   162,     0,     0,     0,     0,
       0,     0,     0,   152,    66,    67,    68,    69,    70,    71,
      72,    73,   140,    74,    75,    76,    77,    78,    79,    80,
     166,     0,   168,    81,     0,     0,   170,     0,   171,   169,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,   153,    74,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,    80,     0,    -2,
       4,    81,     5,     6,     7,     8,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,     0,    14,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
       0,     0,    18,     4,    19,     5,     6,     7,     8,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,     0,
       0,     0,    14,   -29,   -29,   -29,    15,    16,     0,    17,
       0,     0,     0,     0,     0,    18,     4,    19,     5,     6,
       7,     8,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,     0,    14,   -30,   -30,   -30,    15,
      16,     0,    17,     0,     0,     0,     0,     0,    18,     4,
      19,     5,     6,     7,     8,   144,     9,    10,     0,   145,
      11,     0,    12,     0,    13,     0,     0,     0,    14,     0,
       0,     0,    15,    16,     0,    17,     0,     0,     0,     0,
       0,    18,     4,    19,     5,     6,     7,     8,     0,     9,
      10,     0,     0,    11,     0,    12,    90,    13,     0,     0,
       0,    14,     0,     0,     0,    15,    16,     0,    17,     0,
       0,     0,     0,     0,    18,     4,    19,     5,     6,     7,
       8,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,     0,    14,     0,     0,     0,    15,    16,
       0,    17,    94,     0,     0,     0,     0,    18,     4,    19,
       5,     6,     7,     8,     0,     9,    10,     0,     0,    11,
     146,    12,     0,    13,     0,     0,     0,    14,     0,     0,
       0,    15,    16,     0,    17,     0,     0,     0,     0,     0,
      18,     4,    19,     5,     6,     7,     8,     0,     9,    10,
       0,   159,    11,     0,    12,     0,    13,     0,     0,     0,
      14,     0,     0,     0,    15,    16,     0,    17,     0,     0,
       0,     0,     0,    18,     4,    19,     5,     6,     7,     8,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
       0,     0,     0,    14,     0,     0,   -31,    15,    16,     0,
      17,     0,     0,     0,     0,     0,    18,     4,    19,     5,
       6,     7,     8,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,   172,     0,     0,    14,     0,     0,     0,
      15,    16,     0,    17,     0,     0,     0,     0,     0,    18,
       4,    19,     5,     6,     7,     8,     0,    89,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,     0,    14,
       0,     0,     0,    15,    16,     0,    17,   161,     0,     0,
       0,     0,    18,     0,    19,     0,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,   167,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    81,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,    77,    78,    79,    80,   132,     0,     0,    81,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,    34,
       0,    95,    81,    96,    37,    38,     0,     0,     0,    76,
      77,    78,    79,    80,    39,    40,    41,    81,     0,     0,
       0,     0,    42,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
     103,     0,    81,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
     135,     0,    81,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
     141,     0,    81,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
     150,     0,    81,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    81,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    81,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    81,
     -32,   -32,   -32,   -32,   -32,   -32,     0,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      11,    12,     0,     9,    46,    33,    17,    35,    14,    39,
      40,    41,    42,    54,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    53,    57,    55,    56,    52,    53,    21,
      22,    61,    57,    33,    54,    35,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    33,     3,    84,    30,    29,    54,    29,     3,
      54,    91,    92,    38,    39,    40,    41,    42,    43,    44,
      45,     3,    47,    48,    49,    50,    51,    52,    53,     3,
       3,    18,    57,    89,    90,   127,   128,    54,    31,    54,
      33,    57,    35,    36,    37,    55,    55,    10,    12,    55,
      55,   131,   132,    46,    47,    48,    55,     3,    12,    21,
     140,    54,   123,   124,    23,    26,   143,    -1,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    38,    39,    40,    41,    42,    43,
      44,    45,    15,    47,    48,    49,    50,    51,    52,    53,
     161,    -1,   163,    57,    -1,    -1,   167,    -1,   169,   165,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    19,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,     0,
       1,    57,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,     1,    35,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    12,    -1,    14,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    33,     1,    35,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    12,    -1,    14,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,     1,
      35,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,     1,    35,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,     1,    35,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    12,    -1,    14,    -1,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,     1,    35,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,     1,    35,     3,     4,     5,     6,    -1,     8,     9,
      -1,    11,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,     1,    35,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    12,    -1,    14,    -1,    16,
      -1,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,     1,    35,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    -1,
      14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
       1,    35,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    -1,    27,    26,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    26,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    48,
      49,    50,    51,    52,    53,    30,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    31,
      -1,    33,    57,    35,    36,    37,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    46,    47,    48,    57,    -1,    -1,
      -1,    -1,    54,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    40,    41,    42,    43,    44,    45,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,    60,     0,     1,     3,     4,     5,     6,     8,
       9,    12,    14,    16,    20,    24,    25,    27,    33,    35,
      61,    62,    64,    65,    66,    67,    68,    69,    73,    74,
      75,    76,    77,    78,    31,    33,    35,    36,    37,    46,
      47,    48,    54,    79,    54,    63,    63,    54,    60,    60,
      33,    63,     3,    54,    60,    29,    29,     3,     3,     3,
       3,    54,    79,    79,    79,    79,    38,    39,    40,    41,
      42,    43,    44,    45,    47,    48,    49,    50,    51,    52,
      53,    57,    33,    35,    54,    72,    72,    33,    35,     8,
      15,    18,    54,    79,    28,    33,    35,    75,    79,    75,
      79,    79,    80,    55,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      55,    55,    79,    10,    12,    55,    55,    63,    63,    79,
      79,    30,    30,    81,    55,    55,    60,    60,    72,    72,
      15,    55,    79,    79,     7,    11,    13,    79,    21,    70,
      55,    81,    60,    19,    79,    21,    22,    71,     3,    11,
      79,    26,    79,    26,    23,    12,    60,    26,    60,    63,
      60,    60,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    64,    64,    65,    66,    67,    68,    69,    70,
      70,    71,    71,    72,    73,    74,    75,    75,    75,    75,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     6,     8,     6,     5,     5,    12,     8,     4,
       5,     3,     0,     3,     2,     7,     3,     3,     3,     3,
       2,     4,     4,     4,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       0,     2,     0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* program: stmtlist  */
#line 246 "interpreter.y"
                  { 
		    // Create a new AST
			(yyval.prog) = new lp::AST((yyvsp[0].stmts)); 

			// Assign the AST to the root
			root = (yyval.prog); 

			// End of parsing
			//	return 1;
		  }
#line 1779 "interpreter.tab.c"
    break;

  case 3: /* stmtlist: %empty  */
#line 259 "interpreter.y"
                  { 
			// create a empty list of statements
			(yyval.stmts) = new std::list<lp::Statement *>(); 
		  }
#line 1788 "interpreter.tab.c"
    break;

  case 4: /* stmtlist: stmtlist stmt  */
#line 265 "interpreter.y"
                  { 
			// copy up the list and add the stmt to it
			(yyval.stmts) = (yyvsp[-1].stmts);
			(yyval.stmts)->push_back((yyvsp[0].st));

			// Control the interative mode of execution of the interpreter
			if (interactiveMode == true && control == 0)
 			{
				for(std::list<lp::Statement *>::iterator it = (yyval.stmts)->begin(); 
						it != (yyval.stmts)->end(); 
						it++)
				{
					(*it)->printAST();
					(*it)->evaluate();
					
				}

				// Delete the AST code, because it has already run in the interactive mode.
				(yyval.stmts)->clear();
			}
		}
#line 1814 "interpreter.tab.c"
    break;

  case 5: /* stmtlist: stmtlist error  */
#line 288 "interpreter.y"
      { 
			 // just copy up the stmtlist when an error occurs
			 (yyval.stmts) = (yyvsp[-1].stmts);

			 // The previous look-ahead token ought to be discarded with `yyclearin;'
			 yyclearin; 
       }
#line 1826 "interpreter.tab.c"
    break;

  case 6: /* stmt: SEMICOLON  */
#line 299 "interpreter.y"
          {
		// Create a new empty statement node
		(yyval.st) = new lp::EmptyStmt(); 
	  }
#line 1835 "interpreter.tab.c"
    break;

  case 7: /* stmt: asgn SEMICOLON  */
#line 304 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1844 "interpreter.tab.c"
    break;

  case 8: /* stmt: print SEMICOLON  */
#line 309 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1853 "interpreter.tab.c"
    break;

  case 9: /* stmt: read SEMICOLON  */
#line 314 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1862 "interpreter.tab.c"
    break;

  case 10: /* stmt: read_string SEMICOLON  */
#line 320 "interpreter.y"
          {
		// Default action
		// $$ = $1;
	  }
#line 1871 "interpreter.tab.c"
    break;

  case 11: /* stmt: if  */
#line 327 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1880 "interpreter.tab.c"
    break;

  case 12: /* stmt: while  */
#line 334 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1889 "interpreter.tab.c"
    break;

  case 13: /* stmt: for  */
#line 340 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1898 "interpreter.tab.c"
    break;

  case 14: /* stmt: do  */
#line 346 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1907 "interpreter.tab.c"
    break;

  case 15: /* stmt: repeat  */
#line 352 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1916 "interpreter.tab.c"
    break;

  case 16: /* stmt: case  */
#line 358 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1925 "interpreter.tab.c"
    break;

  case 17: /* stmt: block  */
#line 364 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1934 "interpreter.tab.c"
    break;

  case 18: /* stmt: clear  */
#line 370 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1943 "interpreter.tab.c"
    break;

  case 19: /* stmt: place  */
#line 376 "interpreter.y"
         {
		// Default action
		// $$ = $1;
	 }
#line 1952 "interpreter.tab.c"
    break;

  case 20: /* block: LETFCURLYBRACKET stmtlist RIGHTCURLYBRACKET  */
#line 384 "interpreter.y"
                {
			// Create a new block of statements node
			(yyval.st) = new lp::BlockStmt((yyvsp[-1].stmts)); 
		}
#line 1961 "interpreter.tab.c"
    break;

  case 21: /* controlSymbol: %empty  */
#line 391 "interpreter.y"
                {
			// To control the interactive mode in "if" and "while" sentences
			control++;
		}
#line 1970 "interpreter.tab.c"
    break;

  case 22: /* if: IF controlSymbol cond THEN stmtlist END_IF  */
#line 400 "interpreter.y"
    {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	}
#line 1982 "interpreter.tab.c"
    break;

  case 23: /* if: IF controlSymbol cond THEN stmtlist ELSE stmtlist END_IF  */
#line 410 "interpreter.y"
         {
		// Create a new if statement node
		(yyval.st) = new lp::IfStmt((yyvsp[-5].expNode), (yyvsp[-3].stmts), (yyvsp[-1].stmts));

		// To control the interactive mode
		control--;
	 }
#line 1994 "interpreter.tab.c"
    break;

  case 24: /* while: WHILE controlSymbol cond DO stmtlist END_WHILE  */
#line 421 "interpreter.y"
                {
			// Create a new while statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[-3].expNode), (yyvsp[-1].stmts));

			// To control the interactive mode
			control--;
    }
#line 2006 "interpreter.tab.c"
    break;

  case 25: /* do: DO stmtlist WHILE controlSymbol cond  */
#line 432 "interpreter.y"
                {
			// Create a new do statement node
			(yyval.st) = new lp::WhileStmt((yyvsp[0].expNode), (yyvsp[-3].stmts));

			control--;
		}
#line 2017 "interpreter.tab.c"
    break;

  case 26: /* repeat: REPEAT stmtlist UNTIL controlSymbol cond  */
#line 441 "interpreter.y"
                {
			// Create a new repeat statement node
			(yyval.st) = new lp::RepeatStmt((yyvsp[0].expNode), (yyvsp[-3].stmts));

			control--;
		}
#line 2028 "interpreter.tab.c"
    break;

  case 27: /* for: FOR VARIABLE FROM exp UNTIL exp STEP exp DO controlSymbol stmtlist END_FOR  */
#line 450 "interpreter.y"
                {
			// Create a new for statement node
			(yyval.st) = new lp::ForStmt((yyvsp[-10].string), (yyvsp[-8].expNode), (yyvsp[-6].expNode), (yyvsp[-4].expNode), (yyvsp[-1].stmts));

			control--;
		}
#line 2039 "interpreter.tab.c"
    break;

  case 28: /* case: CASE controlSymbol LPAREN exp RPAREN values default END_CASE  */
#line 459 "interpreter.y"
                {
			// Create a new case statement node
			(yyval.st) = new lp::CaseStmt((yyvsp[-4].expNode), (std::list<lp::ValueStmt *> *) (yyvsp[-2].values), (lp::DefaultStmt *) (yyvsp[-1].st));

			control--;
		}
#line 2050 "interpreter.tab.c"
    break;

  case 29: /* values: VALUE exp COLON stmtlist  */
#line 467 "interpreter.y"
                {
			// Create a new values statement node
			std::list<lp::ValueStmt *> * stmts = new std::list<lp::ValueStmt *>();
			stmts->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
			(yyval.values) = stmts;
		}
#line 2061 "interpreter.tab.c"
    break;

  case 30: /* values: values VALUE exp COLON stmtlist  */
#line 474 "interpreter.y"
                {
			// Create a new values statement node
			(yyval.values) = (yyvsp[-4].values);
			(yyval.values)->push_back(new lp::ValueStmt((yyvsp[-2].expNode), (yyvsp[0].stmts)));
		}
#line 2071 "interpreter.tab.c"
    break;

  case 31: /* default: DEFAULT COLON stmtlist  */
#line 481 "interpreter.y"
                {
			// Create a new default statement node
			(yyval.st) = new lp::DefaultStmt((yyvsp[0].stmts));
		}
#line 2080 "interpreter.tab.c"
    break;

  case 32: /* default: %empty  */
#line 486 "interpreter.y"
                {
			// Create a new default statement node
			(yyval.st) = new lp::DefaultStmt(new std::list<lp::Statement*>());
		}
#line 2089 "interpreter.tab.c"
    break;

  case 33: /* cond: LPAREN exp RPAREN  */
#line 493 "interpreter.y"
                { 
			(yyval.expNode) = (yyvsp[-1].expNode);
		}
#line 2097 "interpreter.tab.c"
    break;

  case 34: /* clear: CLEAN SEMICOLON  */
#line 500 "interpreter.y"
                {
			// Create a new clear statement node
			(yyval.st) = new lp::ClearStmt();
		}
#line 2106 "interpreter.tab.c"
    break;

  case 35: /* place: PLACE LPAREN exp COMMA exp RPAREN SEMICOLON  */
#line 507 "interpreter.y"
                {
			// Create a new place node
			(yyval.st) = new lp::PlaceStmt((yyvsp[-4].expNode), (yyvsp[-2].expNode));
		}
#line 2115 "interpreter.tab.c"
    break;

  case 36: /* asgn: VARIABLE ASSIGNMENT exp  */
#line 514 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (yyvsp[0].expNode));
		}
#line 2124 "interpreter.tab.c"
    break;

  case 37: /* asgn: VARIABLE ASSIGNMENT asgn  */
#line 520 "interpreter.y"
                { 
			// Create a new assignment node
			(yyval.st) = new lp::AssignmentStmt((yyvsp[-2].string), (lp::AssignmentStmt *) (yyvsp[0].st));
		}
#line 2133 "interpreter.tab.c"
    break;

  case 38: /* asgn: CONSTANT ASSIGNMENT exp  */
#line 527 "interpreter.y"
                {   
 			execerror("Semantic error in assignment: it is not allowed to modify a constant ", (yyvsp[-2].string));
		}
#line 2141 "interpreter.tab.c"
    break;

  case 39: /* asgn: CONSTANT ASSIGNMENT asgn  */
#line 532 "interpreter.y"
                {   
 			execerror("Semantic error in multiple assignment: it is not allowed to modify a constant ",(yyvsp[-2].string));
		}
#line 2149 "interpreter.tab.c"
    break;

  case 40: /* print: PRINT exp  */
#line 538 "interpreter.y"
                {
			// Create a new print node
			 (yyval.st) = new lp::PrintStmt((yyvsp[0].expNode));
		}
#line 2158 "interpreter.tab.c"
    break;

  case 41: /* read: READ LPAREN VARIABLE RPAREN  */
#line 545 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStmt((yyvsp[-1].string));
		}
#line 2167 "interpreter.tab.c"
    break;

  case 42: /* read: READ LPAREN CONSTANT RPAREN  */
#line 552 "interpreter.y"
                {   
 			execerror("Semantic error in \"read statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2175 "interpreter.tab.c"
    break;

  case 43: /* read_string: READ_STRING LPAREN VARIABLE RPAREN  */
#line 558 "interpreter.y"
                {
			// Create a new read node
			 (yyval.st) = new lp::ReadStringStmt((yyvsp[-1].string));
		}
#line 2184 "interpreter.tab.c"
    break;

  case 44: /* read_string: READ_STRING LPAREN CONSTANT RPAREN  */
#line 565 "interpreter.y"
                {   
 			execerror("Semantic error in \"read_string statement\": it is not allowed to modify a constant ",(yyvsp[-1].string));
		}
#line 2192 "interpreter.tab.c"
    break;

  case 45: /* exp: NUMBER  */
#line 571 "interpreter.y"
                { 
			// Create a new number node
			(yyval.expNode) = new lp::NumberNode((yyvsp[0].number));
		}
#line 2201 "interpreter.tab.c"
    break;

  case 46: /* exp: STRING  */
#line 577 "interpreter.y"
                {
			// Create a new string node
			(yyval.expNode) = new lp::StringNode((yyvsp[0].string));
		}
#line 2210 "interpreter.tab.c"
    break;

  case 47: /* exp: exp CONCATENATION exp  */
#line 583 "interpreter.y"
                {
			// Create a new concatenation node
			(yyval.expNode) = new lp::ConcatenationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2219 "interpreter.tab.c"
    break;

  case 48: /* exp: exp PLUS exp  */
#line 589 "interpreter.y"
                { 
			// Create a new plus node
			 (yyval.expNode) = new lp::PlusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		 }
#line 2228 "interpreter.tab.c"
    break;

  case 49: /* exp: exp MINUS exp  */
#line 595 "interpreter.y"
        {
			// Create a new minus node
			(yyval.expNode) = new lp::MinusNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2237 "interpreter.tab.c"
    break;

  case 50: /* exp: exp MULTIPLICATION exp  */
#line 601 "interpreter.y"
                { 
			// Create a new multiplication node
			(yyval.expNode) = new lp::MultiplicationNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2246 "interpreter.tab.c"
    break;

  case 51: /* exp: exp DIVISION exp  */
#line 607 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::DivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2255 "interpreter.tab.c"
    break;

  case 52: /* exp: exp INTEGER_DIVISION exp  */
#line 613 "interpreter.y"
                {
		  // Create a new division node	
		  (yyval.expNode) = new lp::IntegerDivisionNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
	   }
#line 2264 "interpreter.tab.c"
    break;

  case 53: /* exp: LPAREN exp RPAREN  */
#line 619 "interpreter.y"
        { 
		    // just copy up the expression node 
			(yyval.expNode) = (yyvsp[-1].expNode);
		 }
#line 2273 "interpreter.tab.c"
    break;

  case 54: /* exp: PLUS exp  */
#line 625 "interpreter.y"
                { 
		  // Create a new unary plus node	
  		  (yyval.expNode) = new lp::UnaryPlusNode((yyvsp[0].expNode));
		}
#line 2282 "interpreter.tab.c"
    break;

  case 55: /* exp: MINUS exp  */
#line 631 "interpreter.y"
                { 
		  // Create a new unary minus node	
  		  (yyval.expNode) = new lp::UnaryMinusNode((yyvsp[0].expNode));
		}
#line 2291 "interpreter.tab.c"
    break;

  case 56: /* exp: exp MODULO exp  */
#line 637 "interpreter.y"
                {
		  // Create a new modulo node	

		  (yyval.expNode) = new lp::ModuloNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
       }
#line 2301 "interpreter.tab.c"
    break;

  case 57: /* exp: exp POWER exp  */
#line 644 "interpreter.y"
        { 
		  // Create a new power node	
  		  (yyval.expNode) = new lp::PowerNode((yyvsp[-2].expNode), (yyvsp[0].expNode));
		}
#line 2310 "interpreter.tab.c"
    break;

  case 58: /* exp: VARIABLE  */
#line 650 "interpreter.y"
                {
		  // Create a new variable node	
		  (yyval.expNode) = new lp::VariableNode((yyvsp[0].string));
		}
#line 2319 "interpreter.tab.c"
    break;

  case 59: /* exp: CONSTANT  */
#line 656 "interpreter.y"
                {
		  // Create a new constant node	
		  (yyval.expNode) = new lp::ConstantNode((yyvsp[0].string));

		}
#line 2329 "interpreter.tab.c"
    break;

  case 60: /* exp: BUILTIN LPAREN listOfExp RPAREN  */
#line 663 "interpreter.y"
                {
			// Get the identifier in the table of symbols as Builtin
			lp::Builtin *f= (lp::Builtin *) table.getSymbol((yyvsp[-3].string));

			// Check the number of parameters 
			if (f->getNParameters() ==  (int) (yyvsp[-1].parameters)->size())
			{
				switch(f->getNParameters())
				{
					case 0:
						{
							// Create a new Builtin Function with 0 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_0((yyvsp[-3].string));
						}
						break;

					case 1:
						{
							// Get the expression from the list of expressions
							lp::ExpNode *e = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 1 parameter node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_1((yyvsp[-3].string),e);
						}
						break;

					case 2:
						{
							// Get the expressions from the list of expressions
							lp::ExpNode *e1 = (yyvsp[-1].parameters)->front();
							(yyvsp[-1].parameters)->pop_front();
							lp::ExpNode *e2 = (yyvsp[-1].parameters)->front();

							// Create a new Builtin Function with 2 parameters node	
							(yyval.expNode) = new lp::BuiltinFunctionNode_2((yyvsp[-3].string),e1,e2);
						}
						break;

					default:
				  			 execerror("Syntax error: too many parameters for function ", (yyvsp[-3].string));
				} 
			}
			else
	  			 execerror("Syntax error: incompatible number of parameters for function", (yyvsp[-3].string));
		}
#line 2379 "interpreter.tab.c"
    break;

  case 61: /* exp: exp GREATER_THAN exp  */
#line 710 "interpreter.y"
                {
		  // Create a new "greater than" node	
 			(yyval.expNode) = new lp::GreaterThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2388 "interpreter.tab.c"
    break;

  case 62: /* exp: exp GREATER_OR_EQUAL exp  */
#line 716 "interpreter.y"
                {
		  // Create a new "greater or equal" node	
 			(yyval.expNode) = new lp::GreaterOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2397 "interpreter.tab.c"
    break;

  case 63: /* exp: exp LESS_THAN exp  */
#line 722 "interpreter.y"
                {
		  // Create a new "less than" node	
 			(yyval.expNode) = new lp::LessThanNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2406 "interpreter.tab.c"
    break;

  case 64: /* exp: exp LESS_OR_EQUAL exp  */
#line 728 "interpreter.y"
                {
		  // Create a new "less or equal" node	
 			(yyval.expNode) = new lp::LessOrEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2415 "interpreter.tab.c"
    break;

  case 65: /* exp: exp EQUAL exp  */
#line 734 "interpreter.y"
                {
		  // Create a new "equal" node	
 			(yyval.expNode) = new lp::EqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2424 "interpreter.tab.c"
    break;

  case 66: /* exp: exp NOT_EQUAL exp  */
#line 740 "interpreter.y"
                {
		  // Create a new "not equal" node	
 			(yyval.expNode) = new lp::NotEqualNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2433 "interpreter.tab.c"
    break;

  case 67: /* exp: exp AND exp  */
#line 746 "interpreter.y"
                {
		  // Create a new "logic and" node	
 			(yyval.expNode) = new lp::AndNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2442 "interpreter.tab.c"
    break;

  case 68: /* exp: exp OR exp  */
#line 752 "interpreter.y"
                {
		  // Create a new "logic or" node	
 			(yyval.expNode) = new lp::OrNode((yyvsp[-2].expNode),(yyvsp[0].expNode));
		}
#line 2451 "interpreter.tab.c"
    break;

  case 69: /* exp: NOT exp  */
#line 758 "interpreter.y"
                {
		  // Create a new "logic negation" node	
 			(yyval.expNode) = new lp::NotNode((yyvsp[0].expNode));
		}
#line 2460 "interpreter.tab.c"
    break;

  case 70: /* listOfExp: %empty  */
#line 767 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2469 "interpreter.tab.c"
    break;

  case 71: /* listOfExp: exp restOfListOfExp  */
#line 773 "interpreter.y"
                        {
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2480 "interpreter.tab.c"
    break;

  case 72: /* restOfListOfExp: %empty  */
#line 783 "interpreter.y"
                        {
			    // Create a new list STL
				(yyval.parameters) = new std::list<lp::ExpNode *>(); 
			}
#line 2489 "interpreter.tab.c"
    break;

  case 73: /* restOfListOfExp: COMMA exp restOfListOfExp  */
#line 789 "interpreter.y"
                        {
				// Get the list of expressions
				(yyval.parameters) = (yyvsp[0].parameters);

				// Insert the expression in the list of expressions
				(yyval.parameters)->push_front((yyvsp[-1].expNode));
			}
#line 2501 "interpreter.tab.c"
    break;


#line 2505 "interpreter.tab.c"

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
          YYNOMEM;
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 800 "interpreter.y"




