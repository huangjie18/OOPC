/* EX33-ap-4.c (BLINKY.c) */
#include <REG52.H>
#include "ex33-ifs.h"
#include "ex33-ctrl.h"

extern void* CTRLSetting(void*);
char xdata MemPool[1024];

void main (void)
{

	 CTRL controller;
	init_mempool(MemPool,sizeof(MemPool));
//-----------------------------------
	CTRLSetting(&controller);
	controller.init(&controller);
	controller.start(&controller);
         
	while(1) {
       ;    
	}
}
 