/* control.c  */
#include "stdio.h"
#include "light.h"

static Light *pl;
void init()
	{  pl = (Light*)LightNew();    }
void turnOn()
	{  pl->turnOn();  }
void turnOff()
	{  pl->turnOff();  }
