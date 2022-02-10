/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:31:10 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:48:42 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	free_window(t_map *map)
{
	free (map->field);
	mlx_destroy_window(map->mlx, map->mlx_win);
	printf("\033[0;33mwindow closed\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int key_code, t_map *map)
{
	if (key_code == ESC)
		free_window(map);
	else if (key_code == A)
	{
		map->pict_hero = mlx_xpm_file_to_image(map->mlx, \
		"bonus_part/images/hero_left.xpm", \
		&map->img_width, &map->img_height);
		moves_of_player(map, 0, -1);
	}
	else if (key_code == W)
		moves_of_player(map, -1, 0);
	else if (key_code == D)
	{
		map->pict_hero = mlx_xpm_file_to_image(map->mlx, \
		"bonus_part/images/hero_right.xpm", \
		&map->img_width, &map->img_height);
		moves_of_player(map, 0, 1);
	}
	else if (key_code == S)
		moves_of_player(map, 1, 0);
	return (0);
}
