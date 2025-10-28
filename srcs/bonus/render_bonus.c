/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:19:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:17:25 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	display_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 20, MOVES_BACKGROUND_COLOR, "Moves: XX");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 10, 0xFFFFFFFF, moves_str);
	free(moves_str);
}

void	draw_map_bonus(t_game *game)
{
	int			i;
	int			frame;
	t_vectors	pos;

	find_player_pos(game, &pos);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player_frames[game->player_current_frame].ptr,
		pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	i = 0;
	while (i < game->enemy_count)
	{
		frame = game->frame_counter % ENEMY_FRAMES;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->enemy_frames[frame].ptr,
			game->enemies[i].x * TILE_SIZE, game->enemies[i].y * TILE_SIZE);
		i++;
	}
}

int	animate_sprites(t_game *game)
{
	move_enemies(game);
	draw_map(game);
	draw_map_bonus(game);
	display_moves(game);
	return (0);
}
