/* cx13-mat.h  */
#ifndef MAT_H
#define MAT_H
#include <stdio.h>
#include "lw_oopc.h"
#include "cx13-vec.h"

CLASS(Matrix)
 {
        int m, n;
        Vector **p;
	void (*initialize)(Matrix*);
        void (*init_fii)(Matrix*, float*, int, int);
	void (*assign)(Matrix*, Matrix*);
        Vector* (*row)(Matrix*, int);
        Vector* (*col)(Matrix*, int);
	void (*destroy)(Matrix*);
        void (*setRow)(Matrix*, Vector*, int);
   };
   #endif