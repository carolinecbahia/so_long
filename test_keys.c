/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:55:39 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/14 20:02:13 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

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

int	handle_key(int keycode, void *param)
{
	(void)param;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "Key Test");
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
