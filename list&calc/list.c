#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int elem;
	struct list *next;
} node;

void list_create(node *list)
{
	list->next = NULL;
}

void list_new_elem(node *list, int num)
{
	if (list->next == NULL)
	{
		(list->next) = (node*)malloc(sizeof(node));
		list->next->elem = num;
		list->next->next = NULL;
	}
	else
	{
		list_new_elem(list->next, num);
	}

}

void print_list(node *list)
{
    node *pointer = list-> next;
	if (list == NULL)
	{
		printf("List is empty");
		return;
	}

	while (pointer != NULL)
	{
		printf("%d ", pointer->elem);
		pointer = pointer->next;
	}
	
}

void list_elem_del(node *list, int num)
{
	node *pointer;
	if (list->next == NULL)
	{
		printf("list is empty");
		return;
	}
	if (list->next->elem == num)
	{
		pointer = list->next->next;
		free(list->next);
		list->next = pointer;
	}
	else
	{
		list_elem_del(list->next, num);
	}
}

int number_of_elem(node *list)
{
    node *pointer = list->next;
	int NumOfElem = 0;
	while (pointer != NULL)
	{
		NumOfElem++;
		pointer = pointer->next;
	}
	return NumOfElem;
	
}

int main()
{
	node list;
	list_create(&list);
	
	list_new_elem(&list, 1);
	list_new_elem(&list, 2);
	list_new_elem(&list, 3);
	list_new_elem(&list, 4);
	list_new_elem(&list, 5);
	
	printf("list: ");
	print_list(&list);
	
	printf("\n");
	printf("Number of elements: ");
	printf("%d\n", number_of_elem(&list));
	
	printf("list: ");
	print_list(&list);
	
	system("pause");
}