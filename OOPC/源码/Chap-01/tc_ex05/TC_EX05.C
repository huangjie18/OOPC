/* tc_ex05.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "ctrl.h"
#include "switch.h"

void main()
{
    CTRL* ctrl = (CTRL*)CTRLNew();
    DoorSwitch *psw = (DoorSwitch*)DoorSwitchNew();
    ctrl->init(ctrl);
    ctrl->turnOn(ctrl);
    psw->swDown();
    ctrl->turnOff(ctrl);
    psw->swUp();
    getchar();
    return;
}
