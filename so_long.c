/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:33:07 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/04 12:18:26 by mlakhssa         ###   ########.fr       */
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
	void	*c_img;
	char	*p1_img_address;
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
		return (-1);
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
	g->img2.c_img = mlx_xpm_file_to_image(g->id,"Game_Assets/Collectable.xpm",&(g->plen),&(g->plen));
	g->img2.c_img_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
	g->img2.p1_img = mlx_xpm_file_to_image(g->id,"Game_Assets/p1.xpm",&(g->plen),&(g->plen));
	g->img2.p1_img_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
	g->img2.wall_image = mlx_xpm_file_to_image(g->id,"Game_Assets/wall.xpm",&(g->plen),&(g->plen));
	g->img2.wall_image_address = mlx_get_data_addr(g->id,&(g->b_px),&(g->line_length),&(g->endian));
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
	if(g->map[x + x][y + y] == 'C')
	{
		mlx_clear_window(g->id,g->wdw);
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
		mlx_clear_window(g->id,g->wdw);
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
void	new_image(t_param *g,int keycode)
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
}

int	main(int argc, char **argv)
{
	t_param	g;

	g.id = mlx_init();
	g.window = mlx_new_window(g.id,4*16000,4*16, "Game");
	mlx_loop(g.id);
}