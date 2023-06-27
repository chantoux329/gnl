/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantoux329 <chantoux329@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:06 by chkala-l          #+#    #+#             */
/*   Updated: 2023/06/09 18:48:10 by chantoux329      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//# include <bsd/string.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 42

#endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*search_end_line(char *string);

#endif