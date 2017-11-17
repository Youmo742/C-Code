// List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
using namespace std;
struct Node
{
	int data;
	Node *link;
};

Node *Creat()//创建链表，输入0结束，尾插法
{
	Node *first, *newNode, *last;
	int num;
	cout << "INsert is ending with 0" << endl;
	cin >> num;
	first = NULL;
	last = NULL;
	while (num != 0)
	{
		newNode = new Node;
		assert(newNode != NULL);
		newNode->data = num;
		newNode->link = NULL;
		if (first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->link = newNode;
			last = newNode;
		}
		cin >> num;
	}
	return first;
}
void Delete(Node * &L, int n)//删除一个指定位置的元素
{
	Node *p, *q;
	int i = 0;
	p = L;
	for (int i = 1; i<n-1; i++)
	{
		if (p == NULL)
		{
			cout << "Not Find" << endl;
			exit(0);
		}
		p = p->link;
	}
	q = p->link;
	p->link = p->link->link;
	delete q;
}
void ListInsert(Node *&L, int Element)//在此位置后插入
{
	Node *current;
	current = L;
	for (int i = 1; i<Element; i++)
	{
		if (current == NULL)
			exit(0);
		current = current->link;
	}
	Node *p = new Node;
	if (!p)
		exit(0);
	cin >> p->data;
	p->link = current->link;
	current->link = p;
}
void ShowList(Node *L)//遍历链表，输出元素
{
	Node *p = new Node;
	p = L;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->link;
	}
	cout << endl;
}
int main()
{
	Node *L = new Node;
	int select;
	L = Creat();
	cout << endl;
	ShowList(L);
	cout << endl << "请选择操作" << endl<<"1	insert" << endl << "2	delete" << endl
		<< "0	exit" << endl;;
	cin >> select;
	while (select)
	{
		switch (select)
		{
		case 1:
			int n;
			cout << "输入插入的位置" <<endl<< "输入插入的元素" <<endl;
			cin >> n;
			ListInsert(L, n);
			ShowList(L);
			break;
		case 2:
			int i;
			cout << "输入删除的位置"  << endl;;
			cin >> i;
			Delete(L, i);
			ShowList(L);
			break;
		case 0:break;
		}
		cout << "选择操作" << endl;
		cin >> select;
	}
	system("pause");
	return 0;
}

