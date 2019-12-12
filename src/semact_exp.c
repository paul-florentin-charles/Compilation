#include "semact_exp.h"
#include <string.h>
#include "Table_des_registres.h"

registre exp_neg(registre r) {
  registre res = new_reg();
  if (r.n_ptr > 0)
    quit("can't negate reference");
  if (r.type == R_VOID)
    quit("can't negate void value");
  res.type = r.type;
  if (is_float(r.type)) {
    printf("%%r%i = fsub float ", res.id);
  } else {
    printf("%%r%i = sub add ", res.id);
  }
  printf("0, %%r%i\n", r.id);
  return res;
}


registre exp_add(registre l, registre r) {
  registre res;
  if (r.n_ptr > 0 && l.n_ptr > 0)
    quit("can't sum two pointers");
  if (r.type == R_VOID || l.type == R_VOID)
    quit("can't sum a void type");
  if (is_float(r.type) && is_float(l.type)) {
    res = new_reg();
    res.type = R_FLOAT;
    printf("%%r%i = fadd float ", res.id);
  } else if (is_int(r.type) && is_int(l.type)) {
    res = new_reg();
    res.type = R_INT;
    printf("%%r%i = add i32 ", res.id);
  } else if (is_int(l.type) && is_float(r.type)) {
    registre res_cvrt = int_to_float(l);
    return exp_add(res_cvrt, r);
  } else if (is_float(l.type) && is_int(r.type)) {
    registre res_cvrt = int_to_float(r);
    return exp_add(l, res_cvrt);
  } else {
    quit("Bad types for arithmetic operation");
  }
  printf("%%r%i, %%r%i\n", l.id, r.id);
  return res;
}

registre exp_sub(registre l, registre r) {
  registre res;
  if (r.n_ptr != l.n_ptr) {
    quit("uncompatible pointers");
  } else {
    res.n_ptr = r.n_ptr;
  }
  if (r.type == R_VOID || l.type == R_VOID)
    quit("can't soustract a void type");
  if (is_float(r.type) && is_float(l.type)) {
    res = new_reg();
    res.type = R_FLOAT;
    printf("%%r%i = fsub float ", res.id);
  } else if (is_int(r.type) && is_int(l.type)) {
    res = new_reg();
    res.type = R_INT;
    printf("%%r%i = sub i32 ", res.id);
  } else if (is_int(l.type) && is_float(r.type)) {
    registre res_cvrt = int_to_float(l);
    return exp_sub(res_cvrt, r);
  } else if (is_float(l.type) && is_int(r.type)) {
    registre res_cvrt = int_to_float(r);
    return exp_sub(l, res_cvrt);
  } else {
    quit("Bad types for arithmetic operation");
  }
  printf("%%r%i, %%r%i\n", l.id, r.id);
  return res;
}

registre exp_mul(registre l, registre r) {
  registre res;
  if (r.n_ptr > 0 && l.n_ptr > 0)
    quit("can't multiply two pointers");
  if (r.type == R_VOID || l.type == R_VOID)
    quit("can't multiply a void type");
  if (is_float(r.type) && is_float(l.type)) {
    res = new_reg();
    res.type = R_FLOAT;
    printf("%%r%i = fmul float ", res.id);
  } else if (is_int(r.type) && is_int(l.type)) {
    res = new_reg();
    res.type = R_INT;
    printf("%%r%i = mul i32 ", res.id);
  } else if (is_int(l.type) && is_float(r.type)) {
    registre res_cvrt = int_to_float(l);
    return exp_mul(res_cvrt, r);
  } else if (is_float(l.type) && is_int(r.type)) {
    registre res_cvrt = int_to_float(r);
    return exp_mul(l, res_cvrt);
  } else {
    quit("Bad types for arithmetic operation");
  }
  printf("%%r%i, %%r%i\n", l.id, r.id);
  return res;
}

registre exp_div(registre l, registre r) {
registre res;
  if (r.n_ptr > 0 && l.n_ptr > 0)
    quit("can't div two pointers");
  if (r.type == R_VOID || l.type == R_VOID)
    quit("can't divide a void type");
  if (is_float(r.type) && is_float(l.type)) {
    res = new_reg();
    res.type = R_FLOAT;
    printf("%%r%i = fdiv float ", res.id);
  } else if (is_int(r.type) && is_int(l.type)) {
    res = new_reg();
    res.type = R_INT;
    printf("%%r%i = div i32 ", res.id);
  } else if (is_int(l.type) && is_float(r.type)) {
    registre res_cvrt = int_to_float(l);
    return exp_div(res_cvrt, r);
  } else if (is_float(l.type) && is_int(r.type)) {
    registre res_cvrt = int_to_float(r);
    return exp_div(l, res_cvrt);
  } else {
    quit("Bad types for arithmetic operation");
  }
  printf("%%r%i, %%r%i\n", l.id, r.id);
  return res;
}

registre exp_id(char* s_id, int scope) {
  registre res = new_reg();
  registre r = sid_to_reg(s_id);
  res.type = r.type;
  res.n_ptr = r.n_ptr;
  res.r_str = r.r_str;
  if (!sid_valid(s_id, scope)) {
    quit("variable doesn't exist");
  } else if (!r.is_init) {
    quit("variable isn't initialized"); 
  } else {
    printf("%%r%i = load %s, %s* %%%s\n", res.id, llvm_type(res.type),llvm_type(res.type), s_id);
  }
  return res;
}

registre exp_csti(int n) {
  registre res = new_reg();
  res.type = R_INT;
  res.is_init = 1;
  printf("%%r%i = add i32 %d, 0\n", res.id, n);
  return res;
}

registre exp_cstf(float f) {
  registre res = new_reg();
  res.type = R_FLOAT;
  res.is_init = 1;
  char buff[19];
  float_to_hex(f, buff);
  char buff_2[19];
  float_to_hex(0,buff_2);
  printf("%%r%i = fadd float %s, %s\n", res.id, buff, buff_2);
  return res;
}

