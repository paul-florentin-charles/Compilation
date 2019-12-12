/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SRC_LANG_TAB_H_INCLUDED
# define YY_YY_SRC_LANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANTI = 258,
    CONSTANTF = 259,
    ID = 260,
    IF = 261,
    ELSE = 262,
    INT = 263,
    FLOAT = 264,
    VOID = 265,
    VIR = 266,
    PV = 267,
    AO = 268,
    AF = 269,
    PO = 270,
    PF = 271,
    UNTIL = 272,
    DO = 273,
    WHILE = 274,
    RETURN = 275,
    PLUS = 276,
    MOINS = 277,
    STAR = 278,
    DIV = 279,
    EQ = 280,
    INF = 281,
    EQUAL = 282,
    SUP = 283,
    DIFF = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    UNA = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "src/lang.y" /* yacc.c:1909  */

  int n;
  float f;
  registre reg;
  reg_type r_type;
  type_and_ptr t_p;
  int n_ptr;
  char * sid;
  label lab;
  f_decl f_d;
  elem_reg * reg_list;
  struct elem_fun * fun_list;
  elem * list;
  p_list p_l;
  f_head f_h;

#line 105 "src/lang.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_LANG_TAB_H_INCLUDED  */
