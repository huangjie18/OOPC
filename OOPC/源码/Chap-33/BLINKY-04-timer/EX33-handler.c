/* EX33-handler.c  */
#include <REG52.H>
#include "ex33-ifs.h"
#include "ex33-handler.h"
 
static Handler *pL;
static long count;
static int max;

void init_timer0() {
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TH0 = 0x00; 
	TL0 = 0x00; 
	ET0 = 1;
	TR0 = 1;
	EA = 1;
}

void reload_timer0() {
	TR0 = 0;
	TH0 = 0x00; 
	TL0 = 0x00; 
	TR0 = 1;
}
 
static void init(Handler *t){
	t->fs = NULL;
	pL = t;
	max = 400;
}

static void run(Handler *t) {
	t->fs->handle(t->fs);
}

static void call_back2() interrupt 1 {
	count++;
	if(count > max)  run(pL);
		reload_timer0();
}

static void start() {
	long i;
    P0 = 0x00;
	count = 0;
	for(i=0; i<100000; i++) 
	      ;  /* ÈÃTimer0ÂäºóTimer1 */
	init_timer0();
   } 
    
CTOR(Handler)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(start, start)
END_CTOR





