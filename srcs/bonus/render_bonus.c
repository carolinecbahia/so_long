/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:19:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:25:00 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_sprite_textures_bonus(t_game *game)
{
	int size;

	game->enemy_img.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/sprites/enemy.xpm", &size, &size));
	game->player_frame1.ptr = (mlx_xpm_file_to_image(game->mlx_ptr,
			))
	if (!game->enemy_img.ptr)
	{
		ft_printf("Error\nFailed to load one or more base textures.\n");
		return (-1);
	}
	return (0);
}

void	bonus_init(t_game *game)
{
	game->frames = 0;
	load_sprite_textures_bonus(game);
	mlx_loop_hook(game->mlx_ptr, animate_sprites, game);
}

void	display_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, COR_DO_FUNDO, "Moves: XX");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xFFFFFFFF, moves_str);
	free(moves_str);
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
