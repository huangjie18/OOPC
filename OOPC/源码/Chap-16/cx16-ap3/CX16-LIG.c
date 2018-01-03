/*  cx16-lig.c   */
#include "lw_oopc.h"
#include "cx16-ip.h"
#include "cx16-il.h"
#include "cx16-vec.h"

CLASS(FlashLight)
{
   IMPLEMENTS(ILight);
   Vector* cell_list;
};

static void init(void* t)
{
   FlashLight* cthis = (FlashLight*)t;
   Vector* pv = (Vector*)VectorNew();
   pv->init(pv, 10);
   cthis->cell_list = pv;
}

static void AddCell(void*t, void* cp)
{
    FlashLight* cthis = (FlashLight*)t;
    Vector* list = cthis->cell_list;
    list->Add(list, cp);
}
static int Power(void*t)
{
  FlashLight* cthis = (FlashLight*)t;
  IPower *po;
  int sum = 0;
  int i, n;
  Vector* list = cthis->cell_list;
  n = list->GetSize(list);
  for(i=0; i<n; i++)
     {
       po= (IPower*)list->Get(list, i);
       sum = sum + po->GetPower(po);
     }
     return sum;
  }
CTOR(FlashLight)
    FUNCTION_SETTING(ILight.init, init);
    FUNCTION_SETTING(ILight.AddCell, AddCell);
    FUNCTION_SETTING(ILight.Power, Power);
END_CTOR