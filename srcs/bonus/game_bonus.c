/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:34:45 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:21:44 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_loop(t_game *game)
{
	static int	player_anim_counter;
	static int	enemy_anim_counter;

	player_anim_counter++;
	enemy_anim_counter++;
	if (player_anim_counter >= ANIMATION_SPEED)
	{
		game->player_current_frame++;
		if (game->player_current_frame >= PLAYER_FRAMES)
			game->player_current_frame = 0;
		player_anim_counter = 0;
	}
	if (enemy_anim_counter >= ANIMATION_SPEED)
	{
		game->frame_counter++;
		if (game->frame_counter >= ENEMY_FRAMES)
			game->frame_counter = 0;
		enemy_anim_counter = 0;
	}
	draw_map(game);
	draw_map_bonus(game);
	display_moves(game);
	return (0);
}

int	setup_game_bonus(t_game *game)
{
	game->frame_counter = 0;
	game->player_current_frame = 0;
	load_base_textures(game);
	load_sprite_textures(game);
	mlx_key_hook(game->win_ptr, handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, handle_close, game);
	mlx_loop_hook(game->mlx_ptr, animate_sprites, game);
	return (0);
}
