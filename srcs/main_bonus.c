/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:22:51 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:31:43 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char *open_and_read_map_bonus(char *file)
{
	int		fd;
	char	*map_content;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_free_and_error(NULL, strerror(errno)));
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
		return (ft_free_and_error(NULL, "Failed to read map file"));
	return (map_content);
}

static int	init_mlx_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_free_and_error(game->matrix, "mlx_init failed"));
	game->win_ptr = mlx_new_window(
		game->mlx_ptr, 
		game->width * TILE_SIZE, 
		game->height * TILE_SIZE, 
		"So Long Bonus"
	);
	if (!game->win_ptr)
		return (ft_free_and_error(game->matrix, "mlx_new_window failed"));
	return (0);		
}

int	main(int argc, char **argv)
{
	char	*map_content;
	t_game	game;

	if (argc != 2)
		return (ft_free_and_error(NULL, "Usage: ./so_long_bonus <map_file.ber>"));
	map_content = open_and_read_map(argv[1]);
	if (!map_content)
		return (1);
	if (map_validator(map_content, &game) == -1)
	{
		free(map_content);
		return (-1);
	}
	if (init_mlx_window(&game))
	{
		free(map_content);
		return (-1);
	}
	setup_game(&game);
	bonus_textures(&game);
	bonus_init(&game);
	mlx_loop_hook(game.mlx_ptr, animate_sprites, &game);
	mlx_hook(game.wall_img, 17, 0, handle_close, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_matrix(game.matrix);
	free(map_content);
	return (0);
}
