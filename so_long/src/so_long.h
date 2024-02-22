/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:11:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/22 19:02:43 by ruidos-s         ###   ########.fr       */
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
	char	**map;
	void	*img_player;
	void	*img_wall;
	void	*img_collectable;
	void	*img_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		n_collectables;
}               t_data;

int		handle_input(int keycode, t_data *data);
char	**open_map(char *path);
void	map_checker(t_data *data);
void 	free_map(t_data *data);
void	init_game(t_data *data);


#endif