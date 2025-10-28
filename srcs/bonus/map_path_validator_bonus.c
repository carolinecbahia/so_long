/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:34:25 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:19:59 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_map_elements_bonus(t_game *game)
{
	int	x;
	int	y;

	game->collectible_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	y = 0;
	while (game->matrix[y] != NULL)
	{
		x = 0;
		while (game->matrix[y][x] != '\0')
		{
			if (game->matrix[y][x] == COLLECTIBLE)
				game->collectible_count++;
			else if (game->matrix[y][x] == ENEMY)
				game->enemy_count++;
			else if (game->matrix[y][x] == EXIT)
				game->exit_count++;
			else if (game->matrix[y][x] == PLAYER)
				game->player_count++;
			else if ((game->matrix[y][x] != EMPTY
				&& game->matrix[y][x] != WALL
				&& game->matrix[y][x] != ENEMY
				&& game->matrix[y][x] != COLLECTIBLE
				&& game->matrix[y][x] != EXIT
				&& game->matrix[y][x] != PLAYER))
			{
				ft_printf("Invalid character: %c\n", game->matrix[y][x]);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	flood_fill_bonus(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || WALL)
		return ;
	if (map[y][x] == VISITED)
		return ;
	if ((map[y][x] == COLLECTIBLE || map[y][x] == EXIT
			|| map[y][x] == EMPTY || map[y][x] == PLAYER
			|| map[y][x] == ENEMY))
		map[y][x] = VISITED;
	flood_fill_bonus(map, x + 1, y);
	flood_fill_bonus(map, x - 1, y);
	flood_fill_bonus(map, x, y + 1);
	flood_fill_bonus(map, x, y - 1);
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

int	path_validator(t_game *game)
{
	char		**map_copy;
	t_vectors	player_pos;

	map_copy = dup_matrix(game->matrix);
	if (!map_copy)
		return (-1);
	find_player_pos(game, &player_pos);
	flood_fill_bonus(map_copy, player_pos.x, player_pos.y);
	if (check_remaining(map_copy) == 0)
	{
		ft_free_matrix(map_copy);
		return (-1);
	}
	ft_free_matrix(map_copy);
	return (0);
}

int	map_validator_bonus(char *map_content, t_game *game)
{
	game->matrix = create_matrix(map_content);
	if (!game->matrix)
	{
		ft_printf("Failed to create matrix\n");
		return (-1);
	}
	if (check_map_dimensions(game) != 0)
	{
		ft_printf("Invalid map dimensions\n");
		return (-1);
	}
	if (check_map_walls(game) != 0)
	{
		ft_printf("Error\n Map is not enclosed by walls\n");
		return (-1);
	}
	if (count_map_elements_bonus(game) != 0)
		return (-1);
	if ((game->player_count != 1 || game->exit_count != 1
			|| game->collectible_count < 1))
	{
		ft_printf("Wrong elements count\n");
		return (-1);
	}
	if (enemies_count(game) == -1)
	{
		ft_printf("Error\n Failed to allocate enemies\n");
		return (-1);
	}
	init_enemies(game);
	if (path_validator(game) != 0)
	{
		ft_printf("No valid path\n");
		return (-1);
	}
	return (0);
}
