#include <iostream>
#include <stdio.h>
#include <stdlib.h>
const int MAXSIZE = 50;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];//存储数据元素
	int length;//顺序表当前长度
}SqList;
int InitList(SqList &L)//单链表初始化
{
	L.length = 0;
	for (int i = 0;i < MAXSIZE;i++)
	{
		L.data[i] = -9999;
	}
	return 1;
}
int GetElem(SqList &L, int i,ElemType *e)//查找第i个元素
{
	if (i > MAXSIZE || L.length == 0)
	{
		puts("元素不存在");
		return -1;
	}
	*e = L.data[i - 1];
	return *e;
}
int InsElem(SqList &L,int i ,const ElemType & em)//在第i个位置插入元素e
{
	/*if (L.length == 0||L.data[i-1]==-9999)//如果表为空，直接放进去即可
	{
		L.data[i-1] = e;
		L.length++;
		return 1;
	}*/
	if (i > MAXSIZE || L.length >= MAXSIZE || i < 1)
	{
		puts("无法插入");
		return -1;
	}
	if (i > L.length&&i<MAXSIZE)
	{
		puts("表后都为空，直接插到表尾了");
		L.data[L.length] = em;
		L.length++;
		return 1;
	}
	if (i <= L.length)//插入位置不在表尾，需要移动元素
	{
		for (int k = L.length;k >= i;k--)
			L.data[k] = L.data[k-1];
	}
	L.data[i - 1] = em;
	L.length++;
	return 1;
}
int DelElem(SqList &L,int i)//第i个位置，删除元素
{
	if (i >= L.length||i<1)
	{
		puts("元素不存在啊");
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