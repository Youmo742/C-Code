#include <iostream>

using namespace std;
struct node
{
	int data;
	node *next;
};
node *creat(int n)
{
	node *p = NULL, *head;
	node *s;
	head = (node *) new node;
	p = head;
	int i = 1;
	if (0 != n)
	{
		while (i <= n)
		{
			s = (node *) new node;
			s->data = i++;
			p->next = s;
			p = s;
		}
		p->next = head->next;
	}
	delete head;
	return s->next;
}
int main()
{
	int total = 7;
	int num = 3;
	int i = 0;
	num%= total;
	node *p = creat(total);
	node *temp;
	while (p != p->next)
	{
		for (i = 1;i < num - 1;i++)
		{
			p = p->next;
		}
		cout << p->next->data << "-->";
		temp = p->next;
		p->next = temp->next;
		delete temp;
		p = p->next;
	}
	cout << p->data;
	cin.get();
	return 0;
}

