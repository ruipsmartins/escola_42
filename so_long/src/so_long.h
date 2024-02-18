/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:11:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/18 15:38:13 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/mlx_linux/mlx.h"
#include "../libs/libft/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	int		x_player;
	int		y_player;
}               t_data;

int		handle_input(int keycode, t_data *data);

#endif