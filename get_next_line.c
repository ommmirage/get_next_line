/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dechanel <ommmirage@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:57:10 by dechanel          #+#    #+#             */
/*   Updated: 2020/10/28 15:06:52 by dechanel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	str_len(const char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

static char	*str_plus_char(char *line, char c)
{
	char	*nl;
	int		i;

	nl = malloc(str_len(line) + 2);
	i = -1;
	while (line[++i])
		nl[i] = line[i];
	nl[i] = c;
	nl[++i] = 0;
	free(line);
	return (nl);
}

static int	clear_buf(char (*buf)[BUFFER_SIZE])
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		(*buf)[i++] = 0;
	return (1);
}

static void add_symbols_before_endl(char **line, int *endl, char *buf)
{
	while (++(*endl) < BUFFER_SIZE && buf[*endl])
	{
		if (buf[*endl] == '\n')
			return (1);
		*line = str_plus_char(*line, buf[endl]);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE];
	static int	endl = -1;

	if (BUFFER_SIZE < 1)
		return (-1);
	*line = malloc(1);
	**line = 0;
	if (endl != -1)
		add_symbols_before_endl(line, &endl, buf);
	while (clear_buf(&buf) && read(fd, buf, BUFFER_SIZE))
	{
		endl = -1;
		while (++endl < BUFFER_SIZE && buf[endl])
		{
			if (buf[endl] == '\n')
				return (1);
			*line = str_plus_char(*line, buf[endl]);
		}
	}
	return (0);
}
