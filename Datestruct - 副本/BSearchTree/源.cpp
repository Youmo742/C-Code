#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define false 0 
#define true 1 
#define xfree(x) free(x); x = NULL; 

typedef struct BiTnode
{
	int data;
	struct BiTnode *lchild, *rchild;
} BiTnode, *BiTree;


bool SearchBst(BiTree T, int key, BiTree *f, BiTree *p);
bool InsertBst(BiTree *T, int key);
void Inordervist(const BiTree T);
void BTreedestroy(BiTree tree);
bool DeleteBst(BiTree *T, int key);
bool Delete(BiTree *p);

bool SearchBst(BiTree T, int key, BiTree *f, BiTree *p)
{
	if (!T)
	{
		*p = *f;
		return false;
	}
	else if (key == T->data)
	{
		*p = T;
		return true;
	}
	else if (key < T->data)
	{
		*f = T;
		return SearchBst(T->lchild, key, f, p);
	}
	else
	{
		*f = T;
		return SearchBst(T->rchild, key, f, p);
	}
}

bool InsertBst(BiTree *T, int key)
{
	BiTree p = NULL, s = NULL, f = NULL;
	if (!SearchBst(*T, key, &f, &p)) //init NULL,KEY,NULL,&P=NULL
	{
		s = (BiTree)calloc(1, sizeof(BiTnode));
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
		{
			printf("Create Tree with key:%d\n", key);
			*T = s; //create Bst one node
		}
		else if (key < p->data)
		{
			printf("Insert Key To Tree(left):%d\n", key);
			p->lchild = s;
		}
		else
		{
			printf("Insert Key To Tree(right):%d\n", key);
			p->rchild = s;
		}
		return true;
	}
	else
	{
		return false;
	}
}
/*
inorder traversal method
*/

void Inordervist(const BiTree T)
{
	if (T)
	{
		Inordervist(T->lchild);
		printf("%d\n", T->data);
		Inordervist(T->rchild);
	}
}

/*
postorder traversal method to destroy tree
*/

void BTreedestroy(BiTree T)
{

	if (T)
	{
		BTreedestroy(T->lchild);
		BTreedestroy(T->rchild);
		printf("Delete node for Key%d\n", T->data);
		xfree(T);
	}
}


bool DeleteBst(BiTree *T, int key)//use **p *p is parent->child,here is very import 
{
	if (!*T)//
	{
		printf("no delete data %d find\n........\n", key);
		return true;
	}
	else
	{
		if (key == (*T)->data)
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return DeleteBst(&(*T)->lchild, key);//here use lchild pointer's address 
		}
		else
		{
			return DeleteBst(&(*T)->rchild, key);
		}
	}
}

bool Delete(BiTree *p)//use **p *p is parent->child,here is very import 
{
	BiTree q, s;

	printf("delete data :%d\n........\n", (*p)->data);
	if ((*p)->rchild == NULL)//right node is NULL
	{
		q = *p;
		*p = (*p)->lchild;
		xfree(q);
	}
	else if ((*p)->lchild == NULL)//leaf node is NULL
	{
		q = *p;
		*p = (*p)->rchild;
		xfree(q);
	}
	else 
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) 
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;

		

		if (q != *p) //if (*p)->lchild s have right node 
		{
			q->rchild = s->lchild;
		}
		else // if (*p)->lchild s have no right node
		{
			q->lchild = s->lchild;
		}
		xfree(s);//free find last right node,beacuse it's data used for find node
	}
	return 1;
}

int main(void)
{
	BiTree root = NULL;
	InsertBst(&root, 10);
	InsertBst(&root, 20);
	InsertBst(&root, 40);
	InsertBst(&root, 5);
	InsertBst(&root, 1);
	InsertBst(&root, -1);
	InsertBst(&root, -20);
	InsertBst(&root, 100);
	printf("≈≈–Ú∫Û\n");
	Inordervist(root);
	DeleteBst(&root, 25);
	DeleteBst(&root, 10);
	printf("≈≈–Ú∫Û\n");
	Inordervist(root);
	//printf("Use postorder traversal method destroy Bst:\n");
	//BTreedestroy(root);
	system("pause");
}