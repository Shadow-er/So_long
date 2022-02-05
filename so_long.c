/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:33:07 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/05 11:19:05 by mlakhssa         ###   ########.fr       */
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
	void	*p1_img;
	void	*wall_image;
	void	*end_image;
	void	*c_img;
	char	*p1_img_address;
	char	*end_image_address;
	char	*wall_image_address;
	char	*c_img_address;
}t_im_id;

typedef struct param
{
	void		*wdw;
	void		*id;
	char		**map;
	int			height;
	int			width;
	int			plen;
	int			b_px;
	int			line_length;
	int			endian;
	char		*pixel;
	int			movement;
	int			object_number;
	t_im_id	img2;
}t_param;

typedef struct p1
{
	int	x;
	int	y;
}t_p1;

char	*research_end(char *s, int c)
{
	char	d;
	int		r;
	char	*p;

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
		return (p);
	if (*s == c)
	{
		p = (char *)s;
		return (p);
	}
	return (0);
}
int file_format(char *argv)
{
	char	*format;
	int		i;
	int		k;

	i = 0;
	k = 3;
	format = ".ber";
	while(argv[i])
		i++;
	if (i <= 3)
		return(0);
	while(k >= 0 && argv[i])
	{
		if(argv[i - 1] != format[k])
			return (0);
		k--;
		i--;
	}
	return (1);
}

int	surrounded_by_1(t_param *g)
{
	int		i;
	int		j;
	
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (i == 0 || i == g->height - 1 || (i != 0 && j == 0)
				|| (i != 0 && j == g->width))
			{
				if(g->map[i][j] != '1')
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
	int	k;

	fd = open(argv,O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	i = get_next_line(fd);
	if (i == NULL)
	{
		perror("get_next_line");
		return (-1);
	}
	k = 0;
	c = 0;
	while (i)
	{
		while(i[k] != '\n' && i[k])
		{
			if(i[k] == 'E' || i[k] == 'P' ||  i[k] == '0'
			|| i[k] == 'C' || i[k] == '1')
			{
				if (i[k] == 'P' && c == 0)
					c = 1;
				else if(i[k] == 'P' && c != 0)
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
int rectangular_map(char *argv)
{
	char	*i;
	int		fd;
	int		width;
	int		temp;
	int		height;
	int		c;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	i = get_next_line(fd);
	if (i == NULL)
	{
		perror("get_next_line");
		return (-1);
	}
	c = 0;
	height = 0;
	while (i)
	{
		if (!ft_strchr((const char *)i, '\n'))
		{	
			temp = width;
			width = ft_strlen(i);
		}
		else if (c != 0)
		{
			temp = width;
			width = ft_strlen(i) -1;
		}
		else
			width = ft_strlen(i) -1;
		if (c != 0 && temp != width)
			return (0);
		height++;
		free(i);
		i = get_next_line(fd);
	}
	free(i);
	if (height != 3)
		return (0);
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
		return (-1);
	}
	i = get_next_line(fd);
	if (i == NULL)
	{
		perror("get_next_line");
		return (-1);
	}
	g->width = ft_strlen(i) - 1;
	g->height = 1;
	while (get_next_line(fd) != NULL)
		g->height += 1;
	close(fd);
	free(i);
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
			return (0);// Khassek tfreeyez li 9bel menou bach may w93ch mouchkil
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
		mlx_put_image_to_window(g->id,g->wdw,g->img2.c_img,y * (g->plen),x * (g->plen));
		g->object_number += 1;
	}
	if (g->map[x][y] == 'P')
		mlx_put_image_to_window(g->id,g->wdw,g->img2.p1_img,y * (g->plen),x * (g->plen));
	if (g->map[x][y] == '1')
		mlx_put_image_to_window(g->id,g->wdw,g->img2.wall_image,y * (g->plen),x * (g->plen));
	if (g->map[x][y] == 'E')
		mlx_put_image_to_window(g->id,g->wdw,g->img2.end_image,y * (g->plen),x * (g->plen));
}
void	init(t_param *g)
{
	g->plen = 16;
	g->height = 0;
	g->width = 0;
	g->movement = 0;
	g->object_number = 0;
	g->img2.c_img = mlx_xpm_file_to_image(g->id,"Collectable.xpm",&(g->plen),&(g->plen));
	g->img2.c_img_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
	g->img2.p1_img = mlx_xpm_file_to_image(g->id,"Character.xpm",&(g->plen),&(g->plen));
	g->img2.p1_img_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
	g->img2.wall_image = mlx_xpm_file_to_image(g->id,"Wall.xpm",&(g->plen),&(g->plen));
	g->img2.wall_image_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
	g->img2.end_image = mlx_xpm_file_to_image(g->id,"puerta.xpm",&(g->line_length),&(g->endian));
}
void	render(t_param *g)
{
	int	i;
	int	j;

	i = 0;
	while(i < g->height)
	{
		j = 0;
		while(j < g->width)
		{
			put_it(g,i,j);
			j++;
		}
		i++;
	}
}

void	im_puts(t_param *g,int x,int y)
{
	int	temp;
	mlx_clear_window(g->id,g->wdw);
	if(g->map[x + x][y + y] == 'C')
	{
		temp = g->map[x][y];
		g->map[x][y] = g->map[x + x][y + y];
		g->map[x + x][y + y]= '0';
		g->movement +=1;
		g->object_number -= 1;
		ft_putnbr_fd(g->movement,1);
		render(g);
	}
	else if(g->map[x + x][y + y] == '0')
	{
		temp = g->map[x][y];
		g->map[x][y] = g->map[x + x][y + y];
		g->map[x + x][y + y]= temp;
		g->movement +=1;
		ft_putnbr_fd(g->movement,1);
		render(g);
	}
	else if(g->map[x + x][y + y] == 'E' && g->object_number == 0)
	{
		g->map[x + x][y + y] = g->map[x][y];
		g->map[x][y] = '0';
		g->movement +=1;
		ft_putnbr_fd(g->movement,1);
		render(g);
		exit(0);
	}
}
int	key_hook(int keycode, t_param *g)
{
	if(keycode == 13)//w
		im_puts(g,-1,0);
	if(keycode == 2)//d
		im_puts(g,0,1);
	if(keycode == 1)//s
		im_puts(g,1,0);
	if(keycode == 0)//a
		im_puts(g,0,-1);
	if (keycode == 53)
		exit(0);//escape
	return (1);
}
int Error_Handling(char *argv, t_param *g, int argc)
{
	if (argc < 2)
	{
		write(1,"Error\n",6);
		return (0);
	}
	if(rectangular_map(argv) == 0 || correct_input(argv) == 0)
	{
		write(1,"Error\n",6);
		return (0);
	}
	if(!chargement(g,argv))
	{
		write(1,"Error\n",6);
		return (0);
	}
	if(!affect_map(g,argv))
	{
		write(1,"Error\n",6);
		return (0);
	}
	if(surrounded_by_1(g))
	{
		write(1,"Error\n",6);
		return (0);
	}
	return (1);
}
int	shutdown_w(int keycode, t_param *g)
{
	mlx_destroy_window(g->id, g->wdw);
	return (0);
}
int	main(int argc, char **argv)
{
	t_param	g;
	if (Error_Handling(argv[1],&g,argc) == 0)
		exit(0);
	g.id = mlx_init();
	init(&g);
	g.wdw = mlx_new_window(g.id,g.width * 16,g.height * 16, "Game");
	mlx_key_hook(g.id,key_hook,&g);
	mlx_hook(g.id,17,1L << 5,shutdown_w,&g);
	mlx_loop(g.id);
	exit(0);
}