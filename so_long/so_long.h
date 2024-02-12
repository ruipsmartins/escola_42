/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:11:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/10 11:11:17 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		y;
}               t_mlx_data;

int		handle_input(int keycode, t_mlx_data *data);

#endif