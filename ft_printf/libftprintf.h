/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:13 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:05 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_format(char specifier, va_list ap);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long nbr, int base, int upper);

#endif