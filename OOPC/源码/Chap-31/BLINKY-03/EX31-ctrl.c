/* EX31-ctrl.c  */
#include <REG52.H>
#include "lw_oopc_kc.h"
#include "ex31-ctrl.h"

extern void* LEDNew();
extern void* Channel_0New();
extern void* Channel_1New();
extern void g_delay(unsigned int);

static int buffer[10] = {7, 2, 0, 4};

static void load_data(LED *t) {
	t->digits[0] = buffer[0];
	t->digits[1] = buffer[1];
	t->digits[2] = buffer[2];
	t->digits[3] = buffer[3];
}

static void init(CTRL *t)
{
	t->ple = LEDNew();
	t->ps = Channel_0New();
	t->pd = Channel_1New();
	t->ple->load_data = load_data;
	t->ple->scan_port = t->ps;
	t->ple->data_port = t->pd;

}

static void run(CTRL *t) {
	t->ple->load_data(t->ple);
	t->ple->show_data(t->ple);
}
CTOR(CTRL)
	FUNCTION_SETTING(init, init)
	FUNCTION_SETTING(run, run)
END_CTOR
