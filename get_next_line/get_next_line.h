/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:50:47 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/02/04 11:38:38 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

char			*ft_launch(char **s);
char			*ft_strjon(char *s1, char *s2);
char			*ft_strdp(char *src);
void			*ft_memmve(void *dst, void *src, size_t len);
char			*ft_strcr(char *str, int c);
char			*ft_subsr(char *s, unsigned int start, size_t len);
unsigned int	ft_strln(char *src);
char			*get_next_line(int fd);
int				gnl(char **s, char **temp, char *buffer, int fd);

#endif