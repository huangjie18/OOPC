/* cx08-pa2.c */
/* External storage class */
#include <stdio.h>
int sum;
static int numb1, numb2;

void smith()
{
	puts( "Type In Two Numbers:" );
	scanf( "%d,%d", &numb1, &numb2 );
}

void jamis()
{
	sum = numb1 + numb2;
}
