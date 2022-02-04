/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:27:18 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 10:08:44 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*r;

	r = (unsigned char *)b;
	while (len-- > 0)
		*r++ = (unsigned char)c;
	return (b);
}
