/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:20:19 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 10:16:17 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	res(int *p, size_t *j, size_t len)
{
	*p = 0;
	*j = len + 1;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*i;
	int		j;
	int		k;
	size_t	p;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + j) && len-- > 0)
	{
		res(&k, &p, len);
		while (haystack[j + k] == needle[k] && haystack[j] && p-- > 0)
		{
			if (needle[k + 1] == '\0')
			{
				i = (char *)&haystack[j];
				return (i);
			}
			k++;
		}
		j++;
	}
	return (0);
}
