/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carol <carol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:59:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/10/26 01:09:54 by carol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_reader(int fd)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*map_content;
	char	*temp;

	map_content = ft_strdup("");
	if (!map_content)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(map_content, buffer);
		free(map_content);
		map_content = temp;
		if (!map_content)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		ft_printf("Error\nReading file failed\n");
		return (NULL);
	}
	return (map_content);
}

char	*open_and_read_map(char *file)
{
	int		fd;
	char	*map_content;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	map_content = map_reader(fd);
	close (fd);
	if (!map_content)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Failed to read map file", 2);
		return (NULL);
	}
	return (map_content);
}
