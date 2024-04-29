
#include "list.h"

/* typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

int ascending(int a, int b)
{
	return (a <= b);
}

 */
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	int temp;

	while(lst->next)
	{
		if (!cmp(lst->data, lst->next->data))
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}

	return (head);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	t_list *list_a = malloc(sizeof(t_list));
	t_list *list_b = malloc(sizeof(t_list));
	t_list *list_c = malloc(sizeof(t_list));
	t_list *teste;

	list_a->data=108;
	list_a->next=list_b;

	list_b->data = 73;
	list_b->next = list_c;

	list_c->data = 45;
	list_c->next = NULL;

	sort_list(list_a, ascending);
	teste = list_a;

	while (teste)
	{
		printf("%d - ", teste->data);
		teste = teste->next;
	}
	
	

	return (0);
} */