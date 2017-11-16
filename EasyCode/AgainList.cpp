#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *link;
};

Node *Creat()//创建链表，输入0结束，尾插法
{
	Node *first,*newNode,*last;
	int num;
	cout<<"INsert is ending with 0"<<endl;
	cin>>num;
	first=NULL;
	while(num!=0)
	{
		newNode=new Node;
		assert(newNode!=NULL);
		newNode->data=num;
		newNode->link=NULL;
		if(first==NULL)
		{
			first=newNode;
			last=newNode;
		}
		else
		{
			last->link=newNode;
			last=newNode;
		}
		cin>>num;
	}
	return first;
}
void Delete(Node * &L,int n)//删除一个指定位置的元素
{
	Node *p,*q;
	int i=0;
	p=L;
	for(int i=1;i<n;i++)
	{
		if(p==NULL)
		{
			cout<<"Not Find"<<endl;
			exit(0);
		}
		p=p->link;	
	}
	q=p->link;
	p->link=p->link->link;
	delete q;
}
void ShowList(Node *L)//遍历链表，输出元素
{
	Node *p=new Node;
	p=L;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->link;
	}
}
int main()
{
	Node *L=new Node;
	L=Creat();
	cout<<endl;
	ShowList(L);
	cout<<endl;
	Delete(L,2);
	ShowList(L);
	return 0;
}
