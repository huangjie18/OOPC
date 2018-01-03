// win32_ex01.cpp : Defines the entry point for the application.
#include "stdafx.h"
#include "windows.h"
#include "tchar.h"
#include <commctrl.h>
#include "recorder.h"
#include "win32_ex01.h"

#define MAX_LOADSTRING 100

extern void* RecorderNew();
Recorder* scr;
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

	
	hWndToolbar = CreateToolbarEx(hWindow, WS_VISIBLE | WS_CHILD | WS_BORDER,
	                              IDB_BITMAP2, 10, //NUMBUTTONS,
				      hInst, IDB_BITMAP2,  tbrButtons,  10, // NUMBUTTONS,
				      16, 16, 16, 16,
				      sizeof(TBBUTTON));

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
	TCHAR sss[100];
	
	switch (message)
	{
     case WM_CREATE:
           scr = (Recorder*)RecorderNew();
	       scr->init(scr);
		   mState = 0;
           break;
	 case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:

 //_stprintf (sss, _T("X  is: %d "), wmId);
 //MessageBox(NULL,sss,_T(""), MB_OK | MB_ICONINFORMATION);
 //         
		switch (wmId)
		{
			case IDM_CLEAR_AND_BEGIN:  // begin recording
				 scr->prepare_rec(scr);
                 scr->start_rec(scr);
                 mState = 1;
      			 break;
             case IDM_STOP:  // stop recording and save wave data to file & DB
               if(mState == 0)
				 {  MessageBox(NULL,_T("No wave data to save!"),_T(""), MB_OK | MB_ICONINFORMATION);
				    return 0;
				 }
                 if(mState == 2)
				 {  MessageBox(NULL,_T("Already Saved in file!"),_T(""), MB_OK | MB_ICONINFORMATION);
				    return 0;
				 }
				 scr->close_rec(scr);  // Save to c:\\SymSound.wav
				 mState = 2;
			    break;
             case IDM_STOP_AND_DRAW:
                if(mState == 1) return 0;  // is recording
                scr->play_WaveFile(scr);
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
