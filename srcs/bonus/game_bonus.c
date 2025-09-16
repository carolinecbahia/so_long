/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:34:45 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:44:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		load_base_textures(t_game *game);
int		load_sprite_textures(t_game *game);
int		handle_close(t_game *game);
int 	move_up(t_game *game);
int 	move_down(t_game *game);
int 	move_left(t_game *game);
int 	move_right(t_game *game);

void	enemy_directions(t_game *game, int *x, int *y, t_enemy *dir)
{
	int	new_x;
	int	new_y;

	new_x = *x + dir->dir_x;
	new_y = *y + dir->dir_y;

	if (game->matrix[new_y][new_x] == EMPTY)
	{
		game->matrix[*y][*x] = EMPTY;
		game->matrix[new_y][new_x] = ENEMY;
		*x = new_x;
		*y = new_y;
	}
	else
	{
		dir->dir_x = dir->dir_x * -1;
		dir->dir_y = dir->dir_y * -1;
	}
}

void	move_enemies(t_game *game)
{
	int		x;
	int		y;
	t_enemy	dir;

	dir.dir_x = 1;
	dir.dir_y = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->matrix[y][x] == ENEMY)
			{
                enemy_directions(game, &x, &y, &dir);
			}
			x++;
		}
		y++;
	}
}

static int	init_game(t_game *game)
{

}

int	setup_game_bonus(t_game *game)
{
	if (load_base_textures == -1 || load_sprite_textures == -1)
		return (-1);
	game->frame_counter = 0;
	game->player_current_frame = 0;
	mlx_key_hook(game->win_ptr, handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, handle_close, game);
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	return (0);
}
