/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:18:19 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 23:32:19 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define ANIMATION_SPEED 10000
# define ENEMY_SPEED 30000
# define MOVES_BACKGROUND_COLOR #0x000000
# define PLAYER_FRAMES 2

//structs and others
typedef struct s_img 
{
    void    *ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} 	t_img;

typedef struct s_game
{
	char	**matrix;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		width;
	int		height;
	long	moves;
	int		collected;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	player_img;
	int		frame_counter;
	int		player_current_frame;
	t_img	player_frames[PLAYER_FRAMES];
	t_img	wall_img;
	t_img	collectible_img;
	t_img	empty_img;
	t_img	exit_img;
	t_enemy	*enemies;
	int		enemy_count;
	t_img	enemy_img;
}	t_game;

typedef struct s_vectors
{
	int	y;
	int	x;	
}	t_vectors;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	dir_x;
	int	dir_y;
}	t_enemy;

typedef enum e_map_chars
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	VISITED = '2',
	ENEMY = 'X'
}	t_map_chars;

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}	t_keys;

// clean
void	ft_free_matrix(char **matrix);
int		ft_free_and_error(char **matrix, char *msg);
void	cleanup_game(t_game *game);

// map handlers
char	*map_reader(int fd);
int		path_validator(t_game *data);
int		map_validator(char *map_content, t_game *map_data);

// gamerun
int		setup_game(t_game *game);
void	find_player_pos(t_game *map_data, t_vectors *pos);
int		move_player(t_game *game, t_vectors *pos, int new_x, int new_y);
int		handle_key(int keycode, t_game *game);
int		handle_close(t_game *game);
int 	move_up(t_game *game);
int 	move_down(t_game *game);
int 	move_left(t_game *game);
int 	move_right(t_game *game);

// render
int		load_base_textures(t_game *game);
int		load_sprite_textures(t_game *game);
void	draw_map(t_game *game);

// gamerun bonus
int		animate_sprites(t_game *game);
void	move_enemies(t_game *game);
void	display_moves(t_game *game);

#endif