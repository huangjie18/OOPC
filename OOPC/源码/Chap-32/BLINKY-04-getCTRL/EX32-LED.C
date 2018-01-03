/* EX32-led.c */
#include <REG51F.H>
#include "lw_oopc_kc.h"
#include "ex32-led.h"

static void send(unsigned char hx) {
	P0 = hx;
}

CTOR(LED_P0)
	FUNCTION_SETTING(IL.send, send)
END_CTOR

//----------------------------------------
static void send2(unsigned char hx) {
	P1 = hx;
}

CTOR(LED_P1)
	FUNCTION_SETTING(IL.send, send2)
END_CTOR
