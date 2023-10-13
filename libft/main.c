/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/13 16:00:46 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main(void)
{
	char *s1 = "hello ";
	char *s2 = "world!";
	char *newstr = ft_strjoin(s1, s2);

	if (newstr != NULL)
	{
		printf("Substring: %s\n", newstr);
		free(newstr);
	}
	else
	{
		printf("Failed to create substring.\n");
	}

	return (0);
}
