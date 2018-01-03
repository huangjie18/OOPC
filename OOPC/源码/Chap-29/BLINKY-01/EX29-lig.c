/* EX29-lig.c   */
#include <REG51F.H>
#include <stdio.h>

#define LW_OOPC_STATIC
#include "ex29-lig.h"

sbit RED_pin = P0^0;
sbit YELLOW_pin = P0^1;
sbit GREEN_pin = P0^2;
					
void g_delay(unsigned int ms) {
	int i, j;
	for(i=0; i<ms; i++)
		for(j=0; j<120; j++);
}

static void init(TLight* t) {
    P0 = 0x00;
    t->state = 'R'; 
}

static void run(TLight* t) {
      switch(t->state) {
	  case 'R':
	       t->state = 'G';
		   t->goto_G();
		   break;
	  case 'G':
	       t->state = 'Y';
		   t->goto_Y();
		   break;
	  case 'Y':
           t->state = 'R';
		   t->goto_R();
		   break;
	}
}
static void goto_R() {
      RED_pin = 1;
	  YELLOW_pin = 0;
	  GREEN_pin = 0;
	  g_delay(10000);
    } 
static void goto_Y() {
      RED_pin = 0;
	  YELLOW_pin = 1;
	  GREEN_pin = 0;
	  g_delay(3000);
    } 
static void goto_G() {
      RED_pin = 0;
	  YELLOW_pin = 0;
	  GREEN_pin = 1;
	  g_delay(10000);
    } 	
	
CTOR(TLight)
  FUNCTION_SETTING(init, init)
  FUNCTION_SETTING(run, run)
  FUNCTION_SETTING(goto_R, goto_R)
  FUNCTION_SETTING(goto_Y, goto_Y)
  FUNCTION_SETTING(goto_G, goto_G)
END_CTOR

				   