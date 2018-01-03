/*  cx14-vm.h  */
#include <stdio.h>
#include "cx14-con.h"

CLASS(VendingMachine)
{
       void  (*init)(void*);
       void (*feedCoin)(void*, ICoin*);
       double (*getTotal)(void*);
       int index;
       ICoin* array[10];
};
