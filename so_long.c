/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:33:07 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/06 17:13:06 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putter(t_param *g, int x, int y)
{
	g->map[g->player.x][g->player.y] = '0';
	g->map[g->player.x + x][g->player.y + y] = 'P';
	g->movement += 1;
	ft_putnbr_fd(g->movement, 1);
	write(1, "\n", 1);
}

void	im_puts(t_param *g, int x, int y)
{
	mlx_clear_window(g->id, g->wdw);
	if (g->map[g->player.x + x][g->player.y + y] == 'C')
	{
		g->object_number -= 1;
		putter(g, x, y);
	}
	if (g->map[g->player.x + x][g->player.y + y] == '0')
		putter(g, x, y);
	if (g->map[g->player.x + x][g->player.y + y] == 'E'
		&& g->object_number == 0)
	{
		putter(g, x, y);
		exit(0);
	}
	render(g);
}

int	key_hook(int keycode, t_param *g)
{
	if (keycode == 13)
		im_puts(g, -1, 0);
	if (keycode == 2)
		im_puts(g, 0, 1);
	if (keycode == 1)
		im_puts(g, 1, 0);
	if (keycode == 0)
		im_puts(g, 0, -1);
	if (keycode == 53)
		exit(0);
	return (1);
}

int	error_handl(char *argv, t_param *g, int argc)
{
	if (!chargement(g, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!affect_map(g, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!surrounded_by_1(g))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!requirement_in(g))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	error_handling(char *argv, t_param *g, int argc)
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!file_format(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!rectangular_map(argv) || !correct_input(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (error_handl(argv, g, argc) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}


int	shutdown_w(t_param *g)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_param	g;

	if (error_handling(argv[1], &g, argc) == 0)
		exit(0);
	g.id = mlx_init();
	init(&g);
	g.wdw = mlx_new_window(g.id, (g.width) * 16, g.height * 16, "Game");
	render(&g);
	mlx_hook(g.wdw, 17, 1L << 5, shutdown_w, &g);
	mlx_key_hook(g.wdw, key_hook, &g);
	mlx_loop(g.id);
	exit(0);
}
