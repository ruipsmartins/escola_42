/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:43:53 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/18 17:56:47 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while(s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return 0;
}

int main (void)
{
	int a = 0;
	int b = 0;
	char s1[]= "olabb";
	char s2[]= "olab";

	a = ft_strcmp(s1, s2);
	b = strcmp(s1, s2);
	printf("minha    str: %d\n", a);	
	printf("já feita str: %d\n", b);	
	return 0;
}