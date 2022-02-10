/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:57:08 by zchbani           #+#    #+#             */
/*   Updated: 2022/02/05 17:07:44 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *argv)
{
	int		x;
	char	*extension;

	x = 0;
	while (argv[x])
		x++;
	extension = &(*(argv + x - 4));
	x = 0;
	if (extension[0] == '.' && extension[1] == 'b' \
		&& extension[2] == 'e' && extension[3] == 'r')
		return ;
	else
	{
		printf("\033[0;33mError\nFile extension is missing!\n");
		exit(EXIT_FAILURE);
	}
}
