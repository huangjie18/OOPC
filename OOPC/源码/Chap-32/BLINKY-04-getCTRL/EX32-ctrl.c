/* EX32-ctrl.c */
#include <REG51F.H>
#include "lw_oopc_kc.h"
#include "ex32-ctrl.h"

static void send(CTRL* t, char hx)
{
	t->pa->send(hx);
	t->pb->send(hx);
}

CTOR(CTRL)
	FUNCTION_SETTING(send, send)
END_CTOR
