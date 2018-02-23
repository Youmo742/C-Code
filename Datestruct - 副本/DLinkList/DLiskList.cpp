#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int ElemType;
static int length=0;
typedef struct DNode
{
	ElemType data;
	DNode * next;
	DNode * prev;
}*DLinkList;
DNode * head = NULL;;
int InitList(DLinkList &L)
{
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	L->prev = NULL;
	L->data = 0;
	head = L;
	return 1;
}
int DInsList(DLinkList &L, int i, ElemType em)//���뵽iλ��֮��
{
	DNode *p = head;
	if (i >= length)
	{
		puts("���������ȣ��嵽��β");
		while (p->next!=NULL)
		{
			p = p->next;
		}
		DNode *q = (DNode *)malloc(sizeof(DNode));
		q->next = NULL;
		q->prev = p;
		q->data = em;
		p->next = q;
		length++;
		return 1;
	}
	if (i < 1)
	{
		puts("����λ�ô���");
		return -1;
	}
	for(int t=0;t<i;t++)
		p = p->next;
	DNode *q = (DNode *)malloc(sizeof(DNode));
	/*p->next = q;
	q->prev = p;
	q->next = p->next;
	p->next->prev = q;*/
	q->prev = p;
	q->next = p->next;
	p->next->prev = q;
	p->next = q;
	q->data = em;
	length++;

	return 1;
}
int DDelList(DLinkList &L, int i)//ɾ����i��λ�õ�Ԫ��
{
	if (i > length)
	{
		puts("û�д�Ԫ��");
		return -1;
	}
	DNode *p = head;
	for (int t = 0;t < i;t++)
		p = p->next;
	DNode *q = p->prev;
	q->next = p->next;
	p->next->prev = q;
	free(p);
	return 1;
}
int Print(DLinkList L)
{
	DNode *p = head;
	if (length == 0)
	{
		puts("����Ϊ��");
		return -1;
	}
	while (p->next != NULL)
	{
		p = p->next;
		std::cout << p->data << " ";
	}
	return 1;
}
int main()
{
	DLinkList L;
	InitList(L);
	DInsList(L, 2, 5);
	DInsList(L, 1, 4);
	DInsList(L, 1, 9);
	DInsList(L, 1, 4);
	DInsList(L, 1, 6);
	DDelList(L, 2);
	Print(L);
	system("pause");
	return 0;
}