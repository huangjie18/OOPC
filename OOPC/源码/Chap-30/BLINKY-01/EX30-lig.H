/* EX12-lig.h   */
#ifndef LIGHT_H
#define LIGHT_H
#include "lw_oopc_kc.h" 

CLASS(Light)
{
    int state;
    void (*init)(void*);
    int (*get_state)(void*);
    void (*set_light)(void*, int flag);
};
#endif
