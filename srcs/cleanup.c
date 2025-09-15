/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:33:50 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/15 03:09:40 by ccavalca         ###   ########.fr       */
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

int	ft_free_and_error(char **matrix, char *msg)
{
	if (msg)
		ft_putstr(msg);
	ft_putchar('\n');
	if (matrix)
		ft_free_matrix(matrix);
	return (-1);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->wall_img);
	if (game->matrix)
		ft_free_matrix(game->matrix);
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->empty_img)
		mlx_destroy_image(game->mlx_ptr, game->empty_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);	
}
