/*  pcmatrix.h   */
#include "lw_oopc.h"
#ifndef IPCM_H
#define IPCM_H
INTERFACE(IPCM)
  {
    void (*init)(void*, double**, int);
	void (*calculate)(void*);
    double (*getCR)(void*);
	double (*getPV)(void*, int);
	int (*getSize)(void*);
};
#endif

