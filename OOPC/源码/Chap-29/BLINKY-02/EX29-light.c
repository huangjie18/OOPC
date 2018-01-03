/* EX29-light.c */
#include <REG51F.H>
#define LW_OOPC_STATIC
#include "ex29-light.h"

sbit RED_pin = P0^0;
sbit YELLOW_pin = P0^1;
sbit GREEN_pin = P0^2;

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
					
static void init(TLight* t) {
    P0 = 0x00;
    t->state = 'R'; 
	t->wait_R = 10;
	t->wait_Y = 2;
	t->wait_G = 10;
   }

static void run(TLight* t) {
      switch(t->state) {
	  case 'R':
	       t->state = 'G';
		   t->perform(t);
		   break;
	  case 'G':
	       t->state = 'Y';
		   t->perform(t);
		   break;
	  case 'Y':
           t->state = 'R';
		   t->perform(t);
		   break;
	}
}
static void perform(TLight *t) {
	 switch(t->state) {
	  case 'R':
	       RED_pin = 1;
	       YELLOW_pin = 0;
	       GREEN_pin = 0;
		   g_delay(t->wait_R);
		   break;
	  case 'Y':
           RED_pin = 0;
	       YELLOW_pin = 1;
	       GREEN_pin = 0;
		   g_delay(t->wait_Y);
		   break;
	  case 'G':
	       RED_pin = 0;
	       YELLOW_pin = 0;
	       GREEN_pin = 1;
		   g_delay(t->wait_G);
		   break;
      }
	} 	
	
CTOR(TLight)
  FUNCTION_SETTING(init, init)
  FUNCTION_SETTING(run, run)
  FUNCTION_SETTING(perform, perform)
END_CTOR
