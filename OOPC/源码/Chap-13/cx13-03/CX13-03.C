/*  cx13-03.c  */
#include <stdio.h>
#include "lw_oopc.h"
#define VTYPE int

CLASS(Vector){
    VTYPE *pv;
    void (*init)(void*, VTYPE*, int);
    VTYPE (*get)(void*, int);
};

static void initialize(void* t, VTYPE* from, int n){
  int i;  Vector* cthis = (Vector*) t;
  cthis->pv = (VTYPE*)malloc(n * sizeof(VTYPE));
  for(i=0; i<n; i++)
     cthis->pv[i] =from[i];
}
static VTYPE get_value(void* t, int k){
   Vector* cthis = (Vector*)t;
   return cthis->pv[k];
}
CTOR(Vector)
   FUNCTION_SETTING(init, initialize);
   FUNCTION_SETTING(get, get_value);
END_CTOR
/* ------------------------------------------------------- */
int main()
{  Vector *px = (Vector*)VectorNew();
   int x[] = { 3, 4, 5, 6, 7};
   px->init(px, x, 5);
   printf("%d\n", px->get(px, 3));
   getchar();   return 0;
}
