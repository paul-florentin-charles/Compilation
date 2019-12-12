#include "utile.h"

#ifndef SEMACT_FUN_H
#define SEMACT_FUN_H

void alloc_param(char *, reg_type, int, int);

void fun_param(type_and_ptr, char *);

void fun_param_end(type_and_ptr, char *);

void fun_type(type_and_ptr);

void fun_head(char *);

void fun_decl(type_and_ptr, f_head, int);

void fun_ret(registre, reg_type);

#endif

