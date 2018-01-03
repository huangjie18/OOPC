/* EX33-ap-3.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"
#include "ex33-handler.h"

extern void* HandlerNew();
extern void* FlyingNew();
char xdata MemPool[1024];

void main (void)
{
   Handler *hnd;
   init_mempool(MemPool,sizeof(MemPool));
   //---------------------------------------
   hnd = HandlerNew();
   hnd->init(hnd);
         
   while(1) {
       hnd->run(hnd);
	 }
}
 