/*  CX11-mat.c  */
#include "stdio.h"
#include "lw_oopc.h"
#include "cx11-mat.h"

static void init(Matrix* this, double** A, int sz)
{  int i, j;
   this->size = sz;
   /* 产生一个2维数组 */
   this->V = (double**)malloc((sz) * sizeof(double *));
   for(i=0; i < sz; i++)
      this->V[i] = (double*)malloc((sz) * sizeof(double));
   for(j=0; j<sz; j++)
	for(i=0; i<sz; i++)
	   this->V[j][i] = A[j][i];
}
static void normalize(Matrix* this)   /* 矩阵正规化运算 */
 { int sz,i,j;
   double ss;
   sz = this->size;
   for (j = 0; j < sz; j++)
    {  ss = 0;
      for (i = 0; i < sz; i++)    ss += this->V[i][j];
      for (i = 0; i < sz; i++)    this->V[i][j] = this->V[i][j] / ss;
    }
}
static double get(Matrix *this, int i, int j)
  {   return this->V[i][j];  }
CTOR(Matrix)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(normalize, normalize)
   FUNCTION_SETTING(get, get)
END_CTOR

