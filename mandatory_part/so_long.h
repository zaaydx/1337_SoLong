/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:39:11 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:45:40 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	void	*pict_hero;
	void	*pict_home;
	void	*pict_floor;
	void	*pict_wall;
	void	*pict_collect;
	void	*pict_enemy;
	void	*pict_back;
	char	**field;
	int		player;
	int		exit;
	int		height;
	int		width;
	int		moves;
	int		img_height;
	int		img_width;
	int		posit_x;
	int		posit_y;
	int		collectible;
}	t_map;

/* utiles1.c File */
void	check_map_content(t_map *map);
void	check_walls(t_map *map);

/* utiles2.c File */
void	set_game_path(t_map *map);
int		sprite_game(t_map *map);

/* utiles3.c File */
int		key_hook(int key_code, t_map *map);
int		free_window(t_map *map);

/* utiles4.c File */
void	moves_of_player(t_map *map, int i, int j);

/* utiles5.c File */
void	map_render(t_map *map, int i, int j);

/* extension.c File */
void	check_extension(char *argv);

/* good_map.c File */
void	good_map(t_map *map, int fd, char *argv);

#endif
