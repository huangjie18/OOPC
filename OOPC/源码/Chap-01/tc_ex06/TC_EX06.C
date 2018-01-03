/* tc_ex06.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "ctrl.h"
#include "switch.h"

int length, width;
void init(){
	length = 10;
    width = 5;
}

void print_perimeter() {
	printf("P = %d\n", 2*(length + width));
}

void main()
{
    CTRL* ctrl = (CTRL*)CTRLNew();
    DoorSwitch *psw = (DoorSwitch*)DoorSwitchNew();
    
	ctrl->init(ctrl);
    ctrl->turnOn(ctrl);
    psw->swDown();
    ctrl->turnOff(ctrl);
    psw->swUp();

    init();
    print_perimeter();

    getchar();
    return;
}
