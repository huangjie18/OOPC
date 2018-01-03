/* EX32-ap-2.c  */
#include <REG52.H>
#include <stdio.h>
#include "lw_oopc_kc.h" 
#include "ex32-idisp.h"
#include "ex32-int.h"

extern void* IntegerNew();

CLASS(Document)
   {
      void (*init)(Document *t);
	  void (*display)(Document *t);
      IDisplay *pi;
   };

static void init(Document *t)
   {  t->pi = IntegerNew(); 
      t->pi->init(t->pi);   }

static void display(Document *t)
   {  t->pi->display(t->pi); }

CTOR(Document)
    FUNCTION_SETTING(init, init);
	FUNCTION_SETTING(display, display);
END_CTOR

/* ----------------------------------- */
char xdata MemPool[1024];

void main() {
	Document *pdoc;

	init_mempool(MemPool,sizeof(MemPool));
	pdoc = DocumentNew();
	pdoc->init(pdoc);
	pdoc->display(pdoc); 
	while(1) {
	   ;
	}
}
