/*  cx13-05.c  */
#include <stdio.h>
#include "lw_oopc.h"

CLASS(Vector){
    void **pv;
    void (*init)(void*, int);
    void (*set)(void*, void*, int);
    void* (*get)(void*, int);
};

static void initialize(void* t, int n){
  Vector* cthis = (Vector*) t;
  cthis->pv = (void**)malloc(n * sizeof(void*));  
}
static void set_value(void* t, void* from, int k){
  int i;  Vector* cthis = (Vector*) t;
  cthis->pv[k] =from;
}
static void* get_value(void* t, int k){
   Vector* cthis = (Vector*)t;
   return cthis->pv[k];
}
CTOR(Vector)
   FUNCTION_SETTING(init, initialize);
   FUNCTION_SETTING(set, set_value);
   FUNCTION_SETTING(get, get_value);
END_CTOR
/*-------------------------------------------------------*/
CLASS(Rectangle){
   double width, length;
};
CTOR(Rectangle)
END_CTOR
/* ------------------------------------------------------ */
int main(){
   Rectangle *pr, *obj;
   Vector *px = (Vector*)VectorNew();   px->init(px, 3);
   pr = (Rectangle*)RectangleNew();   pr->width = 3.5;   pr->length =35.0;
   px->set(px, pr, 0);
   pr = (Rectangle*)RectangleNew();   pr->width = 4.5;   pr->length =45.0;
   px->set(px, pr, 1);
   pr = (Rectangle*)RectangleNew();   pr->width = 5.5;   pr->length =55.0;
   px->set(px, pr, 2);
   obj = (Rectangle*)px->get(px, 1);
   printf("%5.2f, %5.2f\n", obj->width, obj->length);
   obj = (Rectangle*)px->get(px, 2);
   printf("%5.2f, %5.2f\n", obj->width, obj->length);
   getchar();   return 0;
}

