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

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*str_join(char *s1, char *s2)
{
	char	*res;
	char	*res2;
	int		i;

	if (!(res = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char))))
		return (NULL);
	res2 = res;
	i = 0;
	while (s1[i])
		*res++ = s1[i++];
	free(s1);
	i = 0;
	while (s2[i])
		*res++ = s2[i++];
	free(s2);
	*res = 0;
	return (res2);
}
