#include "semact_aff.h"
#include "utile.h"

void aff(registre exp, char* var_name) {
  registre var = sid_to_reg(var_name);
  sid_init(var_name);
  
  /* à creuser pour faire les scopes
  registre res = new_reg();
  res.r_str = var;
  res.type = v.type;
  */
  
  if (var.type == R_INT && exp.type == R_INT) {
    printf("store i32 %%r%i, i32* %%%s\n", exp.id, var_name);
  } else if (var.type == R_FLOAT && exp.type == R_FLOAT) {
    printf("store float %%r%i, float* %%%s\n", exp.id, var_name);
  } else if (var.type == R_FLOAT && exp.type == R_INT) {
    registre r = int_to_float(exp);
    printf("store float %%r%i, float* %%%s\n", r.id, var_name);
  } else if (var.type == R_INT && exp.type == R_FLOAT) {
    registre r = float_to_int(exp);
    printf("store i32 %%r%i, i32* %%%s\n", r.id, var_name);
  } else {
    quit("Bad affectation");
  }
}
