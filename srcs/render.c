/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:29 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:38:18 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	size;

	game->wall_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/wall.xpm", &size, &size));
	game->empty_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/empty.xpm", &size, &size));
	game->player_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/sprites/player.xpm", &size, &size));
	game->collectible_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/sprites/collectible.xpm", &size, &size));
	game->exit_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/exit.xpm", &size, &size));
}

static void	*get_tile_img(t_game *game, char tile)
{
	if (tile == WALL)
		return (game->wall_img);
	else if (tile == EMPTY)
		return (game->empty_img);
	else if (tile == PLAYER)
		return (game->player_img);
	else if (tile == COLLECTIBLE)
		return (game->collectible_img);
	else if (tile == EXIT)
		return (game->exit_img);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (game->matrix[y])
	{
		x = 0;
		while (game->matrix[y][x])
		{
			img = get_tile_img(game, game->matrix[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
