/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/11 01:14:47 by ccavalca         ###   ########.fr       */
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
	if (ft_verify_fds(fd, argv[1]) == -1)
		return (-1);
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
		return (ft_free_and_error(NULL, "Failed to read map file"));
	if (map_validator(map_content, &map_data) == -1)
		return (-1);

	//TODO start_game(&map_data);
	
	ft_free_matrix(map_data.matrix);
	free(map_content);
	return (0);	
}