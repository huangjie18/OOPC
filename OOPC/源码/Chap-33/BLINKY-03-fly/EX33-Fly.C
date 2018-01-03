/* EX33-fly.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"

CLASS(Flying)
{		   
	IMPLEMENTS(IFlyState);
	STATE st;
};

static void init(void *t){
	Flying *cthis = t;
	cthis->st.state_code = 0x77;
	cthis->st.position_x = 2;
	cthis->st.position_y = 2;
}

static void handle(IFlyState *t) {
	Flying *cthis = t;	
	P0 = cthis->st.state_code;
}

CTOR(Flying)
	FUNCTION_SETTING(IFlyState.init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR