#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct
{
	int num;
	char name[20];
} ElemType;//������ҵĽ��Ԫ��
typedef struct
{
	ElemType *elem;
	int count;
	int sizeindex;
} HashTable;//�����ϣ��
int Hash(int num)
{
	int p;
	p = num % 5;
	return p;
}//�����ϣ����
void InitHash(HashTable *H)//������ϣ��
{
	int i;
	H->elem = (ElemType *)malloc(MAX * sizeof(ElemType));
	H->count = 0;
	H->sizeindex = MAX;
	for (i = 0; i < MAX; i++)
		H->elem[i].num = 0; //��ʼ����ʹSearHash�������жϵ�����û��Ԫ��������
}
/************************************************************************/
/* ������H��ʾ��ϣ��;key��ʾ���������;p��ʾΪ��ϣֵ������Ҫ����ڹ�ϣ���еĵ�ַλ��                                                                     */
/************************************************************************/
int SearHash(HashTable H, int key, int *p) //���Һ���
{
	int c = 0;
	*p = Hash(key);
	while (H.elem[*p].num != key && H.elem[*p].num != 0) //ͨ������̽����ɢ�н����ͻ
	{
		c = c + 1;
		if (c % 2 == 1)  //�ж�ż����������
			*p = *p + (c + 1) * (c + 1) / 4; //�������������ϣֵ
		else
			*p = *p - (c * c) / 4;  //ż�����������ϣֵ
	}
	if (H.elem[*p].num == key)
		return 1;
	else
		return 0;
}


void InsertHash(HashTable *H, ElemType e) //������Ҳ����Ͳ���Ԫ��
{
	int p;
	SearHash(*H, e.num, &p);
	H->elem[p] = e;
	++H->count;
}


void haxicz()
{
	HashTable H; //����һ����ϣ��
	int p,key,i;
	ElemType e;  //ʵ��һ��������
	InitHash(&H); //�Թ�ϣ���ʼ��
	for(i = 0;i<3;i++)
	{
loop:	printf("�����%d��ѧ��ѧ��\n", i + 1);
		scanf("%d", &e.num); //����ѧ��
		if (!SearHash(H, e.num, &p)) //ͨ�����ҹ�ϣ���õ�ַ�Ƿ�ռ��
		{
			printf("�����%d��ѧ������\n", i + 1);
			scanf("%s", e.name); //��������
			InsertHash(&H, e); //����Ԫ��
		}
		else
		{
			printf("��ѧ���Ѿ�����\n");//����ͱ�ʾԪ�ص�ѧ���Ѿ�����
			goto loop;//����loop��
		}
	}
	printf("��������Ҫ���Ҳ��ҵ�ѧ��ѧ��:\n");
	scanf("%d", &key); //����Ҫ���ҵ�ѧ��
	if (SearHash(H, key, &p)) //�ܲ��ҳɹ�
	{
		printf("���ҳɹ���ѧ����������%s\n", H.elem[p].name); //�������
		printf("ѧ�����ڱ��е�λ����%d\n", p); //���λ��
	}
	else
		printf("����ʧ�ܣ���Ҫ���ҵ�ѧ�������ڣ�\n");
}

/************************************************************************/
/* ������ݹ�ϣֵ���ҹ�ϣ��Ȼ������������ݲ����Լ�Ҫ���ҵ����ݣ���ô���¼���һ��
/* ��ϣֵ�ٴβ��ң�Ȼ����ݷ���ֵ���в���
/* ʹ�õ��ǣ�������ַ��
/************************************************************************/