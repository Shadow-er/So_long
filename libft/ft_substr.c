/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:59:35 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 08:00:05 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static unsigned int	length(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strndup(const char *src, size_t n)
{
	unsigned int	r;
	unsigned int	i;
	char			*dst;

	r = length(src);
	dst = (char *)malloc(sizeof(char) * (n + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (src[i] && n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == '\0')
		return (0);
	if (start >= length(s))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = ft_strndup(s + start, len);
	return (str);
}
