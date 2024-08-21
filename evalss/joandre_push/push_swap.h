/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 18:18:26 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				numb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
t_stack			*create_node(int n);
t_stack			*last_node(t_stack *a);
unsigned int	stack_size(t_stack *a);
void			free_stack(t_stack *a);
void			create_stack(t_stack **a, char **n, unsigned int i);
bool			int_check(long long n);
bool			int_repeat(t_stack *a);
long long		ft_atol(char *n);
int				max(t_stack *a);
int				min(t_stack *a);
bool			argv_check(int argc, char **argv);
unsigned int	target_a(t_stack *a, int n);
unsigned int	target_b(t_stack *b, int n);
unsigned int	index_numb(t_stack *a, int n);
int				numb(t_stack *a, unsigned int i);
unsigned int	calc_a2b_reverse(t_stack *a, t_stack *b, int n);
unsigned int	calc_a2b_rotate(t_stack *a, t_stack *b, int n);
unsigned int	calc_a2b_rrotate(t_stack *a, t_stack *b, int n);
unsigned int	calc_a2b_rreverse(t_stack *a, t_stack *b, int n);
int				cheap_a(t_stack *a, t_stack *b);
unsigned int	calc_b2a_reverse(t_stack *a, t_stack *b, int n);
unsigned int	calc_b2a_rotate(t_stack *a, t_stack *b, int n);
unsigned int	calc_b2a_rrotate(t_stack *a, t_stack *b, int n);
unsigned int	calc_b2a_rreverse(t_stack *a, t_stack *b, int n);
int				cheap_b(t_stack *a, t_stack *b);
void			sort_a(t_stack **a, t_stack **b);
void			sort_b(t_stack **a, t_stack **b);
bool			sort_check(t_stack *a);
void			sort_algo(t_stack **a);
void			debug_stack(t_stack *a, t_stack *b);
#endif
