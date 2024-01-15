/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:06:56 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 17:24:28 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//nao esquecer de apagar stdio.h
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long				content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

// error handling and creating stack a
void	ft_find_errors(char *str);
void	check_duplicates(char **splited, char *input);
int		ft_print_error(void);
void	ft_add_stack(t_stack **lst, long num);
void	process_and_add_to_stack(t_stack **stack_a, char *input);
void	concatenate_and_process_args(t_stack **stack_a, int argc, char **argv);
void	ft_clear_stack(t_stack **stack_a);
void	free_and_clear(t_stack **stack_a, char **splited_input,
			char *input, int i);

//commands 
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node,	char stack_name);
//sorting
int		check_if_sorted(t_stack *stack);
void	small_sort(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

//helper functions
int		count_nodes(t_stack *stack);
void	print_nodes(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
t_stack	*find_bigger(t_stack *a);
t_stack	*find_smaller(t_stack *a);
void	ft_print_stacks(t_stack *a, t_stack *b);
void	ft_free_stacks(t_stack *a, t_stack *b);
void	set_index_median(t_stack *node);
t_stack	*get_cheapest(t_stack *node);

#endif
