/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:13:31 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/01 15:41:57 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_organization(t_map *map)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map->field[++i])
	{
		j = -1;
		len = 0;
		while (map->field[i][++j] != '\n' && map->field[i][j])
			len++;
		if (len != map->width)
		{
			printf("\033[0;33mError\nUnorganized map!\n");
			free (map->field);
			exit(EXIT_FAILURE);
		}
	}
}

void	good_map(t_map *map, int fd, char *argv)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		map->height++;
	if (close(fd) == -1)
	{
		perror("\033[0;33mError\nCan't close the file!\n");
		exit(EXIT_FAILURE);
	}
	map->field = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->field)
		exit(EXIT_FAILURE);
	fd = open(argv, O_RDONLY);
	while (i < map->height)
		map->field[i++] = get_next_line(fd);
	close (fd);
	i = 0;
	while (i < map->field[0][i])
		i++;
	map->width = i;
	map->field[map->height] = 0;
	check_organization(map);
	check_walls(map);
	check_map_content(map);
}
