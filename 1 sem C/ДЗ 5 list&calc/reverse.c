#define _CRT_SECURE_NO_WARNING
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
	node *pointer = list;
	if (list == NULL)
	{
		printf("List is empty");
		return;
	}

	while (pointer->next)
	{
		printf("%d ", pointer->elem);
		pointer = pointer->next;
	}

}

void reverse(node *list)
{
	node *ptr = NULL, *tmp;
	while (list)
	{
		tmp = list->next;
		list->next = ptr;
		ptr = list;
		list = tmp;
	}
	print_list(ptr);
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

	//print_list(&list);

	reverse(&list);

	system("pause");
}