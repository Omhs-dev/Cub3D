/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:23:46 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/14 02:12:34 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
// #include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// char	*ft_strjoin(char *left_str, char *buff);
int		ft_strleng(char *str);
char	*get_next_line(int fd);
char	*read_str(int fd, char *left_str);
char	*ft_strchrg(char *s, int c);
char	*get_the_line(char *left_str);
char	*remained_str_new(char *left_str);
void	*ft_memcpyy(void *dest, const void *src, size_t n);
char	*ft_strjoing(char *s1, char *s2);

#endif