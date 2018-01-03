/* cx13-app.c  */
#include "cx13-vec.h"
#include "cx13-mat.h"

int main()
{  Matrix* py; Vector *pr, *pv;  int k;
   Matrix* px = (Matrix*)MatrixNew();
   float vv[28] = { 1.1, 2.2, 3.3, 4.4, 15.5, 6.5, 7.5,
		    0.5, 1.5, 2.5, 13.5, 4.5, 5.5, 6.9,
		    7.1, 7.2, 17.3, 7.4, 7.5, 7.6, 7.7,
		    12.6, 13.7, 14.8, 25.9, 16.0, 17.1, 18.2  };
    px->init_fii(px, vv, 3, 3);
    py = (Matrix*)MatrixNew();
    py->assign(py, px);
    pr = px->row(px, 2);
    pr->PR(pr);
    k = pr->indexOfMax(pr);
    printf("indexOfMax = %d\n", k);
    /*------------------------------*/
    py->setRow(py, pr, 1);
    pv = py->col(py, 1);
    pv->PR(pv);
    /*------------------------------*/
    px->destroy(px);
    getchar();
    return 0;
}
