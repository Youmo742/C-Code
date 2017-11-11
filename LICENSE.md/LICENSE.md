```C++
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node *next;
}Node, *LinkList;
int CreatList_L(LinkList & L)
{
	LinkList p;
	L = (LinkList)malloc(sizeof(Node));
	if (!L)
	{
		cout << "失败" << endl;
		return 0;
	}
	L->next = NULL;
	while(1)
	{
		p = (LinkList)malloc(sizeof(Node));
		if (!p)
		{
			cout << "创建失败" << endl;
			return 0;
		}
		cin >> p->data;
		if (!p->data)
			return 0;
		p->next = L->next;
		L->next = p;
	}
	return 1;
}
int Visit(LinkList L)
{
	LinkList p = (LinkList)malloc(sizeof(Node));
	p = L->next;
	while (p!=NULL)
	{

		cout <<p->data<<" ";
		p = p->next;
	}
	free(p);
	return 1;
}
int Delete(LinkList & L)
{
	LinkList top = (LinkList)malloc(sizeof(Node));
	top = L;
	L = L->next;
	free(top);
	return 1;
}
int main()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(Node));
	int n = 0;
	cout << "请输入数据，以0结尾" << endl;
	CreatList_L(L);
	Visit(L);
	cout << endl;
	while (L->next)
	{
		Delete(L);
		Visit(L);
		cout << endl;
	}
	cout << "empty list" << endl;
	system("pause");
}
```
