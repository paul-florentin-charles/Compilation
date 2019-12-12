/*
 *  Table des registres.h
 * 
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 *  This module provide an (implicit) storage capacity
 *  that copy and store each (null terminated) string 
 *  once and only once.
 * 
 *  The adress of the unique copy stored of a given string 
 *  is called the sid (string id) of that string
 * 
 */

//#include "utile.h"

#ifndef TABLE_DES_REGISTRES_H
#define TABLE_DES_REGISTRES_H

typedef enum {
  R_VOID = 0, R_INT, R_FLOAT
} reg_type;

typedef struct {
  int id;
  reg_type type;
  int n_ptr;
  char * r_str;
  int is_init;
} registre;

/* type used for string id, this could be changes with another coding */

typedef void * sid;

typedef struct elem_reg elem_reg;

//static elem_reg * storage_reg;

/* error function */

void quit(char*);

/* creation and deletion of the list*/

elem_reg * return_list_reg();

void delete_list_reg(elem_reg *);

/* insert a string into the structure giving back its (unique) sid */
sid reg_to_sid(registre);

/* retreiving (already inserted) string value associated to a given sid */
registre sid_to_reg(sid);

/* check validity of an sid as being present in the strorage structure */
int sid_valid_reg(sid);

/* allows the register that corresponds to sid, to be seen as initialized */
void sid_init(sid);

void remove_reg(int);

void insert_scope_reg(char * s, int scope);	

#endif

