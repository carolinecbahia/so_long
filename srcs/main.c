/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:03:58 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/09 00:49:11 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;
	char *map_content;
	
	if (argc != 2)
		return (1);
	fd = open(file_path, O_RDONLY);
	ft_verify_fds(fd);

	map_content = map_reader(fd);
	close (fd);
	if(map_content)
	{
		if(map_validator(map_content) == 0)
		{
			
		}
		else
		{
			
		}
		free(map_content);
	}
	return (0);	
}