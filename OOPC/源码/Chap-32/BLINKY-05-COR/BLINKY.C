/* EX32-ap-5.c (BLINKY.c) */
#include <REG51F.H>
#include "lw_oopc_kc.h"
#include "ex32-il.h"
#include "ex32-factory.h"

void g_timer_delay() {
   TMOD &= 0xF0;     TMOD |= 0x01;
   ET0 = 0;
   TH0 = 0x3C;	     TL0 = 0xB0;
   TF0 = 0;		     TR0 = 1;
   while(TF0 == 0);
   TR0 = 0;
}

void g_delay(unsigned int sec) {
   int i, j;
   for(i=0; i<sec; i++)
      for(j=0; j<20; j++)
         g_timer_delay();
}

extern void* FactoryNew();

char xdata MemPool[1024];

void main (void){
   IL *leds; Factory *fa;
   init_mempool(MemPool,sizeof(MemPool));
   fa = FactoryNew();
   fa->init(fa);
   //
   leds = fa->get_LED_LIST(fa); 
  
   leds->pass('0', 0x77, leds);
      g_delay(2);
   leds->pass('1', 0x33, leds);
      g_delay(2);
   leds->pass('3', 0xaa, leds);
	  g_delay(2);
   leds->pass('2', 0xaa, leds);
	  g_delay(2);
   P0 = 0x00;
   P1 = 0x00;
   P2 = 0x00;
    g_delay(2);
   leds->pass('A', 0xf0, leds);


   while(1) {
	    ;
	 }
}
