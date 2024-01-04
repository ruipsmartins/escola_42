/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:58:27 by rui               #+#    #+#             */
/*   Updated: 2024/01/04 15:42:33 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    long content;
    int index;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

static void    swap(t_stack **node)
{

    *node = (*node)->next;
    (*node)->prev->prev = *node;
    (*node)->prev->next = (*node)->next;
    if ((*node)->next)
        (*node)->next->prev = (*node)->prev;
    (*node)->next = (*node)->prev;
    (*node)->prev = NULL;

    printf("1º node %li\n", (*node)->content);
}

void    sa(t_stack **a)
{
    if (!(*a) || !(*a)->next)
        return ;
    swap(a);
    write(1, "sa\n", 3);
}

int main()
{
    // Criação dos nós
    t_stack *node1 = malloc(sizeof(t_stack));
    t_stack *node2 = malloc(sizeof(t_stack));
    t_stack *node3 = malloc(sizeof(t_stack));
    t_stack *stack_a;
    
    stack_a = node1;
	

    // Atribuição dos valores
    node1->content = 10;
    node1->index = 1;
    node1->prev = NULL;
    node1->next = node2;

    node2->content = 15;
    node2->index = 2;
    node2->prev = node1;
    node2->next = node3;

    node3->content = 20;
    node3->index = 3;
    node3->prev = node2;
    node3->next = NULL;

    // Atribuição do ponteiro head
    sa(&stack_a);
    // Impressão dos nós
    t_stack *current = stack_a;
    while (current != NULL)
    {
        printf("Node %d:\n", current->index);
        printf("Content: %li\n", current->content);
        if (current->prev != NULL)
            printf("Prev: Node %d\n", current->prev->index);
        else
            printf("Prev: NULL\n");
        if (current->next != NULL)
            printf("Next: Node %d\n", current->next->index);
        else
            printf("Next: NULL\n");

        printf("----------------------------\n");

        current = current->next;
    }

    // Libertação da memória alocada
    free(node1);
    free(node2);
    free(node3);

    return 0;
}