/*   threading.cpp   */
#include "StdAfx.h"
#include <io.h>
#include <iostream>
#include <fcntl.h>
#include "controller.h"

extern void* ControllerNew();
//---------------------------------------------------------------------
static int m_event_id;
HANDLE hThread_sc;
DWORD threadId_sc;
static Controller* ctrl;

static DWORD WINAPI sc_ThreadProcccc(LPVOID lpParameter)
	{
	 
	 /* AllocConsole();
      HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
      stdin->_file = _open_osfhandle((INT_PTR)hin, _O_RDONLY|_O_TEXT);
      HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
      stdout->_file = _open_osfhandle((INT_PTR)hout, _O_APPEND|_O_TEXT);
      HANDLE herr = GetStdHandle(STD_ERROR_HANDLE);*/
	 
	  ////*****************************************
      ctrl = (Controller*)ControllerNew();
	  ctrl->init(ctrl);
      ctrl->begin_record(ctrl);

	  ctrl->start(ctrl);
	  ////*****************************************
	  m_event_id = 0;
	  int k = 0;
      while(1)
	   { 
		 //  printf("id=%d\n", m_event_id);
         Sleep(100);
		 if(m_event_id == 1)
		 	 ctrl->turnOn(ctrl);
		 else if(m_event_id == 2)
			 ctrl->turnOff(ctrl);
		 else if(m_event_id < 0)
		 {
			 ctrl->destroy(ctrl);
			 break;
		 }
		 m_event_id = 0;
	   }
      FreeConsole();
      return 0;
    }
void begin()
	{
	   hThread_sc = CreateThread(NULL,0,sc_ThreadProc,NULL,0,&threadId_sc);
	}
void close()
    {
	   m_event_id = -1;  
	   /*TerminateThread(SC_Boundary::hThread_sc, NULL); */
    }
void pressSwitch_one()
{
	m_event_id = 1;
}
void pressSwitch_two()
{
	m_event_id = 2;
}

void recordX(int x, int y, int ty, COLORREF color)
{
  ctrl->record(ctrl, x,y,ty,color);
}