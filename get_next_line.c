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

int process_cache()

int	get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
	static char *cache = 0;
	int 		res;

	if (cache)
	{
		res = process_cache(cache, line);
		if (res == 1 || res == -1)
			return (res);
	}
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (endl_in_str(buf))
			*line = str_dup(buf, 0, endl_in_str(buf));
	}
}