/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:56:58 by chkala-l          #+#    #+#             */
/*   Updated: 2023/07/27 18:09:21 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		x;

	x = 0;
	i = 0;
	x = ft_strlen(s);
	dup = (char *)malloc((x + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	if (s)
	{
		while (s[i] != '\0' && (i < x))
		{
			dup[i] = s[i];
			i++;
		}
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	j = -1;
	while (++j < len2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
			i++;
		else if (s[i] == (char)c)
			return ((char *)s + i + 1);
	}
	if (s[i] == c)
		return ((char *)s + i + 1);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size && (nmemb > SIZE_MAX / size))
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < (nmemb * size))
		str[i++] = 0;
	return ((void *)str);
}
