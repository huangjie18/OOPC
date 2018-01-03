/* cx08-pa1.c */
/* External storage class */
#include <stdio.h>

extern int sum;

void smith();
void jamis();

void linda()
{	printf( "SUM=%d", sum );  }

int main(void)
{
	smith();
	jamis();
	linda();
           
	fflush(stdin);
	getchar();
	return 0;
}
