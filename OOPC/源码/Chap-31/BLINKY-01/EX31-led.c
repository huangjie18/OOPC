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

static void channel_1(char x) {
   P1 = x;
}

static void channel_0(char y) {
   P0 = y;
}

static void run(LED *t) {
    unsigned char ch, sc;
	t->data_port = channel_0;
	t->scan_port = channel_1;
							 
	/* -------------------- */
	P0 = 0xf0;
    ch = SEGTAB[0];
	sc = SCANLINE[0];
	t->scan_port(0xff);
	t->data_port(ch);
	t->scan_port(sc);
	g_delay(20000);
    /* -------------------- */
	ch = SEGTAB[9];
	sc = SCANLINE[1];
	t->scan_port(0xff);
	t->data_port(ch);
	t->scan_port(sc);
	g_delay(20000);
}

CTOR(LED)
	FUNCTION_SETTING(run, run)
END_CTOR