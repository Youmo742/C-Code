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
bool Isempty(stack S)//�ж��Ƿ�Ϊ��
{
	if (S->top <= 0)
		return 1;
	return 0;
}
int PushStack(stack &S, ElemType e)//ѹջ
{
	if (S->top >= MAXSIZE)
	{
		puts("ջ�������޷�ѹջ");
		return -1;
	}
	else
	{
		S->data[++S->top] = e;
		//S->top++;
		return 1;
	}
}
int PopStack(stack &S, ElemType &e)//��ջ
{
	if (Isempty(S))
	{
		std::cout << "ջΪ��" << std::endl;
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