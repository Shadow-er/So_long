/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:38:53 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/08 10:59:54 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	i = 0;
	p = malloc(count * size);
	if (p == 0)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
