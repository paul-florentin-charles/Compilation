#ifndef SEMACT_BOOL_H
#define SEMACT_BOOL_H

#include "utile.h"

void bool_label_true(label l);

void bool_label_false(label l);

label bool_inf(registre, registre);

label bool_sup(registre, registre);

label bool_eq(registre, registre);

label bool_diff(registre, registre);

label bool_and(label, label);

label bool_or(label, label);

label bool_not(label);

label bool_cond(label);

#endif
