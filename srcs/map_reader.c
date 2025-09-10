/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:59:52 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/09 22:30:46 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *map_reader(int fd)
{
	ssize_t	bytes_read;
	char buffer[BUFFER_SIZE];
	char *map_content;
	char *temp;
	
	map_content = NULL;
	while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = map_content;
		map_content = ft_strjoin(map_content, buffer);
		free(temp);
		if (!map_content)
			return (NULL);
	}
	if (bytes_read == -1)
	{
		ft_putendl_fd("Error\nReading file failed.", 2);
		if(map_content)
			free(map_content);
		return (NULL);
	}
	return (map_content);
}