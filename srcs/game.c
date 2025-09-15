/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 01:51:09 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game);
int		handle_close(t_game *game);
int 	move_up(t_game *game);
int 	move_down(t_game *game);
int 	move_left(t_game *game);
int 	move_right(t_game *game);

int	setup_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (-1);
	game->win_ptr = (mlx_new_window(game->mlx_ptr, 
			game->width * TILE_SIZE, game->height * TILE_SIZE, "So Long"));
	if (!game->win_ptr)
		return (-1);
	load_textures(game);
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

int move_player(t_game *game, t_vectors *pos, int new_x, int new_y)
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

int		handle_key(int keycode, t_game *game)
{
	t_vectors pos;
	
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
