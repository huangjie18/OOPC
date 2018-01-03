/* CX11-ap2.c */
#include "stdio.h"
#include "string.h"
#include "lw_oopc.h"
#include "cx11-mat.h"

extern void* MatrixNew();
void main(){
  Matrix* pcm = (Matrix*)MatrixNew();   /* 生成Matrix对象 */
  double ** A;     /* 先把值存入A[][]里 */
  double a = 0.0;
  int i;
  A = (double**)malloc(2 * sizeof(double *));
  for(i=0; i < 2; i++)
       { A[i] = (double*)malloc(2 * sizeof(double));
        A[i][i] = 1.0;  }
  A[0][1] = 1.0/4.0;
  A[1][0] = 4.0;
  pcm->init(pcm,A,2);    /* 把A[][]值传过去，以设定对象初值 */
  pcm->normalize(pcm);   /* 调用normalize()以进行矩阵正规化运算 */
  a = pcm->get(pcm, 0, 0);     printf("a=%7.3f\n", a);  /* 取出矩阵元素值 */
  a = pcm->get(pcm, 0, 1);     printf("a=%7.3f\n", a);
  a = pcm->get(pcm, 1, 0);     printf("a=%7.3f\n", a);
  a = pcm->get(pcm, 1, 1);     printf("a=%7.3f\n", a);
  getchar();  return;
}


