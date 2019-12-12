#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "Table_des_chaines.h"
#include "Table_des_registres.h"

#ifndef UTILE_H
#define UTILE_H

typedef struct {
  int one;
  int two;
} label;

typedef struct {
  reg_type type;
  int n_ptr;
} type_and_ptr;

typedef struct {
  type_and_ptr t_p;
  char * name;
} arg;

typedef struct {
  arg args[40];
  int cpt;
} p_list;

typedef struct {
  p_list p_l;
  char * name;
} f_head;

typedef struct {
} f_body;

typedef struct {
  reg_type ret_type;
  int ret_n_ptr;
  f_head f_h;
  f_body f_b;
} f_decl;



/* generation de numero de registre */

registre new_reg();

/* generation de numero de label */

label new_label();

/* generation d'un type_and_ptr */

type_and_ptr new_type_and_ptr();

/* renvoie le type llvm correspondant */
const char* llvm_type(reg_type);

/* vérifie le type d'un registre */

bool is_void(reg_type);

bool is_int(reg_type);

bool is_float(reg_type);

/* fonctions de conversion */

registre float_to_int(registre);

registre int_to_float(registre); 

void float_to_hex(float, char []);

#endif
