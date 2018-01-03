/* EX33-FlyState.c  */
#include <REG52.H>
#include <string.h>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"

CLASS(Preparing)
{
	IMPLEMENTS(IFlyState);
	STATE st;
};

static void init(void *t){
	Preparing *cthis = t;
	strcpy(cthis->st.state, "Preparing");
	cthis->st.height = 5000;
}

static Status getStatus(void *t) {
	Preparing *cthis = t;
	return cthis->st;
}

CTOR(Preparing)
	FUNCTION_SETTING(IFlyState.init, init)
	FUNCTION_SETTING(IFlyState.getStatus, getStatus)
END_CTOR