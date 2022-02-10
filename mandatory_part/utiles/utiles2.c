/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:48:30 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/02 18:44:46 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_game_path(t_map *map)
{
	map->pict_hero = mlx_xpm_file_to_image(map->mlx, \
	"mandatory_part/images/hero_right.xpm", &map->img_width, &map->img_height);
	map->pict_home = mlx_xpm_file_to_image(map->mlx, \
	"mandatory_part/images/home.xpm", &map->img_width, &map->img_height);
	map->pict_floor = mlx_xpm_file_to_image(map->mlx, \
	"mandatory_part/images/floor.xpm", &map->img_width, &map->img_height);
	map->pict_wall = mlx_xpm_file_to_image(map->mlx, \
	"mandatory_part/images/wall.xpm", &map->img_width, &map->img_height);
	map->pict_collect = mlx_xpm_file_to_image(map->mlx, \
	"mandatory_part/images/collect.xpm", &map->img_width, &map->img_height);
	if (!map->pict_hero || !map->pict_home || !map->pict_floor || \
	!map->pict_wall || !map->pict_collect)
	{
		perror("\033[0;33mError with xpm files\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}
