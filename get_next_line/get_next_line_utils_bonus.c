/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:38:12 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 16:56:45 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < p && p < s + len)
	{
		s = s + len;
		p = p + len;
		while (len--)
			*--p = *--s;
	}
	else
	{
		while (len--)
			*p++ = *s++;
	}	
	return (dst);
}

char	*ft_strdup(char *s1)
{
	unsigned int	r;
	unsigned int	i;
	char			*dst;

	r = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (r + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

unsigned int	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	j;

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
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char				*i;
	unsigned int		len1;
	unsigned int		len2;
	unsigned int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 && s2 == 0)
		return (ft_strdup(s1));
	if (s1 == 0 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	j = len1 + len2 + 1;
	i = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (i == 0)
		return (0);
	ft_strlcpy(i, s1, len1 + 1);
	ft_strlcpy(i + len1, s2, len2 + 1);
	i[j - 1] = '\0';
	return (i);
}

char	*ft_launch(char **s, int fd)
{
	char	*a;
	char	*b;
	int		j;

	j = 0;
	if (s[fd] == 0)
		return (0);
	while (s[fd][j] != '\n' && s[fd][j])
		j++;
	a = ft_substr(s[fd], 0, j + 1);
	b = ft_substr(s[fd], j + 1, ft_strlen(s[fd]) - j);
	free(s[fd]);
	if (b[0] == '\0')
	{
		s[fd] = NULL;
		free(b);
	}
	else
		s[fd] = b;
	return (a);
}
