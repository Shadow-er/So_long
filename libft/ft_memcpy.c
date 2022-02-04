/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:18:17 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 08:30:08 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			r;
	unsigned char	*p;
	unsigned char	*q;

	if (dest == 0 && src == 0)
		return (0);
	p = (unsigned char *)dest;
	q = (unsigned char *)src;
	r = 0;
	while (r < n)
	{
		p[r] = q[r];
		r++;
	}
	return (dest);
}
