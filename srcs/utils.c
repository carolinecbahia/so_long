/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:17:32 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/08 21:19:35 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_fds(int fd, const char *path)
{
	if (fd == -1)
	{
		ft_putchar_fd("Error", 2);
		ft_putstr_fd("Could not open file:", 2);
		ft_putendl_fd(path, 2);
		exit(EXIT_FAILURE);
	}
	return(fd);
}