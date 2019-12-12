%{
#include <string.h>
#include <stdio.h>
#include "utile.h"
#include "Table_des_registres.h"
#include "Table_des_fonctions.h"
#include "semact_decl.h"
#include "semact_exp.h"
#include "semact_bool.h"
#include "semact_fun.h"
#include "semact_aff.h"
#include "semact_app.h"
  
#define YYDEBUG 1

#define MAX_ARGLIST_LENGTH 1000
  
  void yyerror (char* s) {
    printf ("%s\n",s);
  }

  void yywrap () {

  }

  int yylex();

  static int scope = 0;
  static int has_ret = 0;
  static reg_type ret_type = R_VOID;
%}

/* Le type union (plus ou moins mal définissable en C) permet de représenter l'union disjointe
de deux types.En maths, on peut poser A + B = ({1} x A) U ({2} x B).

Un élement de A + B est  alors de la forme (t,v) avec t = 1 ou 2. La valeur de t permet de savoir
si la valeur v est de type A  (lorsque t = 1) ou de type A (lorsque t = 2).

Le type union ci-dessous fait (presque) la même chose pour le type attribut, le "typage" d'un
attribut se faisant à l'utilisation par $<type>n. Example: $<sid>-3 indique que l'atrribut $-3
sera lue comme un char * (le type de sid). */


%union {
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
}

%token <n> CONSTANTI /* attribut d’une constante entière = int */
%token <f> CONSTANTF /* attribut d’une constante flottante = float */

%token <sid> ID /* attribut d’un registre = sid */

%token IF ELSE


%token INT FLOAT VOID

%token VIR PV AO AF PO PF
%token UNTIL DO WHILE RETURN

%token PLUS MOINS STAR DIV EQ
%token INF EQUAL SUP DIFF
%token AND OR NOT

%left PLUS MOINS
%left STAR DIV    /* * et / plus prioritaires que + et - */

%nonassoc NOT
%left OR
%left AND
%nonassoc UNA    /* pseudo token pour assurer une priorite locale */
%nonassoc ELSE

%type <reg> exp fun_app  /* attribut d’une expr = valeur entiere */
%type <r_type> typename
%type <t_p> type
%type <lab> if else bool bool_cond while do
%type <n_ptr> pointer
%type <reg_list> return_list_reg
%type <fun_list> return_list_fun
%type <list> return_list   
%type <f_h> fun fun_head
%type <f_d> fun_decl
%type <p_l> param_list
   
%start lcc

%%

lcc : return_list_fun return_list_reg return_list block free_lists;

return_list_fun : {$$ = return_list_fun(); };

return_list_reg: {$$ = return_list_reg(); };

return_list: {$$ = return_list(); };

block: decl block | inst block | ;

// declarations

decl: var_decl PV
| fun_decl;

var_decl : type vlist;

fun_decl : type fun fun_body {ret_type = R_VOID; };

fun : fun_head {ret_type = $<t_p>0.type; $$ = $1; scope += 1; fun_decl($<t_p>0, $$, scope); } 

fun_head : ID PO PF {$$.name = $1; $$.p_l.cpt = 0; }
| ID PO param_list PF {$$.name = $1; $$.p_l = $3; }

fun_body : AO block AF {if (! has_ret) printf("ret void\n"); has_ret=0; printf("}\n"); remove_str(scope); remove_reg(scope); scope -= 1; }

type
: typename pointer {$$.type = $1; $$.n_ptr = $2;}
| typename {$$.type = $1; $$.n_ptr = 0; }
;

typename
: INT {$$ = R_INT; }
| FLOAT {$$ = R_FLOAT; }
| VOID {$$ = R_VOID; }
;

pointer : STAR pointer {$$ = $2 + 1; }
| STAR {$$ = 1; }
;

param_list: param_list vir type ID {$$.args[$$.cpt].t_p = $3 ; $$.args[$$.cpt].name = $4; $$.cpt = $1.cpt + 1; }
| type ID {$$.args[$$.cpt].t_p = $1; $$.args[$$.cpt].name = $2; $$.cpt += 1; }
;

vlist: vlist vir ID {alloc($3, $<t_p>0.type, $<t_p>0.n_ptr, scope); }
| ID {alloc($1, $<t_p>0.type, $<t_p>0.n_ptr, scope); };

vir : VIR ;

inst:
exp PV
| AO {scope += 1 ; } block AF {remove_str(scope); remove_reg(scope); scope -= 1; }
| cond
| loop
| aff
| ret
| PV;

loop : while PO bool PF DO {printf("L%i:\n", $3.one);} AO block AF {printf("br label %%L%i\n", $1.one); bool_label_false($3);}
| do AO block AF WHILE PO bool PF PV {bool_label_true($7); printf("br label %%L%i\n", $1.one); bool_label_false($7);}
;

 while : WHILE {$$ = new_label(); printf("L%i:\n", $$.one);};
do : DO {$$ = new_label(); printf("L%i:\n", $$.one);};

fun_app : ID PO args PF {$$ = fun_app($1); };

args : arglist
| ;

arglist : ID {fun_app_arg($1); } VIR arglist 
| ID {fun_app_arg($1); };

aff : ID EQ exp PV {aff($3, $1);} ;

ret : RETURN PV {printf("ret void\n"); has_ret = 1; }
| RETURN exp PV {fun_ret($2, ret_type); has_ret = 1; } ;

cond :
if bool_cond inst %prec UNA {bool_label_false($2);}
| if bool_cond inst else inst {bool_label_true($1);}


bool_cond : PO bool PF {$$=$2; bool_label_true($2); } 


if : IF {$$ = new_label(); };

 else : ELSE {printf("br label %%L%i\n", $<lab>-2.one); printf("L%i:\n", $<lab>-1.two);};

bool :
exp INF exp {$$ = bool_inf($1,$3); }
| exp SUP exp {$$ = bool_sup($1,$3); }
| exp EQUAL exp {$$ = bool_eq($1,$3); }
| exp DIFF exp {$$ = bool_diff($1,$3); }
| bool AND {bool_label_true($1);} bool {$$ = bool_and($1,$4); }
| bool OR {bool_label_false($1);} bool {$$ = bool_or($1,$4); }
| NOT bool {$$ = bool_not($2); }
| PO bool PF{$$ = $2;};

exp
: MOINS exp %prec UNA {$$ = exp_neg($2); }
| exp PLUS exp {$$ = exp_add($1, $3); }
| exp MOINS exp {$$ = exp_sub($1, $3); }
| exp STAR exp {$$ = exp_mul($1, $3); }
| exp DIV exp {$$ = exp_div($1, $3); }
| PO exp PF {$$=$2; }
| ID {$$ = exp_id($1, scope); }
| CONSTANTI {$$ = exp_csti($1); }
| CONSTANTF {$$ = exp_cstf($1); }
| fun_app {$$ = $1; }
;

free_lists : {delete_list($<list>-1); delete_list_reg($<reg_list>-2); delete_list_fun($<fun_list>-3);};

%%
int main () {
  return yyparse();
}
