/*  cx15-lig.c   */
#include "lw_oopc.h"
#include "cx15-ic.h"
#include "cx15-il.h"

CLASS(FlashLight)
{
   IMPLEMENTS(ILight);
   ICell *head, *tail;
};

static void init(void* t)
{
   FlashLight* cthis = (FlashLight*)t;
   cthis->head = NULL;
   cthis->tail = NULL;
}

static void AddCell(void*t, ICell* cell)
{   ICell *pc;
    FlashLight* cthis = (FlashLight*)t;
    if( cthis->head == NULL)
       {
	 cthis->head = cell;
	 cthis->tail =cthis-> head;
       }
    else
       {
	  pc = cthis->tail;
	  pc->SetLinkToNext(pc, cell);
	  cthis->tail = cell;
       }
}
static int Power(void*t)
{
  FlashLight* cthis = (FlashLight*)t;
  ICell *pc = cthis->head;
  return pc->GetPower(pc);
  }

CTOR(FlashLight)
    FUNCTION_SETTING(ILight.init, init);
    FUNCTION_SETTING(ILight.AddCell, AddCell);
    FUNCTION_SETTING(ILight.Power, Power);
END_CTOR
