/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:37:34 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/10 20:50:08 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE=42

//structs and others
typedef struct s_map_data
{
	char	**matrix;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		width;
	int		height;
}	t_map_data;

typedef struct s_vectors
{
	int y;
	int x;	
}	t_vectors;

typedef enum e_map_chars
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_map_chars;

// utils
int		ft_verify_fds(int fd, const char *path);

// map handlers
char	*map_reader(int fd);
int		path_validator(t_map_data *data);
int		map_validator(char *map_content, t_map_data *map_data);

// gamerun

// graphics

#endif