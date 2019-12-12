#include "arglist.h"
#include <stdlib.h>

/*
typedef struct {
  reg_type type;
  int reg_id;
} argu;
*/

typedef struct element {
  struct element* next;
  argu data;
} element;

static int size = 0;
static element head = {.next=NULL};

void arglist_reset() {
  for (int i=0; i<size; ++i) {
    arglist_get();
  }
  size=0;
}

int arglist_size() {
  return size;
}

void arglist_add(reg_type type, reg_type id) {
  element* elt = &head;
  while (elt->next != NULL)
    elt = elt->next;
  element* new = malloc(sizeof(element));
  new->next = NULL;
  elt->next = new;
  new->data.type = type;
  new->data.reg_id = id;
  size++;
}

argu arglist_get() {
  if (head.next == NULL)
    quit("Trying to get an arg in an empty arglist");

  argu res = head.next->data;

  head.next = head.next->next;
  free(head.next);

  size--;
  
  return res;
}
