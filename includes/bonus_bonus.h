/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:18:19 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 19:49:26 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_BONUS_H
# define BONUS_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define BUFFER_SIZE 42
# define TILE_SIZE 32

//structs and others
typedef struct s_game
{
	char	**matrix;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		width;
	int		height;
	int		moves;
	int		collected;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*empty_img;
	void	*exit_img;
	int		frames;
}			t_game;

typedef struct s_vectors
{
	int	y;
	int	x;
}	t_vectors;

typedef enum e_map_chars
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	VISITED = 'X'
}	t_map_chars;

// utils
int		ft_verify_fds(int fd, const char *path);
void	ft_free_matrix(char **matrix);
int		ft_free_and_error(char **matrix, char *msg);

// map handlers
char	*map_reader(int fd);
int		path_validator(t_game *data);
int		map_validator(char *map_content, t_game *map_data);

// gamerun

// graphics

#endif