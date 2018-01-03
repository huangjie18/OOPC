/*  cx16-pan.c   */
#include "lw_oopc.h"
#include "cx16-ip.h"

CLASS(PanasonicCell)
{
    IMPLEMENTS(IPower);
    int pw;
};

static void init(void* t)
 {
    PanasonicCell* cthis = (PanasonicCell*)t;
    cthis->pw = 2;
}

static int GetPower(void* t)
{
  PanasonicCell* cthis = (PanasonicCell*)t;
  return cthis->pw;
}

CTOR(PanasonicCell)
    FUNCTION_SETTING(IPower.init, init);
    FUNCTION_SETTING(IPower.GetPower, GetPower);
END_CTOR
