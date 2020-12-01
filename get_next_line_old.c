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
#include "get_next_line_old.h"
#include <stdlib.h>

int 	free_all(char *tail, int *res, char *buf, int need_to_free_tail)
{
	int r;

	r = *res;
	free(res);
	free(buf);
	if (tail && need_to_free_tail)
		free(tail);
	return (r);
}

char 	*join_strings(char *s1, char *s2)
{
	char	*res;
	char	*res2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char))))
		return (NULL);
	res2 = res;
	i = 0;
	while (s1[i])
	{
		*res++ = s1[i];
		i++;
	}
	free(s1);
	i = 0;
	while (s2[i])
		*res++ = s2[i++];
	free(s2);
	*res = 0;
	return (res2);
}

void 	cat_line(char **line, char *src, char **tail, int src_len, int *res)
{
	char	*new_line;

	if (!(new_line = get_new_line(src, tail, src_len, res)))
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
	char		*buf;
	int			len;
	static char	*tail = 0;
	int 		*res;

	buf = malloc(BUFFER_SIZE + 1);
	*line = malloc(sizeof(char));
	**line = 0;
	res = malloc(sizeof(int));
	*res = 0;
	if (tail)
		cat_line(line, tail, &tail, str_len(tail), res);
	if (*res == 1 || *res == -1)
		return (free_all(tail, res, buf, !*tail));
	while ((len = read(fd, buf, BUFFER_SIZE)))
	{
		buf[len] = 0;
		cat_line(line, buf, &tail, len, res);
		free(buf);
		buf = malloc(BUFFER_SIZE + 1);
		if (*res == 1 || *res == -1)
			return (free_all(tail, res, buf, 0));
	}
	free_all(tail, res, buf, 1);
	return (0);
}
