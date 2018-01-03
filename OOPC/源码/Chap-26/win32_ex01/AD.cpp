/*  recorder.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include "AD.h"
#include "Half_adder.h"

extern void* Half_adderNew();
/*    -----------------------------------    */
// the main window class name
HANDLE hThread1;
HANDLE hThread2;
Half_adder* m_adder;
extern void signal_to_UI(LPCWSTR);

static DWORD WINAPI ThreadProc1(LPVOID lpParameter)
	{
	  m_adder->start_thread(m_adder);
      return 0;
    }
static void createThread1()
	{
       DWORD threadId;
	   hThread1 = CreateThread(NULL,0,ThreadProc1,NULL,0,&threadId);
	}

static DWORD WINAPI ThreadProc2(LPVOID lpParameter)
	{
	   // Reserved 
       return 0;
    }
static void createThread2()
	{
       DWORD threadId;
	   hThread2 = CreateThread(NULL,0,ThreadProc2,NULL,0,&threadId);
	}

static void init(void *t)
{
	AD* cthis = (AD*)t;
    cthis->adder = (Half_adder*)Half_adderNew();
    cthis->adder->init(cthis->adder);
	m_adder = cthis->adder;
    createThread1();
  	cthis->go_state_Ready(cthis);
}

static void EvDigitPress(void* t, int d)
{
    AD* cthis = (AD*)t;
    cthis->d = d;
    if(cthis->state == 0)
		cthis->go_state_First(cthis);
	else if(cthis->state == 1)
        cthis->go_state_First(cthis);
	else if(cthis->state == 2)
        cthis->go_state_Second(cthis);
    else if(cthis->state == 3)
        cthis->go_state_Second(cthis);
	
}
static void EvPlusPress(void* t)
{
    AD* cthis = (AD*)t;
    if(cthis->state == 1)
        cthis->go_state_Plus(cthis);
}

static void EvAssignPress(void* t)
{
    AD* cthis = (AD*)t;
    if(cthis->state == 3)
        cthis->go_state_Cal(cthis);
}

static void EvCPress(void* t)
{
    AD* cthis = (AD*)t;
    cthis->go_state_Ready(cthis);
}

static void go_state_Ready(void*t)
{
 AD* cthis = (AD*)t;
 cthis->state = 0;
 cthis->digit_1 = 0;
 cthis->digit_2 = 0;
 cthis->adder->init(cthis->adder);
 signal_to_UI(_T("><"));
}

static void go_state_First(void*t)
{
 AD* cthis = (AD*)t;
 cthis->state = 1;
 if(cthis->d == 1)
       signal_to_UI(_T("1"));
    else
       signal_to_UI(_T("0"));
 cthis->digit_1 = cthis->d;
}

static void go_state_Plus(void*t)
{
 AD* cthis = (AD*)t;
 cthis->state = 2;
}

static void go_state_Second(void*t)
{
 AD* cthis = (AD*)t;
 cthis->state = 3;
 if(cthis->d == 1)
       signal_to_UI(_T("1"));
    else
       signal_to_UI(_T("0"));
 cthis->digit_2 = cthis->d;
}

static void go_state_Cal(void*t)
{
 AD* cthis = (AD*)t;
 cthis->state = 4;
 cthis->adder->a = cthis->digit_1;
 cthis->adder->b = cthis->digit_2;

 //-------------- wait ------------------------------
 DWORD base_time, curr_time;
 base_time = GetTickCount();
 do {  curr_time =  GetTickCount() - base_time; 	 }  
 while (curr_time < 200);
 //---------------------------------------------------
 cthis->carry = cthis->adder->carry;
 cthis->sum = cthis->adder->sum;
 
 if(cthis->carry == 1 & cthis->sum == 1)
      signal_to_UI(_T("[11]"));
 else if(cthis->carry == 1 & cthis->sum == 0)
      signal_to_UI(_T("[10]"));
 else if(cthis->carry == 0 & cthis->sum == 1)
      signal_to_UI(_T("[01]"));
 else
      signal_to_UI(_T("[00]"));

}


CTOR(AD)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(EvDigitPress, EvDigitPress)
   FUNCTION_SETTING(EvPlusPress, EvPlusPress)
   FUNCTION_SETTING(EvAssignPress, EvAssignPress)
   FUNCTION_SETTING(EvCPress, EvCPress)
   FUNCTION_SETTING(go_state_Ready, go_state_Ready)
   FUNCTION_SETTING(go_state_First, go_state_First)
   FUNCTION_SETTING(go_state_Plus, go_state_Plus)
   FUNCTION_SETTING(go_state_Second, go_state_Second)
   FUNCTION_SETTING(go_state_Cal, go_state_Cal)
END_CTOR

