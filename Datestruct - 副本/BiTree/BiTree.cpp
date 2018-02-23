#include "BiTree.h"
void CreatTree(Bitree &T)
{
		char ch;
		scanf("%c", &ch);//�����ַ�  
		if (ch == '.')//.���������  
			T = NULL;
		else
		{
			T = (BiNode *)malloc(sizeof(BiNode));
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
BiNode * Find(Bitree T, ElemType e)//����ĳ��Ԫ��
{
	if (T == NULL)
		return NULL;
	if (T->data == e)
		return T;
	Find(T->lchild, e);
	Find(T->rchild, e);
}
void PreOrderTra(Bitree T)//�������
{
	if (T == NULL)
		return;
	travel(T);
	PreOrderTra(T->lchild);
	PreOrderTra(T->rchild);
}
void InOrderTra(Bitree T)//�������
{
	if (T == NULL)
		return;
	InOrderTra(T->lchild);
	travel(T);
	InOrderTra(T->rchild);
}
void PostOrderTra(Bitree T)//�������
{
	if (T == NULL)
		return;
	InOrderTra(T->lchild);
	InOrderTra(T->rchild);
	travel(T);
}
void travel(Bitree T)//�����
{
	printf("%c", T->data);
}
int main()
{
	Bitree T;
	CreatTree(T);
	PreOrderTra(T);
	puts("");
	InOrderTra(T);
	puts("");
	PostOrderTra(T);
	if (Find(T, 'E'))
		std::cout << "�ҵ���";
	else std::cout << "û�ҵ�";
	system("pause");
}