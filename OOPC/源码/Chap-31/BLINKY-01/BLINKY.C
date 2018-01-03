/* EX31-ap-1.c (BLINKY.c) */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-led.h"


extern void* LEDNew();
char xdata MemPool[1024];

void main (void) {
   LED *led;
   init_mempool(MemPool,sizeof(MemPool));
   /* -------------------------- */
   led = LEDNew();
   led->run(led);
}
 			