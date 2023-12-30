/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:06:56 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 16:41:11 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//nao esquecer de apagar stdio.h
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long				content;
	long				index;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

void	ft_find_errors(char *str);
int		ft_print_error(void);
void	ft_add_stack(t_stack **lst, long num);
void	process_and_add_to_stack(t_stack **stack_a, char *input);
void	concatenate_and_process_args(t_stack **stack_a, int argc, char **argv);
void	ft_clear_stack(t_stack **stack_a);
void	handle_errors_and_free(t_stack **stack_a, char **splited_input, char *input);

#endif