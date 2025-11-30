/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:09:56 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:27:53 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemies_count(t_game *game)
{
	int	x;
	int	y;

	game->enemy_count = 0;
	y = 0;
	while (game->matrix[y] != NULL)
	{
		x = 0;
		while (game->matrix[y][x] != '\0')
		{
			if (game->matrix[y][x] == ENEMY)
				game->enemy_count++;
			x++;
		}
		y++;
	}
	if (game->enemy_count > 0)
		game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
	{
		free(game->enemies);
		return (-1);
	}
	return (0);
}

void	init_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->matrix[y][x] == ENEMY)
			{
				game->enemies[i].x = x;
				game->enemies[i].y = y;
				game->enemies[i].dir_y = 1;
				i++;
			}
			x++;
		}
		y++;
	}
}

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
