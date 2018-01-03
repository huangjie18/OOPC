/*  EX32-factory.h */ 
#include "ex32-il.h"

CLASS(Factory)
{
	void (*init)(Factory*);
	CTRL* (*get_CTRL)(Factory*);
	void (*destroy)(Factory*);
	IL* list[2];
	CTRL *ctrl;
};