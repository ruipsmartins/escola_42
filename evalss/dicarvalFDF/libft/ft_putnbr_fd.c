/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:06:27 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:17 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln == 0)
		write(fd, "0", 1);
	else if (ln > 0 && ln < 10)
		ft_putchar_fd((ln + 48), fd);
	else
	{
		ft_putnbr_fd((ln / 10), fd);
		ft_putchar_fd((ln % 10) + 48, fd);
	}
}
