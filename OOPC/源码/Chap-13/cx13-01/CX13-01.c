/*  cx13-01.c    */
#include "stdio.h"
#include "lw_oopc.h"

CLASS(Vector){
   int v[3];
   void (*display)(void*, int);
};
static void print(void* t, int k) {
   Vector* cthis = (Vector*)t;
   printf("%d\n", cthis->v[k]);
}
CTOR(Vector)
   FUNCTION_SETTING(display, print);
END_CTOR
/* ---------------------------------------------------- */
int main(){
   Vector *px = (Vector*)VectorNew();
   px->v[0] = 3;   px->v[1] = 6;   px->v[2] = 9;
   px->display = print;   px->display(px, 1);
   getchar();   return 0;
}
