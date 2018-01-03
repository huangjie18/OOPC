/*   cx12-sw.h   */
#ifndef SWITCH_H
#define SWITCH_H
#include "lw_oopc.h"
#include "cx12-lig.h"

CLASS(Switch)
{
	int state;
	Light* light_obj;
	void (*init)(void*, Light*);
	int (*get_state)(void*);
	void  (*set_switch)(void*);
};
#endif
