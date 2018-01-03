#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct
{
	int num;
	char name[20];
} ElemType;//定义查找的结点元素
typedef struct
{
	ElemType *elem;
	int count;
	int sizeindex;
} HashTable;//定义哈希表
int Hash(int num)
{
	int p;
	p = num % 5;
	return p;
}//定义哈希函数
void InitHash(HashTable *H)//创建哈希表
{
	int i;
	H->elem = (ElemType *)malloc(MAX * sizeof(ElemType));
	H->count = 0;
	H->sizeindex = MAX;
	for (i = 0; i < MAX; i++)
		H->elem[i].num = 0; //初始化，使SearHash函数能判断到底有没有元素在里面
}
/************************************************************************/
/* 参数：H表示哈希表;key表示输入的数据;p表示为哈希值，即是要存放在哈希表中的地址位置                                                                     */
/************************************************************************/
int SearHash(HashTable H, int key, int *p) //查找函数
{
	int c = 0;
	*p = Hash(key);
	while (H.elem[*p].num != key && H.elem[*p].num != 0) //通过二次探测再散列解决冲突
	{
		c = c + 1;
		if (c % 2 == 1)  //判断偶数还是奇数
			*p = *p + (c + 1) * (c + 1) / 4; //奇数，重新求哈希值
		else
			*p = *p - (c * c) / 4;  //偶数，重新求哈希值
	}
	if (H.elem[*p].num == key)
		return 1;
	else
		return 0;
}


void InsertHash(HashTable *H, ElemType e) //如果查找不到就插入元素
{
	int p;
	SearHash(*H, e.num, &p);
	H->elem[p] = e;
	++H->count;
}


void haxicz()
{
	HashTable H; //定义一个哈希表
	int p,key,i;
	ElemType e;  //实例一个结点对象
	InitHash(&H); //对哈希表初始化
	for(i = 0;i<3;i++)
	{
loop:	printf("输入第%d个学生学号\n", i + 1);
		scanf("%d", &e.num); //输入学号
		if (!SearHash(H, e.num, &p)) //通过查找哈希表看该地址是否被占用
		{
			printf("输入第%d个学生名字\n", i + 1);
			scanf("%s", e.name); //输入名字
			InsertHash(&H, e); //插入元素
		}
		else
		{
			printf("该学号已经存在\n");//否则就表示元素的学号已经存在
			goto loop;//跳到loop处
		}
	}
	printf("请输入您要查找查找的学生学号:\n");
	scanf("%d", &key); //输入要查找的学号
	if (SearHash(H, key, &p)) //能查找成功
	{
		printf("查找成功！学生的姓名是%s\n", H.elem[p].name); //输出名字
		printf("学生所在表中的位置是%d\n", p); //输出位置
	}
	else
		printf("查找失败！您要查找的学生不存在！\n");
}

/************************************************************************/
/* 如果根据哈希值查找哈希表然后发现里面的内容不是自己要查找的内容，那么重新计算一个
/* 哈希值再次查找，然后根据返回值进行操作
/* 使用的是：开发定址法
/************************************************************************/