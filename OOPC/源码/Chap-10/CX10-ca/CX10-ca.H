/*  cx10-ca.h  */
#include <stdio.h>
#ifndef  CLASS_H
#define  CLASS_H
#define   PRINT(value)  printf("area=%6.2f\n",  value);
#define   CLASS(type)\
struct type\
{
#define  END_CLASS \
           };
#endif
