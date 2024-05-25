/* A Bison parser, made by GNU Bison 3.8.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INTERPRETER_TAB_H_INCLUDED
# define YY_YY_INTERPRETER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    SEMICOLON = 258,               /* SEMICOLON  */
    PRINT = 259,                   /* PRINT  */
    READ = 260,                    /* READ  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    READ_STRING = 264,             /* READ_STRING  */
    THEN = 265,                    /* THEN  */
    END_IF = 266,                  /* END_IF  */
    DO = 267,                      /* DO  */
    END_WHILE = 268,               /* END_WHILE  */
    REPEAT = 269,                  /* REPEAT  */
    UNTIL = 270,                   /* UNTIL  */
    FOR = 271,                     /* FOR  */
    END_FOR = 272,                 /* END_FOR  */
    FROM = 273,                    /* FROM  */
    STEP = 274,                    /* STEP  */
    CASE = 275,                    /* CASE  */
    VALUE = 276,                   /* VALUE  */
    DEFAULT = 277,                 /* DEFAULT  */
    END_CASE = 278,                /* END_CASE  */
    CLEAN = 279,                   /* CLEAN  */
    PLACE = 280,                   /* PLACE  */
    LETFCURLYBRACKET = 281,        /* LETFCURLYBRACKET  */
    RIGHTCURLYBRACKET = 282,       /* RIGHTCURLYBRACKET  */
    ASSIGNMENT = 283,              /* ASSIGNMENT  */
    COMMA = 284,                   /* COMMA  */
    NUMBER = 285,                  /* NUMBER  */
    BOOL = 286,                    /* BOOL  */
    VARIABLE = 287,                /* VARIABLE  */
    UNDEFINED = 288,               /* UNDEFINED  */
    CONSTANT = 289,                /* CONSTANT  */
    BUILTIN = 290,                 /* BUILTIN  */
    STRING = 291,                  /* STRING  */
    OR = 292,                      /* OR  */
    AND = 293,                     /* AND  */
    GREATER_OR_EQUAL = 294,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 295,           /* LESS_OR_EQUAL  */
    GREATER_THAN = 296,            /* GREATER_THAN  */
    LESS_THAN = 297,               /* LESS_THAN  */
    EQUAL = 298,                   /* EQUAL  */
    NOT_EQUAL = 299,               /* NOT_EQUAL  */
    NOT = 300,                     /* NOT  */
    PLUS = 301,                    /* PLUS  */
    MINUS = 302,                   /* MINUS  */
    MULTIPLICATION = 303,          /* MULTIPLICATION  */
    DIVISION = 304,                /* DIVISION  */
    MODULO = 305,                  /* MODULO  */
    LPAREN = 306,                  /* LPAREN  */
    RPAREN = 307,                  /* RPAREN  */
    UNARY = 308,                   /* UNARY  */
    POWER = 309                    /* POWER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 141 "interpreter.y"

  double number;
  char * string; 				 /* NEW in example 7 */
  bool logic;						 /* NEW in example 15 */
  lp::ExpNode *expNode;  			 /* NEW in example 16 */
  std::list<lp::ExpNode *>  *parameters;    // New in example 16; NOTE: #include<list> must be in interpreter.l, init.cpp, interpreter.cpp
  std::list<lp::Statement *> *stmts; /* NEW in example 16 */
  lp::Statement *st;				 /* NEW in example 16 */
  lp::AST *prog;					 /* NEW in example 16 */

#line 129 "interpreter.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INTERPRETER_TAB_H_INCLUDED  */
