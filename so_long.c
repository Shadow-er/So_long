/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:33:07 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/06 16:08:29 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "fcntl.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct im_inf
{
	void *p1_img;
	void *wall_image;
	void *end_image;
	void *c_img;
	char *p1_img_address;
	char *end_image_address;
	char *wall_image_address;
	char *c_img_address;
} t_im_id;
typedef struct p1
{
	int x;
	int y;
} t_p1;

typedef struct param
{
	void *wdw;
	void *id;
	char **map;
	int height;
	int width;
	int plen;
	int b_px;
	t_p1 player;
	int line_length;
	int endian;
	char *pixel;
	int movement;
	int object_number;
	t_im_id img2;
} t_param;

int research_end(char *s, int c)
{
	char d;
	int r;
	char *p;

	d = (char)c;
	r = 0;
	while (*s)
	{
		if (*s == d)
		{
			p = (char *)s;
			r = 1;
		}
		s++;
	}
	if (r == 1)
		return (1);
	if (*s == c)
	{
		p = (char *)s;
		return (1);
	}
	return (0);
}
int file_format(char *argv)
{
	char *format;
	int i;
	int k;

	i = 0;
	k = 3;
	format = ".ber";
	while (argv[i])
		i++;
	if (i <= 3)
		return (0);
	while (k >= 0 && argv[i])
	{
		if (argv[i - 1] != format[k])
			return (0);
		k--;
		i--;
	}
	return (1);
}

int surrounded_by_1(t_param *g)
{
	int i;
	int j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (i == 0 || i == g->height - 1 || j == 0 || j == g->width - 1)
			{
				if (g->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int correct_input(char *argv)
{
	char *i;
	int fd;
	int c;
	int k;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (0);
	}
	i = get_next_line(fd);
	if (i == NULL)
		return (0);
	k = 0;
	c = 0;
	while (i)
	{
		while (i[k] != '\n' && i[k])
		{
			if (i[k] == 'E' || i[k] == 'P' || i[k] == '0' || i[k] == 'C' || i[k] == '1')
			{
				if (i[k] == 'P' && c == 0)
					c = 1;
				else if (i[k] == 'P' && c != 0)
					return (0);
				k++;
			}
			else
			{
				free(i);
				return (0);
			}
		}
		free(i);
		i = get_next_line(fd);
	}
	return (1);
}
int requirement_in(t_param *g)
{
	int i;
	int j;
	int counter_c;
	int counter_e;
	int counter_p;

	i = 1;
	counter_c = 0;
	counter_e = 0;
	counter_p = 0;
	while (i < g->height)
	{
		j = 1;
		while (j < (g->width) - 1)
		{
			if (g->map[i][j] == '0' || g->map[i][j] == 'E' || g->map[i][j] == '1' || g->map[i][j] == 'P' || g->map[i][j] == 'C')
			{
				if (g->map[i][j] == 'C')
					counter_c += 1;
				if (g->map[i][j] == 'P')
					counter_p += 1;
				if (g->map[i][j] == 'E')
					counter_e += 1;
			}
			else
				return (0);
			j++;
		}
		i++;
	}
	if (counter_c == 0 || counter_e == 0 || counter_p != 1)
		return (0);
	return (1);
}

int rectangular_map(char *argv)
{
	char *i;
	char *temp2;
	int fd;
	int width;
	int height;

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
	return (1);
}
int chargement(t_param *g, char *argv)
{
	char *i;
	int fd;

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
	while (get_next_line(fd) != NULL)
		g->height += 1;
	close(fd);
	free(i);
	return (1);
}

int affect_map(t_param *g, char *argv)
{
	int i;
	int j;
	char *l;
	int fd;

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
			return (0); // Khassek tfreeyez li 9bel menou bach may w93ch mouchkil
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
	return (1);
}
void put_it(t_param *g, int x, int y)
{
	
	if (g->map[x][y] == 'C')
	{
		mlx_put_image_to_window(g->id, g->wdw, g->img2.c_img, y * (g->plen), x * (g->plen));
		g->object_number += 1;
	}
	if (g->map[x][y] == 'P')
	{
		g->player.x = x;
		g->player.y = y;
		mlx_put_image_to_window(g->id, g->wdw, g->img2.p1_img, y * (g->plen), x * (g->plen));
	}
	if (g->map[x][y] == '1')
		mlx_put_image_to_window(g->id, g->wdw, g->img2.wall_image, y * (g->plen), x * (g->plen));
	if (g->map[x][y] == 'E')
		mlx_put_image_to_window(g->id, g->wdw, g->img2.end_image, y * (g->plen), x * (g->plen));
}
void init(t_param *g)
{
	g->plen = 16;
	g->movement = 0;
	g->img2.c_img = mlx_xpm_file_to_image(g->id, "Collectable.xpm", &(g->plen), &(g->plen));
	g->img2.c_img_address = mlx_get_data_addr(g->id, &(g->b_px), &(g->line_length), &(g->endian));
	g->img2.p1_img = mlx_xpm_file_to_image(g->id, "Character.xpm", &(g->plen), &(g->plen));
	g->img2.p1_img_address = mlx_get_data_addr(g->id, &(g->b_px), &(g->line_length), &(g->endian));
	g->img2.wall_image = mlx_xpm_file_to_image(g->id, "Wall.xpm", &(g->plen), &(g->plen));
	g->img2.wall_image_address = mlx_get_data_addr(g->id, &(g->b_px), &(g->line_length), &(g->endian));
	g->img2.end_image = mlx_xpm_file_to_image(g->id, "puerta.xpm", &(g->line_length), &(g->endian));
}
void render(t_param *g)
{
	int i;
	int j;

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

void im_puts(t_param *g, int x, int y)
{
	int temp;
	
	mlx_clear_window(g->id, g->wdw);
	if (g->map[g->player.x + x][g->player.y + y] == 'C')
	{
		g->map[g->player.x][g->player.y] = '0';
		g->map[g->player.x + x][g->player.y + y] = 'P';
		g->movement += 1;
		g->object_number -= 1;
		ft_putnbr_fd(g->movement, 1);
		write(1, "\n", 1);
	}
	if (g->map[g->player.x + x][g->player.y + y] == '0')
	{
		g->map[g->player.x][g->player.y] = '0';
		g->map[g->player.x + x][g->player.y + y] = 'P';
		g->movement += 1;
		ft_putnbr_fd(g->movement, 1);
		write(1, "\n", 1);
	}
	printf("object : %d\n", g->object_number);
	if (g->map[g->player.x + x][g->player.y + y] == 'E' && g->object_number == 0)
	{
		g->map[g->player.x + x][g->player.y + y] = 'P';
		g->map[g->player.x][g->player.y] = '0';
		g->movement += 1;
		ft_putnbr_fd(g->movement, 1);
		write(1, "\n", 1);
		exit(0);
	}
	render(g);
}
int key_hook(int keycode, t_param *g)
{
	if (keycode == 13) //w
		im_puts(g, -1, 0);
	if (keycode == 2) //d
		im_puts(g, 0, 1);
	if (keycode == 1) //s
		im_puts(g, 1, 0);
	if (keycode == 0) //a
		im_puts(g, 0, -1);
	if (keycode == 53)
		exit(0); //escape
	return (1);
}
int Error_Handling(char *argv, t_param *g, int argc)
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
int shutdown_w(t_param *g)
{
	exit(0);
}
int main(int argc, char **argv)
{
	t_param g;
	if (Error_Handling(argv[1], &g, argc) == 0)
		exit(0);
	g.id = mlx_init();
	init(&g);
	g.wdw = mlx_new_window(g.id, (g.width)* 16, g.height * 16, "Game");
	render(&g);
	mlx_hook(g.wdw,17,1L<<5,shutdown_w,&g);
	mlx_key_hook(g.wdw, key_hook, &g);
	mlx_loop(g.id);
	exit(0);
}