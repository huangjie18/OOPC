/*  cx16-app.c   */
#include <stdio.h>
#include "lw_oopc.h"
#include "cx16-ip.h"
#include "cx16-il.h"

int main()
{
   ILight *light;
   IPower *pan1, *pan2, *cat1;
   int pow;

   light = (ILight*)FlashLightNew();
   light->init(light);

   pan1 = PanasonicCellNew();
   pan1->init(pan1);
   pan2 =PanasonicCellNew();
   pan2->init(pan2);
   cat1 = CatCellNew();
   cat1->init(cat1);

   light->AddCell(light, pan1);
   light->AddCell(light, pan2);
   light->AddCell(light, cat1);

   pow = light->Power(light);
   printf("Power = %d\n", pow);
   getchar();
   return 0;
}
