/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:22:51 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 12:33:49 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	init_mlx_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		cleanup_game(game);
		ft_printf("Error.\n Init window failed");
		return (-1);
	}
	game->win_ptr = mlx_new_window(
			game->mlx_ptr,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"So Long Bonus");
	if (!game->win_ptr)
	{
		cleanup_game(game);
		ft_printf("Error.\n Init window failed");
		return (-1);
	}
	return (0);
}

static int	init_game(t_game *game, int argc, char **argv)
{
	char	*map_content;

	if (argc != 2)
	{
		ft_printf("Error\n Usage: ./so_long <map.ber>\n");
		return (-1);
	}
	map_content = open_and_read_map(argv[1]);
	if (!map_content)
	{
		return (-1);
	}
	if (map_validator_bonus(map_content, game) == -1)
	{
		free(map_content);
		return (-1);
	}
	free(map_content);
	if (init_mlx_window(game) == -1)
	{
		cleanup_game(game);
		return (-1);
	}
	setup_game_bonus(game);
	return (0);
}

void	bonus_init(t_game *game)
{
	game->frame_counter = 0;
	load_player_textures_bonus(game);
	load_enemies_textures_bonus(game);
	mlx_loop_hook(game->mlx_ptr, animate_sprites, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (init_game(&game, argc, argv) == -1)
		return (1);
	bonus_init(&game);
	bonus_init(&game);
	mlx_loop(game.mlx_ptr);
	cleanup_game_bonus(&game);
	return (0);
}
