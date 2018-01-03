/*  cx15-pan.c   */
#include "lw_oopc.h"
#include "cx15-ic.h"

CLASS(PanasonicCell)
{
    IMPLEMENTS(ICell);
    int pw;
    ICell* next_cell;
};

static void init(void* t)
{
   PanasonicCell* cthis = (PanasonicCell*) t;
   cthis-> next_cell =NULL;
   cthis->pw = 10;
}

static void SetLink(void* t, ICell* nc)
{
     PanasonicCell* cthis = (PanasonicCell*)t;
     cthis->next_cell = nc;
}

static int GetPower(void* t)
{
    PanasonicCell* cthis = (PanasonicCell*) t;
    ICell *pc;
    if( cthis->next_cell == NULL)
	return cthis->pw;
    else
      {
         pc =  cthis->next_cell;
         return (cthis->pw +  pc->GetPower(pc));
       }
}
CTOR(PanasonicCell)
    FUNCTION_SETTING(ICell.init, init);
    FUNCTION_SETTING(ICell.SetLinkToNext, SetLink);
    FUNCTION_SETTING(ICell.GetPower, GetPower);
END_CTOR
