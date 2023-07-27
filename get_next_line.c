/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:03 by chkala-l          #+#    #+#             */
/*   Updated: 2023/07/27 18:09:07 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *str)
{
	int		i;
	int		size;
	char	*temp;
	char	*string;

	if (ft_strlen(str) == 0)
		return (NULL);
	i = 0;
	temp = search_end_line(str);
	size = ft_strlen(str);
	if (temp != NULL)
		size -= ft_strlen(temp);
	string = malloc(sizeof(char) * ((size) + 1));
	if (!string)
		return (NULL);
	while (i < size)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = 0;
	return (string);
}

char	*copy_line(char *string)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (string && string[i] && string[i] != '\n')
		i++;
	if (!string || !string[i])
		return (free(string), NULL);
	str = malloc(ft_strlen(string) - i);
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (string && string[i])
		str[j++] = string[i++];
	str[j] = '\0';
	return (free(string), str);
}

char	*search_end_line(char *string)
{
	char	*str;
	char	c;

	c = '\n';
	if (string == NULL || ft_strchr(string, c) == NULL)
		return (NULL);
	str = ft_strchr(string, c);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock = NULL;
	char		*buffer;
	int			nb_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	nb_read = 1;
	while (!search_end_line(buffer) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(buffer), NULL);
		buffer[nb_read] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (!stock)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (line = make_line(stock), stock = copy_line(stock), line);
}

// int	main()
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	line = NULL;
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("STR = %s", line);
// 		free(line);
// 		i++;
// 	}
// 	line = get_next_line(fd);
// 	printf("\n");
// 	close(fd);
// 	return (0);
// }