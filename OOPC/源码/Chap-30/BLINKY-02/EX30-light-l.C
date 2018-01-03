/* EX30-light-l.c  */
#include <REG51F.H>
#include <stdio.h>

#define LW_OOPC_STATIC
#include "EX30-light-l.h"

sbit RED_pin = P1^0;
sbit YELLOW_pin = P1^1;
sbit GREEN_pin = P1^2;
  
/* ---------------------------------------------- */				
static void init(char st, LightL* t) {
    P1 = 0x00;
    t->state = st; 
    if(st == 'G') t->goto_G();
	else if(st == 'R') t->goto_R();
	     else t->goto_Y();
   }

static void ev_Y(LightL* t) {
	if( t->state == 'G') {
		t->state = 'Y';
		t->goto_Y();
	}
}
static void ev_RG(LightL* t) {
	if( t->state == 'Y') {
		t->state = 'R';
		t->goto_R();
	}
	else if(t->state == 'R') {
		t->state = 'G';
		t->goto_G();
	}
}
static void goto_R() {
	RED_pin = 1;
	YELLOW_pin = 0;
	GREEN_pin = 0;
}
	 
static void goto_Y() {
	RED_pin = 0;
	YELLOW_pin = 1;
	GREEN_pin = 0;
} 
static void goto_G() {
	RED_pin = 0;
	YELLOW_pin = 0;
	GREEN_pin = 1;
} 	
	
CTOR(LightL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(ev_Y, ev_Y)
	FUNCTION_SETTING(ev_RG, ev_RG)
	FUNCTION_SETTING(goto_R, goto_R)
	FUNCTION_SETTING(goto_Y, goto_Y)
	FUNCTION_SETTING(goto_G, goto_G)
END_CTOR
