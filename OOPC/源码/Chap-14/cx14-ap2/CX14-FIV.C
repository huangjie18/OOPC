/*  cx14-fiv.c  */
#include <stdio.h>
#include "cx14-con.h"

CLASS(five_dollar)
{
    IMPLEMENTS(ICoin);
};

static void init(){}
static double value()
    {  return 5.0;   }

CTOR(five_dollar)
   FUNCTION_SETTING(ICoin.init, init)
   FUNCTION_SETTING(ICoin.value, value)
END_CTOR   
