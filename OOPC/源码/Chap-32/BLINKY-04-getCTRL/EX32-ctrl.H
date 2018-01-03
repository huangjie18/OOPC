/*  EX32-ctrl.h */ 
#include "ex32-il.h"

CLASS(CTRL)
{
    void (*send)(CTRL*, char);
	IL *pa, *pb;
};

