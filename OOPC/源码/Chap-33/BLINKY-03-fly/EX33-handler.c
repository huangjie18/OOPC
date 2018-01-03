/* EX33-handler.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex33-ifs.h"
#include "ex33-handler.h"

extern void* LandingNew();
extern void* FlyingNew();
extern void* PreparingNew();
extern void* TakingOffNew();

void g_delay(unsigned int ms) {
	int i, j;
	for(i=0; i<ms; i++)
		for(j=0; j<120; j++);
}

static void init(Handler *t){
    IFlyState *fs;
 	fs = PreparingNew();
	fs->init(fs);
	t->array[0] = fs;

	fs = TakingOffNew();
	fs->init(fs);
	t->array[1] = fs;

	fs = FlyingNew();
	fs->init(fs);
	t->array[2] = fs;

	fs = LandingNew();
	fs->init(fs);
	t->array[3] = fs;

	t->state = 'I';
}

static void goto_P(Handler *t){
	t->state = 'P';
	t->array[0]->handle(t->array[0]);
}
static void goto_T(Handler *t){
	t->state = 'T';
	t->array[1]->handle(t->array[1]);
}
static void goto_F(Handler *t){
	t->state = 'F';
	t->array[2]->handle(t->array[2]);
}
static void goto_L(Handler *t){
	t->state = 'L';
	t->array[3]->handle(t->array[3]);
}

static void run(Handler *t) {
	switch(t->state) {
	   case 'I':
	      goto_P(t);
		  break;
	   case 'P':
	      goto_T(t);
		  break;
	   case 'T':  
		  goto_F(t);
		  break;
	   case 'F':
		  goto_L(t);
		  break;
	   case 'L':
		  goto_P(t);
		  break;
	  }
	  g_delay(20000);
  }

CTOR(Handler)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(run, run)
END_CTOR
 