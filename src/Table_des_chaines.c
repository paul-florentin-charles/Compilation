 /*
 *  Table des chaines.c
 *
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 */

#include "Table_des_chaines.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* good old string copy function with malloc */

char * string_copy(char *s) {
  if (!s) return NULL;
  char * sc = malloc(strlen(s)*sizeof(char));
  return strcpy(sc, s);
}

/* The storage structure is implemented as a linked chain.
   A more efficient structure would be (why so ?) a hash table  */

/* linked element def */

typedef struct elem {
  char * value;
  int scope;
  struct elem * next;
} elem;

/* linked chain initial element */

static elem * storage = NULL;

/* allocates and free the storage list*/

elem * return_list() {
  //storage = malloc(sizeof(elem));
  return storage;
}

void delete_list(elem * ll) {
  elem * llvm = NULL;
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

sid string_to_sid(char * s) {	
	elem * tracker;

	/* check s is a real string */
	if (!s) return NULL;
	
	
	/* look for the presence of s in storage  and returns its copy if there */
	
	tracker = storage;
	
	while (tracker) {
		if (!strcmp(tracker->value, s)) return tracker->value;
		tracker = tracker -> next;
	}

	/* otherwise insert it at head of storage */
	
        tracker = malloc(sizeof(elem));
	tracker -> value = string_copy(s);
	tracker -> next = storage;
	storage = tracker;
	return storage -> value;
}

void insert_scope(char * s, int scope) {	
	elem * tracker;

	/* check s is a real string */
	if (!s) return;
	
	
	/* look for the presence of s in storage  and returns its copy if there */
	
	tracker = storage;
	
	while (tracker) {
	  if (!strcmp(tracker->value, s)) {
	    tracker -> scope = scope;
	    return;
	  }
		tracker = tracker -> next;
	}
}

/* check the validity of an sid as being present in the storage structure */
int sid_valid(sid i, int scope) {
  elem * tracker = storage;
  while (tracker) {
    if (!strcmp(tracker->value, i) && tracker->scope >= scope) return 1;
    tracker=tracker->next;
  }
  return 0;
}

/* retreiving (already inserted) string value associated to a given sid */
char * sid_to_string(sid i, int scope) {
	/* for debug purpose */
  if (!sid_valid(i, scope)) return NULL;
	
  return (char *) i;
}

void remove_str(int scope) {
  elem * tracker = storage;
  if (!tracker)
    return;
  
  while (tracker && tracker -> scope == scope) {
    //printf("chaîne = %s\n",tracker -> value);
    //printf("scope = %d\n",tracker -> scope);
    elem * tmp = tracker -> next;
    free(tracker);
    tracker = tmp;
  }
  storage = tracker;
}
