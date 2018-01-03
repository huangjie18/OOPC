/* EX32-int.c */
#include <REG52.H>
#include "lw_oopc_kc.h" 
#include "ex32-idisp.h"
#include "ex32-int.h"
 
static void init(Integer *t)
{  
	t->value = 15;
}

static void display(Integer *t)
{
    P0 = (char)t->value;
			  
}

CTOR(Integer)
    FUNCTION_SETTING(IDisplay.init, init);
    FUNCTION_SETTING(IDisplay.display, display);
END_CTOR
