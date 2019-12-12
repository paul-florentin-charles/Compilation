/*
 *  Table des chaines.h
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

#include "utile.h"
#include "Table_des_registres.h"

#ifndef TABLE_DES_FONCTIONS_H
#define TABLE_DES_FONCTIONS_H

#define MAX_ARGS 50

/* type used for string id, this could be changes with another coding */

typedef void * sid;

//typedef struct elem_fun elem_fun;


typedef struct {
  char * name;
  reg_type ret_type;
  int n_args;
  reg_type args_type[MAX_ARGS];
} fun;

typedef struct elem_fun {
  fun value;
  struct elem_fun * next;
} elem_fun;

//static elem_fun * storage_fun;

/* creation and deletion of the list*/

elem_fun * return_list_fun();

void delete_list_fun(elem_fun *);

/* insert a string into the structure giving back its (unique) sid */
sid fun_to_sid(fun);

/* retreiving (already inserted) string value associated to a given sid */
fun sid_to_fun(sid);

/* check validity of an sid as being present in the strorage structure */
int sid_valid_fun(sid);

#endif

