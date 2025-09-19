/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:37:10 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/19 14:56:42 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**create_matrix(char *map_content)
{
	char	**matrix;

	if (!map_content)
		return (NULL);
	matrix = ft_split(map_content, '\n');
	if (!matrix)
		return (NULL);
	return (matrix);
}

int	check_map_dimensions(t_game *map_data)
{
	int		y;
	size_t	x;

	y = 0;
	while (map_data->matrix[y] != NULL)
		y++;
	if (y < 3)
		return (-1);
	x = ft_strlen(map_data->matrix[0]);
	if (x < 3)
		return (-1);
	map_data->height = y;
	map_data->width = x;
	y = 0;
	while (map_data->matrix[y] != NULL)
	{
		if (ft_strlen(map_data->matrix[y]) != x)
			return (-1);
		y++;
	}
	return (0);
}

int	check_map_walls(t_game *map_data)
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

char	**dup_matrix(char **matrix)
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

void	find_player_pos(t_game *map_data, t_vectors *pos)
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
