/*  Half_adder.h   */
#ifndef HA_H
#define HA_H
#include "lw_oopc.h"

CLASS(Half_adder)
{
    int a, b;
	int carry, sum;
    void (*init)(void*);
	void (*start_thread)(void*);
};
#endif

