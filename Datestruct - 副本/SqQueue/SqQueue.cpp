#include<iostream>
#include <cstdio>
#include <cstdlib>
const int MAXSIZE = 5;
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;//指向队头
	int real;//指向队尾的下一个位置
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
		std::cout << "队列已满，无法插入" << std::endl;
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
		std::cout << "队列为空" << std::endl;
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