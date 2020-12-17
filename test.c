//
// Created by mirage on 24.11.2020.
//

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int		fd;
	int 	fd_out;
	char	*line;

//	fd = open("/mnt/c/c/get_next_line/test.txt", O_RDONLY);
	fd = open("C:/c/get_next_line/test.txt", O_RDONLY);
//	fd = open("C:/C/gnl-war-machine/tests/Mr._Justice_Maxell_by_Edgar_Wallace.txt", O_RDONLY);
//	fd = open("C:/c/get_next_line/42TESTERS-GNL/files/alphabet", O_RDONLY);

//	fd = open("/Users/dechanel/get_next_line/test.txt", O_RDONLY);
//	fd = open("/Users/dechanel/GNL_lover/test_files_GNL/test_file7", O_RDONLY);
//	fd = open("/Users/dechanel/get_next_line/42TESTERS-GNL/files/empty_lines", O_RDONLY);
//	fd = open("/Users/dechanel/gnl-war-machine-v2019/tests/void.txt",
//		   O_RDONLY);

	fd_out = open("C:/C/get_next_line/out.txt", O_RDWR | O_CREAT |  O_TRUNC, 0644);

	char	buf[BUFFER_SIZE];
	printf("%d\n", read(180, buf, 50));

	while (get_next_line(fd, &line))
	{
		printf("line: %s\n", line);
		write(fd_out, line, str_len(line));
		write(fd_out, "\n", 1);
		free(line);
	}
	printf("line: %s", line);
//	write(fd_out, line, str_len(line));
	free(line);
	close(fd);
//	close(fd_out);
}