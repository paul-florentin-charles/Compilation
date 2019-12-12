#include "utile.h"
#include <stdlib.h>
#include <stdio.h>

const char * llvm_void = "void";
const char * llvm_int = "i32";
const char * llvm_float = "float";
const char * llvm_default = "default";

/* generation de numero de registre */

registre new_reg() {
  static int n = 0;
  registre reg = {.id = n++, .type = R_VOID, .n_ptr=0, .r_str = NULL, .is_init = 0 };
  return reg;
}

/* generation de numero de label */

label new_label() {
  static int n = 0;
  label result = {.one = n++, .two = n++};
  return result;
}

type_and_ptr new_type_and_ptr() {
  type_and_ptr t_ptr = {.type = R_VOID, .n_ptr = 0};
  return t_ptr;
}

const char* llvm_type(reg_type r_t) {
  switch(r_t) {
  case R_VOID:
    return llvm_void;
  case R_INT:
    return llvm_int;
  case R_FLOAT:
    return llvm_float;
  default:
    quit("unrecognised type : doesnt belong to the grammar");
    return llvm_default;
  }
}

bool is_float(reg_type r_t) {
  if (r_t == R_FLOAT)
    return true;
  return false;
}

bool is_int(reg_type r_t) {
  if (r_t == R_INT)
    return true;
  return false;
}

bool is_void(reg_type r_t) {
  if (r_t == R_VOID)
    return true;
  return false;
}

registre float_to_int(registre r) {
  registre res = new_reg();
  res.type = R_INT;
  printf("%%r%i = fptosi float %%r%i to i32\n", res.id, r.id);
  return res;
}

registre int_to_float(registre r) {
  registre res = new_reg();
  res.type = R_FLOAT;
  printf("%%r%i = sitofp i32 %%r%i to float\n", res.id, r.id);
  return res;
}

void float_to_hex(float f, char buff[]) {
  double f_d = (double) f;
  double * f_d_ptr = &f_d;

  sprintf(buff, "0x%016LX", *((unsigned long long int *) (f_d_ptr)));
}

