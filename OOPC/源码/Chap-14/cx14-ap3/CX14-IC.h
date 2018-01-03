/*  cx14-ic.h  */
#ifndef IC_H
#define IC_H

INTERFACE(IC)
  {
    void (*init)(void*, double, double);
    double (*cal_perimeter)(void*);
  };
#endif
