//
// Created by Dewitt Chanell on 12/3/20.
//

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE];
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

	}
}