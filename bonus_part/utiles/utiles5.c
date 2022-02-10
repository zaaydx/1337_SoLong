/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:03:12 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:53:03 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	img_size(t_map *map, int i, int j, void *img_ptr)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	img_ptr, j * 48, i * 48);
}

static void	show_moves(t_map *map)
{
	char	str[10];

	sprintf(str, "%d", map->moves);
	map->pict_back = mlx_xpm_file_to_image(map->mlx, \
	"bonus_part/images/back.xpm", &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->pict_back, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 6, 6, 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx, map->mlx_win, 70, 6, 0xFFFFFF, str);
}

void	map_render(t_map *map, int i, int j)
{
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->field[i][j] == '1')
				img_size(map, i, j, map->pict_wall);
			else
			{
				img_size(map, i, j, map->pict_floor);
				if (map->field[i][j] == 'P')
					img_size(map, i, j, map->pict_hero);
				else if (map->field[i][j] == 'C')
					img_size(map, i, j, map->pict_collect);
				else if (map->field[i][j] == 'E')
					img_size(map, i, j, map->pict_home);
				else if (map->field[i][j] == 'A')
					img_size(map, i, j, map->pict_enemy);
			}
		}
	}
	show_moves(map);
}
