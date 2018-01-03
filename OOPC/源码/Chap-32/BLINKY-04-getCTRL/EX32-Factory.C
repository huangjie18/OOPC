/* EX32-factory.c */
#include "lw_oopc_kc.h"
#include "ex32-ctrl.h"
#include "ex32-factory.h"

extern void* CTRLNew();
extern void* LED_P0New();
extern void* LED_P1New();

static void init(Factory *t) {
    t->ctrl = CTRLNew();
	t->list[0] = (IL*)LED_P0New();
	t->list[1] = (IL*)LED_P1New();
	t->ctrl->pa = t->list[0];
	t->ctrl->pb = t->list[1];
}

static CTRL* get_CTRL(Factory *t){
	return t->ctrl;
}

static void destroy(Factory *t) {
	free(t->list[0]);
    free(t->list[1]);
}

CTOR(Factory)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(get_CTRL, get_CTRL)
	FUNCTION_SETTING(destroy, destroy)
END_CTOR