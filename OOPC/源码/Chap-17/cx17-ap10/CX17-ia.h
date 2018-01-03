/*  cx17-ia.h   */
INTERFACE(IA)
{
    void (*init)(void*, double, double);
    double (*cal_area)(void*);
    double (*cal_perimeter)(void*);
};
