/* cx14-sq.c */
#include "lw_oopc.h"
#include "cx14-ia.h"

CLASS(Square)
{
   IMPLEMENTS(IA);
   double side;
};

static void init(void* t, double s)
{
  Square* cthis = (Square*)t;
  cthis->side = s;
}

static double cal_area(void* t)
{
   Square* cthis = (Square*)t;
   return (cthis->side * cthis->side);
}

static double cal_perimeter(void* t)
{
   Square* cthis = (Square*)t;
   return (4 * cthis->side);
}

CTOR(Square)
   FUNCTION_SETTING(IA.init, init)
   FUNCTION_SETTING(IA.cal_area, cal_area)
   FUNCTION_SETTING(IA.cal_perimeter, cal_perimeter);
END_CTOR
