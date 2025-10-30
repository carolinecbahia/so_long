/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:29 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/30 15:32:59 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_merged_tile(t_game *game, t_img *base, t_img *sprite)
{
	int				x;
	int				y;
	unsigned int	sprite_pixel_color;
	t_img			merged_tile;

	merged_tile.ptr = mlx_new_image(game->mlx_ptr, TILE_SIZE, TILE_SIZE);
	merged_tile.addr = mlx_get_data_addr(merged_tile.ptr, &merged_tile.bpp,
			&merged_tile.line_len, &merged_tile.endian);
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			sprite_pixel_color = get_pixel_color(sprite, x, y);
			if (sprite_pixel_color != 0xFF000000)
				put_pixel_to_img(&merged_tile, x, y, sprite_pixel_color);
			else
			{
				put_pixel_to_img(&merged_tile, x, y,
					get_pixel_color(base, x, y));
			}
			x++;
		}
		y++;
	}
	return (merged_tile);
}

int	load_base_textures(t_game *game)
{
	int	size;

	game->wall_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/wall.xpm", &size, &size));
	game->wall_img.addr = (mlx_get_data_addr(game->wall_img.ptr,
				&game->wall_img.bpp, &game->wall_img.line_len,
				&game->wall_img.endian));
	game->empty_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/empty.xpm", &size, &size));
	game->empty_img.addr = (mlx_get_data_addr(game->empty_img.ptr,
				&game->empty_img.bpp, &game->empty_img.line_len,
				&game->empty_img.endian));
	game->exit_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/exit.xpm", &size, &size));
	game->exit_img.addr = (mlx_get_data_addr(game->exit_img.ptr,
				&game->exit_img.bpp, &game->exit_img.line_len,
				&game->exit_img.endian));
	if ((!game->wall_img.ptr || !game->empty_img.ptr || !game->exit_img.ptr))
	{
		ft_printf("Error\nFailed to load one or more base textures.\n");
		return (-1);
	}
	return (0);
}

int	load_sprite_textures(t_game *game)
{
	int	size;

	game->player_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/sprites/player.xpm", &size, &size));
	game->player_img.addr = (mlx_get_data_addr(game->player_img.ptr,
				&game->player_img.bpp, &game->player_img.line_len,
				&game->player_img.endian));
	game->collectible_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/sprites/collectible.xpm", &size, &size));
	game->collectible_img.addr = (mlx_get_data_addr(game->collectible_img.ptr,
				&game->collectible_img.bpp, &game->collectible_img.line_len,
				&game->collectible_img.endian));
	if (!game->player_img.ptr || !game->collectible_img.ptr)
	{
		ft_printf("Error\nFailed to load one or more base textures.\n");
		return (-1);
	}
	return (0);
}

void	draw_map(t_game *game)
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
			if (sprite_img && base_img && base_img->ptr && sprite_img->ptr)
			{
				merged_img = create_merged_tile(game, base_img, sprite_img);
				if (merged_img.ptr)
					(mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
							merged_img.ptr, x * TILE_SIZE, y * TILE_SIZE));
				mlx_destroy_image(game->mlx_ptr, merged_img.ptr);
			}
			else if (base_img && base_img->ptr)
			{
				(mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						base_img->ptr, x * TILE_SIZE, y * TILE_SIZE));
			}
			x++;
		}
		y++;
	}
}
