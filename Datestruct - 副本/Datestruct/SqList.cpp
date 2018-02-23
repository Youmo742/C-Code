#include <iostream>
#include <stdio.h>
#include <stdlib.h>
const int MAXSIZE = 50;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];//�洢����Ԫ��
	int length;//˳���ǰ����
}SqList;
int InitList(SqList &L)//�������ʼ��
{
	L.length = 0;
	for (int i = 0;i < MAXSIZE;i++)
	{
		L.data[i] = -9999;
	}
	return 1;
}
int GetElem(SqList &L, int i,ElemType *e)//���ҵ�i��Ԫ��
{
	if (i > MAXSIZE || L.length == 0)
	{
		puts("Ԫ�ز�����");
		return -1;
	}
	*e = L.data[i - 1];
	return *e;
}
int InsElem(SqList &L,int i ,const ElemType & em)//�ڵ�i��λ�ò���Ԫ��e
{
	/*if (L.length == 0||L.data[i-1]==-9999)//�����Ϊ�գ�ֱ�ӷŽ�ȥ����
	{
		L.data[i-1] = e;
		L.length++;
		return 1;
	}*/
	if (i > MAXSIZE || L.length >= MAXSIZE || i < 1)
	{
		puts("�޷�����");
		return -1;
	}
	if (i > L.length&&i<MAXSIZE)
	{
		puts("���Ϊ�գ�ֱ�Ӳ嵽��β��");
		L.data[L.length] = em;
		L.length++;
		return 1;
	}
	if (i <= L.length)//����λ�ò��ڱ�β����Ҫ�ƶ�Ԫ��
	{
		for (int k = L.length;k >= i;k--)
			L.data[k] = L.data[k-1];
	}
	L.data[i - 1] = em;
	L.length++;
	return 1;
}
int DelElem(SqList &L,int i)//��i��λ�ã�ɾ��Ԫ��
{
	if (i >= L.length||i<1)
	{
		puts("Ԫ�ز����ڰ�");
		return -1;
	}
	for (int t = i;t<=L.length;t++)
	{
		L.data[t-1] = L.data[t];
	}
	L.length--;
	return 1;

}
int Print(SqList L)
{
	for (int i = 0;i < L.length;i++)
	{
		std::cout << L.data[i] << " ";
	}
	return 1;
}

int main()
{
	SqList L;
	InitList(L);
	InsElem(L, 5, 5);
	InsElem(L, 2, 5);
	InsElem(L, 1, 3);
	DelElem(L, 2);
	Print(L);
	system("pause");
	return 0;
}