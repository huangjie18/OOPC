#include "lw_oopc.h"
#include <stdio.h>
CLASS(Light_12)
{
	int state;
	void (*init)(void*);
	int (*get_state)(void*);
	void (*set_light)(void*,int flag);
};

static void init(void *t)
{
	Light_12* cthis = (Light_12*)t;
	cthis->state = 0;
}

static int get_state(void* t)
{
	Light_12* cthis = (Light_12*)t;
	return cthis->state;
}

static void set_light(void* t,int flag)
{
	Light_12* cthis = (Light_12*)t;
	cthis->state = flag;
	if(cthis->state == 0)
	{
		printf("LIGHT_OFF!\n");
	}
	else
	{
		printf("LIGHT_ON!\n");
	}
}

CTOR(Light_12)
	FUNCTION_SETTING(init,init)
	FUNCTION_SETTING