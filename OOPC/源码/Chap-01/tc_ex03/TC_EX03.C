/* tc_ex03.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "ctrl.h"

extern void* CTRLNew();
void main()
{
    CTRL* ctrl = (CTRL*)CTRLNew();
    ctrl->init(ctrl);
    ctrl->turnOn(ctrl);
    ctrl->turnOff(ctrl);
    getchar();
    return;
}
