/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:50:17 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:52:15 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	exit_game(t_map *map, int i)
{
	if (i == 0)
		printf ("\033[0;33mWE GOT A WINNER!\n");
	else if (i == 1)
		printf ("\033[0;33mWE GOT A LOSER!\n");
	free (map->field);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (EXIT_SUCCESS);
}

void	moves_of_player(t_map *map, int i, int j)
{
	if (map->field[map->posit_x + i][map->posit_y + j] != '1')
	{
		if (map->field[map->posit_x + i][map->posit_y + j] == 'C')
			map->collectible--;
		else if (map->field[map->posit_x + i][map->posit_y + j] == 'E' \
				&& map->collectible == 0)
			exit_game(map, 0);
		else if (map->field[map->posit_x + i][map->posit_y + j] == 'E' \
				&& map->collectible != 0)
			return ;
		else if (map->field[map->posit_x + i][map->posit_y + j] == 'A')
			exit_game(map, 1);
		else if (map->collectible == 0)
		{
			map->pict_home = mlx_xpm_file_to_image(map->mlx, \
			"bonus_part/images/home2.xpm", &map->img_width, &map->img_height);
		}
		map->moves++;
		map->field[map->posit_x + i][map->posit_y + j] = 'P';
		map->field[map->posit_x][map->posit_y] = '0';
		map->posit_x += i;
		map->posit_y += j;
		map_render(map, -1, -1);
	}
}
