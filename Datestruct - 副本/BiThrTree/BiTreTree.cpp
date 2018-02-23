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
void CreatTree(BiThrTree &T)//创建一棵二叉树
{
	char ch;
	scanf("%c", &ch);//读入字符  
	if (ch == '.')//.代表空子树  
		T = NULL;
	else
	{
		T = (BiThrNode *)malloc(sizeof(BiThrNode));
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
void InThreadIng(BiThrTree &T)//中序线索化
{
	if (T)
	{
		InThreadIng(T->lchild);

		if (!T->lchild)//没有左孩子，左线索化
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild)//线索化右孩子
		{
			pre->rtag = Thread;
			pre->rchild = T;//后继就是当前节点
		}
		pre = T;
		InThreadIng(T->rchild);
	}
}
/*BiThrNode * FindLast(BiThrTree T)//找到最后一个节点
{
	BiThrTree S = T;
	if (S == NULL)
		return NULL;
	FindLast(S->rchild);
		return S;
}
BiThrNode * FindFirst(BiThrTree T)//找到第一个节点
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
//建立头结点，中序线索二叉树
int InOrderThread_Head(BiThrTree &h, BiThrTree t)
{
	h= (BiThrTree)malloc(sizeof(BiThrNode));
	if (h== NULL)
	{
		return 0;
	}

	h->rchild = h;
	h->rtag = Link;

	if (!t)      //如果为NULL
	{
		h->lchild = h;
		h->ltag = Link;
	}
	else
	{
		pre = h;
		h->lchild = t;        //第一步
		h->ltag = Link;
		InThreadIng(t);         //找到最后一个结点
		pre->rchild = h;        //第四步
		pre->rtag = Thread;
		(h)->rchild = pre;      //第二步
	}
}
void BitThreadTar(BiThrTree S)
{/* 中序遍历线索二叉树T(头结点)的非递归算法。*/
		BiThrTree p;
		p = S->lchild; /* p指向根结点 */

		while (p != S)
		{ /* 空树或遍历结束时，p==T */
			while (p->ltag == Link) /* 由根结点一直找到二叉树的最左结点 */
				p = p->lchild;
			Visit(p); /* 访问此结点 */

			while (p->rtag == Thread&&p->rchild != S) /* p->rchild是线索(后继)，且不是遍历的最后一个结点 */
			{
				p = p->rchild;
				Visit(p); /* 访问后继结点 */
			}

			p = p->rchild; /* 若p->rchild不是线索(是右孩子)，p指向右孩子，返回循环，*/
		}
}              /* 找这棵子树中序遍历的第1个结点 */
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