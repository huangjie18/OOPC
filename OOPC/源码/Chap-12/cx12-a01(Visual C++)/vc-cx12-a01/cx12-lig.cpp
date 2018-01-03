/* cx12-lig.c  */
#include "StdAfx.h"
#include <stdio.h>
#include "cx12-lig.h"

extern void signal_to_light_UI(LPCWSTR);
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
	if(cthis->state == 1)
		signal_to_light_UI(_T("ON"));
	else 
		signal_to_light_UI(_T("OFF"));   
}

CTOR(Light)
	FUNCTION_SETTING(init, init);
	FUNCTION_SETTING(get_state, get_state);
	FUNCTION_SETTING(set_light, set_light);
END_CTOR

