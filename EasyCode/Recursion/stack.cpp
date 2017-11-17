#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*定义最大堆栈容量*/

int stack[MAXSTACK];/*声明用于堆栈的数组*/
int top = -1;/*堆栈的顶端*/
			 /*判断是否为空堆栈*/
int isEmpty()
{
	if (top == -1) 
      return 1;
	else return 0;
}
/*将指定的数据压入堆栈*/
int push(int data)
{
	if (top >= MAXSTACK)
	{
		printf("堆栈已满,无法再加入\n");
		return 0;
	}
	else
	{
		stack[++top] = data; /*将数据压入堆栈*/
		return 1;

	}
}
/*从堆栈取出数据*/
int pop()
{
	if (isEmpty()) /*判断堆栈是否为空,如果是则返回-1*/
		return -1;
	else
		return stack[top--]; /*将数据从堆栈顶端取出后,再将堆栈指针往下移*/
}
/*主程序*/
int main()
{
	int value;
	int i;
	do
	{
		printf("要压入堆栈,请输入1,弹出则输入0,停止操作则输入-1: ");
		scanf("%d", &i);
		if (i == -1)
			break;
		else if (i == 1)
		{
			printf("请输入元素值:");
			scanf("%d", &value);
			push(value);
		}
		else if (i == 0)
			printf("弹出的元素为%d\n", pop());
	} while (i != -1);

	while (!isEmpty()) /*将数据陆续从堆栈顶端弹出*/
		printf("堆栈弹出的顺序为:%d\n", pop());
	printf("==========================\n");
	system("pause");
	return 0;
}
