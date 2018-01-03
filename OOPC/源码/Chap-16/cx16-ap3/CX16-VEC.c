/* cx16-vec.c  */
#include "cx16-vec.h"
static void initialize(void* t, int n)
{
  Vector* cthis = (Vector*) t;
  cthis->index = 0;
  cthis->pv = (void**)malloc(n * sizeof(void*));
}

static void Add(void* t, void* obj)
{
  Vector* cthis = (Vector*) t;
  cthis->pv[cthis->index] = obj;
  cthis->index++;
}

static int GetSize(void* t)
{
   Vector* cthis = (Vector*)t;
   return cthis->index;
}

static void* Get(void* t, int k)
{
   Vector* cthis = (Vector*)t;
   return cthis->pv[k];
}

CTOR(Vector)
   FUNCTION_SETTING(init, initialize);
   FUNCTION_SETTING(Add, Add)
   FUNCTION_SETTING(GetSize, GetSize);
   FUNCTION_SETTING(Get, Get);
END_CTOR
