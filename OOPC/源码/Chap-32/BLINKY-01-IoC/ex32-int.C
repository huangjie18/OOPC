/* EX32-int.c */
#include <REG52.H>
#include <stdio.h>
#include "lw_oopc_kc.h" 
#include "ex32-int.h"

static void init(Integer *t)
	{  t->value = 100;  }

static void display(Integer *t)
	{  P0 = (char)t->value;  }

CTOR(Integer)
    FUNCTION_SETTING(init, init);
	FUNCTION_SETTING(display, display);
END_CTOR
