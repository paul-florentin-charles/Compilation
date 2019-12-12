#include "utile.h"

#ifndef SEMACT_EXP_H
#define SEMACT_EXP_H

registre exp_neg(registre);

registre exp_add(registre, registre);

registre exp_sub(registre, registre);

registre exp_mul(registre, registre);

registre exp_div(registre, registre);

registre exp_id(char*, int);

registre exp_csti(int);

registre exp_cstf(float);

#endif
