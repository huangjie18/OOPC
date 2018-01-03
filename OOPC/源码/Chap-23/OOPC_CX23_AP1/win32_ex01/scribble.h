/*  scribble.h   */
#ifndef CTRL_H
#define CTRL_H
#include "lw_oopc.h"
#include "llist.h"
#include "painter.h"

CLASS(Scribble)
{
    INTERFACE(IColl)* poList;
    Painter* pa;
    	int m_state;
    	void (*init)(void*);
	void (*begin_record)(void* );
	void (*record)(void *t, int, int, int, long);
	void (*stop)(void*);
   	void (*re_draw)(void*);
    void (*save_drawing)(void*);
	void (*load_drawing)(void*);
};
#endif