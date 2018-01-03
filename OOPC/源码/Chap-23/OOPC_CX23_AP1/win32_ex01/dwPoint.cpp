/* dwPoint.c   */
#include "stdafx.h"  
#include "dwPoint.h"

static long initial_time; 
static void init(void* t, int x, int y, int ty, long color)
 {
	 dwPoint* cthis = (dwPoint*)t;
     cthis->m_x = x; 
	 cthis->m_y = y;
	 cthis->m_type = ty;
	 cthis->m_color = color;
	 cthis->m_timeSpan = GetTickCount() - initial_time;
 }

static void set_initial_time(void *t, long iTime)
{
   initial_time = iTime;
}

CTOR(dwPoint)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(set_initial_time, set_initial_time)
END_CTOR