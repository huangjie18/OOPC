#include <windows.h>
#include <commctrl.h>

#include "toolbar_one.rh"

static char g_szClassName[] = "MyWindowClass";
static HINSTANCE g_hInst = NULL;

static HWND g_hToolBar;

#define ID_TOOLBAR         4998

#define  CM_RED_CIRCLE     200
#define  CM_GREEN_SQUARE   201
#define  CM_BLUE_CIRCLE    202
#define  CM_YELLOW_SQUARE  203

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
   switch(Message)
   {
      case WM_CREATE:
      {
         TBADDBITMAP tbab;
         TBBUTTON tbb[6];

         g_hToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
            WS_CHILD | WS_VISIBLE, 0, 0, 0, 0,
            hwnd, (HMENU)ID_TOOLBAR, g_hInst, NULL);

         // Send the TB_BUTTONSTRUCTSIZE message, which is required for
         // backward compatibility.
         SendMessage(g_hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);

         tbab.hInst = g_hInst;
         tbab.nID = IDB_TOOLBITMAP;
         SendMessage(g_hToolBar, TB_ADDBITMAP, 4, (LPARAM)&tbab);

         ZeroMemory(tbb, sizeof(tbb));
         tbb[0].iBitmap = 0;
         tbb[0].fsState = TBSTATE_ENABLED;
         tbb[0].fsStyle = TBSTYLE_BUTTON;
         tbb[0].idCommand = CM_RED_CIRCLE;

         tbb[1].fsStyle = TBSTYLE_SEP;

         tbb[2].iBitmap = 1;
         tbb[2].fsState = TBSTATE_ENABLED | TBSTATE_CHECKED;
         tbb[2].fsStyle = TBSTYLE_CHECKGROUP;
         tbb[2].idCommand = CM_GREEN_SQUARE;

         tbb[3].iBitmap = 2;
         tbb[3].fsState = TBSTATE_ENABLED;
         tbb[3].fsStyle = TBSTYLE_CHECKGROUP;
         tbb[3].idCommand = CM_BLUE_CIRCLE;

         tbb[4].fsStyle = TBSTYLE_SEP;

         tbb[5].iBitmap = 3;
         tbb[5].fsState = TBSTATE_ENABLED | TBSTYLE_GROUP;
         tbb[5].fsStyle = TBSTYLE_CHECK;
         tbb[5].idCommand = CM_YELLOW_SQUARE;

         SendMessage(g_hToolBar, TB_ADDBUTTONS, 6, (LPARAM)&tbb);
      }
      break;
      case WM_COMMAND:
         switch(LOWORD(wParam))
         {
            case CM_RED_CIRCLE:
               MessageBox(hwnd,
                  "You clicked the Red Circle\n(as if you didn't already know)",
                  "Hi", MB_OK | MB_ICONINFORMATION);
            break;
            case CM_GREEN_SQUARE:
               SendMessage(g_hToolBar, TB_ENABLEBUTTON, CM_RED_CIRCLE, MAKELONG(TRUE, 0));
               SendMessage(g_hToolBar, TB_ENABLEBUTTON, CM_YELLOW_SQUARE, MAKELONG(TRUE, 0));
            break;
            case CM_BLUE_CIRCLE:
               SendMessage(g_hToolBar, TB_ENABLEBUTTON, CM_RED_CIRCLE, MAKELONG(FALSE, 0));
               SendMessage(g_hToolBar, TB_ENABLEBUTTON, CM_YELLOW_SQUARE, MAKELONG(FALSE, 0));
            break;
            case CM_YELLOW_SQUARE:
               if(SendMessage(g_hToolBar, TB_ISBUTTONCHECKED, CM_YELLOW_SQUARE, 0))
                  MessageBox(hwnd, "Clap On", "Hi", MB_OK|MB_ICONINFORMATION);
               else
                  MessageBox(hwnd, "Clap Off", "Hi", MB_OK|MB_ICONINFORMATION);
             break;
         }
      break;
      case WM_SIZE:
         SendMessage(g_hToolBar, TB_AUTOSIZE, 0, 0);
      break;
      case WM_CLOSE:
         DestroyWindow(hwnd);
      break;
      case WM_DESTROY:
         PostQuitMessage(0);
      break;
      default:
         return DefWindowProc(hwnd, Message, wParam, lParam);
   }
   return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   LPSTR lpCmdLine, int nCmdShow)
{
   WNDCLASSEX WndClass;
   HWND hwnd;
   MSG Msg;

   InitCommonControls();

   g_hInst = hInstance;

   WndClass.cbSize        = sizeof(WNDCLASSEX);
   WndClass.style         = NULL;
   WndClass.lpfnWndProc   = WndProc;
   WndClass.cbClsExtra    = 0;
   WndClass.cbWndExtra    = 0;
   WndClass.hInstance     = g_hInst;
   WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
   WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
   WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
   WndClass.lpszMenuName  = NULL;
   WndClass.lpszClassName = g_szClassName;
   WndClass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

   if(!RegisterClassEx(&WndClass))
   {
      MessageBox(0, "Window Registration Failed!", "Error!",
         MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
      return 0;
   }

   hwnd = CreateWindowEx(0, g_szClassName, "Toolbar Example",
      WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 320, 240,
      NULL, NULL, g_hInst, NULL);

   if(hwnd == NULL)
   {
      MessageBox(0, "Window Creation Failed!", "Error!",
         MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
      return 0;
   }

   ShowWindow(hwnd, nCmdShow);
   UpdateWindow(hwnd);

   while(GetMessage(&Msg, NULL, 0, 0))
   {
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
   }
   return Msg.wParam;
}
