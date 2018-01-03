/*  pcmatrix.c  */
#include "stdio.h"
#include "lw_oopc.h"
#include "pcmatrix.h"

CLASS(PCMatrix)
{
    IMPLEMENTS(IPCM);
    int size;
    double** V;
	void (*cal_total_row)(void*);
    void (*normalize)(void*);
    void (*cal_PV)(void*);
    void (*cal_CR)(void*);
    double (*calLambda)(void*);
    double (*calCI)(void*);
    double (*calCR)(void *);
};

void init(void*, double**,int);
void calculate(void*);
double getCR(void*);
double getPV(void*, int);
int getSize(void*);
void cal_total_row(void*);
void normalize(void*);
void cal_PV(void*);
void cal_CR(void*);
double calLambda(void*);
double calCI(void*);
double calCR(void *);
double getRI(int);

CTOR(PCMatrix)
 FUNCTION_SETTING(IPCM.init, init)
 FUNCTION_SETTING(IPCM.calculate, calculate)
 FUNCTION_SETTING(IPCM.getCR, getCR)
 FUNCTION_SETTING(IPCM.getPV, getPV)
 FUNCTION_SETTING(IPCM.getSize, getSize)
 FUNCTION_SETTING(cal_total_row, cal_total_row)
 FUNCTION_SETTING(normalize, normalize)
 FUNCTION_SETTING(cal_PV, cal_PV)
 FUNCTION_SETTING(cal_CR, cal_CR)
 FUNCTION_SETTING(calLambda, calLambda)
 FUNCTION_SETTING(calCI, calCI)
 FUNCTION_SETTING(calCR, calCR)
END_CTOR

static void init(void* t, double** A, int sz)
{
   int i, j;
   PCMatrix* cthis = (PCMatrix*)t;
   cthis->size = sz;
   cthis->V = (double**)malloc((sz+1) * sizeof(double *));
   for(i=0; i < sz+1; i++)
   cthis->V[i] = (double*)malloc((sz+2) * sizeof(double));
   for(j=0; j<sz; j++)
	for(i=0; i<sz; i++)
	   cthis->V[j][i] = A[j][i];
}

static void calculate(void* t)
{
  PCMatrix* cthis = (PCMatrix*) t;
  cthis->cal_total_row(cthis);
  cthis->normalize(cthis);
  cthis->cal_PV(cthis);
  cthis->cal_CR(cthis);
 }

static double getCR(void* t)
{
   PCMatrix* cthis = (PCMatrix*) t;
   return cthis->V[2][cthis->size+1];
}

static double getPV(void* t, int k)
{
   PCMatrix* cthis = (PCMatrix*) t;
   return cthis->V[k][cthis->size];
}

static int getSize(void* t)
{
   PCMatrix* cthis = (PCMatrix*) t;
   return cthis->size;
}

static void cal_total_row(void* t)
{
  double ss;
  int sz,i,j;
  PCMatrix* cthis = (PCMatrix*) t;
  sz = cthis->size;
  for (j = 0; j < sz; j++)
    {
      ss = 0;
      for (i = 0; i < sz; i++)
          ss += cthis->V[i][j];
      cthis->V[sz][j] = ss;
    }
}

static void normalize(void* t)
 {
   int sz,i,j;
   PCMatrix* cthis = (PCMatrix*) t;
   sz = cthis->size;
   for (j = 0; j < sz; j++)
	for (i = 0; i < sz; i++)
	   cthis->V[i][j] = cthis->V[i][j] / cthis->V[sz][j];
  }

static void cal_PV(void* t)
      {
	 int sz, i, j;
	 double ss;
         PCMatrix* cthis = (PCMatrix*)t;
         sz = cthis->size;
	 for (i = 0; i < sz; i++)
	      {	  ss = 0;
		 for (j = 0; j < sz; j++)
                 ss += cthis->V[i][j];
	          cthis->V[i][sz] = ss/sz;
	       }
	   }

static void cal_CR(void* t)
       {
         int sz;
         PCMatrix* cthis = (PCMatrix*)t;
         sz = cthis->size;
         cthis->V[0][sz+1]= cthis->calLambda(cthis);
         cthis->V[1][sz+1] = cthis->calCI(cthis);
         cthis->V[2][sz+1] = cthis->calCR(cthis);
	    }

static double calLambda(void* t)
     {
	 int sz, k;
	 double lambda = 0.0;
         PCMatrix* cthis = (PCMatrix*)t;
         sz = cthis->size;
	 for (k = 0; k < sz; k++)
	     lambda += cthis->V[sz][k] * cthis->V[k][sz];
	 return lambda;
     }

static double calCI(void* t)
     {
       int sz;
       double ci;
       PCMatrix* cthis = (PCMatrix*)t;
       sz = cthis->size;
       ci = (cthis->V[0][sz+1] - sz)/ (sz-1.0);
       return ci;
     }
static double calCR(void *t)
     {
       PCMatrix* cthis = (PCMatrix*)t;
	   int sz = cthis->size;
	   if(sz <= 2) return 0.0;
       else return cthis->calCI(cthis)/getRI(sz);
	 }

static double getRI( int size){
	    switch (size)
	    {
	      case 0 : return 0.00;
	      case 1 : return 0.00;
	      case 2 : return 0.00;
	      case 3 : return 0.58;
	      case 4 : return 0.90;
	      case 5 : return 1.12;
	      case 6 : return 1.24;
	      case 7 : return 1.32;
	      case 8 : return 1.41;
	      case 9 : return 1.45;
	      case 10: return 1.49;
	      default : return 1.5;
	    }
	  }

