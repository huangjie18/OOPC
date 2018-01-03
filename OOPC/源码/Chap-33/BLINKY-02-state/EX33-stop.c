/* EX33-stop.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-evs.h"

CLASS(Stop)
{
	IMPLEMENTS(IEvState);
   
};

static void perform() {
	P0 = 0x0F;
}

CTOR(Stop)
	FUNCTION_SETTING(IEvState.perform, perform)
END_CTOR