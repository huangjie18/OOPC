/* EX33-pre.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"

CLASS(Preparing)
{
   IMPLEMENTS(IFlyState);
   STATE st;
};

static void init(void *t){
   Preparing *cthis = t;
   cthis->st.state_code = 0x11;
   }

static void handle(IFlyState *t) {
	 Preparing *cthis = t;	
	 P0 = cthis->st.state_code;
}

CTOR(Preparing)
	FUNCTION_SETTING(IFlyState.init, init)
	FUNCTION_SETTING(IFlyState.handle, handle)
END_CTOR