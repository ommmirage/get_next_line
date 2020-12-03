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

int endl_in_str(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	save_cache(char **cache, const char *src, int start)
{
	int i;
	
	i = 0;
	while (src[start])
		(*cache)[i++] = src[start++];
	(*cache)[i] = 0;
	return (1);
}

int	process_cache(char **cache, char **line)
{
	if (endl_in_str(*cache) == -1)
	{
		if (!(*line = str_dub(*cache, 0, BUFFER_SIZE)))
			return (-1);
		**cache = 0;
		return (0);
	}
	else
	{
		if (!(*line = str_dub(*cache, 0, endl_in_str(*cache))))
			return (-1);
		save_cache(cache, *cache, endl_in_str(*cache) + 1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
	static char *cache;
	int 		res;

	*line = malloc(1); // лик
	**line = 0;
	if (!cache)
		cache = malloc(BUFFER_SIZE);
	else
	{
		res = process_cache(&cache, line);
		if (res == 1 || res == -1)
			return (res);
	}
	while (read(fd, buf, BUFFER_SIZE))
		if (endl_in_str(buf) == -1)
			*line = str_join(*line, str_dub(buf, 0, BUFFER_SIZE));
		else
		{
			if (!(*line = str_join(*line, str_dub(buf, 0, endl_in_str(buf)))))
				return (-1);
			return (save_cache(&cache, buf, endl_in_str(buf) + 1));
		}
	return (0);
}