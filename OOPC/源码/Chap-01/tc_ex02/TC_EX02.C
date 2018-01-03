/* cx01-ap2.c  */
#include "stdio.h"
#include "lw_oopc.h"

extern void init();
extern void turnOn();
extern void turnOff();

void main()
{
    init();
    turnOn();
    turnOff();
    getchar();
    return;
}
