#include "semact_decl.h"

void display_ptr(int n_ptr) {
  int i;
  for (i = 0; i < n_ptr; i++) {
    printf("*");
  }
  printf("\n");
}

void alloc(char * str, reg_type r_t, int n_ptr, int scope) {
  if (!sid_valid(str, scope) && r_t != R_VOID) {
    string_to_sid(str);
    insert_scope(str, scope);
    printf("%%%s = alloca %s", str, llvm_type(r_t));
    display_ptr(n_ptr);
  }
  else if (r_t == R_VOID) {
    quit("can't allocate void variable");
  }
  else {
    quit("variable already exists");
  }

  registre tmp;
  tmp.r_str = str;
  tmp.type = r_t;
  tmp.n_ptr = n_ptr;
  //printf("str = %s, type = %s, n_ptr = %d\n", tmp.r_str, llvm_type(r_t), n_ptr);
  reg_to_sid(tmp);
  insert_scope_reg(tmp.r_str, scope);
}
