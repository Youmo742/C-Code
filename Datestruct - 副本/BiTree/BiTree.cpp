#include "BiTree.h"
void CreatTree(Bitree &T)
{
		char ch;
		scanf("%c", &ch);//读入字符  
		if (ch == '.')//.代表空子树  
			T = NULL;
		else
		{
			T = (BiNode *)malloc(sizeof(BiNode));
			if (!T)
			{
				printf("开辟内存失败\n");
				exit(1);
			}
			T->data = ch;//给T赋值  
			CreatTree(T->lchild);//创建左子树
			CreatTree(T->rchild);//创建右子树	
		}
}
BiNode * Find(Bitree T, ElemType e)//查找某个元素
{
	if (T == NULL)
		return NULL;
	if (T->data == e)
		return T;
	Find(T->lchild, e);
	Find(T->rchild, e);
}
void PreOrderTra(Bitree T)//先序遍历
{
	if (T == NULL)
		return;
	travel(T);
	PreOrderTra(T->lchild);
	PreOrderTra(T->rchild);
}
void InOrderTra(Bitree T)//中序遍历
{
	if (T == NULL)
		return;
	InOrderTra(T->lchild);
	travel(T);
	InOrderTra(T->rchild);
}
void PostOrderTra(Bitree T)//后序遍历
{
	if (T == NULL)
		return;
	InOrderTra(T->lchild);
	InOrderTra(T->rchild);
	travel(T);
}
void travel(Bitree T)//输出树
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
		std::cout << "找到了";
	else std::cout << "没找到";
	system("pause");
}