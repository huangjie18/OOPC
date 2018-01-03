/*  cx08-fa2.c  */
#include <stdio.h>

static int numb1, numb2;

void smith()
{
	puts( "Type In Two Numbers:" );
	scanf( "%d,%d", &numb1, &numb2 );
}

int jamis()
{
	int sum = numb1 + numb2;
	return sum;
}
