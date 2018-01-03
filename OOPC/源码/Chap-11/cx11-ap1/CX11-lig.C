/*  CX11-lig.c   */
#include "stdio.h"
#include "cx11-lig.h"

static void turnOn() 
   {  printf("Light is ON\n");  }
static void turnOff()
   {  printf("Light is OFF\n");  }
CTOR(Light)
   FUNCTION_SETTING(turnOn, turnOn)
   FUNCTION_SETTING(turnOff, turnOff)
END_CTOR
