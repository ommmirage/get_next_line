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
#include <stdlib.h>

int		str_len(const char *str)
{
	int len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*str_dub(const char *src, int start, int end)
{
	char	*dst;
	int 	i;

	dst = malloc(BUFFER_SIZE + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = src[start++];
	dst[i] = 0;
	return (dst);
}

char	*str_join(char *s1, char *s2)
{
	char	*res;
	char	*res2;
	int		i;

	if (!(res = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char))))
		return (NULL);
	res2 = res;
	if (s1 != NULL)
	{
		i = 0;
		while (s1[i])
			*res++ = s1[i++];
		free(s1);
	}
	i = 0;
	while (s2[i])
		*res++ = s2[i++];
	free(s2);
	*res = 0;
	return (res2);
}

char	*cache_dub(char *src, int start)
{
	char	*dst;
	int 	i;

	dst = malloc(BUFFER_SIZE - start + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
		*dst++ = src[i++];
	free(src);
	*dst = 0;
	return (dst);
}