/* EX33-ctrl.c  */
#include <REG52.H>
#include "ex33-ifs.h"
#include "ex33-ctrl.h"

extern void* HandlerSetting(void*);
extern void* PreparingSetting(void*);
extern void* FlyingSetting(void*);

static CTRL *pL;
static long count;
static int max;

void init_timer1() {
	TMOD &= 0x0F;
	TMOD |= 0x10;
	TH1 = 0x00; 
	TL1 = 0x00; 
	ET1 = 1;
	TR1 = 1;
	EA = 1;
}

void reload_timer1() {
	TR1 = 0;
	TH1 = 0x00; 
	TL1 = 0x00; 
	TR1 = 1;
}  
static void init(CTRL *t){
    PreparingSetting(&t->pObj);
	t->pObj.init(&t->pObj);
	
	FlyingSetting(&t->fObj);
	t->fObj.init(&t->fObj);
	
    HandlerSetting(&t->hObj);
	t->hObj.init(&t->hObj);
						 
	t->state = 'I';
	pL = t;
	max = 400;
}

static void goto_P(CTRL *t){
	t->state = 'P';
	t->hObj.fs = (IFlyState*)(&t->pObj);
}

static void goto_F(CTRL *t){
	t->state = 'F';
	t->hObj.fs =(IFlyState*)(&t->fObj);
}

static void run(CTRL *t) {
    count = 0;
	switch(t->state) {
	   case 'I':
	      goto_P(t);
		  break;
	   case 'P':
	      goto_F(t);
		  break;
	   case 'F':
		  goto_P(t);
		  break;
	  }
  }

static void call_back() interrupt 3 {
	count++;
	if(count > max)  run(pL);
	reload_timer1();
}


static void start(CTRL *t) {
  //  P0 = 0x00;
	count = 0;
	init_timer1();
	t->hObj.start();
}
 
CTOR(CTRL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(start, start)
END_CTOR

