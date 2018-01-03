/* EX32-ap-4.c (BLINKY.c) */
#include "lw_oopc_kc.h"
#include "ex32-il.h"
#include "ex32-ctrl.h"
#include "ex32-factory.h"

extern void* FactoryNew();

char xdata MemPool[1024];

void main (void){
   Factory *fa;	CTRL *ctrl;
   init_mempool(MemPool,sizeof(MemPool));
   fa = FactoryNew();
   fa->init(fa);
   //
   ctrl = fa->get_CTRL(fa);
   ctrl->send(ctrl, 0xaa);
    
   while(1) {
	    ;
	 }
}
