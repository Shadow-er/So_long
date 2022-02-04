/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:37 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/04 16:57:19 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<unistd.h>

char			*ft_launch(char **s, int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
void			*ft_memmove(void *dst, void *src, size_t len);
char			*ft_strchr(char *str, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
unsigned int	ft_strlen(char *src);
char			*get_next_line(int fd);
int				gnl(char **s, char **temp, char *buffer, int fd);

#endif