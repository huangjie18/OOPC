/* cx14-cir.c */
#include "lw_oopc.h"
#include "cx14-ia.h"

CLASS(Circle)
{
   IMPLEMENTS(IA);
   double radius;
};

static void init(void* t, double r)
{
  Circle* cthis = (Circle*)t;
  cthis->radius = r;
}

static double cal_area(void* t)
{
   Circle* cthis = (Circle*)t;
   return (3.1416 * cthis->radius * cthis->radius);
}

static double cal_perimeter(void* t)
{
   Circle* cthis = (Circle*)t;
   return (2 * 3.1416 * cthis->radius);
}

CTOR(Circle)
   FUNCTION_SETTING(IA.init, init)
   FUNCTION_SETTING(IA.cal_area, cal_area)
   FUNCTION_SETTING(IA.cal_perimeter, cal_perimeter)
END_CTOR
