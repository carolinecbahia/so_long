/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:12:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/09 18:21:15 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_reader(int fd);

char	create_matrix(t_map_data *map_data, char *map_content)
{
	map_data->matrix = ft_split(map_content, '\n');
	if (!map_data->matrix)
		return (NULL);
	return (map_data->matrix);
}

static int is_map_valid(t_map_data *map_data)
{
	
}

static void count_map_elements(t_map_data *map_data)
{
	
}

int	path_validator(char **map_matrix)
{
	
}

int	map_validator(char *map_content, t_map_data *map_data)
{
	int x;
	int y;
	
	map_data->matrix = create_matrix(map_content);
	if (!map_data->matrix)
		return(-1);
	count_map_elements(map_data);

	if (is_map_valid(map_data) == 0)
	{
		return (-1);
	}
	
	path_validator(map_data->matrix);
	
	return (0);
}
