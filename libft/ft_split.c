/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:14:28 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/03 11:36:58 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isset(char str, char Setter)
{
	if (Setter == str)
		return (1);
	return (0);
}

static int	nbrlen(char *str, char charset)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i])
	{
		while (ft_isset(str[i], charset) == 1)
			i++;
		if (str[i])
			l++;
		while (ft_isset(str[i], charset) == 0 && str[i])
			i++;
	}
	return (l);
}

static int	wl(char *str, char charset)
{
	int	j;

	j = 0;
	while (str[j] && ft_isset(str[j], charset) == 0)
		j++;
	return (j);
}

static char	**ft_fill(char *str, char charset, int k, char **s)
{
	int	j;
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isset(str[i], charset) == 1)
			i++;
		if (str[i])
		{
			j = 0;
			s[k] = (char *)malloc((wl(&str[i], charset) + 1) * sizeof(char));
			if (s[k] == 0)
			{
				while (j <= k)
					free(s[j++]);
				return (0);
			}
			while (str[i] && ft_isset(str[i], charset) == 0)
				s[k][j++] = str[i++];
			s[k++][j] = '\0';
		}
	}
	s[k] = 0;
	return (s);
}

char	**ft_split(char *str, char charset)
{
	char	**bigm;
	int		i;

	if (!str)
		return (0);
	i = nbrlen(str, charset);
	bigm = (char **)malloc((i + 1) * (sizeof(char *)));
	if (bigm == 0)
		return (0);
	ft_fill(str, charset, 0, bigm);
	if (!bigm)
	{
		free(bigm);
		return (NULL);
	}
	return (bigm);
}
