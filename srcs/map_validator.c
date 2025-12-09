/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:12:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/12/09 12:49:24 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_map_elements(t_game *game)
{
	int		x;
	int		y;
	char	c;

	game->collectible_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	y = -1;
	while (game->matrix[++y] != NULL)
	{
		x = -1;
		while (game->matrix[y][++x] != '\0')
		{
			c = game->matrix[y][x];
			if (c == COLLECTIBLE)
				game->collectible_count++;
			else if (c == EXIT)
				game->exit_count++;
			else if (c == PLAYER)
				game->player_count++;
			else if ((c != EMPTY && c != WALL))
				return (print_error("Error: Invalid character!\n"));
		}
	}
	return (0);
}

int	check_map_dimensions(t_game *game)
{
	int		y;
	size_t	x;

	y = 0;
	while (game->matrix[y] != NULL)
		y++;
	if (y < 3)
		return (-1);
	x = ft_strlen(game->matrix[0]);
	if (x < 3)
		return (-1);
	game->height = y;
	game->width = x;
	y = 0;
	while (game->matrix[y] != NULL)
	{
		if (ft_strlen(game->matrix[y]) != x)
			return (-1);
		y++;
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)game->width)
	{
		if (game->matrix[0][x] != WALL
			|| game->matrix[game->height - 1][x] != WALL)
			return (-1);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->matrix[y][0] != WALL
			|| game->matrix[y][game->width - 1] != WALL)
			return (-1);
		y++;
	}
	return (0);
}

int	map_validator(char *map_content, t_game *game)
{
	game->matrix = create_matrix(map_content);
	if (!game->matrix)
		return (print_error("Error: Failed to create matrix\n"));
	if (check_map_dimensions(game) != 0)
		return (print_error("Error: Invalid map dimensions\n"));
	if (check_map_walls(game) != 0)
		return (print_error("Error: Map is not enclosed by walls\n"));
	if (count_map_elements(game) != 0)
		return (print_error("Error: Wrong elements count\n"));
	if ((game->player_count != 1 || game->exit_count != 1
			|| game->collectible_count < 1))
		return (print_error("Error: Wrong elements count\n"));
	if (path_validator(game) != 0)
		return (print_error_and_cleanup("Error: No valid path\n", game));
	return (0);
}
