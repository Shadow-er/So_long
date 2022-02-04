/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:29:16 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 08:30:51 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strln(char *str, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dstsize > 0 && str[i])
	{
		i++;
		dstsize--;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	k;
	size_t	i;
	size_t	j;

	j = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = ft_strln(dst, dstsize);
	k = ft_strlen(src);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (*src && j < dstsize - i - 1)
	{
		*(dst + i) = *src;
		dst++;
		src++;
		j++;
	}
	*(dst + i) = '\0';
	return (i + k);
}
