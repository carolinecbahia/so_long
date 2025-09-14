/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:34:45 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 03:35:04 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate_sprites(t_game *game)
{
    if (game->frames < 1000)
    {
        game->frames++;
        return (0);
    }
    game->frames = 0;

    // TODO: Mova os inimigos
    // TODO: Atualize a posição do jogador
    // TODO: Redesenhe a tela
    return (0);
}

void move_enemies(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->matrix[y][x] == ENEMY)
            {
                // TODO: Adicione a lógica de patrulha do inimigo aqui
            }
            x++;
        }
        y++;
    }
}

void display_moves(t_game *game)
{
    char *moves;
    char *text;
    
    moves = ft_itoa(game->moves);
    text = ft_strjoin("Moves: ", moves);
    mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xFFFFFFFF, text);
    free(moves);
    free(text);
}
