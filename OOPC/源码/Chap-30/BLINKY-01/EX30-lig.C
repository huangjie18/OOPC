/* EX30-lig.c */
#include <REG52.H>
#include "EX30-lig.h"

static void init( void *t )
{  
Light* cthis = (Light*) t;
cthis->state = 0;
} 

static int get_state(void* t)
{  
   Light* cthis = (Light*) t;
return cthis->state; 
}

static void  set_light(void* t, int flag)
{
 Light* cthis = (Light*) t;
 cthis->state = flag;
 if(cthis->state == 0)
     P0 = 0x00;
 else
     P0 = 0x3c;
}

CTOR(Light)
  FUNCTION_SETTING(init, init);
  FUNCTION_SETTING(get_state, get_state);
  FUNCTION_SETTING(set_light, set_light);
END_CTOR
