/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:19:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:20:43 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	bonus_textures(t_game *game)
{
	int	size;

	game->enemy_img = (mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/sprites/enemy.xpm", &size, &size));
}

void	bonus_init(t_game *game)
{
	game->frames = 0;
	bonus_textures(game);
	mlx_loop_hook(game->mlx_ptr, animate_sprites, game);
}

void	display_moves(t_game *game)
{
	char	*moves;
	char	*text;

	moves = ft_itoa(game->moves);
	text = ft_strjoin("Moves: ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xFFFFFFFF, text);
	free(moves);
	free(text);
}
int	animate_sprites(t_game *game)
{
	if (game->frames < 1000)
	{
		game->frames++;
		return (0);
	}
	game->frames = 0;
	move_enemies(game);
	draw_map(game);
	display_moves(game);
	return (0);
}
