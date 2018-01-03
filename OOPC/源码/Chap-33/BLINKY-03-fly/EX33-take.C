/* EX33-take.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"

CLASS(TakingOff)
{
	IMPLEMENTS(IFlyState);
	STATE st;
};

static void init(void *t){
	TakingOff *cthis = t;
	cthis->st.state_code = 0x33;
}

static void handle(IFlyState *t) {
	TakingOff *cthis = t;	
	P0 = cthis->st.state_code;
}

CTOR(TakingOff)
	FUNCTION_SETTING(IFlyState.init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR