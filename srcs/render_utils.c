/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:10:27 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/16 01:49:58 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_base_textures(t_game *game)
{
	int size;

	game->wall_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/wall.xpm", &size, &size));
	game->wall_img.addr = (mlx_get_data_addr(game->wall_img.ptr,
		&game->wall_img.bpp, &game->wall_img.line_len, &game->wall_img.endian));
	game->empty_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/tiles/empty.xpm", &size, &size));
	game->empty_img.addr = (mlx_get_data_addr(game->empty_img.ptr,
		&game->empty_img.bpp, &game->empty_img.line_len, &game->empty_img.endian));
	game->exit_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tiles/exit.xpm", &size, &size));
	game->exit_img.addr = (mlx_get_data_addr(game->exit_img.ptr,
		&game->exit_img.bpp, &game->exit_img.line_len, &game->exit_img.endian));
	if ((!game->wall_img.ptr || !game->empty_img.ptr || !game->exit_img.ptr))
	{
		ft_printf("Error\nFailed to load one or more base textures.\n");
		return (-1);
	}
	return (0);
}

int	load_sprite_textures(t_game *game)
{
	int size;

	game->player_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/sprites/player.xpm", &size, &size));
	game->player_img.addr = (mlx_get_data_addr(game->player_img.ptr,
		&game->player_img.bpp, &game->player_img.line_len, &game->player_img.endian));
	game->collectible_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/sprites/collectible.xpm", &size, &size));
	game->collectible_img.addr = (mlx_get_data_addr(game->collectible_img.ptr,
		&game->collectible_img.bpp, &game->collectible_img.line_len, &game->collectible_img.endian));
	if (!game->player_img.ptr || !game->collectible_img.ptr)
	{
		ft_printf("Error\nFailed to load one or more base textures.\n");
		return (-1);
	}
	return (0);
}

unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel_address;

	pixel_address = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)pixel_address);
}

void	put_pixel_to_img(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel_address;

	pixel_address = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel_address = color;
}

t_img	create_merged_tile(t_game *game, t_img *base, t_img *sprite)
{
	t_img			merged_tile;
	int				x;
	int				y;
	unsigned int	sprite_pixel_color;

	merged_tile.ptr = mlx_new_image(game->mlx_ptr, TILE_SIZE, TILE_SIZE);
	merged_tile.addr = mlx_get_data_addr(merged_tile.ptr, &merged_tile.bpp, &merged_tile.line_len, &merged_tile.endian);

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
				put_pixel_to_img(&merged_tile, x, y, get_pixel_color(base, x, y));
			x++;
		}
		y++;
	}
	return (merged_tile);
}
