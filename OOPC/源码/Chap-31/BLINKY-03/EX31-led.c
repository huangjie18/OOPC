/*  EX31-led.c   */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-led.h"

void g_delay(unsigned int ms) {
   int i, j;
   for(i=0; i<ms; i++)
      for(j=0; j<120; j++);
}

static unsigned char SEGTAB[] = {0xC0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x83, 0xf8, 0x80, 0x98}; 
static unsigned char SCANLINE[] = {0xf7, 0xfb, 0xfd, 0xfe}; 

static void show_data(LED *t) {
    unsigned char ch, sc;
	int i;				   
    IPort *pss = t->scan_port;
	IPort *pdd = t->data_port;	

	P0 = 0xf0;
    for(i=0; i<4; i++)
	   {
	    ch = SEGTAB[t->digits[i]];
		sc = SCANLINE[i];
		pss->send(0xff);
		pdd->send(ch);
		pss->send(sc);
		g_delay(20000);
	   }
}

CTOR(LED)
	FUNCTION_SETTING(show_data, show_data)
END_CTOR