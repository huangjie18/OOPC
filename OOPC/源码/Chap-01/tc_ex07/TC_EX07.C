/* tc_ex07.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "ctrl.h"
#include "switch.h"

CLASS(Rectangle) {
   void (*init)(Rectangle*);
   void (*print_perimeter)(Rectangle*);
   int length, width;
   };

static void init(Rectangle *t){
	t->length = 10;
	t->width = 5;
}
static void pr_perimeter(Rectangle *t) {
	printf("P = %d\n", 2*(t->length + t->width));
}

CTOR(Rectangle)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(print_perimeter, pr_perimeter)
END_CTOR

void main()
{
    CTRL* ctrl = (CTRL*)CTRLNew();
    DoorSwitch *psw = (DoorSwitch*)DoorSwitchNew();
    Rectangle *rect  = (Rectangle*)RectangleNew();

    ctrl->init(ctrl);
    ctrl->turnOn(ctrl);
    psw->swDown();
    ctrl->turnOff(ctrl);
    psw->swUp();

    rect->init(rect);
    rect->print_perimeter(rect);

    getchar();
    return;
}
