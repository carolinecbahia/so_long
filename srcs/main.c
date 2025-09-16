/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:11:34 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*open_and_read_map(char *file)
{
	int		fd;
	char	*map_content;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error",2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
	{
		ft_putendl_fd("Error",2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	return (map_content);
}

static int	init_mlx_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->matrix);
		ft_printf("Error.\nInit matrix failed");
		return (-1);
	}
	game->win_ptr = mlx_new_window(
		game->mlx_ptr, 
		game->width * TILE_SIZE, 
		game->height * TILE_SIZE, 
		"So Long"
	);
	if (!game->win_ptr)
	{
		cleanup_game(game);
		ft_printf("Error.\nInit window failed");
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
		return (-1);
	if (map_validator(map_content, game) == -1)
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
	setup_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	ft_bzero(&game, sizeof(t_game));
	if (init_game(&game, argc, argv) == -1)
		return (1);
	mlx_loop(game.mlx_ptr);
	cleanup_game(&game);
	return (0);
}
