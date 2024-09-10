/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:03 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 11:46:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bigger_case(t_data *data)
{
	while ((data->max_x > W_WIDTH || \
		data->max_x > W_HEIGHT))
	{
		data->max_y /= 3;
		data->max_x /= 3;
		data->size_grid /= 3;
	}
	data->x_pos = W_WIDTH / 2 \
		- data->max_x / 4;
	data->y_pos = W_HEIGHT / 3 \
		- data->max_y / 3;
}

void	smaller_case(t_data *data)
{
	while ((data->max_x < W_WIDTH / 5 \
	|| data->max_x < W_HEIGHT / 5))
	{
		data->max_y *= 3;
		data->max_x *= 3;
		data->size_grid *= 3;
	}
	data->x_pos = W_WIDTH / 2 \
		- data->max_x / 4;
	data->y_pos = W_HEIGHT / 3 \
		- data->max_y / 3;
}

void	range_to_zoom(t_data *data)
{
	int	avb_wth;
	int	avb_hth;

	avb_wth = W_WIDTH - data->max_x;
	avb_hth = W_HEIGHT - data->max_y;
	if (avb_wth < 0 || avb_hth < 0)
		bigger_case(data);
	else
		smaller_case(data);
}
