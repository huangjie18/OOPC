/* EX31-ap-3.c (BLINKY.c) */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-ctrl.h"

extern void* CTRLNew();
char xdata MemPool[1024];

void main (void) {
   CTRL *drive;
   init_mempool(MemPool,sizeof(MemPool));
   /* -------------------------- */
   drive = CTRLNew();
   drive->init(drive);
   drive->run(drive);
} 
