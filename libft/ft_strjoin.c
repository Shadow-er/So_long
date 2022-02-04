/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:23:30 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 08:01:23 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*i;
	int		len1;
	int		len2;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 && s2 == 0)
		return (ft_strdup(s1));
	if (s1 == 0 && s2)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	j = len1 + len2 + 1;
	i = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (i == 0)
		return (0);
	ft_memmove(i, s1, len1);
	ft_memmove(i + len1, s2, len2);
	i[j - 1] = '\0';
	return (i);
}
