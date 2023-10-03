/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:28:08 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/07/30 12:28:21 by tjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line(int l, char b, char m, char e)
{
	int	c;

	c = 0;
	while (c < l)
	{
		if (c == 0)
			ft_putchar(b);
		else if (c == l - 1)
			ft_putchar(e);
		else
			ft_putchar(m);
		c++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (y > 0 && x > 0)
	{
		line(x, 'o', '-', 'o');
		y--;
		while (y > 1)
		{
			line(x, '|', ' ', '|');
			y--;
		}
		if (y == 1)
			line(x, 'o', '-', 'o');
	}
}
