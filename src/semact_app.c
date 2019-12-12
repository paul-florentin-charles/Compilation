#include "arglist.h"
#include "semact_app.h"
#include "Table_des_fonctions.h"

registre fun_app(sid id) {
  fun f = sid_to_fun(id);
  registre res = new_reg();
  res.type = f.ret_type;
  char* id_s = id;
  if (f.ret_type != R_VOID)
    printf("%%r%i = ", res.id);
  printf("call %s @%s(", llvm_type(res.type), id_s);
  int n_arg = arglist_size();
  if (n_arg != f.n_args)
    quit("Wrong number of args");
  int vir=0;
  for (int i=0; i< n_arg; ++i) {
    if (vir) {
      printf(", ");
    } else {
      vir=1;
    }
    argu a = arglist_get();
    if (a.type != f.args_type[i])
      quit("Wrong arg type");
    printf("%s %%r%i", llvm_type(a.type), a.reg_id);
  }
  printf(")\n");
  arglist_reset();
  return res;
}

void fun_app_arg(sid id) {
  registre reg = sid_to_reg(id);
  registre res = new_reg();
  res.type = reg.type;
  res.n_ptr = reg.n_ptr;
  res.r_str = reg.r_str;
  char* id_s = id;
  printf("%%r%i = load %s, %s* %%%s\n", res.id, llvm_type(reg.type), llvm_type(reg.type), id_s);

  arglist_add(reg.type, res.id);
}
