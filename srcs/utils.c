/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:17:32 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/11 01:21:02 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	ft_free_and_error(char **matrix, char *msg)
{
	if (matrix)
		ft_free_matrix(matrix);
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(msg, 2);
    return (-1);
}