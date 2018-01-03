/* cx22-lig.h   */
#ifndef LIGHT_H
#define LIGHT_H
#include "lw_oopc.h"

INTERFACE(IL)
{
   void (*init)();
   void (*turnOn)(void*);
   void (*turnOff)(void*);
};

CLASS(Light)
{
   IMPLEMENTS(IL);
   char m_state[5];
   void (*go_state_On)(void*);
   void (*go_state_Off)(void*);
};
#endif

