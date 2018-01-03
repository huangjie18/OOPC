/* cx22-ref.h   */
#ifndef REFRI_H
#define REFRI_H
#include "lw_oopc.h"

INTERFACE(IR)
{
   void (*init)();
   void (*openTheDoor)(void*);
   void (*closeTheDoor)(void*);
};

CLASS(Refri)
{
   IMPLEMENTS(IR);
   char m_state[15];
   IL* light;
   void (*go_state_DoorOpened)(void*);
   void (*go_state_DoorClosed)(void*);
};
#endif

