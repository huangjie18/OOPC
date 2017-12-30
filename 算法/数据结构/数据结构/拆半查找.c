#include <stdio.h>
static int search(int a[],int n,int x);
void zheb()
{
	int i,x,z;
	int a[10];
	printf("请输入10个有序数字！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数: ");
	scanf("%d",&x);
	z = search(a,10,x);
	if(z<0)
		printf("没有\n");
	else
		printf("%d在数组中第%d个元素处\n",x,z);
}

static int search(int a[],int n,int x)
{
	int low,mid,high;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;  //对半分
		if(a[mid]==x)
			return mid+1;
		else if(a[mid]>x)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}