/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:29 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:29:17 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*get_base_img(t_game *game, char tile)
{
	if (tile == WALL)
		return (&game->wall_img);
	else if (tile == EXIT)
		return (&game->exit_img);
	return (&game->empty_img);
}

static t_img *get_sprite_img(t_game *game, char tile)
{
    if (tile == PLAYER)
        return (&game->player_img);
    else if (tile == COLLECTIBLE)
        return (&game->collectible_img);
    return (NULL);
}

void    draw_map(t_game *game)
{
	int		x;
	int		y;
	t_img	*base_img;
	t_img	*sprite_img;
	t_img	merged_img;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			base_img = get_base_img(game, game->matrix[y][x]);
			sprite_img = get_sprite_img(game, game->matrix[y][x]);
			if (sprite_img)
			{
				merged_img = create_merged_tile(game, base_img, sprite_img);
				(mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					merged_img.ptr, x * TILE_SIZE, y * TILE_SIZE));
				mlx_destroy_image(game->mlx_ptr, merged_img.ptr);
			}
			else
				(mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					base_img->ptr, x * TILE_SIZE, y * TILE_SIZE));
			x++;
		}
		y++;
	}
}
