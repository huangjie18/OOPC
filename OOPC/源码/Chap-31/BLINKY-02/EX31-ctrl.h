/* EX31-ctrl.h */
#ifndef CTRL_H
#define CTRL_H
#include "ex31-led.h"

CLASS(CTRL)
{
  	void (*init)(CTRL *t); 
	void (*run)(CTRL *t);
	LED *ple;
};
#endif




