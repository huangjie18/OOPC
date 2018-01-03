/* EX17-ap-1.c */
#include <REG52.H>
#include "lw_oopc_kc.h"

void g_delay(unsigned int ms) {
	int i, j;
	for(i=0; i<ms; i++)
		for(j=0; j<120; j++);
}

CLASS(ElevatorController)
{
	void (*init)(ElevatorController*);
	void (*move)(ElevatorController*);
	void (*stop)(ElevatorController*);
	void (*goto_state_Move)(ElevatorController*);
	void (*goto_state_Stop)(ElevatorController*);
	int state_var;
};

static void init(ElevatorController *t) {
    t->goto_state_Stop(t);
}

static void goto_state_Stop(ElevatorController *t) {
	t->state_var = 1;
	P0 = 0xF0;
	g_delay(6000);
}  

static void goto_state_Move(ElevatorController *t){
    t->state_var = 2;
	P0 = 0x0F;
	g_delay(6000);
  }
static void move(ElevatorController *t) {
  if(t->state_var == 1) 
       t->goto_state_Move(t);
  }

static void stop(ElevatorController *t){
  if( t->state_var == 2) 
     t->goto_state_Stop(t);  }

CTOR(ElevatorController)
    FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(move, move)
	FUNCTION_SETTING(stop, stop)
	FUNCTION_SETTING(goto_state_Stop, goto_state_Stop)
	FUNCTION_SETTING(goto_state_Move, goto_state_Move)
END_CTOR

char xdata MemPool[1024];

void main (void) {
	ElevatorController *ele;
	init_mempool(MemPool,sizeof(MemPool));
    //---------------------------------------
    ele = ElevatorControllerNew();
	ele->init(ele);

	while(1) {
       ele->move(ele);
	   ele->stop(ele);
	 }
}
	