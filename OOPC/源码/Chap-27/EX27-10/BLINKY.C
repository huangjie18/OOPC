/* EX27-10.C (BLINKY.C)  */
#include <REG51F.H>
#include "lw_oopc_kc.h"
/* 定义LED类 */
CLASS(LED)
{
   void (*run)();     /* 定义LED类里的函数 */
};

void wait (void)  {              
       ;                              
     }

/* 实现LED类里的run()函数 */
	static void run(){
    unsigned int i;   unsigned char j;      
    for (j=0x01; j< 0x80; j<<=1)  {   
       P1 = j;                         
       for (i = 0; i < 10000; i++)  {  
           wait ();                      
       }
    }
    for (j=0x80; j> 0x01; j>>=1)  {  
      P1 = j;                         
      for (i = 0; i < 10000; i++)  { 
       wait ();                      
      }	   
    }
}

/* LED 类的构造器 */
CTOR(LED)
   FUNCTION_SETTING(run, run)
END_CTOR
/* ------------------------------------ */
CLASS(Controller)
{
    void (*doing)();
};

static void doing()
{
   	LED *pl = LEDNew();
     while (1) {  
	   pl->run();
	}
}

CTOR(Controller)
   FUNCTION_SETTING(doing, doing);
END_CTOR
/* ------------------------------------ */
/* 主函数 */
char xdata MemPool[1024];
void main (void)  {
    Controller *pc;	        /* 声明LED型态的指针 */
    init_mempool(MemPool,sizeof(MemPool));
    pc = ControllerNew();  
    pc->doing();            /* 调用该对象的run()函数 */
}
