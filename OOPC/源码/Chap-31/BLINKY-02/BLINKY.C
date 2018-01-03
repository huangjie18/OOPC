/* EX31-ap-2.c  (BLINKY.c) */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-ctrl.h"

extern void* CTRLNew();
char xdata MemPool[1024];

void main (void) {
   CTRL *controller;
   init_mempool(MemPool,sizeof(MemPool));
   /* -------------------------- */
   controller = CTRLNew();
   controller->init(controller);
   controller->run(controller);
}
 