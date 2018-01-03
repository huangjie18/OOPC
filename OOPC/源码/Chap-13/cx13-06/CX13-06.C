/*  cx13-06.c  */
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
/*----------------------------------------------------------*/
CLASS(Circle){
   double radius;
   double (*cal_area)(void*);
};

static double cal_area(void* t){
   Circle *cthis = (Circle*)t;
   return  3.1416 * cthis->radius * cthis->radius;
}
CTOR(Circle)
    FUNCTION_SETTING(cal_area, cal_area);
END_CTOR
/* --------------------------------------------------------  */
int main(){
   int i;   Circle *pc, *obj;
   Vector *px = (Vector*)VectorNew();   px->init(px, 3);
   pc = (Circle*)CircleNew();   pc->radius = 3.5;   px->set(px, pc, 0);
   pc = (Circle*)CircleNew();   pc->radius = 4.5;   px->set(px, pc, 1);
   pc = (Circle*)CircleNew();   pc->radius = 10.0;   px->set(px, pc, 2);
   for(i=0; i<3; i++) {
       obj = (Circle*)px->get(px, i);
       printf("%5.2f\n", obj->cal_area(obj));
    }
   getchar();   return 0;
}
