/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:41:05 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/06 16:43:24 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	research_end(char *s, int c)
{
	char	d;
	int		r;
	char	*p;

	d = (char)c;
	r = 0;
	while (*s)
	{
		if (*s == d)
		{
			p = (char *)s;
			r = 1;
		}
		s++;
	}
	if (r == 1)
		return (1);
	if (*s == c)
	{
		p = (char *)s;
		return (1);
	}
	return (0);
}

int	file_format(char *argv)
{
	char	*format;
	int		i;
	int		k;

	i = 0;
	k = 3;
	format = ".ber";
	while (argv[i])
		i++;
	if (i <= 3)
		return (0);
	while (k >= 0 && argv[i])
	{
		if (argv[i - 1] != format[k])
			return (0);
		k--;
		i--;
	}
	return (1);
}

int	surrounded_by_1(t_param *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (i == 0 || i == g->height - 1 || j == 0 || j == g->width - 1)
			{
				if (g->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	correct_input(char *argv)
{
	char	*i;
	int		fd;
	int		c;
	int		k;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	i = get_next_line(fd);
	if (i == NULL)
		return (0);
	k = 0;
	c = 0;
	while (i)
	{
		while (i[k] != '\n' && i[k])
		{
			if (i[k] == 'E' || i[k] == 'P' || i[k] == '0'
				|| i[k] == 'C' || i[k] == '1')
			{
				if (i[k] == 'P' && c == 0)
					c = 1;
				else if (i[k] == 'P' && c != 0)
					return (0);
				k++;
			}
			else
			{
				free(i);
				return (0);
			}
		}
		free(i);
		i = get_next_line(fd);
	}
	return (1);
}

int	requirement_in(t_param *g)
{
	int	i;
	int	j;
	int	counter_c;
	int	counter_e;
	int	counter_p;

	i = 1;
	counter_c = 0;
	counter_e = 0;
	counter_p = 0;
	while (i < g->height)
	{
		j = 1;
		while (j < (g->width) - 1)
		{
			if (g->map[i][j] == '0' || g->map[i][j] == 'E'
				|| g->map[i][j] == '1' || g->map[i][j] == 'P'
				|| g->map[i][j] == 'C')
			{
				if (g->map[i][j] == 'C')
					counter_c += 1;
				if (g->map[i][j] == 'P')
					counter_p += 1;
				if (g->map[i][j] == 'E')
					counter_e += 1;
			}
			else
				return (0);
			j++;
		}
		i++;
	}
	if (counter_c == 0 || counter_e == 0 || counter_p != 1)
		return (0);
	return (1);
}
