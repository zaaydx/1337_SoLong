/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:33:15 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/05 19:00:12 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(char *str, int fd)
{
	char	*buffer;
	int		byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	byte = 1;
	while (ft_strchr(str, '\n') == NULL && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*storeline(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*deleteline(char *str)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	buf = malloc(ft_strlen(str) - i + 1);
	if (buf == NULL)
		return (NULL);
	i++;
	while (str[i])
		buf[j++] = str[i++];
	buf[j] = '\0';
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = readbuf(str, fd);
	if (str == NULL)
		return (NULL);
	line = storeline(str);
	str = deleteline(str);
	return (line);
}
