/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:34:45 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:24:23 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

