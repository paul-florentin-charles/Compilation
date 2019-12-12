#include "semact_bool.h"

// Modifier le champ label du registre de sortie

void bool_br(registre r, label l) {
  printf("br i1 %%r%i, label %%L%i, label %%L%i\n", r.id, l.one, l.two);
}

void bool_label_true(label l) {
  printf("L%i:\n", l.one);
}

void bool_label_false(label l) {
  printf("L%i:\n", l.two);
}

label bool_inf(registre l, registre r) {
  label res = new_label();
  registre rcmp = new_reg();
  if (is_float(l.type) && is_float(r.type)) {
    printf("%%r%i = fcmp olt float %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && is_int(r.type)) {
    printf("%%r%i = icmp slt i32 %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && (is_float(r.type))) {
    printf("%%r%i = fcmp olt float %%r%i, %%r%i\n", rcmp.id, int_to_float(l).id, r.id);
  }
  else if (is_float(l.type) && (is_int(r.type))) {
    printf("%%r%i = fcmp olt float %%r%i, %%r%i\n", rcmp.id, l.id, int_to_float(r).id);
  }
  else {
    quit("can't compare registers that are not numbers");
  }
  bool_br(rcmp, res);
  return res;
}

label bool_sup(registre l, registre r) {
  label res = new_label();
  registre rcmp = new_reg();
  if (is_float(l.type) && is_float(r.type)) {
    printf("%%r%i = fcmp ogt float %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && is_int(r.type)) {
    printf("%%r%i = icmp sgt i32 %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && (is_float(r.type))) {
    printf("%%r%i = fcmp ogt float %%r%i, %%r%i\n", rcmp.id, int_to_float(l).id, r.id);
  }
  else if (is_float(l.type) && (is_int(r.type))) {
    printf("%%r%i = fcmp ogt float %%r%i, %%r%i\n", rcmp.id, l.id, int_to_float(r).id);
  }
  else {
    quit("can't compare registers that are not numbers");
  }
  bool_br(rcmp, res);
  return res;
}
 
label bool_eq(registre l, registre r) {
  label res = new_label();
  registre rcmp = new_reg();
  if (is_float(l.type) && is_float(r.type)) {
    printf("%%r%i = fcmp oeq float %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && is_int(r.type)) {
    printf("%%r%i = icmp eq i32 %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && (is_float(r.type))) {
    printf("%%r%i = fcmp oeq float %%r%i, %%r%i\n", rcmp.id, int_to_float(l).id, r.id);
  }
  else if (is_float(l.type) && (is_int(r.type))) {
    printf("%%r%i = fcmp oeq float %%r%i, %%r%i\n", rcmp.id, l.id, int_to_float(r).id);
  }
  else {
    quit("can't compare registers that are not numbers");
  }
  bool_br(rcmp, res);
  return res;
}

label bool_diff(registre l, registre r) {
  label res = new_label();
  registre rcmp = new_reg();
  if (is_float(l.type) && is_float(r.type)) {
    printf("%%r%i = fcmp one float %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && is_int(r.type)) {
    printf("%%r%i = icmp ne i32 %%r%i, %%r%i\n", rcmp.id, l.id, r.id);
  }
  else if (is_int(l.type) && (is_float(r.type))) {
    printf("%%r%i = fcmp one float %%r%i, %%r%i\n", rcmp.id, int_to_float(l).id, r.id);
  }
  else if (is_float(l.type) && (is_int(r.type))) {
    printf("%%r%i = fcmp one float %%r%i, %%r%i\n", rcmp.id, l.id, int_to_float(r).id);
  }
  else {
    quit("can't compare registers that are not numbers");
  }
  bool_br(rcmp, res);
  return res;
}

label bool_and(label l, label r) {
  label res;
  res.one = r.one;
  res.two = l.two;
  
  printf("L%i:\nbr label %%L%i\n", r.two, l.two);
  return res;
}

label bool_or(label l, label r) {
  label res;
  res.one = l.one;
  res.two = r.two;
  
  printf("L%i:\nbr label %%L%i\n", r.one, l.one);
  return res;
}

label bool_not(label l) {
  label res;
  res.one = l.two;
  res.two = l.one;
  
  return res;
}

// TODO : Modifier les valeurs pour les numéros de label

label bool_cond(label l) {
  //label res = new_label();
  printf("**bool_cond**\n");
  return l;
}

