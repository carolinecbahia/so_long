/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/15 11:48:12 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x, pos.y - 1));
}

int	move_down(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x, pos.y + 1));
}

int	move_left(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x - 1, pos.y));
}

int	move_right(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x + 1, pos.y));
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free_matrix(game->matrix);
	exit (0);
}
