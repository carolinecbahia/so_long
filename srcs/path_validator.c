/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:44:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 10:37:45 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int allow_exit)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == VISITED || map[y][x] == WALL)
		return ;
	if (map[y][x] == EXIT && !allow_exit)
		return ;
	if (map[y][x] == COLLECTIBLE || map[y][x] == EMPTY ||
		map[y][x] == EXIT || map[y][x] == PLAYER)
		map[y][x] = VISITED;
	flood_fill(map, x + 1, y, allow_exit);
	flood_fill(map, x - 1, y, allow_exit);
	flood_fill(map, x, y + 1, allow_exit);
	flood_fill(map, x, y - 1, allow_exit);
}

int	check_remaining(char **map_copy)
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

int	check_collectibles_remaining(char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE)
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

	find_player_pos(map_data, &player_pos);
	map_copy = dup_matrix(map_data->matrix);
	if (!map_copy)
		return (-1);
	flood_fill(map_copy, player_pos.x, player_pos.y, 0);
	if (check_collectibles_remaining(map_copy) != 0)
	{
		ft_free_matrix(map_copy);
		return (-1);
	}
	ft_free_matrix(map_copy);
	map_copy = dup_matrix(map_data->matrix);
	flood_fill(map_copy, player_pos.x, player_pos.y, 1);
	if (check_remaining(map_copy) != 0)
	{
		ft_free_matrix(map_copy);
		return (-1);
	}
	ft_free_matrix(map_copy);
	return (0);
}
