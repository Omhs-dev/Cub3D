/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:23:46 by ohamadou          #+#    #+#             */
/*   Updated: 2023/03/31 01:04:15 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int	    foo_strlen(char *str);
char	*foo_strchr(char *s, int c);
char	*get_the_line(char *strng);
void	*foo_memcpy(void *dest, const void *src, size_t n);
char	*foo_strjoin(char *s1, char *s2);
#endif