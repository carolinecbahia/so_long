/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:09:56 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:40:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemies_count(t_game)
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