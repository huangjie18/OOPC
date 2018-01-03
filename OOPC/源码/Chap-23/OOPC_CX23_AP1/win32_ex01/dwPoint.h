/* dwPoint.h   */
#ifndef DWPOINT_H
#define DWPOINT_H
#include "lw_oopc.h"

CLASS(dwPoint)
{	
    int m_x;
    int m_y;
	int m_type;
    long m_color;
    long m_timeSpan;

    void (*init)(void*, int, int, int, long);
    void (*set_initial_time)(void*, long);
};
#endif
