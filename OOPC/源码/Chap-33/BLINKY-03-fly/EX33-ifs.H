/* EX33-ifs.h */
#ifndef IFS_H
#define IFS_H
#include "lw_oopc_kc.h"

CLASS(STATE)
{
	unsigned char state_code;
	int height;
	int position_x;
	int position_y;
};

INTERFACE(IFlyState)
{
    void (*init)(void*);
    void (*handle)(void*);
};
#endif
