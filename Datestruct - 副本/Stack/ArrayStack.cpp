#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int ElemType;
const int MAXSIZE = 1000;
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}*stack;
int InitStack(stack &  S)
{
	S = (Stack *)malloc(sizeof(Stack));
	S->top = -1;
	return 1;
}
bool Isempty(stack S)//ÅÐ¶ÏÊÇ·ñÎª¿Õ
{
	if (S->top <= 0)
		return 1;
	return 0;
}
int PushStack(stack &S, ElemType e)//Ñ¹Õ»
{
	if (S->top >= MAXSIZE)
	{
		puts("Õ»ÒÑÂú£¬ÎÞ·¨Ñ¹Õ»");
		return -1;
	}
	else
	{
		S->data[++S->top] = e;
		//S->top++;
		return 1;
	}
}
int PopStack(stack &S, ElemType &e)//µ¯Õ»
{
	if (Isempty(S))
	{
		std::cout << "Õ»Îª¿Õ" << std::endl;
		return -1;
	}
	e = S->data[S->top--];
	return e;
}
int main1()
{
	stack S;
	ElemType e=-9999;
	InitStack(S);
	PushStack(S, 10);
	PushStack(S, 9);
	PushStack(S, 8);
	PushStack(S, 7);
	std::cout << PopStack(S, e);
	std::cout << PopStack(S, e);
	std::cout << PopStack(S, e);
	system("pause");
	return 0;
}