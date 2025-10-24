/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-09 13:41:11 by avalsang          #+#    #+#             */
/*   Updated: 2025-01-09 13:41:11 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

void	*ft_calloc(size_t nmemb, size_t size);
ssize_t	find_newline(char *str);
size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2, size_t len);
char	*ft_strdup(const char *src);

char	*split_buffer(char **line, char *buffer, size_t len);
char	*read_until_newline(int fd, char *line, size_t *len);
char	*get_next_line(int fd);
#endif
