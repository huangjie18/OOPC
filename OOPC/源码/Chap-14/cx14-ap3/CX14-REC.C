/*  cx14-rec.c  */
#include "stdio.h"
#include "lw_oopc.h"
#include "cx14-ib.h"
#include "cx14-ic.h"

CLASS(Rect)
   {  IMPLEMENTS(IB);
      IMPLEMENTS(IC);
      double  length;
      double  width;
      void (*display)(char*, double);
   };

void initialize(void*, double, double);
double calculate_area(void*);
double calculate_perimeter(void*);
void pr(char*, double);

CTOR(Rect)
  FUNCTION_SETTING(IB.init, initialize)
  FUNCTION_SETTING(IB.cal_area, calculate_area)
  FUNCTION_SETTING(IC.init, initialize)
  FUNCTION_SETTING(IC.cal_perimeter, calculate_perimeter)
  FUNCTION_SETTING(display, pr)
END_CTOR

static void initialize(void* t, double len, double wid)
{ Rect* cthis = (Rect*)t;
  cthis->length = len;
  cthis->width = wid;
}
static double calculate_area(void* t)
{   Rect* cthis = (Rect*)t;
    double v;
    v = cthis->length * cthis->width;
    cthis->display("area", v);
    return v;
}
static double calculate_perimeter(void* cthis)
{   Rect* t = (Rect*)cthis;
    double v = (t->length + t->width)*2;
    t->display("perimeter", v);
    return v;
}
static void pr(char* str, double v )
{   printf("%s=%7.2f\n", str, v);
}

