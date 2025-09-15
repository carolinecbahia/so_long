/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:59:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 00:39:18 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *map_reader(int fd)
{
	ssize_t	bytes_read;
	char buffer[BUFFER_SIZE + 1];
	char *map_content;
	char *temp;
	
	map_content = ft_strdup("");
	if (!map_content)
		return (NULL);
	while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(map_content, buffer);
		free(map_content);
		map_content = temp;
		if (!map_content)
			return (NULL);
	}
	if (bytes_read == -1)
	{
		ft_free_and_error(&map_content, "Error\nReading file failed");
		return (NULL);
	}
	return (map_content);
}
