#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
typedef char ElemType;
typedef struct BiNode
{
	ElemType data;
	BiNode *lchild;
	BiNode *rchild;
}*Bitree;
void CreatTree(Bitree &T);//�����������д���������
BiNode * Find(Bitree T, ElemType e);//����ĳ��Ԫ��
void PreOrderTra(Bitree T);//�������
void InOrderTra(Bitree T);//�������
void PostOrderTra(Bitree T);//�������
void travel(Bitree T);//�����
