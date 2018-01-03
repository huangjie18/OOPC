/* cx17-ap1.c  */
#include "stdio.h"
double cal_area(double length, double width)
{	return length * width; }

double cal_perimeter(double length, double width)
{   return (length + width) * 2; }

/*------------------------------------------*/
int main()
{
   double v;
   v = cal_area(10.5, 20.5);
   printf("area=%7.3f\n", v);

   v = cal_perimeter(10.5, 20.5);
   printf("perimeter=%7.3f\n", v);

   getchar();
   return 0;
}
