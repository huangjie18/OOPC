// win32_ex01.cpp : Defines the entry point for the application.
#include "stdafx.h"
#include "windows.h"
#include "tchar.h"
#include <commctrl.h>
#include "AD.h"
#include "win32_ex01.h"

#define MAX_LOADSTRING 100

extern void* ADNew();
AD* ad;
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

	
   ShowWindow(hWindow, nCmdShow);
   UpdateWindow(hWindow);
   return TRUE;
}

HWND hWndButton3, hWndButton4;
HWND hWndButton5, hWndButton6;
HWND hWndButton7, hWndButton8;
HWND hWndButton9;

//
void signal_to_UI(LPCWSTR ss)
{  
   SetWindowText(hWndButton8, ss);
 }



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int ret;
	
	
	switch (message)
	{
     case WM_CREATE:
		 {
           HINSTANCE hInstance = 
               (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);

            hWndButton3= CreateWindowEx( 0, 
            _T("BUTTON"), _T("1"), 
            WS_VISIBLE | WS_CHILD, 
            20, 130, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON3, hInstance, NULL); 
                       
            hWndButton4= CreateWindowEx(0,
            _T("BUTTON"), _T("0"), 
            WS_VISIBLE | WS_CHILD, 
            120, 130, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON4, hInstance, NULL); 
                       
            hWndButton5= CreateWindowEx(0, 
            _T("BUTTON"), _T("C"), 
            WS_VISIBLE | WS_CHILD, 
            220, 130, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON5, hInstance, NULL); 
                        
            hWndButton6= CreateWindowEx( 0, 
            _T("BUTTON"), _T("+"), 
            WS_VISIBLE | WS_CHILD, 
            20, 200, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON6, hInstance, NULL); 
                       
            hWndButton7= CreateWindowEx(0,
            _T("BUTTON"), _T("="), 
            WS_VISIBLE | WS_CHILD, 
            120, 200, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON7, hInstance, NULL); 

            hWndButton8= CreateWindowEx(WS_EX_CLIENTEDGE | WS_EX_RIGHT,
            _T("EDIT"), _T("0"), 
            WS_VISIBLE | WS_CHILD, 
            20, 60, 260, 35, 
            hWnd, (HMENU) IDB_BUTTON8, hInstance, NULL); 
 
			hWndButton9= CreateWindowEx(WS_EX_CLIENTEDGE,
            _T("BUTTON"), _T("Exit"), 
            WS_VISIBLE | WS_CHILD, 
            350, 60, 80, 35, 
            hWnd, (HMENU) IDB_BUTTON9, hInstance, NULL); 
            mState = 0;
            //-----------------------------------------------
            ad = (AD*)ADNew();
			ad->init(ad);
		 }
           break;
	 case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId)
		{
			case IDB_BUTTON3:  // 1
                 ad->EvDigitPress(ad, 1);
				 break;
			case IDB_BUTTON4:  // 0
			     ad->EvDigitPress(ad, 0);
                 break;
            case IDB_BUTTON5:  // C
			     ad->EvCPress(ad);
                 break;
            case IDB_BUTTON6:  // +
			     ad->EvPlusPress(ad);
                 break;
            case IDB_BUTTON7: // =
                 ad->EvAssignPress(ad);
			     break;
            case IDB_BUTTON9:  //OK
			    DestroyWindow(hWindow);
             break;
		case IDM_ABOUT:
		 	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			//scr->copy_from_file_to_db(scr);
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
