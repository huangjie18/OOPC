/*  cx14-ten.c  */
#include <stdio.h>
#include "cx14-con.h"

CLASS(ten_dollar)
{
    IMPLEMENTS(ICoin);
};
static void init(){}
static double value()
    {  return 10.0;   }

CTOR(ten_dollar)
   FUNCTION_SETTING(ICoin.init, init)
   FUNCTION_SETTING(ICoin.value, value)
END_CTOR
