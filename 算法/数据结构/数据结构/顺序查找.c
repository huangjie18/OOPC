#include <stdio.h>

static int search(int a[],int y,int x);//对自定义的函数定义
void sxcz()
{
	int i,x,n;
	int a[10];
	printf("请输入10个数字！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数: ");
	scanf("%d",&x);
	n = search(a,10,x);
	if(n<0)
		printf("没有\n");
	else
		printf("%d在数组中第%d个元素处\n",x,n);
}

static int search(int a[],int y,int x)
{
	int i,f=-1;
	for(i=0;i<y;i++)
	{
		if(a[i]==x)
		{
			return i+1;
		}
	}
	return f;
}
