/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/16 16:58:56 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		print_error("Error using malloc");
}

void init_mutex(pthread_mutex_t *mutex) {
    if (pthread_mutex_init(mutex, NULL) != 0)
        print_error("Erro ao inicializar mutex");
}