/*  cx14-vm.c  */
#include <stdio.h>
#include "cx14-con.h"
#include "cx14-vm.h"

static void init(void*t)
{
    VendingMachine* cthis = (VendingMachine*)t;
    cthis->index = 0;
}

static void feedCoin(void*t, ICoin* c)
   {  double v;
      VendingMachine* cthis = (VendingMachine*)t;
      cthis->array[cthis->index] = c;
      cthis->index++;
   }
static double getTotal(void*t)
  {
    int i, sum; ICoin *pc;
    VendingMachine* cthis = (VendingMachine*)t;
    sum = 0;
    for(i=0; i<cthis->index; i++)
     {
       pc = cthis->array[i];
       sum += pc->value(pc);
     }
     return sum;
  }
CTOR(VendingMachine)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(feedCoin, feedCoin)
   FUNCTION_SETTING(getTotal, getTotal)
END_CTOR
