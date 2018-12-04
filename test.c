#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct NODE
{
	int data;
	struct NODE* next;
	struct NODE* prev;
}Node;
typedef struct LIST
{
	Node* head;
	Node* tail;
	int size;
}List;
List* CreateList();
Node* CreateNode();
Node* FindNode(List* list, int index);
void InsertBefore(List* list, int index, int Data);
void InsertAfter(List* list, int index, int Data);
void PrintNode(List* list, int index);
void FreeNode(Node* node);
void DeleteNode(List* list, int index);
void DeleteList(List* list);
int main()
{
	List* first_list = CreateList();
	int a = 136, b = 56, c = 38;
	InsertBefore(first_list, 1, a);
	InsertBefore(first_list, 1, b);
	InsertAfter(first_list, 1, c);
	PrintNode(first_list, 1);
	PrintNode(first_list, 2);
	PrintNode(first_list, 3);
	printf("%d\n", first_list->size);
	printf("\n");
	DeleteNode(first_list, 2);
	PrintNode(first_list, 2);
	printf("%d\n", first_list->size);
	DeleteList(first_list);
	printf("%d", first_list->size);
	return 0;
}
List* CreateList()
{
	List* new_ptr = (List*)calloc(1, sizeof(List));
	if (new_ptr == NULL)
	{
		printf("Cannot create a list\n");
		exit(1);
	}
	else
	{
		new_ptr->head = NULL;
		new_ptr->tail = NULL;
		new_ptr->size = 0;
		return new_ptr;
	}
	return new_ptr;
}
Node* CreateNode()
{
	Node* new_ptr = (Node*)calloc(1, sizeof(Node));
	if (new_ptr == NULL)
	{
		printf("Cannot create a node\n");
		exit(1);
	}
	else
	{
		new_ptr->data = 0;
		new_ptr->next = NULL;
		new_ptr->prev = NULL;
		return new_ptr;
	}
}
Node* FindNode(List* list, int index)
{
	Node* current = NULL;
	if (list == NULL)
	{
		printf("List cannot be found\n");
		exit(1);
	}
	else if (index > list->size)
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
		if (index < (int)(list->size / 2))
		{
			current = list->head;
			for (int i = 2; i <= index; i++)
			{
				current = current->next;
			}
		}
		else
		{
			current = list->tail;
			for (int i = list->size - 1; i >= index; i--)
			{
				current = current->prev;
			}
		}
	}
	return current;
}
void InsertBefore(List* list, int index, int Data)
{
	Node* node = CreateNode();
	node->data = Data;
	if (list == NULL)
	{
		printf("List cannot be found\n");
	}
	else if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->size = 1;
	}
	else if (index == 1)
	{
		(list->head)->prev = node;
		node->next = list->head;
		list->head = node;
		list->size++;
	}
	else
	{
		Node* current = FindNode(list, index);
		node->next = current;
		node->prev = current->prev;
		(node->prev)->next = node;
		(node->next)->prev = node;
		list->size++;
	}
	
}
void InsertAfter(List* list, int index, int Data)
{
	Node* node = CreateNode();
	node->data = Data;
	if (list == NULL)
	{
		printf("List cannot be found\n");
	}
	else if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->size = 1;
	}
	else if (index == list->size)
	{
		(list->tail)->next = node;
		node->prev = list->tail;
		list->tail = node;
		list->size++;
	}
	else
	{
		Node* current = FindNode(list, index);
		node->prev = current;
		node->next = current->next;
		(node->prev)->next = node;
		(node->next)->prev = node;
		list->size++;
	}
}
void PrintNode(List* list, int index)
{
	if (list == NULL)
	{
		printf("List cannot be found\n");
	}
	else
	{
		Node* current = FindNode(list, index);
		printf("%d\n", current->data);
	}
}
void FreeNode(Node* node)
{
	node->data = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}
void DeleteNode(List* list, int index)
{
	Node* node;
	if (list == NULL)
	{
		printf("List cannot be found\n");
	}
	else if ((list->size == 1) && (index == 1))
	{
		(list->head)->data = 0;
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	else if (index == list->size)
	{
		((list->tail)->prev)->next = NULL;
		node = list->tail;
		list->tail = (list->tail)->prev;
		FreeNode(node);
		list->size--;
	}
	else if (index == 1)
	{
		((list->head)->next)->prev = NULL;
		node = list->head;
		list->head = (list->head)->next;
		FreeNode(node);
		list->size--;
	}
	else
	{
		node = FindNode(list, index);
		(node->next)->prev = node->prev;
		(node->prev)->next = node->next;
		FreeNode(node);
		list->size--;
	}
}
void DeleteList(List* list)
{
	for (int i = 1; i <= list->size; i++)
	{
		DeleteNode(list, 1);
	}
	free(list);
}