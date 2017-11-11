#include <windows.h> 
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

typedef int dataType;

typedef struct siglist
{
	dataType data;
	struct siglist *next;
}sList;

void add_data_to_list_tail(sList **head, dataType *data)
{
	sList *p = *head;
	sList *newList = NULL;

	newList = (sList *)malloc(sizeof(sList));
	newList->data = *data;
	newList->next = NULL;

	if ((head == NULL)
		|| (*head == NULL))
	{
		*head = newList;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newList;
	}
}

void delete_list_data(sList **head, dataType *data)
{
	sList *p = *head;
	sList *prevNode = NULL;
	if ((head != NULL)
		&& (*head != NULL))
	{
		if (p->data == *data)
		{
			*head = p->next;
			free(p);
		}
		else
		{
			prevNode = p;
			p = p->next;
			while ((p != NULL)
				&& (p->data != *data))
			{
				prevNode = p;
				p = p->next;
			}
			if (p != NULL)
			{
				prevNode->next = p->next;
				free(p);
			}
		}
	}
}

void add_list_to_tail(sList **head, sList *list)
{
	sList *p = *head;
	if (p == NULL)
	{
		*head = list;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = list;
	}
}

void sort_list(sList **head)
{
	if ((head == NULL)
		|| (*head == NULL)
		|| ((*head)->next == NULL))
	{
		return;
	}

	sList *tmpHead = NULL;
	sList *tmp = NULL;
	sList *smallNode = NULL;
	sList *prevNode = NULL;
	sList *nextNode = NULL;

	prevNode = *head;
	smallNode = *head;
	nextNode = *head;
	while (prevNode->next != NULL)
	{
		while (nextNode->next != NULL)
		{
			if (nextNode->next->data < smallNode->next->data)
			{
				smallNode = nextNode;
			}
			nextNode = nextNode->next;
		}

		if (smallNode != prevNode)
		{
			add_list_to_tail(&tmpHead, smallNode->next);
			/*delete the node from the list*/
			tmp = smallNode->next;
			smallNode->next = smallNode->next->next;
			tmp->next = NULL;
		}
		else if (prevNode->next->data < smallNode->data)
		{
			add_list_to_tail(&tmpHead, smallNode->next);
			/*delete the node from the list*/
			tmp = smallNode->next;
			smallNode->next = smallNode->next->next;
			tmp->next = NULL;
		}
		else
		{
			smallNode = *head;
			*head = (*head)->next;
			add_list_to_tail(&tmpHead, smallNode);
			/*delete the node from the list*/
			tmp = smallNode->next;
			smallNode->next = smallNode->next->next;
			tmp->next = NULL;
		}
		prevNode = *head;
		smallNode = *head;
		nextNode = *head;
	}
	add_list_to_tail(&tmpHead, prevNode);
	*head = tmpHead;
}

void main(void)
{
	sList *list = NULL;
	dataType data;
	//dataType data[] = { 56,35,88,44,34,65,1,8 };

	int index = 0;
	/*for (index = 0;index < sizeof(data) / sizeof(dataType);index++)
	{
		add_data_to_list_tail(&list, &(data[index]));
	}*/
	cin >> data;
	while ( data)
	{
		cin >> data;
		add_data_to_list_tail(&list, &data);
		
	}

	sort_list(&list);

	sList *p = list;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	system("PAUSE");
}