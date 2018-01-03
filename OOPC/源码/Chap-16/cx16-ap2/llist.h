/*  llist.h   */
#include "lw_oopc.h"
#ifndef LLIST_H
#define LLIST_H

INTERFACE(IColl)
  {
    void (*init)(void*);
    void (*add)(void*, void*);
	void (*top)(void*);
    void* (*next)(void*);
	void* (*get)(void*, int);
   };
#endif
