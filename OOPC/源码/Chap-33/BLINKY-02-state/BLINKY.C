/* EX33-ap-1.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-evs.h"
#include "ex33-handler.h"

void g_delay(unsigned int ms) {
   int i, j;
   for(i=0; i<ms; i++)
      for(j=0; j<120; j++);
}

extern void* HandlerNew();

char xdata MemPool[1024];

void main (void)
{
   Handler *hnd;
   init_mempool(MemPool,sizeof(MemPool));
   //---------------------------------------
   hnd = HandlerNew();
   hnd->init(hnd);
          
   while(1) {
       hnd->change_state(hnd);
	   g_delay(6000);
	 }
}
 