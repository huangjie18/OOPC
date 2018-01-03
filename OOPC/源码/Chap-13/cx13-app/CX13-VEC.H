/* cx13-vec.h */
#ifndef VEC_H
#define VEC_H
#include <stdio.h>
#include "lw_oopc.h"

CLASS(Vector)
 {
        float *V;
        int size;
        void (*init)(Vector*);
        void (*init_fi)(Vector*, float*, int);
        void (*init_i)(Vector*, int);
	    void (*destroy)(Vector*);
        float* (*get)(Vector*, int);
        float (*get_val)(Vector*, int);
	    int   (*EQ)(Vector*, Vector*);
        void (*set)(Vector*, float*, int);
        Vector* (*assign)(Vector*, Vector*);
        void (*mul)(Vector*, float);
        void (*div)(Vector*, float);
        void (*PR)(Vector*);
        int (*indexOfMax)(Vector*);
        int (*includes)(Vector*, int);
  };
  #endif