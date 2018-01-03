/* EX31-ctrl.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-led.h"
#include "ex31-ctrl.h"

extern void* LEDNew();
extern void g_delay(unsigned int);

static void channel_1(char x) {
	P1 = x;
}

static void channel_0(char y) {
	P0 = y;
}

static int buffer[10] = {7, 2, 0, 4};

static void data_in_channel(LED *t) {
    t->digits[0] = buffer[0];
	t->digits[1] = buffer[1];
	t->digits[2] = buffer[2];
	t->digits[3] = buffer[3];
}

static void init(CTRL *t)
{
   t->ple = LEDNew();
   t->ple->scan_port = channel_1;
   t->ple->data_port = channel_0;
   t->ple->load_data = data_in_channel;
}

static void run(CTRL *t) {
   while(1) {
	   t->ple->load_data(t->ple);
       t->ple->show_digits(t->ple);
	   P0 = 0x00;
       P1 = 0x00;
       g_delay(10000);
	 }
}
CTOR(CTRL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(run, run)
END_CTOR