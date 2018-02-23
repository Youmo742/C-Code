#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//����˼·���ö���ʵ�ֱ���
struct TreeNode
{
	char data;//�ڵ�����
	float weight;//Ȩ��
	TreeNode * lchild;
	TreeNode * rchild;
	TreeNode * parent;
	TreeNode *next;
	char Code[10] = {0};
};
typedef TreeNode *HuffmanTree;
typedef TreeNode * Queue;
//¼������
TreeNode * head;//����ͷ�ڵ�
TreeNode * front;//��ͷ
TreeNode * real;//��β
void InitQueue(Queue &Q)
{
	Q = new TreeNode;
	Q->next = NULL;
	Q->weight = 0;
	head = Q;
	front = Q;
	real = Q;
}
void InsData(Queue &Q,int n)//�����ʱ��ֱ�������
{
	for (int i = 0;i < n;i++)
	{
		Queue p = Q;
		int index = 0;
		TreeNode * NewNode = new TreeNode;
		cin >> NewNode->data;
		cin >> NewNode->weight;
		if (real == front)
		{
			head->next = NewNode;
			front = head;
			real = NewNode;
			real->next = NULL;
		}
		else
		{
			//��취�ҵ�p��ǰһ���ڵ�
			while (NewNode->weight > p->weight)
			{
				p = p->next;
				index++;
				if (p == real)
					break;
			}
			if (NewNode->weight > real->weight)
			{
				p->next = NewNode;
				real = NewNode;
				NewNode->next = NULL;
			}
			else
			{
				Queue q = Q;
				for (int i = 1;i < index;i++)
					q = q->next;
				q->next = NewNode;
				NewNode->next = p;
			}
		}
	}
}
TreeNode * SelectNode(Queue &Q)//ѡ��ڵ�,��������
{
	TreeNode *q = Q->next;
	Q->next = Q->next->next;
	if (Q->next ==NULL)
		front = real;
	return q;
}
TreeNode *WNewNode(TreeNode *q, TreeNode *p)
{
	TreeNode *NewNode = new TreeNode;
	NewNode->weight = q->weight + p->weight;
	NewNode->data = '#';
	return NewNode;
}
void PushNode(Queue &Q, TreeNode *N)//�������ɵĽڵ�������
{
	Queue p = Q;
	int index = 0;
	if (real == front)
	{
		head->next = N;
		N->next = NULL;
	}
	else
	{
		//��취�ҵ�p��ǰһ���ڵ�
		while (N->weight > p->weight)
		{
			p = p->next;
			index++;
			if (p == real)
				break;
		}
		if (N->weight > real->weight)
		{
			p->next = N;
			real = N;
			N->next = NULL;
		}
		else
		{
			Queue q = Q;
			for (int i = 1;i < index;i++)
				q = q->next;
			q->next = N;
			N->next = p;
		}
	}
}
TreeNode * CreateHuffman(Queue &Q)
{
	while(Q->next->next != NULL)
	{
		TreeNode *q = SelectNode(Q);
		TreeNode *p = SelectNode(Q);
		TreeNode *Parent = WNewNode(q, p);
		if (q->data != '#' ) 
		{
			q->lchild = NULL;
			q->rchild = NULL;
			
		}
		if (p->data != '#')
		{
			p->lchild = NULL;
			p->rchild = NULL;
		}
		q->weight = '0';
		p->weight = '1';
		Parent->lchild = q;
		Parent->rchild = p;
		q->parent = Parent;
		p->parent = Parent;
		PushNode(Q, Parent);
	}
	TreeNode *T = SelectNode(Q);
	T->parent = NULL;
	T->weight = '0';
	return T;
}
void TravelTree(HuffmanTree &T)
{
	if (T->lchild==NULL || T->rchild==NULL)
	{
			int index = 0;
			TreeNode *q = T;
			TreeNode *p = T;
			//cout << q->data<<" ";
			HuffmanTree M =new TreeNode;
			while (q->parent != NULL)
			{
				M->Code[index] = q->weight;
				index++;
				q = q->parent;
			}
			M->Code[index++] = '0';
			for (int i = index - 1,t=0;i >= 0;i--,t++)
			{
				//cout << M->Code[i];�����õĴ���
				p->Code[t] = M->Code[i];
			}
			
			cout << endl;
			return;
	}
	TravelTree(T->lchild);
	TravelTree(T->rchild);
}
void Travel(HuffmanTree T)
{
	if (T == NULL)
		return;
	if (T->data != '#')
	{
		cout << T->data<<" "<<T->Code << endl;
	}
	Travel(T->lchild);
	Travel(T->rchild);
}
int main()
{
	Queue Q;
	InitQueue(Q);
	InsData(Q, 5);
	HuffmanTree T;
	T=CreateHuffman(Q);
	//PrintCoding(T);
	TravelTree(T);
	Travel(T);
	//TreeNode *q=SelectNode(Q);
	//TreeNode *p = SelectNode(Q);
	system("pause");
	return 0;
}