/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:41:44 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/06 17:14:49 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangular_map(char *argv)
{
	char	*i;
	char	*temp2;
	int		fd;
	int		width;
	int		height;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	i = get_next_line(fd);
	if (i == NULL)
		return (0);
	height = 0;
	width = ft_strlen(i);
	while (i)
	{
		temp2 = i;
		i = get_next_line(fd);
		if (!i && ft_strlen(temp2) != width - 1)
			return (0);
		if (i && ft_strlen(temp2) != width)
			return (0);
		free(temp2);
		height++;
	}
	if (height < 3)
		return (0);
	close(fd);
	return (1);
}

int	chargement(t_param *g, char *argv)
{
	char	*i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	i = get_next_line(fd);
	if (i == NULL)
		return (0);
	g->width = ft_strlen(i) - 1;
	g->height = 1;
	while (i)
	{
		free(i);
		i = get_next_line(fd);
		if (i)
			g->height += 1;
	}
	close(fd);
	return (1);
}

int	affect_map(t_param *g, char *argv)
{
	int		i;
	int		j;
	char	*l;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	g->map = (char **)malloc(sizeof(char *) * (g->height + 1));
	if (g->map == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < g->height)
	{
		j = 0;
		l = get_next_line(fd);
		g->map[i] = (char *)malloc((sizeof(char) * (g->width + 1)));
		if (g->map[i] == 0)
			return (0);
		while (j < g->width)
		{
			g->map[i][j] = l[j];
			j++;
		}
		g->map[i][j] = '\0';
		free(l);
		i++;
	}
	g->map[i] = 0;
	close(fd);
	return (1);
}

void	put_it(t_param *g, int x, int y)
{
	if (g->map[x][y] == 'C')
	{
		mlx_put_image_to_window(g->id, g->wdw, g->img2.c_img,
			y * (g->plen), x * (g->plen));
		g->object_number += 1;
	}
	if (g->map[x][y] == 'P')
	{
		g->player.x = x;
		g->player.y = y;
		mlx_put_image_to_window(g->id, g->wdw, g->img2.p1_img,
			y * (g->plen), x * (g->plen));
	}
	if (g->map[x][y] == '1')
		mlx_put_image_to_window(g->id, g->wdw, g->img2.wall_image,
			y * (g->plen), x * (g->plen));
	if (g->map[x][y] == 'E')
		mlx_put_image_to_window(g->id, g->wdw, g->img2.end_image,
			y * (g->plen), x * (g->plen));
}

void	init(t_param *g)
{
	g->plen = 16;
	g->movement = 0;
	g->img2.c_img = mlx_xpm_file_to_image(g->id, "Collectable.xpm",
			&(g->plen), &(g->plen));
	g->img2.c_img_address = mlx_get_data_addr(g->id, &(g->b_px),
			&(g->line_length), &(g->endian));
	g->img2.p1_img = mlx_xpm_file_to_image(g->id, "Character.xpm",
			&(g->plen), &(g->plen));
	g->img2.p1_img_address = mlx_get_data_addr(g->id, &(g->b_px),
			&(g->line_length), &(g->endian));
	g->img2.wall_image = mlx_xpm_file_to_image(g->id, "Wall.xpm",
			&(g->plen), &(g->plen));
	g->img2.wall_image_address = mlx_get_data_addr(g->id, &(g->b_px),
			&(g->line_length), &(g->endian));
	g->img2.end_image = mlx_xpm_file_to_image(g->id, "puerta.xpm",
			&(g->line_length), &(g->endian));
}

void	render(t_param *g)
{
	int	i;
	int	j;

	i = 0;
	g->object_number = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			put_it(g, i, j);
			j++;
		}
		i++;
	}
}
