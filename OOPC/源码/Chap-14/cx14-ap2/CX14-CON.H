/*  c14-con.h  */
#ifndef COIN_H
#define COIN_H
#include "lw_oopc.h"

INTERFACE(ICoin)
{
    void (*init)();
    double (*value)();
};
#endif
