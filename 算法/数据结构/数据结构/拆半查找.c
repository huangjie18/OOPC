#include <stdio.h>
static int search(int a[],int n,int x);
void zheb()
{
	int i,x,z;
	int a[10];
	printf("������10���������֣�\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("������Ҫ���ҵ���: ");
	scanf("%d",&x);
	z = search(a,10,x);
	if(z<0)
		printf("û��\n");
	else
		printf("%d�������е�%d��Ԫ�ش�\n",x,z);
}

static int search(int a[],int n,int x)
{
	int low,mid,high;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;  //�԰��
		if(a[mid]==x)
			return mid+1;
		else if(a[mid]>x)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}