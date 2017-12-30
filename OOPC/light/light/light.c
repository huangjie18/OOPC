#include "stdio.h"
#include "light.h"

static void turnOn()
{
	printf("Light is ON\n");
}

static void turnOff()
{
	printf("Light is OFF\n");
}



void *LightNew()
{
	struct Light *t;
	t = (struct Light*)malloc(sizeof(struct Light));
	t->turnOn = turnOn;
	t->turnOff = turnOff;
	END_CTOR

CLASS(Circle)
	{

		double (*cal_area)(double r);
	};

double funcl(double r)
{
	return 3.1416 * r * r;
}

CTOR(Circle)
	FUNCTION_SETTING(cal_area,funcl)
END_CTOR

void main()
{
	double area;
	Circle *pc;
	pc=(Circle*)CircleNew();
	area = pc->cal_area(10);
	printf("area=%6.2f\n",area);
	getchar();
	return;
}