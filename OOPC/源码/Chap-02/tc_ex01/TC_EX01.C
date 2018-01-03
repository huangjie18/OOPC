/* tc_ex01.c   */
#include "stdio.h"
#include "light.h"

extern void* LightNew();
void main()
{
    Light* light = (Light*)LightNew();
    light->turnOn();
    light->turnOff();
    getchar();
    return;
}
