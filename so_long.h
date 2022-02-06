/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:30:12 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/06 16:40:47 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "fcntl.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

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
}	t_im_id;
typedef struct p1
{
	int	x;
	int	y;
}	t_p1;

typedef struct param
{
	void	*wdw;
	void	*id;
	char	**map;
	int		height;
	int		width;
	int		plen;
	int		b_px;
	t_p1	player;
	int		line_length;
	int		endian;
	char	*pixel;
	int		movement;
	int		object_number;
	t_im_id	img2;
}	t_param;
int		research_end(char *s, int c);
int		file_format(char *argv);
int		surrounded_by_1(t_param *g);
int		correct_input(char *argv);
int		requirement_in(t_param *g);
int		rectangular_map(char *argv);
int		chargement(t_param *g, char *argv);
int		affect_map(t_param *g, char *argv);
void	put_it(t_param *g, int x, int y);
void	init(t_param *g);
void	render(t_param *g);
void	im_puts(t_param *g, int x, int y);
int		key_hook(int keycode, t_param *g);
int		Error_Handling(char *argv, t_param *g, int argc);
int		shutdown_w(t_param *g);

#endif