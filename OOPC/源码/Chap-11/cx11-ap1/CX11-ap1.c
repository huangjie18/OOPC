/*  CX11-ap1.c   */
#include "stdio.h"
#include "cx11-lig.h"
extern void* LightNew();
void main()
{   Light* light = (Light*)LightNew();
    light->turnOn(); 
    light->turnOff();
    getchar();
    return;
}
