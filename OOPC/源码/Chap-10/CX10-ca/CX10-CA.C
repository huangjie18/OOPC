/* cx10-ca.c  */
#include <stdio.h>
#include "cx10-ca.h"
#include "cx10-ca2.h"

double func1(double r)
{
  return (PI*r*r);
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