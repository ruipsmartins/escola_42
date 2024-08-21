/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:02:35 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/04 02:23:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static bool	input_check(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**numb;

	if (argv_check(argc, argv))
	{
		if (argc > 2)
			create_stack(a, argv, 1);
		else if (argc == 2)
		{
			numb = ft_split(argv[1], ' ');
			create_stack(a, numb, 0);
			i = 0;
			while (numb[i])
				free(numb[i++]);
			free(numb);
		}
		if (int_repeat(*a) || stack_size(*a) < 3)
		{
			free_stack(*a);
			return (false);
		}
		return (true);
	}
	return (false);
}

static bool	exec_inst(t_stack **a, t_stack **b, char *i)
{
	if (i[0] == 's' && i[1] == 'a' && i[2] == '\n')
		csa(a);
	else if (i[0] == 's' && i[1] == 'b' && i[2] == '\n')
		csb(b);
	else if (i[0] == 's' && i[1] == 's' && i[2] == '\n')
		css(a, b);
	else if (i[0] == 'r' && i[1] == 'a' && i[2] == '\n')
		cra(a);
	else if (i[0] == 'r' && i[1] == 'b' && i[2] == '\n')
		crb(b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == '\n')
		crr(a, b);
	else if (i[0] == 'p' && i[1] == 'a' && i[2] == '\n')
		cpa(b, a);
	else if (i[0] == 'p' && i[1] == 'b' && i[2] == '\n')
		cpb(a, b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'a' && i[3] == '\n')
		crra(a);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'b' && i[3] == '\n')
		crrb(b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'r' && i[3] == '\n')
		crrr(a, b);
	else
		return (false);
	return (true);
}

static char	*parse_inst(char *inst)
{
	char	c[1];
	int		i;
	int		r;

	ft_bzero((char *)inst, 5);
	ft_bzero((char *)c, 1);
	i = 0;
	r = read(0, c, 1);
	while (r)
	{
		inst[i] = c[0];
		if (inst[i] == '\n' || i == '4')
			break ;
		++i;
		r = read(0, c, 1);
	}
	if (r == 0)
		return (NULL);
	return (inst);
}

static bool	get_inst(t_stack **a)
{
	t_stack	**b;
	char	inst[5];
	char	*cmd;

	b = malloc(sizeof(t_stack));
	if (b == NULL)
		return (false);
	*b = NULL;
	cmd = parse_inst(inst);
	while (cmd)
	{
		if (!exec_inst(a, b, cmd))
			break ;
		cmd = parse_inst(inst);
	}
	if (stack_size(*b))
	{
		free_stack(*b);
		free(b);
		write(2, "Error\n", 6);
		return (false);
	}
	free(b);
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	**a;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		return (2);
	if (input_check(argc, argv, a))
	{
		if (get_inst(a))
		{
			if (sort_check(*a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		free_stack(*a);
	}
	free(a);
	return (0);
}
