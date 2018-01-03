/* EX33-handler.c  */
#include <REG52.H>
#include <string.h>
#include "lw_oopc_kc.h"
#include "ex33-evs.h"
#include "ex33-handler.h"

extern void* StopNew();
extern void* MoveNew();
extern void* g_delay(unsigned int);

static void init(Handler*t) {
    t->list[0] = StopNew();
	t->list[1] = MoveNew();
	t->state = 'I';
 }
	
static void perform_action(Handler *t) {
    t->es_obj->perform();  
}

static void goto_S(Handler *t){
	t->state = 'S';
	t->es_obj = t->list[0];
}
static void goto_M(Handler *t){
	t->state = 'M';
	t->es_obj = t->list[1];
}

static void change_state(Handler *t) {
	switch(t->state) {
	   case 'I':
	      goto_S(t);
		  break;
	   case 'S':
		  goto_M(t);
		  break;
	   case 'M':
		  goto_S(t);
		  break;
	  }
	perform_action(t);
	g_delay(6000);
}

CTOR(Handler)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(change_state, change_state)
END_CTOR
