/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:13 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:05 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_format(char specifier, va_list ap);
int	printf_putchar(char c);
int	printf_putstr(char *s);
int	printf_putnbr(long nbr, int base, int upper);
int	printf_putptr(unsigned long nbr, int base, int reset);

#endif