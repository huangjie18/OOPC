/* EX32-factory.c */
#include "lw_oopc_kc.h"
#include "ex32-led.h"
#include "ex32-factory.h"


extern void* LED_P0New();
extern void* LED_P1New();
extern void* LED_P2New();

static void init(Factory *t) {
    LED_P0* ps0;
	LED_P1* ps1;
	LED_P2* ps2;
	ps0 = LED_P0New();
	ps0->init(ps0);
	t->head = (IL*)ps0;
	
	ps1 = LED_P1New();
	ps1->init(ps1);
	ps0->next = (IL*)ps1;

	ps2 = LED_P2New();
	ps2->init(ps2);
	ps1->next = (IL*)ps2;
  }

static IL* get_LED_LIST(Factory *t) {
    return t->head;
  }

CTOR(Factory)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(get_LED_LIST, get_LED_LIST)
END_CTOR