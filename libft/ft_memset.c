/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:47:37 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/26 15:04:46 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	The memset() function fills the first n bytes of the memory
	area pointed to by s with the constant byte c. */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

/*
#include <stdio.h>

int    main(void)
{
    char    str[] = "Hello World!";

    printf("antes do ft_memset: %s\n", str);
    ft_memset(str,'x', 5);
    printf("depois do ft_memset: %s\n", str);
    return (0);
} */