 /*
 *  Table des chaines.c
 *
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 */

#include "Table_des_registres.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* The storage structure is implemented as a linked chain.
   A more efficient structure would be (why so ?) a hash table  */

/* linked element def */

typedef struct elem_reg {
  registre value;
  struct elem_reg * next;
  int scope;
} elem_reg;

/* linked chain initial element */

static elem_reg * storage_reg = NULL;

/* error function */

void quit(char* msg) {
  fprintf(stderr, "ERROR : %s\n", msg);
  exit(1);
}

/* allocates and free the storage list*/

elem_reg * return_list_reg() {
  //storage = malloc(sizeof(elem));
  return storage_reg;
}

void delete_list_reg(elem_reg * ll) {
  elem_reg * llvm = NULL;
  if (!ll)
    return;
  else if (!(ll -> next)) {
    free(ll);
    return;
  }
  while (ll -> next) {
    llvm = ll -> next;
    free(ll);
    ll = llvm;
  }
}

/* insert a string into the storage structure giving back its (unique) id */

sid reg_to_sid(registre r) {	
	elem_reg * tracker;

	char * s = r.r_str;

	/* check s is a real string */
	if (!s) return NULL;
	
	
	/* look for the presence of s in storage  and returns its copy if there */
	
	tracker = storage_reg;
	
	while (tracker) {
	  if (!strcmp((tracker->value).r_str, s)) return (tracker->value).r_str;
		tracker = tracker -> next;
	}

	/* otherwise insert it at head of storage */
	
        tracker = malloc(sizeof(elem_reg));
	tracker -> value = r;
	tracker -> next = storage_reg;
	storage_reg = tracker;
	return (storage_reg -> value).r_str;
}

/* check the validity of an sid as being present in the storage structure */
int sid_valid_reg(sid i) {
  elem_reg * tracker = storage_reg;
  while (tracker) {
    if (!strcmp((tracker->value).r_str, i)) return 1;
    tracker=tracker->next;
  }
  return 0;
}

/* retreiving (already inserted) string value associated to a given sid */
registre sid_to_reg(sid i) {
  elem_reg * tracker = storage_reg;
  
  while (tracker) {
    if (!strcmp((tracker->value).r_str, i)) return tracker -> value;
    tracker=tracker->next;
  }
  quit("sid doesn't correspond to an existing registre");
  registre res;
  res.id = 4012;
  return res;
}

void insert_scope_reg(char * s, int scope) {	
  elem_reg * tracker;
  
  /* check s is a real string */
  if (!s) return;
  
  
  /* look for the presence of s in storage  and returns its copy if there */
  
  tracker = storage_reg;
  
  while (tracker) {
    if (!strcmp(tracker->value.r_str, s)) {
      tracker -> scope = scope;
      return;
    }
    tracker = tracker -> next;
  }
}

void sid_init(sid i) {
  elem_reg * tracker = storage_reg;
  
  while (tracker) {
    if (!strcmp((tracker->value).r_str, i)) {
      (tracker -> value).is_init = 1;
      return;
    }
    tracker=tracker->next;
  }
  quit("sid doesn't correspond to an existing registre");
}

void remove_reg(int scope) {
  elem_reg * tracker = storage_reg;
  if (!tracker)
    return;
  
  while (tracker && tracker -> scope == scope) {
    //printf("chaîne = %s\n",tracker -> value);
    //printf("scope = %d\n",tracker -> scope);
    elem_reg * tmp = tracker -> next;
    free(tracker);
    tracker = tmp;
  }
  storage_reg = tracker;
}
