/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:19:54 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 10:14:20 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
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
		return (p);
	if (*s == c)
	{
		p = (char *)s;
		return (p);
	}
	return (0);
}
