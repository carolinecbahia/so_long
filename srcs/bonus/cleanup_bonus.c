/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:32:28 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/16 01:46:22 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void    cleanup_enemies(t_game *game)
{
    if (game->enemies)
    {
        free(game->enemies);
        game->enemies = NULL;
    }
}

void	cleanup_game_bonus(t_game *game)
{
	if (!game)
		return ;
	cleanup_enemies(game);
	cleanup_game(game);
}