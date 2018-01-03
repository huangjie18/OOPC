/* cx13-mat.c  */
/*             */
#include <stdio.h>
#include "cx13-mat.h"

static void initialize(Matrix* t)  { t->m = 0;   t->n = 0;  }
static void init_fii(Matrix* t, float* from, int row, int col )
	{   Vector* pv;  int i;
	    t->m = row+1;
		t->n = row+col+1;
		t->p = (Vector**)malloc(t->m * sizeof(Vector*));
	    for( i=0; i<t->m; i++, from += t->n )
			   {  pv = (Vector*)VectorNew();
			      pv->init_fi(pv, from, t->n);
		    	  t->p[i] = pv;
  				}
          }

static void destroy(Matrix* t)
  {   int i; Vector*pv;
	  if(t->m) {
	      for( i=0; i<t->m; i++)
	        { pv = t->p[i];
	          pv->destroy(pv);
	        }
  	      free(t->p);
	  }
  }

static void setRow(Matrix* t, Vector* from, int row) {
          Vector* pv;
		  pv = t->p[row];
		  pv->assign(pv, from);
      }
static Vector* row(Matrix* t, int i){  return t->p[i];   }
static Vector* col(Matrix* t, int i)  {
		  int k;  Vector* pv2;
	      Vector* pv = (Vector*)VectorNew();
		  pv->init_i(pv, t->m);
		  for(k=0; k<t->m; k++) {
              pv2 = t->p[k];
			  *pv->get(pv,k) = pv2->get_val(pv2,i);
		  }
          return pv;
		 }

static void assign(Matrix* t, Matrix* px) {
	Vector *pv, *pv2;  int i;
    t->m = px->m;
	t->n = px->n;
	t->p = (Vector**)malloc(t->m * sizeof(Vector*));
    for( i=0; i<t->m; i++){
	 		pv2 = px->row(px, i);
			pv = (Vector*)VectorNew();
            pv->init(pv);
			pv->assign(pv, pv2);
			t->p[i] = pv;
		}
    }

CTOR(Matrix)
	FUNCTION_SETTING(initialize, initialize);
    FUNCTION_SETTING(init_fii, init_fii);
	FUNCTION_SETTING(destroy, destroy);
    FUNCTION_SETTING(setRow, setRow);
    FUNCTION_SETTING(row, row);
    FUNCTION_SETTING(col, col);
	FUNCTION_SETTING(assign, assign);
END_CTOR