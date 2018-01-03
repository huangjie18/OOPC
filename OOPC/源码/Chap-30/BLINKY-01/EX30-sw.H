/*   EX30-sw.h   */
#ifndef SWITCH_H
#define SWITCH_H
#include "lw_oopc_kc.h"
#include "EX30-lig.h"

CLASS(Switch)
{
  int state;
  Light* light_obj;
  void (*init)(void*);
  int (*get_state)(void*);
  void  (*set_switch)(void*);
};
#endif
