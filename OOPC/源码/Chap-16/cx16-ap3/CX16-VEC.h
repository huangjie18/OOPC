/*  cx16-vec.h  */
#include <stdio.h>
#include "lw_oopc.h"

CLASS(Vector)
{
    void **pv;
    int index;
    void (*init)(void*, int);
    void (*Add)(void*, void*);
    int (*GetSize)(void*);
    void* (*Get)(void*, int);
};
