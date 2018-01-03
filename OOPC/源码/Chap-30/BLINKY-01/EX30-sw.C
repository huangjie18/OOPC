/*  cx30-sw.c  */
#include <stdio.h>
#include "EX30-sw.h"

static void init(void *t)
{
Switch* cthis = (Switch*) t;
cthis->state = 0;
}

static int get_state(void* t)
{
   Switch* cthis = (Switch*) t;
return cthis->state;
}

static void  set_switch(void* t)
{
  int st;
  Light* light;
  Switch* cthis = (Switch*) t;
  cthis->state = !(cthis->state);
  light = cthis->light_obj;
  st = light->get_state(light);
  if (st == 1)
       light->set_light(light, 0);
  else
       light->set_light(light, 1);
}

CTOR(Switch)
FUNCTION_SETTING(init, init);
FUNCTION_SETTING(get_state, get_state);
FUNCTION_SETTING(set_switch, set_switch);
END_CTOR
