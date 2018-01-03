/*  cx16-cat.c   */
#include "lw_oopc.h"
#include "cx16-ip.h"

CLASS(CatCell)
{
    IMPLEMENTS(IPower);
    int watt;
};

static void initialize( void* t )
{
    CatCell* cthis = (CatCell*)t;
    cthis->watt = 3;
};

static int get_power(void* t)
{
  CatCell* cthis = (CatCell*)t;
  return cthis->watt;
}

CTOR(CatCell)
    FUNCTION_SETTING(IPower.init, initialize);
    FUNCTION_SETTING(IPower.GetPower, get_power);
END_CTOR
