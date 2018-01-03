/*  EX31-led.c   */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-led.h"

void g_delay(unsigned long ms) {
   long i, j;
   for(i=0; i<ms; i++)
      for(j=0; j<120; j++);
}

static unsigned char SEGTAB[] = {0xC0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x83, 0xf8, 0x80, 0x98}; 
static unsigned char SCANLINE[] = {0xf7, 0xfb, 0xfd, 0xfe}; 

static void show_digits(LED *t) {
    unsigned char ch, sc;
	int i;
	P0 = 0xf0;
    for(i=0; i<4; i++)
	   {
	    ch = SEGTAB[t->digits[i]];
		sc = SCANLINE[i];
		t->scan_port(0xff);
		t->data_port(ch);
		t->scan_port(sc);
		g_delay(20000);
	   }
}

CTOR(LED)
	FUNCTION_SETTING(show_digits, show_digits)
END_CTOR