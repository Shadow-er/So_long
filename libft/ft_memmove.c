/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:51:55 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 05:51:21 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
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
