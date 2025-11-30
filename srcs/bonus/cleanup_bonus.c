/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:32:28 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:51:44 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	cleanup_enemies(t_game *game)
{
	int	i;

	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
	i = 0;
	while (i < ENEMY_FRAMES)
	{
		if (game->enemy_frames[i].ptr)
			mlx_destroy_image(game->mlx_ptr, game->enemy_frames[i].ptr);
		i++;
	}
}

static void	cleanup_player_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (game->player_frames[i].ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_frames[i].ptr);
		i++;
	}
}

void	cleanup_game_bonus(t_game *game)
{
	if (!game)
		return ;
	cleanup_enemies(game);
	cleanup_player_frames(game);
	game->player_img.ptr = NULL;
	game->enemy_img.ptr = NULL;
	cleanup_game(game);
}
