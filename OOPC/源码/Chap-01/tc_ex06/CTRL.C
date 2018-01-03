/* ctrl.c   */
#include "stdio.h"
#include "ctrl.h"

static void init(CTRL *t) {
	t->pl = (Light*)LightNew();
 }
static void turnOn(CTRL *t){
	t->pl->turnOn(t->pl);
}
static void turnOff(CTRL *t) {
    t->pl->turnOff(t->pl);
}
CTOR(CTRL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(turnOn, turnOn)
	FUNCTION_SETTING(turnOff, turnOff)
END_CTOR

