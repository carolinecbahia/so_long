/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:35:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 03:35:37 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_key(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        handle_close(game);
    }
    if (keycode == KEY_W || keycode == KEY_UP)
    {
        // TODO: Mova o jogador para cima
    }
    if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        // TODO: Mova o jogador para baixo
    }
    if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        // TODO: Mova o jogador para a esquerda
    }
    if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        // TODO: Mova o jogador para a direita
    }
    return (0);
}