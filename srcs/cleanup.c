/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:33:50 by ccavalca          #+#    #+#             */
/*   Updated: 2025/11/30 17:45:17 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_matrix(char **matrix)
{
	int	y;

	y = 0;
	if (!matrix)
		return ;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_ptr)
	{
		if (game->wall_img.ptr)
			mlx_destroy_image(game->mlx_ptr, game->wall_img.ptr);
		if (game->empty_img.ptr)
			mlx_destroy_image(game->mlx_ptr, game->empty_img.ptr);
		if (game->player_img.ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_img.ptr);
		if (game->collectible_img.ptr)
			mlx_destroy_image(game->mlx_ptr, game->collectible_img.ptr);
		if (game->exit_img.ptr)
			mlx_destroy_image(game->mlx_ptr, game->exit_img.ptr);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
	}
	if (game->matrix)
		ft_free_matrix(game->matrix);
}
