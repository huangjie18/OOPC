/* EX33-pre.c  */
#include <REG52.H>
#include "ex33-ifs.h"
#include "ex33-pre.h"


static void init(void *t){
	Preparing *cthis = t;
	cthis->st.state_code = 0x11;
}

static void handle(IFlyState *t) {
	Preparing *cthis = t;	
	P0 = cthis->st.state_code;
}

CTOR(Preparing)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR