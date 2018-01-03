/*  cx14-ib.h  */
#ifndef IB_H
#define IB_H
INTERFACE(IB)
  {
    void (*init)(void*, double, double);
    double (*cal_area)(void*);
  };
#endif
