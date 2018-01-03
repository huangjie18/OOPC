/* cx08-ta1.c */
/* External storage class */
#include <stdio.h>
#include <string.h>

void update();
void count();
extern int upr, lwr;
char *ps = "Cute";

int main(void)
{
	update();
	count(); 
	printf( "upr=%d, lwr=%d", upr, lwr );
	fflush(stdin);
	getchar();
	return 0;
}
