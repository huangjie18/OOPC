/* EX33-fly.c  */
#include <REG52.H>
#include "ex33-ifs.h"
#include "ex33-fly.h"

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
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR