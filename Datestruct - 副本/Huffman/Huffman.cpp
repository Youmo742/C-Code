
/*
#include <iostream>
#include <cstdio>
#include<cstdlib>

using namespace std;
const int MAXSIZE = 10;
int tatolIndex;//��Ҫ�������ݵĸ���
int len = tatolIndex;//��ǰ����
//char dataRead[MAXSIZE+1];
//float weightRead[MAXSIZE+1];
//int len = sizeof(weightRead) /sizeof( float);
float lc,rc;
typedef struct //����һ���ṹ�壬��ֹ�����ʱ�����ݺ�Ȩ�ز���Ӧ
{
	char dataRead;
	float weighRead;
}*DaWeData;
DaWeData DWData[MAXSIZE + 1];
//���ڵ�Ķ���
struct TreeNode
{
	char data;//�ڵ�����
	float weight;//Ȩ��
	TreeNode * lchild;
	TreeNode * rchild;
	TreeNode * parent;
};
typedef TreeNode *Huffman;
TreeNode *Node[2*MAXSIZE+1];
 
void ReadData(int n)//n��ʾ���ݸ��� 
{
	for (int i = 0;i < n;i++)
	{
		cin >> DWData[i]->dataRead >> DWData[i]->weighRead;
	}
}
//����Ȩ�ع����������
void Create()
{
	for (int i = 0;i < 2*tatolIndex-1;i++)
	{
		 Node[i] = (TreeNode *)malloc(sizeof(TreeNode));
		 Node[i]->data = '#';
		 Node[i]->lchild = NULL;
		 Node[i]->rchild = NULL;
		 Node[i]->parent = NULL;
		 Node[i]->weight = 0;
	}
	for (int i = 0;i < 2 * tatolIndex - 1;i+=3)
	{
		Node[i]->weight = lc;
		Node[i + 1]->weight = rc;
		Node[i + 2]->weight = lc + rc;
	}
}
TreeNode * CreatHuffman()
{
	TreeNode *LNode = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *RNode = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *NewNode = (TreeNode *)malloc(sizeof(TreeNode));
	selectdata();
	RNode->weight = rc;
	LNode->data = DWData[0]->dataRead;
	RNode->data = DWData[1]->dataRead;
	NewNode->data = '#';
	LNode->weight = lc;
	NewNode->weight = rc + lc;
	NewNode->lchild = LNode;
	NewNode->rchild = RNode;
	LNode->parent = NewNode;
	RNode->parent = NewNode;
	bubbleSort();
}
//��Ȩ�����򣬷���ѡ��
void bubbleSort()
{
	for (int i = 0;i < len;i++)
		for (int j = i + 1;j < len;j++)
		{
			if (DWData[i]->weighRead > DWData[j]->weighRead)
			{
				DaWeData temp;
				temp = DWData[i];
				DWData[i] = DWData[j];
				DWData[j]= temp;
			}
		}
}
//�����γɵĽڵ���뵽Ȩ��������
void Insdata()
{
	float value = DWData[0]->weighRead + DWData[1]->weighRead;
	DWData[len]->weighRead = value;
	for (int i = 2;i < len;i++)
	{
		DWData[i-2]->weighRead = DWData[i]->weighRead;
		DWData[i - 2]->dataRead = DWData[i]->dataRead;
	}
	len = len - 1;
	bubbleSort();
}
void selectdata()//ѡ�����Ľڵ�
{
	lc = DWData[0]->weighRead;
	rc = DWData[1]->weighRead;
}
int main()
{
	return 0;
}
*/