/* EX27-09.C (BLINKY.C) */
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
    unsigned int i;              
    unsigned char j;      
	 
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

/* 主函数 */
char xdata MemPool[1024];
void main (void)  {
    LED *pe;	     /*   声明LED类型的指针  */
init_mempool(MemPool,sizeof(MemPool));
    pe = LEDNew();   /*   调用构造器LEDNew()来产生LED类的对象，
                          并且令pe指向该对象 */
    while (1) {                       
       pe->run();    /*   调用该对象的run()函数 */
    }
}
