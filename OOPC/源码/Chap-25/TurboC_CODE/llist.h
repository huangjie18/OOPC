/*  llist.h   */
#ifndef LLIST_H
#define LLIST_H
#include "lw_oopc.h"

INTERFACE(IColl)
  {
    void (*init)(void*);
    void (*clear)(void*);
    void (*add)(void*, void*);
    void (*top)(void*);
    void* (*next)(void*);
    void* (*get)(void*, int);
    int (*is_empty)(void*);
   };
#endif
