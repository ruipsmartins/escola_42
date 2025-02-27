/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:43:28 by ruidos-s          #+#    #+#             */
/*   Updated: 2025/02/27 18:41:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3D.h"


// our own put_pixel function
void	ft_put_pixel(int x, int y, int color, t_game *game)
{
	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	int index = (x * game->bpp / 8) + (y * game->size_line);
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color & 0xFF00) >> 8;
	game->data[index + 2] = (color & 0xFF0000) >> 16;
}

// our own clear_image function
void clear_image(t_game *game)
{
    for(int y = 0; y < WINDOW_HEIGHT; y++)
        for(int x = 0; x < WINDOW_WIDTH; x++)
            ft_put_pixel(x, y, 0, game);
}


void draw_square(int x, int y, int size, int color, t_game *game)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ft_put_pixel(x + i, y + j, color, game);
        }
    }
}

static void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

void draw_map(t_game *game)
{
	char **map = game->map;
	int color = 0x0000FF;
	(void)color;
	for(int y = 0; map[y]; y++)
		for(int x = 0; map[y][x]; x++)
			if(map[y][x] == '1')
			{
				//draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
				img_draw(game, game->img_wall, x , y );
			}
}
int draw_loop(t_game *game)
{
    t_player *player = &game->player;


    move_player(player);
	clear_image(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
    draw_square(player->x, player->y, 40, 0x00FF00, game);
 
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
}



int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}

	game.map = open_map(argv[1]);
	init_game(&game);

	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	
	mlx_loop_hook(game.mlx, draw_loop, &game);
	
	mlx_loop(game.mlx);
	return (0);
}
