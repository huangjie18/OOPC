/* EX32-fac.c */ 
#include "lw_oopc_kc.h"
#include "ex32-idisp.h"
#include "ex32-int.h"
#include "ex32-fac.h"

extern void* IntegerNew();

static IDisplay* get_object(){
	IDisplay *pi;
	pi = IntegerNew();
	pi->init(pi);
	return pi;
}

CTOR(Factory)
  FUNCTION_SETTING(get_object, get_object)
END_CTOR		