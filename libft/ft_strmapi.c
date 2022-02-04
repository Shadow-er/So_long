/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:35:17 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/09 15:08:55 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static int	t_len(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		j;

	if (s == '\0')
		return (0);
	i = t_len(s) + 1;
	p = (char *)malloc(sizeof(char) * i);
	if (p == 0)
		return (0);
	j = 0;
	while (j < i - 1)
	{
		p[j] = f(j, s[j]);
		j++;
	}
	p[j] = '\0';
	return (p);
}
