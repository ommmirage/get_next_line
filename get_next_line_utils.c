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

char	*str_dub(char *src, int start, int end)
{
	char	*dst;

	dst = malloc(end - start + 1);
	if (!dst)
		return (NULL);
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (dst);
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