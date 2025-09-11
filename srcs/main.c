/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/11 01:27:27 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;
	char *map_content;
	t_map_data	map_data;
	
	if (argc != 2)
		return (ft_free_and_error(NULL, "Usage: ./so_long <map_file.ber>"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_free_and_error(NULL, strerror(errno)));
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
		return (ft_free_and_error(NULL, "Failed to read map file"));
	if (map_validator(map_content, &map_data) == -1)
	{
		free(map_content);
		return (-1);
	}
	//TODO map_data.mlx = mlx_init();
	//TODO map_data.window = (mlx_new_window(map_data.mlx, 
	//TODO map_data.width * TILE_SIZE, map_data.height * TILE_SIZE, "So Long"));
	//TODO setup_game(&map_data);
	//TODO mlx_loop(map_data.mlx);
	ft_free_matrix(map_data.matrix);
	free(map_content);
	return (0);	
}
