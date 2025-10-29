/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:37:10 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/15 00:55:29 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	find_player_pos(t_game *game, t_vectors *pos)
{
	int	x;
	int	y;

	y = 0;
	while (game->matrix[y])
	{
		x = 0;
		while (game->matrix[y][x])
		{
			if (game->matrix[y][x] == PLAYER)
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
