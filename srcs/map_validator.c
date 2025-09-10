/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:12:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/10 20:42:25 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_reader(int fd);

static char	**create_matrix(t_map_data *map_data, char *map_content)
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

static int	path_validator(t_map_data *map_data, t_vectors *vectors, char **map_marked)
{
	int x;
	int y;
	
	y = 0;
	while (map_data->matrix[y] != NULL)
	{
		x = 0;
		while (map_data->matrix[y][x] != '\0')
		{
			if (map_data->matrix[y][x] == PLAYER)
			vectors->x = x;
			vectors->y = y;
		}
			x++;
		}
		y++;
	}
	
	//walk x+1, if the place is 0 or C, mark as X, then x++; else x does not increase but y+1
	//? check if the place is 0 or C, if it is, then change for X and move.
	//? compare the 2 maps, if there is C that not changed to G on the checked map, is invalid (ft_strchr?)
	//? if E is not marked, also is invalid
	//? if all the C and the E are marked, then is valid

	
}

int	map_validator(char *map_content, t_map_data *map_data)
{
	int	x;
	int	y;
	int map_height;
	int map_width;
	
	//TODO map_content = map_reader
	//TODO map_data->matrix = create_matrix(map_content)
	//TODO if set_map_dimensions == rectangle (if row's lenght doesn't match the width, then is an invalid map), 
	//TODO then check map elements (borders 1, matrix[0], matrix[map_height], matrix[while y < height][x == 0 || x = width]) 
	//tODO && count (P = 1, E = 1, C >= 1)
	//TODO if map is valid, then path_validator
	//TODO if path is valid, then return 0 (sucess)
	
	return (0);
}
