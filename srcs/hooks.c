/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:59:58 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(t_game *map_data, t_vectors *pos);

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free_matrix(game->matrix);
	exit (0);
}

int move_up(t_game *game)
{
	t_vectors pos;
	
	find_player_pos(game, &pos);
    return (move_player(game, &pos, pos.x, pos.y - 1));
}

int	move_down(t_game *game)
{
	t_vectors pos;
	
	find_player_pos(game, &pos);
    return (move_player(game, &pos, pos.x, pos.y + 1));
}

int	move_left(t_game *game)
{
	t_vectors pos;
	
	find_player_pos(game, &pos);
    return (move_player(game, &pos, pos.x - 1, pos.y));
}

int	move_right(t_game *game)
{
	t_vectors pos;
	
	find_player_pos(game, &pos);
    return (move_player(game, &pos, pos.x + 1, pos.y));
}
