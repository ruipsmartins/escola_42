/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:06:56 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:04 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//nao esquecer de apagar stdio.h
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
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif