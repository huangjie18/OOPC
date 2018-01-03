/* cx10-poo.c  */
#include "cx10-poo.h"

double func1(double r)
{
  return (3.14*r*r);
}

CLASS(Circle)
   double (*cal_area)(double);
END_CLASS

int main(void)
      {
       double area;
       struct Circle cir;
       cir.cal_area = func1;
       area = cir.cal_area(10);
       PRINT(area);
       getchar();
       return 0;
      }

