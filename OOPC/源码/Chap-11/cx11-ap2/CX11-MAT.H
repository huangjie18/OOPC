/*  CX11-mat.h   */
#include "lw_oopc.h"
#ifndef  MATRIX_H
#define  MATRIX_H

CLASS(Matrix)
{
	int size;
	double** V;
	double result;
	void (*init)(Matrix*, double**, int);
	void (*normalize)(Matrix*);
	double (*get)(Matrix*, int, int);
 };
#endif

