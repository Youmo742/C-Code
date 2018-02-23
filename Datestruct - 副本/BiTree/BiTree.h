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
void CreatTree(Bitree &T);//根据先序序列创建二叉树
BiNode * Find(Bitree T, ElemType e);//查找某个元素
void PreOrderTra(Bitree T);//先序遍历
void InOrderTra(Bitree T);//中序遍历
void PostOrderTra(Bitree T);//后序遍历
void travel(Bitree T);//输出树
