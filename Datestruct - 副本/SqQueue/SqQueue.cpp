#include<iostream>
#include <cstdio>
#include <cstdlib>
const int MAXSIZE = 5;
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;//ָ���ͷ
	int real;//ָ���β����һ��λ��
}SqQueue;
int InitQueue(SqQueue *& S)
{
	S= (SqQueue *)malloc(sizeof(Queue));
	S->front = 0;
	S->real = 0;
	return 1;
}
int InsQueue(SqQueue *& S, ElemType e)
{
	if ((S->real + 1) % MAXSIZE == S->front)
	{
		std::cout << "�����������޷�����" << std::endl;
		return -1;
	}
	S->data[S->real] = e;
	S->real = (S->real + 1) % MAXSIZE;
	return 1;
}
int DelQueue(SqQueue *& S, ElemType &e)
{
	if (S->front == S->real)
	{
		std::cout << "����Ϊ��" << std::endl;
		return -1;
	}
	e = S->data[S->front];
	S->front = (S->front + 1) % MAXSIZE;
	return 1;
}
int LengthQueue(SqQueue * S)
{
	return (S->real - S->front + MAXSIZE) % MAXSIZE;
}
int main()
{
	SqQueue *S; 
	ElemType e;
	InitQueue(S);
	InsQueue(S, 5);
	InsQueue(S, 6);
	std::cout << LengthQueue(S)<<std::endl;
	DelQueue(S, e);
	std::cout << e<<std::endl<<LengthQueue(S);
	DelQueue(S, e);
	std::cout << e;
	system("pause");
	return 0;
}