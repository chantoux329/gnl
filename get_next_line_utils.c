/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:56:58 by chkala-l          #+#    #+#             */
/*   Updated: 2023/06/29 19:31:01 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (!s)
		return 0;
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
	if (s == NULL){
		printf("coucou");
		}
	dup = (char *)malloc((x + 1) * sizeof(char));
	if (!dup)
		return (NULL);
		
	while (s[i] != '\0' && (i < x))
	{
		dup[i] = s[i];
		i++;
	}
	printf("\n dup apres tout : %s\n", dup);
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
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