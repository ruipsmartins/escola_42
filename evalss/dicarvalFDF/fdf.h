/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 11:46:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlibx/mlx.h"

# define W_WIDTH 1920
# define W_HEIGHT 980
# define MLX_ERROR 1
# define DEFAULT_ANG 0.523599

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}	t_point;

typedef struct s_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_param;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_point		**point_map;
	float		size_grid;
	int			map_num;
	int			max_argv;
	char		**map_file;
	int			**map_content;
	int			height;
	int			width;
	int			max_y;
	int			max_x;
	int			max_z;
	int			min_z;
	int			range_z;
	int			z_adapted;
	int			x_pos;
	int			y_pos;
	float		p_rgb;
	int			color;
	double		def_angle;
}	t_data;

//Map checking
int		check_map(t_data *data);
void	free_split(char **line, int code, t_data *data);

//Parsing and inicialization
void	map_loading(t_data *data, int fd, int index);

//Generate the list of points and draw them
void	map_to_point(t_data *data);
void	range_to_zoom(t_data *data);
void	draw_image_to_grid(t_data *data);
t_point	projection(t_point p, t_data *data);
void	bresnham(t_data *data, t_point a, t_point b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Free and close
void	free_split(char **line, int code, t_data *data);
int		ft_close_fdf(void *data);
void	malloc_fail(t_data *data);

#endif
