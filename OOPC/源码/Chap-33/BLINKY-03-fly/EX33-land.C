/* EX33-land.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"

CLASS(Landing)
{
	IMPLEMENTS(IFlyState);
	STATE st;
};

static void init(void *t){
	Landing *cthis = t;
	cthis->st.state_code = 0xaa;
}

static void handle(IFlyState *t) {
	Landing *cthis = t;	
	P0 = cthis->st.state_code;
}

CTOR(Landing)
	FUNCTION_SETTING(IFlyState.init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR