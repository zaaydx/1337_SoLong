/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:48:30 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/02 18:43:49 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_game_path(t_map *map)
{
	map->pict_hero = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/hero_right.xpm", &map->img_width, &map->img_height);
	map->pict_home = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/home.xpm", &map->img_width, &map->img_height);
	map->pict_floor = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/floor.xpm", &map->img_width, &map->img_height);
	map->pict_wall = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/wall.xpm", &map->img_width, &map->img_height);
	map->pict_collect = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/collect.xpm", &map->img_width, &map->img_height);
	map->pict_enemy = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/enemy.xpm", &map->img_width, &map->img_height);
	if (!map->pict_hero || !map->pict_home || !map->pict_floor || \
	!map->pict_wall || !map->pict_collect || !map->pict_enemy)
	{
		perror("\033[0;33mError with xpm files\n");
		free (map->field);
		exit(EXIT_FAILURE);
	}
	map_render(map, -1, -1);
}

void	file_to_img(t_map *map, char *file)
{
	map->pict_enemy = mlx_xpm_file_to_image(map->mlx, \
	file, &map->img_width, &map->img_height);
}

void	update(t_map *map)
{
	if (map->counter >= 0)
		file_to_img(map, "bonus_part/images/enemy.xpm");
	if (map->counter >= 10)
		file_to_img(map, "bonus_part/images/enemy1.xpm");
	if (map->counter >= 20)
		file_to_img(map, "bonus_part/images/enemy2.xpm");
	if (map->counter >= 30)
		file_to_img(map, "bonus_part/images/enemy3.xpm");
	if (map->counter >= 40)
		file_to_img(map, "bonus_part/images/enemy4.xpm");
	if (map->counter >= 50)
		file_to_img(map, "bonus_part/images/enemy5.xpm");
}

int	sprite_game(t_map *map)
{
	map->counter++;
	if (map->counter <= 60)
		update(map);
	else
		map->counter = 0;
	map_render(map, -1, -1);
	return (0);
}
