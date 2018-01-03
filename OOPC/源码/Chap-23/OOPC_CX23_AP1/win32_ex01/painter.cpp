/*   painter.cpp   */
//   Utility Class 
#include "StdAfx.h"
#include "lw_oopc.h"
#include "llist.h"
#include "dwPoint.h"
#include "painter.h"

static HDC hdc;
static HPEN hpen, holdPen;
static HBRUSH hbrush, holdBrush;
extern HWND hWindow;

static void init(void *t) {} 
static void draw_line(void *t, int prevX, int prevY, int x, int y, long color)
{   hdc = GetDC(hWindow); 
	hpen = CreatePen(PS_SOLID, 1, (COLORREF)color); //BLUE
    holdPen = (HPEN)SelectObject(hdc, hpen);
    MoveToEx(hdc, prevX, prevY, (LPPOINT) NULL); 
    LineTo(hdc, x, y);
	ReleaseDC(hWindow, hdc); 
}
static void draw(void *t, INTERFACE(IColl)* list) 
{
    //Painter* cthis = (Painter*)t; 
	    
	DWORD curr_time, base_time, draw_time;
	int lastX, lastY, x, y;
    hdc = GetDC(hWindow); 
    int n=0;
    list->top(list);
	dwPoint* point;
    point = (dwPoint*)list->next(list);
	while(point != NULL)
    {
	     x = point->m_x;
	     y = point->m_y;
         hpen = CreatePen(PS_SOLID, 1,(COLORREF)point->m_color); 
         holdPen = (HPEN)SelectObject(hdc, hpen);
	     draw_time = point->m_timeSpan;
         if(n == 0)    base_time = GetTickCount();
          n++;
          //---------   waiting ----------------------------------
	      do {    curr_time =  GetTickCount() - base_time; 	 }  
	      while (curr_time < draw_time);
   //    //------------------------------------------------------		 
	     if (point->m_type == 0)
			{  lastX = x;    lastY = y; 	}
		 else {
			      MoveToEx(hdc, lastX, lastY, (LPPOINT) NULL); 
	              LineTo(hdc, x, y); 
			      lastX = x;  lastY = y; 
            	}
    point = (dwPoint*)list->next(list);
   }
   ReleaseDC(hWindow, hdc); 
}
//----------------------------------------------
//static void paint(void *t)
//{	
//	Painter* cthis = (Painter*)t; 
//	INTERFACE(IColl)* list = cthis->m_pList;
//    
//	PAINTSTRUCT ps;
//    hdc = GetDC(hWindow); 
//    int lastX, lastY, x, y;
//	list->top(list);
//	dwPoint* point;
//    point = (dwPoint*)list->next(list);
//	while(point != NULL)
//    {
//       x = point->m_x;
//	   y = point->m_y;
//       hpen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
//       holdPen = (HPEN)SelectObject(hdc, hpen);
//	   if (point->m_type == 0)
//			{  lastX = x;    lastY = y; 	}
//		 else {
//			      MoveToEx(hdc, lastX, lastY, (LPPOINT) NULL); 
//	              LineTo(hdc, x, y); 
//			      lastX = x;  lastY = y; 
//            	}
//    point = (dwPoint*)list->next(list);
//	}
//    ReleaseDC(hWindow, hdc); 
//}
CTOR(Painter)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(draw_line, draw_line)
   FUNCTION_SETTING(draw, draw)
//   FUNCTION_SETTING(paint, paint)
END_CTOR

