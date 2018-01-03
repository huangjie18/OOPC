/*  ctrl.h   */
#include "lw_oopc.h"
#include "light.h"

CLASS(CTRL) {
    void (*init)(CTRL*);
    void (*turnOn)(CTRL*);
    void (*turnOff)(CTRL*);
    Light *pl;
  };

