/*  cx13-07.c  */
#include <stdio.h>
#include "lw_oopc.h"

CLASS(Matrix){
   int m, n;   double**v;
   void (*init)(void*, double**, int, int);
   double (*get)(void*, int, int);
};

static void init(void* t, double** A, int p, int q){
   int i, j;
   Matrix* cthis = (Matrix*)t;
   cthis->m = p;   cthis->n = q;
   cthis->v = (double**)malloc(p * sizeof(double *));
   for(i=0; i < p; i++)
	cthis->v[i] = (double*)malloc(q * sizeof(double));
   for(i=0; i<p; i++)
       for(j=0; j<q; j++)
	    cthis->v[i][j] = A[i][j];
}
static double get(void*t, int i, int j)
  {   Matrix* cthis = (Matrix*) t;      return cthis->v[i][j];  }
CTOR(Matrix)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(get, get)
END_CTOR
/* ----------------------------------------------------- */
void main()
{  Matrix* mat = (Matrix*)MatrixNew();
   double a = 0.0;
   double ** A;   int i;
   A = (double**)malloc(2 * sizeof(double *));
   for(i=0; i < 2; i++)
        A[i] = (double*)malloc(2 * sizeof(double));
   A[0][0] = 1.0/9.0;   A[1][1] = 9.0;
   A[0][1] = 1.0/4.0;   A[1][0] = 4.0;
   mat->init(mat,A,2,2);
   a = mat->get(mat, 0, 1);     printf("a=%7.3f\n", a);
   a = mat->get(mat, 1, 0);     printf("a=%7.3f\n", a);
   getchar();
   return 0;
}
