//
// Created by mirage on 12.12.2020.
//

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*str_plus_char(char *line, char c)
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

int		get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE + 1];
	static int 	endl = -1;

	*line = malloc(1);
	**line = 0;
	if (endl != -1)
		while (buf[++endl])
		{
			if (buf[endl] == '\n')
				return (1);
			*line = str_plus_char(*line, buf[endl]);
		}
	while (read(fd, buf, BUFFER_SIZE))
	{
		endl = -1;
		buf[BUFFER_SIZE] = 0;
		while (buf[++endl])
		{
			if (buf[endl] == '\n')
				return (1);
			*line = str_plus_char(*line, buf[endl]);
		}
	}
	return (0);
}