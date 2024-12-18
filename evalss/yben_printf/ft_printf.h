/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:11 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:33:12 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(char c);
int	print_int(int n);
int	print_hex(int n, char *base);
int	print_hex_low(int n);
int	print_hex_upp(int n);
int	print_pointer(void *p);
int	print_percent(void);
int	ft_strlen(char *s);
int	print_string(char *s);
int	print_u_int(unsigned int n);
int	ft_printf(const char *s, ...);

#endif
