/* cx22-lig.c  */
#include <stdio.h>
#include "cx22-lig.h"

static void  Signal_On()
{
 printf("Light On\n");
}
static void  Signal_Off()
{
 printf("Light Off\n");
 }
static void init(void* t)
{
   Light* cthis = (Light*)t;
   cthis->go_state_Off(cthis);
}
static void turnOn(void* t)
{
 Light* cthis = (Light*) t;
 if(!strcmp(cthis->m_state, "On"))
 {   printf("reject turnOn msg!\n");
	 return;
 }
  else
	 cthis->go_state_On(cthis);
}
static void turnOff(void* t)
{
 Light* cthis = (Light*) t;
 if(!strcmp(cthis->m_state, "Off"))
 {   printf("reject turnOff msg!\n");
	 return;
 }
 else
	 cthis->go_state_Off(cthis);
}
static void  go_state_On(void* t)
{
 Light* cthis = (Light*) t;
 strcpy(cthis->m_state, "On");
 Signal_On();
}
static void  go_state_Off(void* t)
{
 Light* cthis = (Light*) t;
 strcpy(cthis->m_state, "Off");
 Signal_Off();
}


CTOR(Light)
  FUNCTION_SETTING(IL.init, init);
  FUNCTION_SETTING(IL.turnOn, turnOn);
  FUNCTION_SETTING(IL.turnOff, turnOff);
  FUNCTION_SETTING(go_state_On, go_state_On);
  FUNCTION_SETTING(go_state_Off, go_state_Off);
END_CTOR

