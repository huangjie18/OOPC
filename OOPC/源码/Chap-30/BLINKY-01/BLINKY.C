/*  EX30-ap-1.c (BLINKY.c)   */
#include <REG52.H>
#include <stdio.h>
#include "EX30-lig.h"
#include "EX30-sw.h"

extern void* LightNew();
extern void* SwitchNew();

void g_delay(unsigned int ms) {
   int i, j;
   for(i=0; i<ms; i++)
      for(j=0; j<120; j++);
}

char xdata MemPool[1024];

void main()
{
    Light* light;  Switch* wall;   Switch* door;

	init_mempool(MemPool,sizeof(MemPool));
    
	light = (Light*)LightNew();
    wall = (Switch*)SwitchNew();
    door = (Switch*)SwitchNew();
    light->init(light);

    wall->light_obj = light;
    door->light_obj = light;

	wall->set_switch(wall);
	
	while(1) {
	   /* ¤W¼Ópress PSW1  */
       wall->set_switch(wall);
	   g_delay(18000);
       /*  press PSW2  */
       door->set_switch(door);
	   g_delay(18000);

       /* ¤U¼Ópress PSW2  */
       door->set_switch(door);
	   g_delay(18000);
       /*  press PSW1  */
	   wall->set_switch(wall);
	   g_delay(18000);
	}
}
