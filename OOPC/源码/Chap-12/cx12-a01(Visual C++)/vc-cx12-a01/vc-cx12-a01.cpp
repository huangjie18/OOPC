// vc-cx12-a01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "vc-cx12-a01.h"
#include "cx12-lig.h"
#include "cx12-sw.h"

//--------------------------------------------
extern void* LightNew();
extern void* SwitchNew();

Light *light;
Switch *wall, *door;
//--------------------------------------------
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

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

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_VCCX12A01, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
 		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VCCX12A01));

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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VCCX12A01));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_VCCX12A01);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//

HWND hWndButton1, hWndButton2;
HWND hWndButton3, hWndButton4;
int st;
char ss[30];

void signal_to_light_UI(LPCWSTR ss)
{  
   SetWindowText(hWndButton3, ss);
   SetWindowText(hWndButton4, ss);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
case WM_CREATE: {
            HINSTANCE hInstance = 
               (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
        //    MessageBox(NULL,_T("diagnostic error"),_T(""), MB_OK | MB_ICONINFORMATION);  


//--------------------------------------
   light = (Light*)LightNew();
   light->init(light);
   wall = (Switch*)SwitchNew();
   wall->init(wall, light);
   door = (Switch*)SwitchNew();
   door->init(door, light);
//--------------------------------------

            hWndButton1= CreateWindowEx( 0, 
            _T("BUTTON"), _T("Wall Sw(down)"), 
            WS_VISIBLE | WS_CHILD, 
            20, 30, 140, 35, 
            hWnd, (HMENU) IDB_BUTTON1, hInstance, NULL); 
                       
            hWndButton2= CreateWindowEx(0,
            _T("BUTTON"), _T("Door Sw(down)"), 
            WS_VISIBLE | WS_CHILD, 
            20, 100, 140, 35, 
            hWnd, (HMENU) IDB_BUTTON2, hInstance, NULL); 
                       
            hWndButton3= CreateWindowEx(0, 
            _T("BUTTON"), _T("OFF"), 
            WS_VISIBLE | WS_CHILD, 
            210, 30, 50, 35, 
            hWnd, (HMENU) IDB_BUTTON3, hInstance, NULL); 
                        
            hWndButton4= CreateWindowEx(0, 
            _T("BUTTON"), _T("OFF"), 
            WS_VISIBLE | WS_CHILD, 
            210, 100, 50, 35, 
            hWnd,(HMENU) IDB_BUTTON4, hInstance, NULL);
     }
	break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
          case IDB_BUTTON1: {
             switch (HIWORD(wParam)){
                case BN_CLICKED:
                     wall->set_switch(wall);
					 st = wall->get_state(wall);
					 if (st == 1)
                        SetWindowText(hWndButton1, _T("Wall Sw(up)"));
                     else 
                        SetWindowText(hWndButton1, _T("Wall Sw(down)"));
                     break; 
                }
           }
           break;
           case IDB_BUTTON2: {
              switch (HIWORD(wParam)) {
                case BN_CLICKED:
                     door->set_switch(door);
					 st = door->get_state(door);
					 if (st == 1)
                        SetWindowText(hWndButton2, _T("Door Sw(up)"));
                     else 
                        SetWindowText(hWndButton2, _T("Door Sw(down)"));
                     break; 
                 break; 
                }}
           break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
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
