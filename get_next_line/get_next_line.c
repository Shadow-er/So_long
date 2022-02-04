/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:11:18 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/04 11:38:35 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strcr(char *str, int c)
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

unsigned int	ft_strln(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_subsr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s == '\0')
		return (0);
	if (start >= ft_strln(s))
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
		if (!(*s))
			*s = ft_strdp(buffer);
		else
		{
			temp[0] = ft_strjon(*s, buffer);
			free(*s);
			*s = temp[0];
		}
		if (ft_strcr(*s, '\n'))
			break ;
	}
	free(buffer);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buffer;
	char		*temp;
	int			i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
	{
		return (0);
	}
	i = gnl(&s, &temp, buffer, fd);
	if (i < 0)
		return (NULL);
	return (ft_launch(&s));
}
