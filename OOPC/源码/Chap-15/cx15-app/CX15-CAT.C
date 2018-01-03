/*  cx15-cat.c   */
#include "lw_oopc.h"
#include "cx15-ic.h"

CLASS(CatCell)
{
    IMPLEMENTS(ICell);
    int pw;
    ICell* next_cell;
};

static void init(void* t)
{
   CatCell* cthis = (CatCell*) t;
   cthis->next_cell = NULL;
   cthis->pw = 7;
}

static void SetLink(void* t, void* nc)
{
     CatCell* cthis = (CatCell*) t;
     cthis->next_cell = nc;
}

static int GetPower(void* t)
{
    CatCell* cthis = (CatCell*) t;
    ICell *pc;
    if( cthis->next_cell == NULL)
	   return cthis->pw;
    else
      {
         pc =  cthis->next_cell;
         return (cthis->pw +  pc->GetPower(pc));
       }
}
CTOR(CatCell)
    FUNCTION_SETTING(ICell.init, init);
    FUNCTION_SETTING(ICell.SetLinkToNext, SetLink);
    FUNCTION_SETTING(ICell.GetPower, GetPower);
END_CTOR
