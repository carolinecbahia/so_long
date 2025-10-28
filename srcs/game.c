/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:09:19 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_game(t_game *game)
{
	load_base_textures(game);
	load_sprite_textures(game);
	draw_map(game);
	mlx_key_hook(game->win_ptr, handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, handle_close, game);
	return (0);
}

static void	check_win(t_game *game)
{
	ft_printf("You won in %d moves!\n", game->moves + 1);
	cleanup_game(game);
	exit (0);
}

int	move_player(t_game *game, t_vectors *pos, int new_x, int new_y)
{
	char	dest;

	dest = game->matrix[new_y][new_x];
	if (dest == WALL)
		return (0);
	if (dest == COLLECTIBLE)
		game->collected++;
	if (dest == EXIT)
	{
		if (game->collected == game->collectible_count)
			check_win(game);
		return (0);
	}
	game->matrix[pos->y][pos->x] = EMPTY;
	game->matrix[new_y][new_x] = PLAYER;
	pos->x = new_x;
	pos->y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
	return (1);
}

int	handle_key(int keycode, t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_D)
		move_right(game);
	return (0);
}
