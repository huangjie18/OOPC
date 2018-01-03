/* EX33-move.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-evs.h"

CLASS(Move)
{
	IMPLEMENTS(IEvState);
};

static void perform() {
	P0 = 0xF0;
}

CTOR(Move)
	FUNCTION_SETTING(IEvState.perform, perform)
END_CTOR