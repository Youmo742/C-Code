#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int Elemtype;
typedef struct StackNode
{
	Elemtype data;
	StackNode * next;
}*LinkStackptr,*LinkStack;
LinkStack top;//Õ»¶¥
LinkStack tail;//Õ»µ×
int InitStack(LinkStack & S)
{
	S = (LinkStack)malloc(sizeof(StackNode));
	S->data = -9999;
	S->next = NULL;
	top = S;
	tail = top;
	return 1;
}
bool IsEmpty(LinkStack S)
{
	if (top == tail)
		return 1;
	return 0;
}
int PushStack(LinkStack &S, Elemtype e)
{
	LinkStackptr current = tail;
	LinkStackptr q=(StackNode *)malloc(sizeof(StackNode));
	if (IsEmpty(S))
	{
		q->data = e;
		q->next = NULL;
		current->next = q;
		top = q;
		return 1;
	}
	else
	{
		while (current->next!=NULL)
		{
			current = current->next;
		}
		q->data = e;
		q->next = NULL;
		current->next = q;
		top = q;
		return 1;
	}
}
int PopStack(LinkStack &S, Elemtype &e)
{
	if (IsEmpty(S))
	{
		puts("Á´Õ»Îª¿Õ");
		return -9999;
	}
	LinkStackptr p = tail;
	while (p->next != top)
		p = p->next;
	LinkStackptr q = top;
	e = top->data;
	free(q);
	top = p;
	return e;	
}
int main()
{
	LinkStack S;
	Elemtype e = 0;
	InitStack(S);
	PushStack(S, 5);
	PushStack(S, 6);
	PushStack(S, 8);
	//PushStack(S, 20);
	std::cout << PopStack(S, e) << std::endl;
	std::cout << PopStack(S, e) << std::endl;
	std::cout << PopStack(S, e) << std::endl;
	std::cout << PopStack(S, e) << std::endl;
	system("pause");
	return 0;
}