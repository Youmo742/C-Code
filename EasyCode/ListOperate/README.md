# 链表的学习笔记
## 顺序表
  1 顺序表是计算机中以数组形式存储的线性表，其要求是**逻辑连续**的同时,**物理空间**也连续。
```C++
#define MaxSize 64
typedef int ElemType

typedef struct Node
{
  ElemType[MaxSize];
  Elemtype len;
}
```
这便定义一个是顺序表，其容量的大小提前确定，容易造成空间的浪费或缺乏
