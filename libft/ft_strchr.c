/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:31:06 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 07:59:03 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*d;

	c = (char)c;
	while (*str)
	{
		if (*str == c)
		{
			d = (char *)str;
			return (d);
		}
		str++;
	}
	if (*str == c)
	{
		d = (char *)str;
		return (d);
	}
	return (0);
}
