/*   cx17-ap5.c   */
#include "stdio.h"
#include "malloc.h"

#define CLASS(type)\
typedef struct type type; \
struct type

/* ------------------------------------------------ */
CLASS(Rectangle)
{
    void (*init)(struct Rectangle*, double, double);
    double (*cal_area)(struct Rectangle*);
    double (*cal_perimeter)(struct Rectangle*);
    double length;
    double width;
};

void init_imp(Rectangle* cthis, double len, double wid)
{
   cthis->length = len;
   cthis->width = wid;
}

double cal_area_imp(Rectangle* cthis)
{
	return cthis->length * cthis->width;
}

double cal_perimeter_imp(Rectangle* cthis)
{
   return (cthis->length + cthis->width) * 2;
}

struct Rectangle* RectangleNew()
{
   Rectangle* t;
   t = (Rectangle*)malloc(sizeof(Rectangle));
   t->init = init_imp;
   t->cal_area = cal_area_imp;
   t->cal_perimeter = cal_perimeter_imp;
   return t;
}
/*------------------------------------------*/
int main()
{
   Rectangle* pr;   double v;
   pr = RectangleNew();
   pr->init(pr, 10.5, 20.5);

   v = pr->cal_area(pr);
   printf("area=%7.2f\n", v);

   v = pr->cal_perimeter(pr);
   printf("perimeter=%7.2f\n", v);

   getchar();
   return 0;
}


