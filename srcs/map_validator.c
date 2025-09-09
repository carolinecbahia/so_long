/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:12:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/09 19:11:38 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	map_reader(int fd);

static char	create_matrix(t_map_data *map_data, char *map_content)
{
	map_data->matrix = ft_split(map_content, '\n');
	if (!map_data->matrix)
		return (NULL);
	return (map_data->matrix);
}

static void	set_map_dimensions(t_map_data *map_data)
{
	int	y;

	y = 0;
	while (map_data->matrix[y] != NULL)
		y++;
	if (map_data->matrix[0] != NULL)
		map_data->width = ft_strlen(map_data->matrix[0]);
	else
		map_data->width = 0;
	map_data->height = y;
}

static void	count_map_elements(t_map_data *map_data)
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

int	path_validator(char **map_matrix)
{
	
}

int	map_validator(char *map_content, t_map_data *map_data)
{
	int	x;
	int	y;

	
	return (0);
}
