/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
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

int endl_in_str(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	return (i);
}

int	process_cache(char **cache, char **line)
{
	if (endl_in_str(*cache))
	{
		if (!(*line = str_dub(*cache, 0, endl_in_str(*cache))))
			return (-1);
		*cache = str_dub(*cache, endl_in_str(*cache) + 1, BUFFER_SIZE);
		if (!*cache)
			return (-1);
	}
	else
	{
		if (!(*line = str_dub(*cache, 0, BUFFER_SIZE)))
			return (-1);
		**cache = 0;
		return (0);
	}
	return (1)
}

int	get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
	static char *cache;
	int 		res;

	if (!cache)
		cache = malloc(BUFFER_SIZE);
	res = process_cache(&cache, line);
	if (res == 1 || res == -1)
		return (res);
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (endl_in_str(buf))
		{
			*line = str_dub(buf, 0, endl_in_str(buf));
			cache = str_dub(cache, endl_in_str(cache) + 1, BUFFER_SIZE);
		}
	}
}