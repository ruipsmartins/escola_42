/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:50:02 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 14:12:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		dst = data->img.addr + (y * data->img.line_len + \
		x * (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static int	color(t_data *data, int z)
{
	z *= data->z_adapted;
	if (data->min_z < 0)
		z -= data->min_z;
	data->p_rgb = (float)z / (float)data->range_z;
	if (data->p_rgb <= 1 && data->p_rgb >= 0.9)
		data->color = 0x00FF0000;
	else if (data->p_rgb < 0.9 && data->p_rgb >= 0.8)
		data->color = 0x00FF5500;
	else if (data->p_rgb < 0.8 && data->p_rgb >= 0.6)
		data->color = 0x00FFAA00;
	else if (data->p_rgb < 0.6 && data->p_rgb >= 0.4)
		data->color = 0x00FFFF00;
	else if (data->p_rgb < 0.4 && data->p_rgb >= 0.2)
		data->color = 0x00AAFF00;
	else if (data->p_rgb < 0.2 && data->p_rgb >= 0.1)
		data->color = 0x0055FF00;
	else if (data->p_rgb < 0.1 && data->p_rgb >= 0.05)
		data->color = 0x0000FF00;
	else if (data->p_rgb < 0.05 && data->p_rgb >= 0.02)
		data->color = 0x0000AA55;
	else if (data->p_rgb < 0.02 && data->p_rgb >= 0.01)
		data->color = 0x000055AA;
	else if (data->p_rgb < 0.01 && data->p_rgb >= 0)
		data->color = 0x000000FF;
	return (data->color);
}

static int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

static t_param	init_param(t_point a, t_point b)
{
	t_param	param;

	param.dx = abs(b.x - a.x);
	param.sx = compare(a.x, b.x);
	param.dy = -abs(b.y - a.y);
	param.sy = compare(a.y, b.y);
	param.err = param.dx + param.dy;
	return (param);
}

void	bresnham(t_data *data, t_point a, t_point b)
{
	t_param	param;

	param = init_param(a, b);
	while (1)
	{
		my_mlx_pixel_put(data, a.x, a.y, color(data, a.z));
		if (a.x == b.x && a.y == b.y)
			break ;
		param.e2 = 2 * param.err;
		if (param.e2 >= param.dy)
		{
			param.err += param.dy;
			a.x += param.sx;
		}
		if (param.e2 <= param.dx)
		{
			param.err += param.dx;
			a.y += param.sy;
		}
	}
}
