/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:17:06 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/11/11 07:57:24 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static unsigned int	uinr(int nbr)
{
	unsigned int	ui;

	if (nbr < 0)
		nbr *= -1;
	ui = (unsigned int)nbr;
	return (ui);
}

static unsigned int	l_mal(int nbr)
{
	unsigned int	j;
	unsigned int	ui;
	int				ne;

	j = 0;
	if (nbr < 0)
		ne = 1;
	ui = uinr(nbr);
	while (ui != 0)
	{
		j++;
		ui /= 10;
	}
	if (ne == 1)
		j++;
	return (j);
}

static void	ft_putnbr(unsigned int n, char *str, unsigned int *i)
{
	unsigned int	k;

	k = *i;
	if (n >= 10)
	{
		*i = *i + 1;
		ft_putnbr(n / 10, str, i);
	}
	str[k] = (n % 10) + '0';
}

static void	reverse(char *c, unsigned int j)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = j;
	while (start < end)
	{
		temp = c[start];
		c[start] = c[end];
		c[end] = temp;
		start ++;
		end --;
	}
}

char	*ft_itoa(int num)
{
	unsigned int	j;
	char			*c;
	unsigned int	ui;

	j = 0;
	if (num == 0)
	{
		c = (char *)malloc(sizeof(char) * 2);
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	ui = l_mal(num);
	c = (char *)malloc(sizeof(char) * (ui + 1));
	if (c == 0)
		return (0);
	ui = uinr(num);
	ft_putnbr(ui, c, &j);
	if (num < 0)
		c[++j] = '-';
	c[++j] = '\0';
	reverse(c, j - 1);
	return (c);
}
