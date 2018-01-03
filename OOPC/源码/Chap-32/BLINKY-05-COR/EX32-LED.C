/* EX32-led.c */
#include <REG51F.H>
#include "lw_oopc_kc.h"
#include "ex32-led.h"

static void init_1(LED_P1* t) {
   	t->next = NULL;
//	xxx = 0xf3;
}

static int pass_1(char ty, char hx, void *t) {
    LED_P1 *cthis = (LED_P1*)t;
	IL* ps = cthis->next;
    if(ty=='1')
	     {
		   P1 = hx;
		   return 1;
		 }
	if(ty=='A') P1 = hx;
    if(ps == NULL) return 0;
	else  return ps->pass(ty, hx, ps);
}


CTOR(LED_P1)
	FUNCTION_SETTING(init, init_1)
	FUNCTION_SETTING(IL.pass, pass_1)
END_CTOR
// ------------------------------- 
 static void init_0(LED_P0* t) {
   	t->next = NULL;
}

static int pass_0(char ty, char hx, void *t) {
    LED_P0 *cthis = (LED_P0*)t;
	IL* ps = cthis->next;
    if(ty=='0')
	     {
		   P0 = hx;
		   return 1;
		 }
	if(ty=='A') P0 = hx;
    if(ps == NULL) return 0;
	else  return ps->pass(ty, hx, ps);
}

CTOR(LED_P0)
	FUNCTION_SETTING(init, init_0)
	FUNCTION_SETTING(IL.pass, pass_0)
END_CTOR
//----------------------------------------
static void init_2(LED_P2* t) {
   	t->next = NULL;
}

static int pass_2(char ty, char hx, void *t) {
    LED_P2 *cthis = (LED_P2*)t;
	IL* ps = cthis->next;
    if(ty=='2')
	     {
		   P2 = hx;
		   return 1;
		 }
	if(ty=='A') P2 = hx;
    if(ps == NULL) return 0;
	else  return ps->pass(ty, hx, ps);
}


CTOR(LED_P2)
	FUNCTION_SETTING(init, init_2)
	FUNCTION_SETTING(IL.pass, pass_2)
END_CTOR
