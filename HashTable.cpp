#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List* first_list = CreateList();
	int a = 136, b = 56, c = 38;
	first_list->InsertBefore(1, a);
	first_list->InsertBefore(1, b);
	first_list->InsertAfter(1, c);
	first_list->PrintNode(1);
	first_list->PrintNode(2);
	first_list->PrintNode(3);
	printf("%d\n", first_list->size);
	printf("\n");
	first_list->DeleteNode(2);
	first_list->PrintNode(2);
	printf("%d\n", first_list->size);
	delete first_list;
	return 0;
}
