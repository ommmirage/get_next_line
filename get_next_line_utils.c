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

#include <stdlib.h>
#include <stdio.h>

int		str_len(const char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int 	len_to_endl(const char *src, int len)
{
	int res;

	res = 0;
	while (*src++ != '\n' && len--)
		res++;
	return (res);
}

int 	write_tail(char **tail, char *src, char *new_line, int tail_len)
{
	int i;

	if (*tail)
		free(*tail);
	if (!(*tail = malloc(str_len(src) + 1)))
	{
		free(new_line);
		return (0);
	}
	i = 0;
	/*
	 * пропускаем первый '/n'
	 */
	src++;
	while (i < tail_len)
		(*tail)[i++] = *src++;
	(*tail)[i] = 0;
	return (1);
}

char	*get_new_line(char *src, char **tail, int src_len, int *res)
{
	char	*new_line;
	int 	line_len;
	int 	i;

	line_len = len_to_endl(src, src_len);
	if (!(new_line = (char *)malloc( sizeof(char) * (line_len + 1))))
	{
		*res = -1;
		return (NULL);
	}
	i = 0;
	while (i < line_len)
		new_line[i++] = *src++;
	new_line[i] = 0;
	if (*src == '\n')
	{
		*res = 1;
		if (!write_tail(tail, src, new_line, src_len - line_len))
		{
			free(new_line);
			*res = -1;
			return (NULL);
		}
	}
	return (new_line);
}