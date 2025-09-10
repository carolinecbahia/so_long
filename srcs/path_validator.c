/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:44:05 by ccavalca          #+#    #+#             */
/*   Updated: 2025/09/10 20:45:26 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void find_player_pos(t_map_data *map_data, t_vectors *vectors)
{
    int x;
    int y;

    y = 0;
    while (map_data->matrix[y])
    {
        x = 0;
        while (map_data->matrix[y][x])
        {
            if (map_data->matrix[y][x] == PLAYER)
            {
                vectors->x = x;
                vectors->y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

static void flood_fill(char **map, int x, int y)
{
    if (x < 0 || y < 0 || !map[y] || !map[y][x])
        return ;
    if (map[y][x] == WALL || map[y][x] == VISITED)
        return ;
    map[y][x] = VISITED;
    if (map[y][x] != EXIT)
    {
        flood_fill(map, x + 1, y);
        flood_fill(map, x - 1, y);
        flood_fill(map, x, y + 1);
        flood_fill(map, x, y - 1);
    }
}

int path_validator(t_map_data *data)
{
    char **map_copy;
    t_vector2 player_pos;
    int x;
    int y;

    map_copy = ft_dup_matrix(data->matrix);
    if (!map_copy)
        return (0);
    find_player_pos(data, &player_pos);
    flood_fill(map_copy, player_pos.x, player_pos.y);
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
            {
                ft_free_matrix(map_copy);
                return (0);
            }
            x++;
        }
        y++;
    }
    ft_free_matrix(map_copy);
    return (1);
}