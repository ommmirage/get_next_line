//
// Created by mirage on 24.11.2020.
//

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int		fd;
	int 	fd_out;
	char	*line;

	fd = open("C:/c/get_next_line/test.txt", O_RDONLY);
//	fd = open("C:/c/get_next_line/42TESTERS-GNL/files/alphabet", O_RDONLY);

//	fd = open("/Users/dechanel/get_next_line/test.txt", O_RDONLY);
//	fd = open("/Users/dechanel/GNL_lover/test_files_GNL/test_file1", O_RDONLY);
//	fd = open("/Users/dechanel/get_next_line/42TESTERS-GNL/files/empty_lines", O_RDONLY);
//	fd = open("/Users/dechanel/gnl-war-machine-v2019/tests/void.txt",
//		   O_RDONLY);

//	fd_out = open("/Users/dechanel/get_next_line/out", O_RDWR | O_CREAT |  O_TRUNC, 0644);
	while (get_next_line(fd, &line))
	{
		printf("line: %s\n", line);
//		write(fd_out, line, str_len(line));
//		write(fd_out, "\n", 1);
		free(line);
	}
	printf("line: %s", line);
//	write(fd_out, line, str_len(line));
	free(line);
	close(fd);
//	close(fd_out);
}