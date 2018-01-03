/* EX32-ap-3.c (BLINKY.c)  */
#include "lw_oopc_kc.h" 
#include "ex32-idisp.h"
#include "ex32-fac.h"

extern void* FactoryNew();
Factory *pfac;

CLASS(Document)
   {
      void (*display)();
   };

static void display()
   {  IDisplay *pi;
   	  pi = pfac->get_object(); 
	  pi->init(pi);
	  pi->display(pi);
    }

CTOR(Document)
    FUNCTION_SETTING(display, display);
END_CTOR

/* ----------------------------------- */
char xdata MemPool[2048];

void main() {
	Document *pd;
	init_mempool(MemPool,sizeof(MemPool));
	pfac = FactoryNew();
	pd = DocumentNew();
	pd->display();
  
	while(1) {
	   ;
	}
}
