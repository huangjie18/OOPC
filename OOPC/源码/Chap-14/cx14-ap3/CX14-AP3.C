/*  cx14-ap3.c  */
#include <stdio.h>
#include "lw_oopc.h"
#include "cx14-all.h"

void main()
{
   double a;
   IALL* pa;   IB* pb;   IC* pc;
   /* -------------------------- */
   pb = (IB*)RectNew();
   pb->init(pb, 10.0, 10.0);
   a = pb->cal_area(pb);
   /* -------------------------- */
   pa = (IALL*)pb;
   pc = &(pa->IC);
   a = pc->cal_perimeter(pa);
   getchar();
}
