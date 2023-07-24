/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:03 by chkala-l          #+#    #+#             */
/*   Updated: 2023/07/25 00:05:19 by chkala-l         ###   ########.fr       */
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
	if (temp == NULL)
		size = ft_strlen(str);
	else
		size = ft_strlen(str) - ft_strlen(temp);

	string = ft_calloc(sizeof(char), ((size) + 1));
	if (!string)
		return (NULL);
	while (i < size)
	{
		string[i] = str[i];
		i++;
	}
	return (string);
}

char	*copy_line(char *string)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (string && string[i] && string[i] != '\n')
	{
		i++;
	}
	if (!string || !string[i])
	{
		free(string);
		return (NULL);
	}	
	str = ft_calloc(ft_strlen(string) - i, 1);
	j = 0;
	i++;
	while (string && string[i])
		str[j++] = string[i++];
	free(string);
	return (str);
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
	int			nb_read;
	static char	*stock_read;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stock_read)
		stock_read = ft_strdup("");
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (!search_end_line(buffer) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(buffer), NULL);
		buffer[nb_read] = '\0';
		stock_read = ft_strjoin(stock_read, buffer);
		if (!stock_read)
			return (NULL);
	}
	free(buffer);
	line = make_line(stock_read);
	stock_read = copy_line(stock_read);
	return (line);
}

// int	main()
// {
// 		int	fd = open("text.txt", O_RDONLY);
// 	char* line = NULL;
// 	int i = 0;
// 	 while (1)
// 	 {
// 	 	line = get_next_line(fd);
// 	 	if (!line)
// 			break ;
// 		printf("STR = %s", line);
// 		free(line);
//  		i++;
// 	}
// 	line = get_next_line(fd);
	
// 	printf("\n");
// 	close(fd);
// 	return (0);
// }