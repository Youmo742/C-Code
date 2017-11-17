# 链表的学习笔记
## 顺序表
  ###  顺序表是计算机中以数组形式存储的线性表，其要求是**逻辑连续**的同时,**物理空间**也连续。
```C++
#define MaxSize 64
typedef int ElemType

typedef struct Node
{
  ElemType[MaxSize];
  Elemtype len;
}
```
**这便定义一个是顺序表**
#### 1. 顺序表的优点 
a. 查找方便，随机存取数据  
b. 空间利用率高，存储效率高 
#### 2. 顺序表的缺点
a. 其容量的大小提前确定，容易造成空间的浪费或缺乏.
b. 空间不易扩充，插入或删除麻烦，插入或删除需要移动大量元素，时间复杂度为  O（n）  
## 链表
  ### 链表是一种仅靠逻辑关系连接起来的表，不需要存储空间连续，靠**指针**将整个表串起来。  
  ```C++
  typedef int Elemtype
  struct Node
  {
    Elemtype data;
    Node *next;
  }
  Node *head,*first,*last;
  ``` 
  **上述即为C++链表节点的定义**  
  1. 链表节点包含了两部分内容，一是**数据域**即表中要存储的数据，二是**指针域**，此指针即为下一个节点的地址。 
  
  ![](http://images.cnblogs.com/cnblogs_com/sunysen/462251/o_201303211523350001.png)    
  
  如上图所示，```head->next```即为第二个方块区域，所以```head->next->data```即为第二方块的数据域。总结起来就是，前一个节点里面存着下一个节点的信息。  
  1 创建链表如下  
  ```C++
  int num;
  first->next=NULL;
  last=first=head;
  while(Num)
  {
  Node *newNode=new Node;
  newNode->data=Nnum;
  head->next->newNode;
  newNode->next=NULL;
  head=newNode;
  }
  last=newNode->next;
```
  2 通常链表会带一个**头节点**和一个**尾节点**，其数据域内没有内容，其目的是方便索引整个链表，而且插入和删除的时候，就算在表尾或表头插入，和其他地方插入也没有什么区别。***插入的语句一般如下***   
  ```C++
  Node *newNode=new Node;
  newNode->data=Nnum;
  current->next=Newnode;
  newNode->next=current->next->next;
```
  3 删除链表的节点如下   
 ```C++
    q=current->next;
    current->next=current->next->next;    
 ```
**将一个节点赋值给另外一个节点，意味着将当前节点，作为另外一个节点**    
