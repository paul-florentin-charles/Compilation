#include "semact_fun.h"
#include "semact_decl.h"
#include "Table_des_fonctions.h"

void alloc_param(char * str, reg_type r_t, int n_ptr, int scope) {
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

  printf("store %s %%%s.val, %s* %%%s\n", llvm_type(r_t), str, llvm_type(r_t), str);

  registre res; 
  //char * str_reg = strcat(str, ".addr");
  res.r_str = str;
  res.type = r_t;
  res.n_ptr = n_ptr;
  res.is_init = 1;
  //printf("str = %s, type = %s, n_ptr = %d\n", tmp.r_str, llvm_type(r_t), n_ptr);
  reg_to_sid(res);
  insert_scope_reg(res.r_str, scope);
}

void fun_param(type_and_ptr t_p, char * sid) {
  if (t_p.type == R_VOID) {
    quit("void can only be used as a return type");
  }
  
  printf("%s",llvm_type(t_p.type));
  
  int i;
  for (i = 0; i < t_p.n_ptr; i++) {
    printf("*");
    }
  
  printf(" %%%s.val, ", sid);  
}

void fun_param_end(type_and_ptr t_p, char * sid) {
  if (t_p.type == R_VOID) {
    quit("void can only be used as a return type");
  }
  
  printf("%s",llvm_type(t_p.type));

  int i;
  for (i = 0; i < t_p.n_ptr; i++) {
    printf("*");
    }
  
  printf(" %%%s.val) {\n", sid); 
}

void fun_type(type_and_ptr t_p) {
  printf("define %s", llvm_type(t_p.type));

  int i;
  for (i = 0; i < t_p.n_ptr; i++) {
    printf("*");
    }
  printf(" ");
}

void fun_head(char * sid) {
  printf("@%s(", sid);
}

void fun_decl(type_and_ptr t_p, f_head f_h, int scope) {
  fun_type(t_p);
  fun_head(f_h.name);
  fun f;
  f.name = f_h.name;
  f.ret_type = t_p.type;
  int lgth = f_h.p_l.cpt;
  f.n_args = lgth;
  if (lgth > 0) {
    int i;
    for (i = 0; i < lgth - 1; i++) {
      fun_param(f_h.p_l.args[i].t_p, f_h.p_l.args[i].name);
      f.args_type[i] = f_h.p_l.args[i].t_p.type;
    }
    fun_param_end(f_h.p_l.args[lgth - 1].t_p, f_h.p_l.args[lgth - 1].name);
    f.args_type[lgth - 1] = f_h.p_l.args[lgth - 1].t_p.type;

    fun_to_sid(f);
    
    for (i = 0; i < lgth - 1; i++) {
      alloc_param(f_h.p_l.args[i].name, f_h.p_l.args[i].t_p.type, f_h.p_l.args[i].t_p.n_ptr, scope);
    }
    alloc_param(f_h.p_l.args[lgth - 1].name, f_h.p_l.args[lgth - 1].t_p.type, f_h.p_l.args[lgth - 1].t_p.n_ptr, scope);
    
  } else {
    printf(") {\n");
  }
}

void fun_ret(registre r, reg_type r_t) {
  if (r.type == R_VOID && r_t != R_VOID) {
    quit("this function should not return a void");
  } else if (r.type  != R_VOID && r_t == R_VOID) {
    quit("this function should return a void");
  } else if (r.type == R_INT && r_t == R_FLOAT) {
    registre r_ = int_to_float(r);
    fun_ret(r_, r_t);
    return;
  } else if (r.type == R_FLOAT && r_t == R_INT) {
    registre r_ = float_to_int(r);
    fun_ret(r_, r_t);
    return;
  }
    
  printf("ret %s", llvm_type(r.type)); 

  int i;
  for (i = 0; i < r.n_ptr; i++) {
    printf("*");
  }
  
  printf(" %%r%i\n",r.id);
}
