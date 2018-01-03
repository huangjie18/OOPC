/*  recorder.h   */
#ifndef RECORDER_H
#define RECORDER_H
#include "lw_oopc.h"
#include "Half_adder.h"

CLASS(AD)
{
    Half_adder* adder;
    int digit_1, digit_2, carry, sum; 
	int state, d;
  	void (*init)(void*);
	void (*EvDigitPress)(void*, int);
    void (*EvPlusPress)(void*);
    void (*EvAssignPress)(void*);
    void (*EvCPress)(void*);
    void (*go_state_Ready)(void*);
    void (*go_state_First)(void*);
	void (*go_state_Plus)(void*);
    void (*go_state_Second)(void*);
    void (*go_state_Cal)(void*); 
  };
#endif