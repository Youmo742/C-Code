#include <iostream>
#include <cstdio>
#include <cstdlib>
typedef int ElemType;
static int length = 0;//������ĳ���
typedef struct Node
{
	ElemType data;
	Node * next;
}*LinkList;
Node * head;
Node * InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	L->data = 0;
	head = L;
	length = 0;
	return head;
}
int InsList(LinkList &L,int i, const ElemType & e)//�ڵ�i��λ��ǰ����Ԫ��e
{
	Node *p = L;
	if (i > length)
	{
		puts("����λ���ˣ�ֱ�Ӳ嵽��β");
		while (p->next != NULL)
			p = p->next;
		Node *q = (Node *)malloc(sizeof(Node));
		q->next = NULL;
		q->data = e;
		p->next = q;
		length++;
		return 1;
	}
	if (i < 1)
	{
		puts("�޷��ҵ�����λ��");
		return -1;
	}
	for (int t =0;t < i-1;t++)
	{
		p = p->next;
	}
	Node *q = (Node *)malloc(sizeof(Node));
	q->next = p->next;
	p->next = q;
	q->data = e;
	length++;
	return 1;
}
int DelList(LinkList &L, int i)//ɾ����i��λ�õ�Ԫ��
{
	Node *p = L;
	if (i > length)
	{
		puts("û�����Ԫ��");
		return -1;
	}
	for (int t = 1;t < i;t++)
	{
		p = p->next;
	}
	Node *q = p->next;
	p->next = p->next->next;
	free(q);
	return 1;
}
int Print(LinkList L)
{
	Node *p = L;
	p = p->next;
	while (p!=NULL)
	{
		std::cout << p->data << "  ";
		p = p->next;
	}
	return 1;
}
int GetElem(LinkList L, int i)
{
	Node *p = L;
	if (i > length)
	{
		puts("NO THIS ELEM");
		return -1;
	}
	for (int t = 0;t < i;t++)
	{
		p = p->next;
	}
	return p->data;
}
int main()
{
	LinkList L;
	InitList(L);
	InsList(L, 2, 3);
	InsList(L, 1, 2);
	InsList(L, 1, 5);
	InsList(L, 2, 2);
	DelList(L, 2);
	Print(L);
	puts("\n");
	std::cout<<GetElem(L, 2);
	system("pause");
	return 0;
}