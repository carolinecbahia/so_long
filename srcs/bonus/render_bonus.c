/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:19:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:32:54 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*str;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	str = ft_strjoin("Moves: ", moves_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		11, 21, MOVES_BACKGROUND_COLOR, str);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 20, 0xFFFFFF, str);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 10, 0xFFFFFFFF, moves_str);
	free(moves_str);
	free(str);
}

void	put_correct_sprite(t_game *game, int x, int y)
{
	char	tile;
	int		f;

	tile = game->matrix[y][x];
	if (tile != WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->empty_img.ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible_img.ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_frames[game->player_current_frame].ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == ENEMY)
	{
		f = (game->frame_counter / 5) % ENEMY_FRAMES;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->enemy_frames[f].ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_map_bonus(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_correct_sprite(game, x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
}

int	animate_sprites(t_game *game)
{
	game->frame_counter++;
	if (game->frame_counter >= ENEMY_SPEED)
	{
		move_enemies(game);
	}
	draw_map_bonus(game);
	return (0);
}
