// SC_Mod.h 
#pragma once
#include "light.h"

//--------------------------------------------------------
//--------------------------------------------------------
class SC_Boundary
{ 
	static Light *light;
	static int m_event_id;
	static HANDLE hThread_sc;
  public:
    static HWND hWnd;
    static void start();
	static DWORD WINAPI sc_ThreadProc(LPVOID lpParameter);
    static void stop();
	static void pressSwitch_one();
	static void pressSwitch_two();
	static void turnOn();
	static void turnOff();
};
