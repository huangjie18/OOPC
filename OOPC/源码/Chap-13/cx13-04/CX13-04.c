/*  cx13-04.c  */
#include <stdio.h>
#include "lw_oopc.h"
#define VTYPE char

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
/* ----------------------------------------------------- */
int main(){
   Vector *px = (Vector*)VectorNew();
   char z[]= "my dog";
   px->init(px, z, 7);   printf("%c\n", px->get(px, 1));   printf(px->pv);
   getchar();   return 0;
}
