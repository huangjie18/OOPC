/* ahpnode.c   */
#include "stdio.h"
#include "string.h"
#include "llist.h"
#include "pcmatrix.h"
#include "iahpnode.h"

/* static char str_temp[120]; */
double temp = 0.0;

CLASS(AHPNode)
{
   IMPLEMENTS(IAHP);
   IColl* sons;
   IPCM* pm;
   char name[120];
   double weight;
 };

void init(void*, char*);
void setPCMatrix(void*, double**, int, char**);
int size(void*);
void* get_ca(void*, int);
void cal_PV_CR_recursive(void*);
void cal_weight_recursive(void*);
void goal_initial(void*);
void alternative_wieght_recursive(void* t, char* na);
void printPV(void*);
void go(void*);
/* double getChoiceWeight(void*);  */

CTOR(AHPNode)
  FUNCTION_SETTING(IAHP.init, init)
  FUNCTION_SETTING(IAHP.setPCMatrix, setPCMatrix)
  FUNCTION_SETTING(IAHP.size, size)
  FUNCTION_SETTING(IAHP.get_ca, get_ca)
  FUNCTION_SETTING(IAHP.cal_PV_CR_recursive, cal_PV_CR_recursive)
  FUNCTION_SETTING(IAHP.cal_weight_recursive, cal_weight_recursive)
  FUNCTION_SETTING(IAHP.goal_initial, goal_initial)
  FUNCTION_SETTING(IAHP.alternative_wieght_recursive, alternative_wieght_recursive)
  FUNCTION_SETTING(IAHP.printPV, printPV)
  FUNCTION_SETTING(IAHP.go, go)
/*  FUNCTION_SETTING(IAHP.getChoiceWeight, getChoiceWeight);  */
END_CTOR

extern void* LListNew();
extern void* PCMatrixNew();
static void init(void* t, char* na)
   {
	   AHPNode* cthis = (AHPNode*)t;
       strcpy(cthis->name, na);
	   cthis->pm = NULL;
       cthis->sons = (IColl*) LListNew();
       (cthis->sons)->init(cthis->sons);
   }

static void setPCMatrix(void* t, double** A, int n, char** caNames)
   {
      int k;
       AHPNode* cthis = (AHPNode*)t;
	   AHPNode* pa;
	   IColl* psons = cthis->sons;
       cthis->pm = (IPCM*) PCMatrixNew();
       (cthis->pm)->init(cthis->pm, A, n);
	   for(k = 0; k < n; k++ )
	   {
	      pa = (AHPNode*)AHPNodeNew();
	      pa->IAHP.init(pa, caNames[k]);
	      psons->add(psons, pa);
	   }
   }

static int size(void* t)
   {
       AHPNode* cthis = (AHPNode*)t;
	   return (cthis->pm)->getSize(cthis->pm);
   }

static void* get_ca(void*t, int k)
   {
       AHPNode* cthis = (AHPNode*)t;
	   IColl* pc = cthis->sons;
	   return pc->get(pc, k);
   }

static void printPV(void* t)
{
   AHPNode* cthis = (AHPNode*)t;
   IPCM* ma = cthis->pm;
   printf("%s\n", cthis->name);
   printf("   %7.3f\n", ma->getPV(ma, 0));
   printf("   %7.3f\n", ma->getPV(ma, 1));
   printf("   %7.3f\n", ma->getPV(ma, 2));
}

static void cal_PV_CR_recursive(void* t)
  {
	   AHPNode* cthis = (AHPNode*)t;
	   AHPNode* nd;
	   int sz, k;
       IPCM* ma = cthis->pm;
       if(ma == NULL) return;
	   ma->calculate(ma);
	   printf("%s's CR=>%7.3f\n", cthis->name, ma->getCR(ma));
	   if(ma->getCR(ma) > 0.1) /* is Not Consistency */
	   {
	 	 printf("%s's CR is NOT Consistent! %7.4f!\n", cthis->name, ma->getCR(ma));
	   }
       sz = ma->getSize(ma);
	   for(k=0; k < sz; k++ )
	   {
	      nd = (AHPNode*)cthis->IAHP.get_ca(cthis, k);
		  nd->IAHP.cal_PV_CR_recursive(nd);
	   }
   }

static void cal_weight_recursive(void* t)
   {
	   AHPNode* cthis = (AHPNode*)t;
	   AHPNode* nd;
	   int sz, k;
	   IPCM* ma = cthis->pm;
	   if(ma == NULL) return;
	   sz = ma->getSize(ma);
	   for(k=0; k < sz; k++ )
 {
		  nd = (AHPNode*)cthis->IAHP.get_ca(cthis, k);
		  nd->weight = cthis->weight * ma->getPV(ma, k);
		  nd->IAHP.cal_weight_recursive(nd);
	   }
   }

static void goal_initial(void* t)
   {
	   AHPNode* cthis = (AHPNode*)t;
	   cthis->weight = 1.0;
   }

static void go(void* t)
   {
	    int sz, k;
	    double a;
		AHPNode* cthis = (AHPNode*)t;
        IPCM* ma = cthis->pm;
		ma->calculate(ma);
		a = ma->getCR(ma);
        printf("CR = %7.3f\n", a);

		sz = ma->getSize(ma);
		for(k=0; k<sz; k++)
		{	a = ma->getPV(ma, k);
	    printf("PV[%d] = %7.3f\n", k, a);
		}

	/* printf("%s --> Value: %6.4f\n", cthis->name, cthis->weight); */
	}

static void alternative_wieght_recursive(void* t, char* na)
   {
        AHPNode* cthis = (AHPNode*)t;
	int sz, k;
        AHPNode* nd;
        IPCM* ma = cthis->pm;
	    if(ma == NULL)
		   {
		      if(!strcmp(cthis->name, na))
			  {
			 /*   printf("%s   %7.3f\n", cthis->name, cthis->weight);*/
		         temp += cthis->weight;
			  }
		      sz =0;
		   }
		   else
			   sz = ma->getSize(ma);

		   for(k=0; k < sz; k++ )
		   {
              nd = (AHPNode*)cthis->IAHP.get_ca(cthis, k);
			  nd->IAHP.alternative_wieght_recursive(nd, na);
		   }

   }