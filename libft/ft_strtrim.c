/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:28:19 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 07:59:43 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static int	isset(char const str, char const *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == str)
			return (1);
		j++;
	}
	return (0);
}

static int	t_len(char const *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (*p)
	{
		p++;
		i++;
	}
	return (i);
}

static int	ft_trimb(char const *s, char const *set)
{
	int	j;

	j = 0;
	while (s[j] && isset(s[j], set) == 1)
		j++;
	return (j);
}

static int	ft_trime(char const *s, char const *set, int begin)
{
	int	j;
	int	r;

	j = t_len(s) - 1;
	r = 0;
	while (s[j] && isset(s[j], set) == 1 && j > begin)
	{
		j--;
		r++;
	}
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == '\0')
		return (0);
	k = ft_trimb(s1, set);
	i = t_len(s1) - ft_trime(s1, set, k) - ft_trimb(s1, set) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (str == 0)
		return (0);
	j = 0;
	while (j < i - 1)
	{
		str[j] = s1[k];
		k++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
