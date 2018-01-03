/* cx19-ap4.c   */
#include "stdio.h"
#include "lw_oopc.h"

CLASS(Light) {
    void (*init)(void*);
    void (*performAction)(void*);
    void (*turnOn)();
    void (*turnOff)();
    int state_var;
  };
static void init(void* t)
    {
      Light* cthis = (Light*) t;
      cthis->state_var = 0;
    }
static void performAction(void* t)
    {
      Light* cthis = (Light*) t;
      if( cthis->state_var == 1)
          printf("Light is ON\n");
      else
          printf("Light is OFF\n");
    }
static void turnOn(void* t)
   {
      Light* cthis = (Light*) t;
      cthis->state_var = 1;
      cthis->performAction(cthis);
   }
static void turnOff(void* t)
   {
     Light* cthis = (Light*) t;
     cthis->state_var = 0;
     cthis->performAction(cthis);
   }

CTOR(Light)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(performAction, performAction)
   FUNCTION_SETTING(turnOn, turnOn)
   FUNCTION_SETTING(turnOff, turnOff)
END_CTOR
/*  ----------------------------  */
CLASS(Refri)
   {
     void (*set)(void*, Light*);
     void (*closeTheDoor)(void*);
     void (*openTheDoor)(void*);
     int state_var;
     Light* light_obj;
};

static void set(void* t, Light* light)
      {
	Refri* cthis = (Refri*)t;
        cthis->state_var = 0;
	cthis->light_obj = light;
       }
static void closeTheDoor(void* t)
      {
	Refri* cthis = (Refri*)t;
        cthis->state_var = 0;
	cthis->light_obj->turnOff(cthis->light_obj);
      }
static void openTheDoor(void* t)
      {
	Refri* cthis = (Refri*)t;
        cthis->state_var = 1;
	cthis->light_obj->turnOn(cthis->light_obj);
      }

CTOR(Refri)
  FUNCTION_SETTING(set, set)
  FUNCTION_SETTING(closeTheDoor, closeTheDoor)
  FUNCTION_SETTING(openTheDoor, openTheDoor)
END_CTOR

int main()
{
    Light *light = (Light*)LightNew();
    Refri *ref = (Refri*)RefriNew();

    light->init(light);
    ref->set(ref, light);

    ref->openTheDoor(ref);
    ref->closeTheDoor(ref);
    ref->openTheDoor(ref);

    getchar();
    return 0;
}