/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 18:47:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	csa(t_stack **a);
void	csb(t_stack **b);
void	css(t_stack **a, t_stack **b);
void	cra(t_stack **a);
void	crb(t_stack **b);
void	crr(t_stack **a, t_stack **b);
void	crra(t_stack **a);
void	crrb(t_stack **b);
void	crrr(t_stack **a, t_stack **b);
void	cpa(t_stack **b, t_stack **a);
void	cpb(t_stack **a, t_stack **b);
#endif
