/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 19:52:44 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_key_hook(game->win_ptr, )
		exit(0);
	}
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free_matrix(game->matrix);
	exit (0);
}
