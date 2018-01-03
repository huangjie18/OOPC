/*  cx13-02.c  */
#include <stdio.h>
#include "lw_oopc.h"

CLASS(Vector){
    int *pv;
    void (*init)(void*);   
    void (*display)(void*, int);
};

static void init(void* t){
  Vector* cthis = (Vector*) t;
  cthis->pv = (int*)malloc(3 * sizeof(int));
  cthis->pv[0] =3;  cthis->pv[1] = 6;   cthis->pv[2] = 9;
}
static void print(void* t, int k){
   Vector* cthis = (Vector*)t;
   printf("%d\n", cthis->pv[k]);
}
CTOR(Vector)
   FUNCTION_SETTING(init, init);
   FUNCTION_SETTING(display, print);
END_CTOR
/* ----------------------------------------------------- */
int main(){
   Vector *px = (Vector*)VectorNew();
   px->init(px);
   px->display(px, 2);
   getchar();
   return 0;
}
