/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 03:30:29 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 03:30:39 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	//TODO constantes de tamanho da sprite;
	int	size;

	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm", &size, &size);
	game->empty_img = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/empty.xpm", &size, &size);
    game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player.xpm", &size, &size);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/collectible.xpm", &size, &size);
    game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/exit.xpm", &size, &size);
}

void	draw_map(t_game *game)
{
	 int x;
    int y;

    y = 0;
    while (game->matrix[y])
    {
        x = 0;
        while (game->matrix[y][x])
        {
            if (game->matrix[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            // TODO: Adicionar a lógica para desenhar os outros tiles
            x++;
        }
        y++;
    }
}