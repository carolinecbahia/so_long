/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:34:45 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:44:13 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_win(t_game *game)
{
	ft_printf("You won in %d moves!\n", game->moves + 1);
	cleanup_game_bonus(game);
	exit (0);
}

void    handle_game_over(t_game *game)
{
    ft_printf("You were caught! GAME OVER.\n");
    cleanup_game_bonus(game); // Use a limpeza do bônus
    exit(0);
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
	draw_map_bonus(game);
	return (1);
}

int	handle_key(int keycode, t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_A || keycode == KEY_LF)
		move_left(game);
	if (keycode == KEY_S || keycode == KEY_DW)
		move_down(game);
	if (keycode == KEY_D || keycode == KEY_RG)
		move_right(game);
	return (0);
}

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
	ft_printf("DEBUG: Init game sucesso, desenhando mapa\n");
	draw_map_bonus(game);
	display_moves(game);
	return (0);
}

int	setup_game_bonus(t_game *game)
{
	if (load_base_textures(game) == -1)
	{
		return (-1);
	}
	if (load_sprite_textures(game) == -1)
	{
		return (-1);
	}
	game->frame_counter = 0;
	game->player_current_frame = 0;
	mlx_key_hook(game->win_ptr, handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, handle_close, game);
	mlx_loop_hook(game->mlx_ptr, animate_sprites, game);
	return (0);
}
