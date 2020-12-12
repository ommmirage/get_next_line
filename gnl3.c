//
// Created by Dewitt Chanell on 12/3/20.
//

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int 	new_endl_in_buf(const char *buf, int endl)
{
	while (buf[++endl])
	{
		if (buf[endl] == '\n')
			return (1);
	}
	return (0);
}

char	*str_before_endl(const char *src, int *endl)
{
	char	*res;
	int		i;

	res = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (src[++(*endl)])
	{
		if (src[*endl] == '\n')
		{
			res[i] = 0;
			return (res);
		}
		res[i] = src[*endl];
		i++;
	}
	res[i] = 0;
	*endl = -1;
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE + 1];
	static int 	endl = -1;

	*line = malloc(1);
	**line = 0;
	if (endl != -1)
	{
		*line = str_join(*line, str_before_endl(buf, &endl));
		if (endl != -1)
			return (1);
	}
	while (read(fd, buf, BUFFER_SIZE))
	{
		buf[BUFFER_SIZE] = 0;
		if (new_endl_in_buf(buf, endl))
		{
			*line = str_join(*line, str_before_endl(buf, &endl));
			return (1);
		}
		*line = str_join(*line, str_before_endl(buf, &endl));
	}
	return (0);
}