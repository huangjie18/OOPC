/*   cx17-ap4.c   */
#include "stdio.h"
#include "malloc.h"

struct Rectangle
{
   double length;
   double width;
   void (*init)(struct Rectangle*, double, double);
   double (*cal_area)(struct Rectangle*);
   double (*cal_perimeter)(struct Rectangle*);
};

void init(struct Rectangle* cthis, double l, double w)
{  cthis->length = l;
   cthis->width = w;
}

double cal_area(struct Rectangle* cthis)
{
	return cthis->length * cthis->width;
}

double cal_perimeter(struct Rectangle* cthis)
{
   return (cthis->length + cthis->width) * 2;
}

struct Rectangle* RectangleNew()
{
   struct Rectangle* t;
   t = (struct Rectangle*)malloc(sizeof(struct Rectangle));
   t->init = init;
   t->cal_area = cal_area;
   t->cal_perimeter = cal_perimeter;
   return t;
}
/*------------------------------------------*/
int main()
{  double v;
   struct Rectangle* pr;
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