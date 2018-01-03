/* cx14-ia.h */
#ifndef IA_H
#define IA_H

INTERFACE(IA)
{
    void (*init)(void*, double);
    double (*cal_area)(void*);
    double (*cal_perimeter)(void*);
};
#endif