/*  cx17-app.c   */
#include "stdio.h"
#include "lw_oopc.h"
#include "cx17-ia.h"
/*------------------------------------------*/
int main()
{
   IA* pr;  double v;
   pr = (IA*)RectangleNew();
   pr->init(pr, 10.0, 20.5);

   v = pr->cal_area(pr);
   printf("area=%7.2f\n", v);

   v = pr->cal_perimeter(pr);
   printf("perimeter=%7.2f\n", v);

   getchar();
   return 0;
}
