/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:34:25 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/16 01:51:03 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	path_validator_bonus(t_game *map_data);

static int	count_map_elements_bonus(t_game *map_data)
{
	int	x;
	int	y;

	map_data->collectible_count = 0;
	map_data->player_count = 0;
	map_data->exit_count = 0;
	y = 0;
	while (map_data->matrix[y] != NULL)
	{
		x = 0;
		while (map_data->matrix[y][x] != '\0')
		{
			if (map_data->matrix[y][x] == COLLECTIBLE)
				map_data->collectible_count++;
			else if (map_data->matrix[y][x] == EXIT)
				map_data->exit_count++;
			else if (map_data->matrix[y][x] == PLAYER)
				map_data->player_count++;
			else if ((map_data->matrix[y][x] != EMPTY
				&& map_data->matrix[y][x] != WALL))
				return(ft_free_and_error(map_data->matrix, "Invalid character in map"));
			x++;
		}
		y++;
	}
	return (0);
}

int	map_validator(char *map_content, t_game *map_data)
{
	map_data->matrix = create_matrix(map_content);
	if (!map_data->matrix)
		return (ft_free_and_error(NULL, "Failed to create matrix"));
	if (check_map_dimensions(map_data) != 0)
		return (ft_free_and_error(map_data->matrix, "Invalid map dimensions"));
	if (check_map_walls(map_data) != 0)
		return (ft_free_and_error(map_data->matrix, "Not enclosed map"));
	if (count_map_elements(map_data) != 0)
		return (-1);
	if ((map_data->player_count != 1 || map_data->exit_count != 1
			|| map_data->collectible_count < 1))
		return (ft_free_and_error(map_data->matrix, "Wrong elements count"));
	if (path_validator(map_data) == 0)
		return (ft_free_and_error(map_data->matrix, "No valid path"));
	return (0);
}

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
