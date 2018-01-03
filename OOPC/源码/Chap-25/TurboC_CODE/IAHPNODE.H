/*  iahpnode.h   */
#include "lw_oopc.h"
#ifndef IAHP_H
#define IAHP_H
INTERFACE(IAHP)
  {
    void (*init)(void*, char*);
    void (*setPCMatrix)(void*, double**, int, char**);
    int (*size)(void*);
    void* (*get_ca)(void*, int);
	void (*cal_PV_CR_recursive)(void*);
    void (*cal_weight_recursive)(void*);
    void (*goal_initial)(void*);
    void (*alternative_wieght_recursive)(void* t, char* na);
	void (*printPV)(void*);
	void (*go)(void*);

};
#endif
