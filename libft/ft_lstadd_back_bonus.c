/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 08:14:48 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 08:14:52 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
	}
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
