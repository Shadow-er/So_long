/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:02:47 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/08 11:27:09 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*p;

	s = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*s == *p && i < n - 1 && *s && *p)
	{
		i++;
		s++;
		p++;
	}
	return (*s - *p);
}
