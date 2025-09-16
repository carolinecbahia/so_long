/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:44:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/16 01:39:06 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || WALL)
		return ;
	if (map[y][x] == VISITED)
		return ;
	if ((map[y][x] == COLLECTIBLE || map[y][x] == EXIT
			|| map[y][x] == EMPTY || map[y][x] == PLAYER))
	map[y][x] = VISITED;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_remaining(char **map_copy)
{
	int	y;
	int	x;
	
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	path_validator(t_game *map_data)
{
	char		**map_copy;
	t_vectors	player_pos;

	map_copy = ft_dup_matrix(map_data->matrix);
	if (!map_copy)
		return (-1);
	find_player_pos(map_data, &player_pos);
	flood_fill(map_copy, player_pos.x, player_pos.y);
	if (check_remaining(map_copy) != 0)
	{
		ft_free_matrix(map_copy);
		return(-1);
	}
	ft_free_matrix(map_copy);
	return (0);
}
