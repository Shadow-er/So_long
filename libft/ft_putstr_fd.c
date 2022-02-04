/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:20:36 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 08:57:48 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static int	t_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	j;

	if (s == 0)
		return ;
	j = t_len(s);
	write(fd, s, j);
}
