#include <iostream>
#include "List.h"
using namespace std;
List* CreateList()
{
	try
	{
		List* new_ptr = new List;
		return new_ptr;
	}
	catch (std::bad_alloc)
	{
		printf("Cannot create a list\n");
		exit(1);
	}
}
Node* CreateNode()
{
	try
	{
		Node* new_ptr = new Node;
		return new_ptr;
	}
	catch (std::bad_alloc)
	{
		printf("Cannot create a node\n");
		exit(1);
	}

}
Node* LIST::FindNode(int index)
{
	Node* current = NULL;
	if (index > size)
	{
		printf("Node with given index not found\n");
		exit(1);
	}
	else if (index < 1)
	{
		printf("Invalid index format\n");
		exit(1);
	}
	else
	{
		if (index < (int)(size / 2))
		{
			current = head;
			for (int i = 2; i <= index; i++)
			{
				current = current->next;
			}
		}
		else
		{
			current = tail;
			for (int i = size - 1; i >= index; i--)
			{
				current = current->prev;
			}
		}
	}
	return current;
}
int LIST::FindIndex(int data)
{
	Node* current = NULL;
	if (size == 0)
	{
		return -1;
	}
	else
		current = head;
		if (current->data == data)
		{
			return 1;
		}
		for (int i = 2; i <= size; i++)
		{
			current = current->next;
			if (current->data == data)
			{
				return i;
			}
		}
		return -1;
}
void LIST::InsertBefore(int index, int Data)
{
	Node* node = CreateNode();
	node->data = Data;
	if (head == NULL)
	{
		head = node;
		tail = node;
		size = 1;
	}
	else if (index == 1)
	{
		(head)->prev = node;
		node->next = head;
		head = node;
		size++;
	}
	else
	{
		Node* current = FindNode(index);
		node->next = current;
		node->prev = current->prev;
		(node->prev)->next = node;
		(node->next)->prev = node;
		size++;
	}

}
void LIST::InsertAfter(int index, int Data)
{
	Node* node = CreateNode();
	node->data = Data;
	if (head == NULL)
	{
		head = node;
		tail = node;
		size = 1;
	}
	else if (index == size)
	{
		(tail)->next = node;
		node->prev = tail;
		tail = node;
		size++;
	}
	else
	{
		Node* current = FindNode(index);
		node->prev = current;
		node->next = current->next;
		(node->prev)->next = node;
		(node->next)->prev = node;
		size++;
	}
}
void LIST::PrintNode(int index)
{
	Node* current = FindNode(index);
	printf("%d\n", current->data);
}

void LIST::DeleteNode(int index)
{
	Node* node;
	if ((size == 1) && (index == 1))
	{
		(head)->data = 0;
		delete[] head;
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else if (index == size)
	{
		((tail)->prev)->next = NULL;
		node = tail;
		tail = (tail)->prev;
		delete node;
		size--;
	}
	else if (index == 1)
	{
		((head)->next)->prev = NULL;
		node = head;
		head = (head)->next;
		delete node;
		size--;
	}
	else
	{
		node = FindNode(index);
		(node->next)->prev = node->prev;
		(node->prev)->next = node->next;
		delete node;
		size--;
	}
}