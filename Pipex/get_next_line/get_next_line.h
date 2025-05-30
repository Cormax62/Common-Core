/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:46 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/24 18:12:04 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin3(char *s1, char const *s2);
int		ft_strchr2(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdel(char *str, char *src);
char	*ft_read(char *buffer, int fd);
char	*get_next_line(int fd);

#endif