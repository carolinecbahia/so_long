/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:10:27 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:07:58 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*get_base_img(t_game *game, char tile)
{
	if (tile == WALL)
		return (&game->wall_img);
	else if (tile == EXIT)
		return (&game->exit_img);
	return (&game->empty_img);
}

t_img	*get_sprite_img(t_game *game, char tile)
{
	if (tile == PLAYER)
		return (&game->player_img);
	else if (tile == COLLECTIBLE)
		return (&game->collectible_img);
	return (NULL);
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

int	is_pixel_solid(t_img *img)
{
}
