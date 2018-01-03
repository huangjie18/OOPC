// win32_ex01.cpp : Defines the entry point for the application.
#include "stdafx.h"
#include "windows.h"
#include "tchar.h"
#include <commctrl.h>
#include "painter.h"
#include "scribble.h"
#include "win32_ex01.h"

#define MAX_LOADSTRING 100

extern void* ScribbleNew();
extern void* PainterNew();
Scribble* scr;
Painter* pa;
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND hWindow;
//--------------------------------------

int mState;
HWND hWndToolbar;
BOOL bMouseDown;
POINTS ptsEnd;
long m_Color;
int lastX, lastY;
//--------------------------------------
static char g_szClassName[] = "MyWindowClass";

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

  	//-------------------------------------------------------------------
   	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32_EX01, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32_EX01));
   
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

//

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32_EX01));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32_EX01);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   hWindow = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   if (!hWindow)
   {
      return FALSE;
   }

    INITCOMMONCONTROLSEX InitCtrlEx;

	InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
	InitCtrlEx.dwICC  = ICC_BAR_CLASSES;
	InitCommonControlsEx(&InitCtrlEx);

	TBBUTTON tbrButtons[10];
	
    tbrButtons[0].iBitmap   = 0;
	tbrButtons[0].idCommand = 0;
	tbrButtons[0].fsState   = TBSTATE_ENABLED;
	tbrButtons[0].fsStyle   = TBSTYLE_SEP;
	tbrButtons[0].dwData    = 0L;
	tbrButtons[0].iString   = 0;

	tbrButtons[1].iBitmap   = 0;
	tbrButtons[1].idCommand = CM_RED; //IDM_FILE_NEW;
	tbrButtons[1].fsState   = TBSTATE_ENABLED;
	tbrButtons[1].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[1].dwData    = 0L;
	tbrButtons[1].iBitmap   = 0;
	tbrButtons[1].iString   = 0;
	
	tbrButtons[2].iBitmap   = 1;
	tbrButtons[2].idCommand = CM_BLACK; //IDM_FILE_OPEN;
	tbrButtons[2].fsState   = TBSTATE_ENABLED;
	tbrButtons[2].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[2].dwData    = 0L;
	tbrButtons[2].iString   = 0;

	tbrButtons[3].iBitmap   = 2;
	tbrButtons[3].idCommand = CM_BLUE; //IDM_ARROW;
	tbrButtons[3].fsState   = TBSTATE_ENABLED;
	tbrButtons[3].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[3].dwData    = 0L;
	tbrButtons[3].iString   = 0;

	tbrButtons[4].iBitmap   = 3;
	tbrButtons[4].idCommand = CM_GREEN; //IDM_DRAW_LINE;
	tbrButtons[4].fsState   = TBSTATE_ENABLED;
	tbrButtons[4].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[4].dwData    = 0L;
	tbrButtons[4].iString   = 0;

    tbrButtons[5].iBitmap   = 0;
	tbrButtons[5].idCommand = 0;
	tbrButtons[5].fsState   = TBSTATE_ENABLED;
	tbrButtons[5].fsStyle   = TBSTYLE_SEP;
	tbrButtons[5].dwData    = 0L;
	tbrButtons[5].iString   = 0;

    tbrButtons[6].iBitmap   = 0;
	tbrButtons[6].idCommand = 0;
	tbrButtons[6].fsState   = TBSTATE_ENABLED;
	tbrButtons[6].fsStyle   = TBSTYLE_SEP;
	tbrButtons[6].dwData    = 0L;
	tbrButtons[6].iString   = 0;

    tbrButtons[7].iBitmap   = 4;
	tbrButtons[7].idCommand = IDM_CLEAR_AND_BEGIN;//CM_YELLOW_SQUARE; //IDM_FILE_OPEN;
	tbrButtons[7].fsState   = TBSTATE_ENABLED;
	tbrButtons[7].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[7].dwData    = 0L;
	tbrButtons[7].iString   = 0;

	tbrButtons[8].iBitmap   = 5;
	tbrButtons[8].idCommand = IDM_STOP; //CM_BLUE_CIRCLE; //IDM_ARROW;
	tbrButtons[8].fsState   = TBSTATE_ENABLED;
	tbrButtons[8].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[8].dwData    = 0L;
	tbrButtons[8].iString   = 0;

	tbrButtons[9].iBitmap   = 6;
	tbrButtons[9].idCommand = IDM_STOP_AND_DRAW; //CM_GREEN_SQUARE; //IDM_DRAW_LINE;
	tbrButtons[9].fsState   = TBSTATE_ENABLED;
	tbrButtons[9].fsStyle   = TBSTYLE_BUTTON;
	tbrButtons[9].dwData    = 0L;
	tbrButtons[9].iString   = 0;

	
	hWndToolbar = CreateToolbarEx(hWindow,
		                      WS_VISIBLE | WS_CHILD | WS_BORDER,
	                              IDB_BITMAP2,
	                              10, //NUMBUTTONS,
				      hInst,
			              IDB_BITMAP2,
				      tbrButtons,
				     10, // NUMBUTTONS,
				      16, 16, 16, 16,
				      sizeof(TBBUTTON));

   //-----------------------------------------------------
   /*CreateWindow(_T("BUTTON"), _T("Switch_1"), 
            WS_VISIBLE | WS_CHILD, 
            100, 60, 140, 35, 
            hWnd, (HMENU) IDB_BUTTON1, hInstance, NULL); 

   CreateWindow(_T("BUTTON"), _T("Switch_2"), 
            WS_VISIBLE | WS_CHILD, 
            100, 200, 140, 35, 
            hWnd, (HMENU) IDB_BUTTON2, hInstance, NULL); */
   //-----------------------------------------------------
   ShowWindow(hWindow, nCmdShow);
   UpdateWindow(hWindow);
   return TRUE;
}

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int ret;
	
	switch (message)
	{
     case WM_CREATE:
           scr = (Scribble*)ScribbleNew();
	       scr->init(scr);
		   pa = (Painter*)PainterNew();
		   pa->init(pa);
		   mState = 0;
           break;
	 case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
            case CM_RED:
               m_Color = (long)RGB(255,0, 0);
               break;
            case CM_BLUE:
               m_Color = (long)RGB(0,0, 255);
               break;
            case CM_GREEN:
               m_Color = (long)RGB(0,255, 0);
               break;
			case CM_BLACK:
               m_Color = (long)RGB(0,0, 0);
               break;
             case IDM_CLEAR_AND_BEGIN:
                 if(mState == 0 )
				 {
                   mState = 1;
                   scr->begin_record(scr);
				 }
				 else  //mState != 0
				 {
				   ret = MessageBox(NULL,_T("Clear current drawing?"),_T(""), MB_YESNO | MB_ICONINFORMATION);
				   if(ret == 6) // Yes
				   {  InvalidateRect(hWindow, NULL, TRUE);
				      mState = 1;
                      scr->begin_record(scr);
				    }
				 else
				    { // do nothing
				    }
				  }
				 break;
             case IDM_STOP:
               if(mState == 0)
				 {  MessageBox(NULL,_T("No drawing to stop!"),_T(""), MB_OK | MB_ICONINFORMATION);
				    return 0;
				 }
                 if(mState == 2)
				 {  MessageBox(NULL,_T("Already Stoped!"),_T(""), MB_OK | MB_ICONINFORMATION);
				    return 0;
				 }
				 mState = 2;
			   break;
             case IDM_STOP_AND_DRAW:
                 if(mState != 1 && mState != 2)
				 {  MessageBox(NULL,_T("Nothing to draw!"),_T(""), MB_OK | MB_ICONINFORMATION);
				    return 0;
				 }
				 scr->re_draw(scr);
			    break;
             case ID_FILE_SAVE:
                scr->save_drawing(scr);
			    break;
             case ID_FILE_LOAD:
                scr->load_drawing(scr);
				mState = 2;
			    break;
             case ID_FILE_CLEAR:
       //            ret = MessageBox(NULL,_T("Clear current drawing?"),_T(""), MB_YESNO | MB_ICONINFORMATION);
				   //if(ret == 6) // Yes
				   //{ 
				 InvalidateRect(hWindow, NULL, TRUE);
				//     scr->clear_list(scr);
				//     mState = 0;
				   //}
				   //else
				   //{  // do nothing
				   //}
				     break;
		case IDM_ABOUT:
		 	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
		    DestroyWindow(hWindow);
		    break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
case WM_LBUTTONUP:
            bMouseDown = false ;
            break;
case WM_RBUTTONDOWN:
      break;
case WM_LBUTTONDOWN:
        //    pX = (unsigned)lParam & (unsigned)0x0000ffff;  // LOWORD = x
        //    pY = (unsigned)lParam >> 16;               // HIWORD = y
		bMouseDown = true ;
        ptsEnd = MAKEPOINTS(lParam);  //«ö¤Umouse¥ªÁä
	    //-----------------------------------------------------------
        scr->record(scr, ptsEnd.x, ptsEnd.y, 0, m_Color);
        lastX = ptsEnd.x;   
	    lastY = ptsEnd.y;  
		//------------------------------------------------------------
        break;
case WM_MOUSEMOVE:  
             if (wParam & MK_LBUTTON) 
            {  	if (bMouseDown )
	     		 { ptsEnd = MAKEPOINTS(lParam); 
             	   pa->draw_line(pa, lastX, lastY, ptsEnd.x, ptsEnd.y,m_Color);
	               scr->record(scr,ptsEnd.x, ptsEnd.y, 1, m_Color);
                   lastX = ptsEnd.x;   
	               lastY = ptsEnd.y;  
			  	 }
            } 
            break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
      	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
