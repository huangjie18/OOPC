#include "lw_oopc.h"
#ifndef LIGIT_H
#define LIGIT_H
CLASS(Light)
{
	void (*turnOn)();
	void (*turnOff)();
};

CLASS(Matrix)
{
	int size;
	double** V;
	double result;

	void (*init)(void*,double**,int);
	void (*normalize)(void*);
	double (*get)(void*,int,int);
};
#endif