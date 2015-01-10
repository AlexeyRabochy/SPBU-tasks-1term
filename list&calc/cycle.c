#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int elem;
	struct list *next;
} node;

void list_new_elem(node **list, int num)
{
	if (*list == NULL) 
	{
		*list = (node*)malloc(sizeof(node));
		(*list)->elem = num;
		(*list)->next = NULL;
	}
	else
	{
		list_new_elem(&(*list)->next, num);
	}

}

int check(node *list)
{
	node *pointer1 = list;
	node *pointer2 = list;

	while (pointer1 && pointer2 && pointer2->next)
	{
		pointer1 = pointer1->next;
		pointer2 = pointer2->next->next;
		if (pointer1 == pointer2)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i = 0;
	int mas[100] = { 0 };
	node* head = NULL;
   
	printf("enter 4 elements");

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &mas[i]);
		list_new_elem(&head, mas[i]);
	}

    //head->next->next->next->next = head;

	if (check(head) == 1)
	{
		printf("list is cyclicle\n");
	}
	else
	{
		printf("list is not cyclicle\n");
	}
	system("pause");
	return 0;
	

}