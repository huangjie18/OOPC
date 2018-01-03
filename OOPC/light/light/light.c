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


static void init(void *t,double **A,int sz)
{
	int i,j;
	Matrix* cthis = (Matrix*)t;
	cthis->size = sz;
	/*产生一个二维数组*/
	cthis->V = (double**)malloc((sz)*sizeof(double *));
	for(i=0;i<sz;i++)
	{
		cthis->V[i] = (double*)malloc((sz)*sizeof(double));
	}
	for(j=0;j<sz;j++)
	{
		for(i=0;i<sz;i++)
		{
			cthis->V[j][i] = A[j][i]; 
		}
	}
}
//矩阵正规化运算
static void normalize(void* t)
{
	int sz,i,j;
	double ss;
	Matrix* cthis = (Matrix*)t;
	sz = cthis->size;
	for(j=0;j<sz;j++)
	{
		ss = 0;
		for(i=0;i<sz;i++)
		{
			ss += cthis->V[i][j];
		}
		for(i=0;i<sz;i++)
		{
			cthis->V[i][j] = cthis->V[i][j]/ss;
		}
	}
}

static double get(void* t,int i,int j)
{
	Matrix* cthis = (Matrix*) t;
	return cthis->V[i][j];
}

CTOR(Matrix)
	FUNCTION_SETTING(init,init)
	FUNCTION_SETTING(normalize,normalize)
	FUNCTION_SETTING(get,get)
END_CTOR

void main()
{
	Matrix* pcm = (Matrix*)MatrixNew();
	double **A;
	double a = 0.0;
	int i;
	A = (double**)malloc(2*sizeof(double*));
	for(i=0;i<2;i++)
	{
		A[i] = (double*)malloc(2*sizeof(double));
		A[i][i] = 1.0;
	}
	A[0][1] = 1.0/4.0;
	A[1][0] = 4.0;

	pcm->init(pcm,A,2);
	pcm->normalize(pcm);
	a = pcm->get(pcm,0,0); 
	printf("a=%7.3f\n",a);
	a = pcm->get(pcm,0,1);
	printf("a=%7.3f\n",a);
	a = pcm->get(pcm,1,0);
	printf("a=%7.3f\n",a);
	a = pcm->get(pcm,1,1);
	printf("a=%7.3f\n",a);
	getchar();
}