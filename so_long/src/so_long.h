/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:11:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/04 14:20:06 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_x;
	int		map_y;
	void	*img_player;
	int		player_x;
	int		player_y;
	void	*img_wall;
	void	*img_ground;
	void	*img_collectable;
	void	*img_exit;
	int		moves;
	int		n_collectables;
	int		n_player;
	int		n_exit;
	int		img_width;
	int		img_height;
}						t_data;

int			handle_input(int keycode, t_data *data);
char		**open_map(char *path);
void		map_checker(t_data *data);
void		free_map(t_data *data);
void		init_game(t_data *data);
void		map_draw(t_data *data);
void		close_game(t_data *data);
void		update_exit(t_data *data);
void		move_player_w(t_data *data);
void		move_player_a(t_data *data);
void		move_player_s(t_data *data);
void		move_player_d(t_data *data);

#endif