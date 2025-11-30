/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:30:18 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:32:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int load_base_textures(t_game *game)
{
    int size;

    game->wall_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
            "./textures/tiles/wall.xpm", &size, &size);
    game->empty_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
            "./textures/tiles/empty.xpm", &size, &size);
    game->exit_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
            "./textures/tiles/exit.xpm", &size, &size);
    game->collectible_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
            "./textures/sprites/collectible.xpm", &size, &size);
            
    if (!game->wall_img.ptr || !game->empty_img.ptr ||
        !game->exit_img.ptr || !game->collectible_img.ptr)
    {
        ft_printf("Error\nFailed to load base textures.\n");
        return (-1);
    }
    return (0);
}

int	load_player_textures_bonus(t_game *game)
{
	int		size;
	int		i;
	char	*player_paths[PLAYER_FRAMES];

	player_paths[0] = "./textures/bonus/sprites/player_frame1.xpm";
	player_paths[1] = "./textures/bonus/sprites/player_frame2.xpm";
	player_paths[2] = "./textures/bonus/sprites/player_frame3.xpm";
	player_paths[3] = "./textures/bonus/sprites/player_frame4.xpm";
	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->player_frames[i].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				player_paths[i], &size, &size);
		if (!game->player_frames[i].ptr)
		{
			ft_printf("Error\nFailed to load one or more player textures.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	load_enemies_textures_bonus(t_game *game)
{
	int		size;
	int		i;
	char	*enemy_paths[ENEMY_FRAMES];

	enemy_paths[0] = "./textures/bonus/sprites/enemy_frame1.xpm";
	enemy_paths[1] = "./textures/bonus/sprites/enemy_frame2.xpm";
	enemy_paths[2] = "./textures/bonus/sprites/enemy_frame3.xpm";
	enemy_paths[3] = "./textures/bonus/sprites/enemy_frame4.xpm";
	i = 0;
	while (i < ENEMY_FRAMES)
	{
		game->enemy_frames[i].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				enemy_paths[i], &size, &size);
		if (!game->enemy_frames[i].ptr)
		{
			ft_printf("Error\nFailed to load one or more enemy textures.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int load_sprite_textures(t_game *game)
{
    if (load_player_textures_bonus(game) == -1)
        return (-1);
    if (load_enemies_textures_bonus(game) == -1)
        return (-1);
    return (0);
}