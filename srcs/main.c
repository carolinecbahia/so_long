/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 02:36:57 by ccavalca         ###   ########.fr       */
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

static int	init_mlx_window(t_game *map_data)
{
	map_data->mlx_ptr = mlx_init();
	if (!map_data->mlx_ptr)
		return (ft_free_and_error(map_data->matrix, "mlx_init failed"));
	map_data->win_ptr = mlx_new_window(
		map_data->mlx_ptr, 
		map_data->width * TILE_SIZE, 
		map_data->height * TILE_SIZE, 
		"So Long"
	);
	if (!map_data->win_ptr)
		return (ft_free_and_error(map_data->matrix, "mlx_new_window failed"));
	return (0);		
}

int	main(int argc, char **argv)
{
	char	*map_content;
	t_game	map_data;

	if (argc != 2)
		return (ft_free_and_error(NULL, "Usage: ./so_long <map_file.ber>"));
	map_content = open_and_read_map(argv[1]);
	if (!map_content)
		return (1);
	if (map_validator(map_content, &map_data) == -1)
	{
		free(map_content);
		return (-1);
	}
	if (init_mlx_window(&map_data))
	{
		free(map_content);
		return (-1);
	}
	setup_game(&map_data);
	mlx_loop(map_data.mlx_ptr);
	ft_free_matrix(map_data.matrix);
	free(map_content);
	return (0);
}
