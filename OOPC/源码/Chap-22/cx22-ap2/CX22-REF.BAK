/* cx22-ref.c  */
#include <stdio.h>
#include "cx22-lig.h"
#include "cx22-ref.h"

static void init(void* t)
{
   Refri* cthis = (Refri*)t;
   cthis->light = (IL*)LightNew();
   cthis->go_state_DoorClosed(cthis);
 }
static void openTheDoor(void* t)
{
 Refri* cthis = (Refri*) t;
 if(!strcmp(cthis->m_state, "DoorOpened"))
  {   printf("reject openTheDoor msg!\n");
	 return;
  }
 else
	 cthis->go_state_DoorOpened(cthis);
}
static void closeTheDoor(void* t)
{
 Refri* cthis = (Refri*) t;
 if(!strcmp(cthis->m_state, "DoorClosed"))
 {   printf("reject closeTheDoor msg!\n");
	 return;
 }
 else
    cthis->go_state_DoorClosed(cthis);
}
static void  go_state_DoorOpened(void* t)
{
 Refri* cthis = (Refri*) t;
 strcpy(cthis->m_state, "DoorOpened");
 cthis->light->turnOn(cthis->light);
}
static void  go_state_DoorClosed(void* t)
{
 Refri* cthis = (Refri*) t;
 strcpy(cthis->m_state, "DoorClosed");
 cthis->light->turnOff(cthis->light);
}

CTOR(Refri)
  FUNCTION_SETTING(IR.init, init);
  FUNCTION_SETTING(IR.openTheDoor, openTheDoor);
  FUNCTION_SETTING(IR.closeTheDoor, closeTheDoor);
  FUNCTION_SETTING(go_state_DoorOpened, go_state_DoorOpened);
  FUNCTION_SETTING(go_state_DoorClosed, go_state_DoorClosed);
END_CTOR

