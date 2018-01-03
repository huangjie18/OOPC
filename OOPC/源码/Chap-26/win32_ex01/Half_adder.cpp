/*  Half_adder.c    */
#include "StdAfx.h" 
#include "stdio.h"
#include "half_adder.h"

static void init(void* t)
{
   Half_adder* cthis = (Half_adder*)t;
   cthis->a = -1;
   cthis->b = -1;
}

static void start_thread(void* t)
{
   //MessageBox(NULL,_T("HI!"),_T(""), MB_OK | MB_ICONINFORMATION);
   Half_adder* cthis = (Half_adder*)t;
   int temp;
   temp = cthis->b;
   DWORD wait_time, base_time, curr_time;
   while(1)
   {
          wait_time = 100;
          base_time = GetTickCount();
          //---------   waiting ----------------------------------
	      do {  curr_time =  GetTickCount() - base_time; 	 }  
	      while (curr_time < wait_time);
          //------------------------------------------------------		 
		  if(temp != cthis->b)
     		  { cthis->carry = cthis->a & cthis->b;
                cthis->sum = cthis->a ^ cthis->b;
              }
		  temp = cthis->b;
   }
}

//--------------------------------------------
CTOR(Half_adder)
   FUNCTION_SETTING(init, init)
   FUNCTION_SETTING(start_thread, start_thread)
END_CTOR