#ifndef ARGLIST_H
#define ARGLIST_H
#include "utile.h"
#include "Table_des_registres.h"

typedef struct {
  reg_type type;
  int reg_id;
} argu;

void arglist_reset();

int arglist_size();

void arglist_add(reg_type type, reg_type id);

argu arglist_get();

#endif
