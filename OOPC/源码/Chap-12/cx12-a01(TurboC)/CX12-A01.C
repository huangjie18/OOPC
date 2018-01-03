/*  cx12-a01.c   */
#include <stdio.h>
#include "cx12-lig.h"
#include "cx12-sw.h"

int main()
{
    Light* light = (Light*)LightNew();
    Switch* wall = (Switch*)SwitchNew();
    Switch* door = (Switch*)SwitchNew();
    light->init(light);
    wall->init(wall, light);
    door->init(door, light);
    /*  press PSW1  */
    wall->set_switch(wall);
    /*  press PSW2  */
    door->set_switch(door);
    /*  press PSW2  */
    door->set_switch(door);
    /*  press PSW1  */
    wall->set_switch(wall);
    getchar();
    return 0;
}
