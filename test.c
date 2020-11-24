//
// Created by mirage on 24.11.2020.
//

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int		fd;
	char	*line;

	fd = open("C:/c/get_next_line/test.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}