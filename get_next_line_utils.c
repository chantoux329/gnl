/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:56:58 by chkala-l          #+#    #+#             */
/*   Updated: 2023/07/23 22:50:50 by chkala-l         ###   ########.fr       */
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
	// free ((void *)s);
	return (dup);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		str[i + j] = s2[j];
		j++;
	}
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
		{
			i++;
		}
		else if (s[i] == (char)c)
		{
			return ((char *)s + i + 1);
		}
	}
	if (s[i] == c)
	{
		return ((char *)s + i + 1);
	}
	return (NULL);
}
