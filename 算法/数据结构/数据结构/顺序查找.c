#include <stdio.h>

static int search(int a[],int y,int x);//���Զ���ĺ�������
void sxcz()
{
	int i,x,n;
	int a[10];
	printf("������10�����֣�\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("������Ҫ���ҵ���: ");
	scanf("%d",&x);
	n = search(a,10,x);
	if(n<0)
		printf("û��\n");
	else
		printf("%d�������е�%d��Ԫ�ش�\n",x,n);
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
