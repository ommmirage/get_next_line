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

#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int 	free_tail_res(char *tail, int *res, int need_to_free_tail)
{
	int r;

	r = *res;
	free(res);
	if (tail && need_to_free_tail)
		free(tail);
	return (r);
}

char 	*join_strings(const char *s1, const char *s2)
{
	char	*res;
	char	*res2;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char))))
		return (NULL);
	res2 = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (res2);
}

void 	cat_line(char **line, char *src, char **tail, int len, int *res)
{
	char	*new_line;

	if (!(new_line = get_new_line(src, tail, len, res)))
	{
		*res = -1;
		return ;
	}
	if (!(*line = join_strings(*line, new_line)))
	{
		free(new_line);
		*res = -1;
		return ;
	}
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE];
	int			len;
	static char	*tail = 0;
	int 		*res;

	*line = malloc(sizeof(char));
	**line = 0;
	res = malloc(sizeof(int));
	*res = 0;
	if (tail)
		cat_line(line, tail, &tail, str_len(tail), res);
	if (*res == 1 || *res == -1)
		return (free_tail_res(tail, res, 1));
	while ((len = read(fd, buf, BUFFER_SIZE)))
	{
		cat_line(line, buf, &tail, len, res);
		if (*res == 1 || *res == -1)
			return (free_tail_res(tail, res, 0));
	}
	free_tail_res(tail, res, 1);
	return (0);
}
