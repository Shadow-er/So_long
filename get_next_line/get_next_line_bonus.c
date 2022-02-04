/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:37:16 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 17:03:17 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*ft_strchr(char *str, int c)
{
	char	*d;

	c = (char)c;
	while (*str)
	{
		if (*str == c)
		{
			d = (char *)str;
			return (d);
		}
		str++;
	}
	if (*str == c)
	{
		d = (char *)str;
		return (d);
	}
	return (0);
}

unsigned int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s == '\0')
		return (0);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s[start + i] && len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

int	gnl(char **s, char **temp, char *buffer, int fd)
{
	int	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buffer);
		else
		{
			temp[0] = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = temp[0];
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buffer);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	char		*buffer;
	char		*temp;
	int			i;

	if (fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
	{
		return (0);
	}
	i = gnl(s, &temp, buffer, fd);
	if (i < 0)
		return (NULL);
	return (ft_launch(s, fd));
}
