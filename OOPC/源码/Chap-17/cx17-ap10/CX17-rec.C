/*  cx17-rec.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "cx17-ia.h"

CLASS(NewRect)
{
    IMPLEMENTS(IA);
    double length;
    double width;
};

void init_imp(void* t, double len, double wid)
{
   NewRect* cthis = (NewRect*)t;
   cthis->length = len;
   cthis->width = wid;
}

double cal_area_imp(void* t)
{
   NewRect* cthis = (NewRect*)t;
   return cthis->length * cthis->width;
}

double cal_perimeter_imp(void* t)
{
   NewRect* cthis = (NewRect*)t;
   return (cthis->length + cthis->width) * 2;
}

CTOR2(NewRect, Rectangle)
   FUNCTION_SETTING(IA.init, init_imp)
   FUNCTION_SETTING(IA.cal_area,cal_area_imp)
   FUNCTION_SETTING(IA.cal_perimeter,cal_perimeter_imp)
END_CTOR

