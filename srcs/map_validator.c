/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:12:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 03:49:02 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_validator(t_game *map_data);
int	ft_free_and_error(char **matrix, char *msg);

static char	**create_matrix(char *map_content)
{
	char	**matrix;

	if (!map_content)
		return (NULL);
	matrix = ft_split(map_content, '\n');
	if (!matrix)
		return (NULL);
	return (matrix);
}

static int	check_map_dimensions(t_game *map_data)
{
	int		y;
	size_t	x;

	y = 0;
	while (map_data->matrix[y] != NULL)
		y++;
	if (y == 0)
		return (-1);
	x = ft_strlen(map_data->matrix[0]);
	if (x < 3)
		return (-1);
	if (x < 3 || y < 3)
		return (-1);
	map_data->height = y;
	map_data->width = x;
	y = 0;
	while (map_data->matrix[y] != NULL)
	{
		if (ft_strlen(map_data->matrix[y] != (int)x))
			return (-1);
		y++;
	}
	return (0);
}

static int	check_map_walls(t_game *map_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)map_data->width)
	{
		if (map_data->matrix[0][x] != WALL
			|| map_data->matrix[map_data->height - 1][x] != WALL)
			return (-1);
		x++;
	}
	y = 0;
	while (y < map_data->height)
	{
		if (map_data->matrix[y][0] != WALL
			|| map_data->matrix[y][map_data->width - 1] != WALL)
			return (-1);
		y++;
	}
	return (0);
}

static void	count_map_elements(t_game *map_data)
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
			x++;
		}
		y++;
	}
}

int	map_validator(char *map_content, t_map_data *map_data)
{
	map_data->matrix = create_matrix(map_content);
	if (!map_data->matrix)
		return (ft_free_and_error(NULL, "Failed to create matrix"));
	if (check_map_dimensions(map_data) != 0)
		return (ft_free_and_error(map_data->matrix, "Invalid map dimensions"));
	if (check_map_walls(map_data) != 0)
		return (ft_free_and_error(map_data->matrix, "Not enclosed map"));
	count_map_elements(map_data);
	if ((map_data->player_count != 1 || map_data->exit_count != 1
			|| map_data->collectible_count < 1))
		return (ft_free_and_error(map_data->matrix, "Wrong elements count"));
	if (path_validator(map_data) == 0)
		return (ft_free_and_error(map_data->matrix, "No valid path"));
	return (0);
}
