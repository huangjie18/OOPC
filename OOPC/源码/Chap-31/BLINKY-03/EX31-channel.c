/*  EX31-channel.c   */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-ip.h"

CLASS(Channel_0)
{
  IMPLEMENTS(IPort);
};

static void send_code_P0(char x) {
	P0 = x;
}

CTOR(Channel_0)
	FUNCTION_SETTING(IPort.send, send_code_P0);
END_CTOR
/*--------------------------------------------- */
CLASS(Channel_1)
{
	IMPLEMENTS(IPort);
};

static void send_code_P1(char y) {
    P1 = y;
}

CTOR(Channel_1)
	FUNCTION_SETTING(IPort.send, send_code_P1);
END_CTOR
