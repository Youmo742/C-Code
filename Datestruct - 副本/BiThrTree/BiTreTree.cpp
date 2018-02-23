#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef enum{Link,Thread} Pointag;
typedef struct BiThrNode
{
	char data;
	BiThrNode *lchild;
	BiThrNode *rchild;
	Pointag ltag;
	Pointag rtag;
}*BiThrTree;
BiThrTree pre;
void CreatTree(BiThrTree &T)//����һ�ö�����
{
	char ch;
	scanf("%c", &ch);//�����ַ�  
	if (ch == '.')//.���������  
		T = NULL;
	else
	{
		T = (BiThrNode *)malloc(sizeof(BiThrNode));
		if (!T)
		{
			printf("�����ڴ�ʧ��\n");
			exit(1);
		}
		T->data = ch;//��T��ֵ  
		CreatTree(T->lchild);//����������
		CreatTree(T->rchild);//����������	
	}
}
void InThreadIng(BiThrTree &T)//����������
{
	if (T)
	{
		InThreadIng(T->lchild);

		if (!T->lchild)//û�����ӣ���������
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild)//�������Һ���
		{
			pre->rtag = Thread;
			pre->rchild = T;//��̾��ǵ�ǰ�ڵ�
		}
		pre = T;
		InThreadIng(T->rchild);
	}
}
/*BiThrNode * FindLast(BiThrTree T)//�ҵ����һ���ڵ�
{
	BiThrTree S = T;
	if (S == NULL)
		return NULL;
	FindLast(S->rchild);
		return S;
}
BiThrNode * FindFirst(BiThrTree T)//�ҵ���һ���ڵ�
{
	BiThrTree S = T;
	if (S == NULL)
		return NULL;
	FindFirst(S->lchild);
	return S;

}
*/
void Visit(BiThrTree T)
{
	std::cout << T->data<<std::endl;
}
//����ͷ��㣬��������������
int InOrderThread_Head(BiThrTree &h, BiThrTree t)
{
	h= (BiThrTree)malloc(sizeof(BiThrNode));
	if (h== NULL)
	{
		return 0;
	}

	h->rchild = h;
	h->rtag = Link;

	if (!t)      //���ΪNULL
	{
		h->lchild = h;
		h->ltag = Link;
	}
	else
	{
		pre = h;
		h->lchild = t;        //��һ��
		h->ltag = Link;
		InThreadIng(t);         //�ҵ����һ�����
		pre->rchild = h;        //���Ĳ�
		pre->rtag = Thread;
		(h)->rchild = pre;      //�ڶ���
	}
}
void BitThreadTar(BiThrTree S)
{/* �����������������T(ͷ���)�ķǵݹ��㷨��*/
		BiThrTree p;
		p = S->lchild; /* pָ������ */

		while (p != S)
		{ /* �������������ʱ��p==T */
			while (p->ltag == Link) /* �ɸ����һֱ�ҵ��������������� */
				p = p->lchild;
			Visit(p); /* ���ʴ˽�� */

			while (p->rtag == Thread&&p->rchild != S) /* p->rchild������(���)���Ҳ��Ǳ��������һ����� */
			{
				p = p->rchild;
				Visit(p); /* ���ʺ�̽�� */
			}

			p = p->rchild; /* ��p->rchild��������(���Һ���)��pָ���Һ��ӣ�����ѭ����*/
		}
}              /* �����������������ĵ�1����� */
int main()
{
	BiThrTree T;
	BiThrTree S;
	CreatTree(T);
	InOrderThread_Head(S, T);
	//InThreadIng(T);

	BitThreadTar(S);
	system("pause");

	return 0;
}