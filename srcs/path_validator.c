/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:44:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 20:28:05 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_dup_matrix(char **matrix)
{
	char	**matrix_copy;
	int		y;

	y = 0;
	while (matrix[y])
		y++;
	matrix_copy = (char **)malloc(sizeof(char *) * (y + 1));
	if (!matrix_copy)
		return (NULL);
	y = 0;
	while (matrix[y])
	{
		matrix_copy[y] = ft_strdup(matrix[y]);
		if (!matrix_copy[y])
		{
			ft_free_matrix(matrix_copy);
			return (NULL);
		}
		y++;
	}
	matrix_copy[y] = NULL;
	return (matrix_copy);
}

static void	find_player_pos(t_game *map_data, t_vectors *pos)
{
	int	x;
	int	y;

	y = 0;
	while (map_data->matrix[y])
	{
		x = 0;
		while (map_data->matrix[y][x])
		{
			if (map_data->matrix[y][x] == PLAYER)
			{
				pos->x = x;
				pos->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == WALL)
		return ;
	if (map[y][x] == VISITED)
		return ;
	if (map[y][x] == EXIT)
	{
		map[y][x] = VISITED;
		return ;
	}
	map[y][x] = VISITED;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	path_validator(t_game *map_data)
{
	char		**map_copy;
	t_vectors	player_pos;
	int			x;
	int			y;

	map_copy = ft_dup_matrix(map_data->matrix);
	if (!map_copy)
		return (0);
	find_player_pos(map_data, &player_pos);
	flood_fill(map_copy, player_pos.x, player_pos.y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
			{
				ft_free_matrix(map_copy);
				return (0);
			}
			x++;
		}
		y++;
	}
	ft_free_matrix(map_copy);
	return (1);
}
