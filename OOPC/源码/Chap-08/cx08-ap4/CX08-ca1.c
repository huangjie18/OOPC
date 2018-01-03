/* cx08-ca1.c */
#include <stdio.h>

float cylinder( float h, float r );
float area( float x );
float volume( float h, float x );

int main(void)
{
	printf( "Area=%.2f\n", area( 10.0 ) );
	printf( "Volume=%.2f\n", volume(4, 20.0) );
	printf( "Cylinder=%.2f\n", cylinder(5.0, 10.0) );
           
	fflush(stdin);
	getchar();
	return 0;
}
