/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 06:40:21 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 10:31:00 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static size_t	ft_strln(const char *str)
{
	size_t	count;

	count = 0;
	while (*(str + count) != '\0')
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;

	j = 0;
	if (size != 0)
	{
		while (j < size - 1 && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (ft_strln(src));
}
