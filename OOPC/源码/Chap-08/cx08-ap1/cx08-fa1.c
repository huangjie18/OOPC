/* cx08-fa1.c  */ 
#include <stdio.h>

static int numb1;

void smith();
int  jamis();

void linda()
{	printf( "SUM=%d", numb1 );  }

int main(void) {
	smith();
	numb1 = jamis();
	linda();
	fflush(stdin);
	getchar();
	return 0;
}
