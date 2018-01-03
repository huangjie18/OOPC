// Painter.cpp
#include "stdafx.h"
#include "llist.h"
#include "Painter.h"
#include "dwPoint.h"

Painter::Painter(INTERFACE(IColl)* pb, HWND hwd)
{
	m_pBuffer = pb;
	hWnd = hwd;
	}

void Painter::draw() //画出所有的点
	{
    DWORD curr_time, base_time, draw_time;
	int prevX, prevY, x, y;
    hdc = GetDC(hWnd); 
    //hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); //BLUE
    //holdPen = (HPEN)SelectObject(hdc, hpen);
    int n=0;
   // for(it = m_pBuffer->begin(); it != m_pBuffer->end(); it++)
   //{
	  // point = (dwPoint*)(*it);
   //    x = point->getX();
	  // y = point->getY();
   //    hpen = CreatePen(PS_SOLID, 1, point->getColor()); //BLUE
   //    holdPen = (HPEN)SelectObject(hdc, hpen);
	  // draw_time = point->getTimeSpan();
   //    if(n == 0)    base_time = GetTickCount();
   //    n++;
   //    //---------   waiting ----------------------------------
   //	   do {    curr_time =  GetTickCount() - base_time; 	 }  
	  // while (curr_time < draw_time);
   //    //------------------------------------------------------		 
	  //   if (point->getType()== 0)
			//{  prevX = x;     prevY = y; 	}
		 //else {
			    /*  MoveToEx(hdc, prevX, prevY, (LPPOINT) NULL); 
	              LineTo(hdc, x, y); */
			//      prevX = x;  prevY = y; 
   //         	}
   //}

   dwPoint* po;
   m_pBuffer->top(m_pBuffer);
   po = (dwPoint*) m_pBuffer->next(m_pBuffer);
   MoveToEx(hdc, 0, 0, (LPPOINT) NULL); 
   LineTo(hdc, po->m_x, po->m_y); 

    ReleaseDC(hWnd, hdc); 
}
//----------------------------------------------
void Painter::clearScreen()
{	
    PAINTSTRUCT ps;
    hdc = BeginPaint(hWnd, &ps); 
    EndPaint(hWnd, &ps);
}
void Painter::paint()
{	
    PAINTSTRUCT ps;
    hdc = BeginPaint(hWnd, &ps); 
    int prevX, prevY, x, y;
   /* for(it = m_pBuffer->begin(); it != m_pBuffer->end(); it++)
            {
	   point = (dwPoint*)(*it);
       x = point->getX();
	   y = point->getY();
       hpen = CreatePen(PS_SOLID, 1, RGB(230, 230, 200));
       holdPen = (HPEN)SelectObject(hdc, hpen);
	   if(point->getType() == 0)
		    MoveToEx(hdc, x, y, (LPPOINT) NULL); 
       else
		{   MoveToEx(hdc, prevX, prevY, (LPPOINT) NULL); 
	         LineTo(hdc, x, y); 
		}
        prevX = x;	    prevY = y;
        }*/
   EndPaint(hWnd, &ps);
}
void Painter::draw_line(int prevX, int prevY, int x, int y, int ty, COLORREF color)
{  // 画线
    hdc = GetDC(hWnd); 
	hpen = CreatePen(PS_SOLID, 1, color); //BLUE
    holdPen = (HPEN)SelectObject(hdc, hpen);
    MoveToEx(hdc, prevX, prevY, (LPPOINT) NULL); 
    LineTo(hdc, x, y);
	ReleaseDC(hWnd, hdc); 
}