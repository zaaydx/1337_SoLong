/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:41:20 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:42:48 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init(t_map *map)
{
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	map->height = 0;
	map->width = 0;
	map->posit_x = 0;
	map->posit_y = 0;
	map->moves = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc == 2)
	{
		check_extension(argv[1]);
		fd = open (argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("\033[0;33mError\ncan't open the map file!\n");
			exit(EXIT_FAILURE);
		}
		map_init(&map);
		good_map(&map, fd, argv[1]);
		map.mlx = mlx_init();
		map.mlx_win = mlx_new_window(map.mlx, map.width * 48, \
		map.height * 48, "so_long");
		set_game_path(&map);
		mlx_hook(map.mlx_win, 17, 0, free_window, &map);
		mlx_hook(map.mlx_win, 2, (1L << 0), key_hook, &map);
		mlx_loop(map.mlx);
	}
}
