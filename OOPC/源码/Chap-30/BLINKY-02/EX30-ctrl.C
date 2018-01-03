/* EX30-ctrl.c  */
#include <REG51F.H>
#include <stdio.h>

#define LW_OOPC_STATIC
#include "ex30-ctrl.h"


extern LightRSetting(LightR*);
extern LightLSetting(LightL*);

void g_timer_delay() {
   TMOD &= 0xF0;
   TMOD |= 0x01;
   ET0 = 0;
   TH0 = 0x3C;
   TL0 = 0xB0;
   TF0 = 0;
   TR0 = 1;
   while(TF0 == 0);
   TR0 = 0;
}

void g_delay(unsigned int sec) {
   int i, j;
   for(i=0; i<sec; i++)
      for(j=0; j<20; j++)
         g_timer_delay();
}
					
static void init(CTRL* t) {
    LightR *pr; LightL *pl;
	pr = &(t->lg_right);
	pl = &(t->lg_left);

   	LightRSetting(pr);   
	LightLSetting(pl);
   
    t->state = 'L'; 
	pr->init('Y', pr);
	pl->init('R', pl); 
	}

static void run(CTRL* t) {
     while(1) {
      switch(t->state) {
	  case 'L':
	       t->goto_SW(t);
		   break;
	  case 'S':
	       t->goto_LW(t);
		   break;
     }
   }
}

static void goto_LW(CTRL *t) {
	LightR *pr; LightL *pl;
	t->state = 'L';
	pr = &(t->lg_right);
	pl = &(t->lg_left);

	 
	
	g_delay(3);
	pr->ev_Y(pr);
	pl->ev_Y(pl);
} 
static void goto_SW(CTRL *t) {
    LightR *pr; LightL *pl;
	t->state = 'S';
	pr = &(t->lg_right);
    pl = &(t->lg_left);
	 
	g_delay(1);
	pr->ev_RG(pr);
	pl->ev_RG(pl);
} 
	
CTOR(CTRL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(run, run)
	FUNCTION_SETTING(goto_LW, goto_LW)
	FUNCTION_SETTING(goto_SW, goto_SW)
END_CTOR

				   