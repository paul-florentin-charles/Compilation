 /*
 *  Table des chaines.c
 *
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 */

#include "Table_des_fonctions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* The storage structure is implemented as a linked chain.
   A more efficient structure would be (why so ?) a hash table  */

/* linked element def */

/* linked chain initial element */

static elem_fun * storage_fun = NULL;

/* allocates and free the storage list*/

elem_fun * return_list_fun() {
  //storage = malloc(sizeof(elem));
  return storage_fun;
}

void delete_list_fun(elem_fun * ll) {
  elem_fun * llvm = NULL;
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

sid fun_to_sid(fun f) {	
	elem_fun * tracker;

	/* check s is a real string */
	if (!(f.name)) return NULL;
	
	
	/* look for the presence of s in storage  and returns its copy if there */
	
	tracker = storage_fun;
	
	while (tracker) {
	  if (!strcmp((tracker->value).name, f.name)) 
	    return (tracker->value).name;
	  
	  tracker = tracker -> next;
	}

	/* otherwise insert it at head of storage */
	
        tracker = malloc(sizeof(elem_fun));
	tracker -> value = f;
	tracker -> next = storage_fun;
	storage_fun = tracker;
	return (storage_fun -> value).name;
}

/* check the validity of an sid as being present in the storage structure */
int sid_valid_fun(sid i) {
  elem_fun * tracker = storage_fun;
  while (tracker) {
    if (!strcmp((tracker->value).name, i)) return 1;
    tracker=tracker->next;
  }
  return 0;
}

/* retreiving (already inserted) string value associated to a given sid */
fun sid_to_fun(sid i) {
	/* for debug purpose */

  elem_fun * tracker = storage_fun;
  
  while (tracker) {
    if (!strcmp((tracker->value).name, i)) return tracker -> value;
    tracker=tracker->next;
  }
  
  quit("sid doesn't correspond to an existing function");
  fun f;
  f.name = "swag_function";
  return f;
}
