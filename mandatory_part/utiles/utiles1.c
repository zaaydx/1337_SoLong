/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:59:58 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/02 18:44:36 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_walls(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->width)
	{
		if (map->field[0][x] != '1' || map->field[map->height - 1][x] != '1')
		{
			printf("\033[0;33mError\nThe walls are not placed properly!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
	x = -1;
	while (++x < map->height)
	{
		if (map->field[x][0] != '1' || map->field[x][map->width - 1] != '1')
		{
			printf("\033[0;33mError\nThe walls are not placed properly!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
}

static void	checker(t_map *map, int i, int j)
{
	if (map->field[i][j] != '0'
		&& map->field[i][j] != 'P'
		&& map->field[i][j] != '1'
		&& map->field[i][j] != 'C'
		&& map->field[i][j] != 'E')
	{
		printf("\033[0;33mError\nInvalid character in the map!\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	if (map->field[i][j] == 'P')
	{
		map->player++;
		map->posit_x = i;
		map->posit_y = j;
	}
	else if (map->field[i][j] == 'E')
		map->exit++;
	else if (map->field[i][j] == 'C')
		map->collectible++;
}

void	check_map_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			checker(map, i, j);
	}
	if (map->player != 1 || map->exit != 1 || map->collectible == 0)
	{
		if (map->player != 1)
			printf("\033[0;33mError\nNumber of players is inconvenient!\n");
		if (map->exit != 1)
			printf("\033[0;33mError\nThe exit is missing!\n");
		if (map->collectible == 0)
			printf("\033[0;33mError\nNo collectibles in the map!\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
}
