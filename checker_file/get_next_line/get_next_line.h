/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:55:03 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 18:24:46 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
int		ft_checkline(char *gline, int bytes);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*substr(char const *s, unsigned int start, size_t len);
size_t	lenght(char *s, char *till_newline);

#endif
