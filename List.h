#pragma once
#include <iostream>
using namespace std;
typedef struct NODE
{
	int data;
	struct NODE* next;
	struct NODE* prev;
	NODE(int _data = 0, struct NODE* _next = NULL, struct NODE* _prev = NULL):
		data(_data),
		next(_next),
		prev(_prev)
	{};
	~NODE()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}
}Node;
typedef struct LIST
{
	Node* head;
	Node* tail;
	int size;
	LIST(Node* _head = NULL, Node* _tail = NULL, int _size = 0) :
		head(_head),
		tail(_tail),
		size(_size)
	{};
	Node* FindNode(int index);
	int FindIndex(int data);
	void InsertBefore(int index, int Data);
	void InsertAfter(int index, int Data);
	void PrintNode(int index);
	void DeleteNode(int index);
	~LIST()
	{
		for (int i = 1; i <= size; i++)
		{
			DeleteNode(1);
		}
		size = 0;
	}
}List;
List* CreateList();
Node* CreateNode();
