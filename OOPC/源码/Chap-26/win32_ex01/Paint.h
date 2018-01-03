// Paint.h
#pragma once
#include "llist.h"
//using namespace std;

class dwPoint;
class Painter
{
	HWND hWnd;
    HDC hdc;
    HPEN hpen, holdPen;
  	INTERFACE(IColl)* m_pBuffer;  
    dwPoint *point;
public:
	Painter(INTERFACE(IColl)* pColl, HWND xhwnd);
    void draw_line(int prevX, int prevY, int x, int y, int ty, COLORREF color);
	void draw();
	void clearScreen();
	void paint();
};
