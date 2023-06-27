/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantoux329 <chantoux329@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:03 by chkala-l          #+#    #+#             */
/*   Updated: 2023/06/10 17:50:10 by chantoux329      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *str)
{
	int		i;
	int		size;
	char	*temp;
	char	*string;

	i = 0;
	temp = search_end_line(str);
	if (temp == NULL)
		{
		size = ft_strlen(str);
		printf("mu");	
		}
	else	
		{size = ft_strlen(str) - ft_strlen(temp);
			printf("ma");
		}
		
	printf("\n size : %d\n", size);
	string = malloc(sizeof(char) *((size) + 1));
	printf("\n size string1 : %zu\n", ft_strlen(string));
	if (!string)
		return NULL;	
	while (i < size)
	{
		string[i] = str[i];
		printf("\n size string2 : %zu\n", ft_strlen(string));
		i++;
	}
	printf("\n size string3 : %zu\n", ft_strlen(string));
	string[i] = '\0';
	printf("\n size string 4: %zu\n", ft_strlen(string));
	printf("\n string : %s\n", string);
	return (string);
}

char	*search_end_line(char *string)
{
	char	*str;
	char	c;

	c = '\n';
	if (ft_strchr(string, c) == NULL || string == NULL)
		return (NULL);
	else
		str = ft_strchr(string, c);
	// free ((void *)string);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	size_t		nb_read;
	static char	*stock_read;
	char		buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return NULL;
	if (!stock_read)
			stock_read = ft_strdup("\0");
	// buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!buffer)
	// 	return (NULL);
	temp = search_end_line(buffer);
	nb_read = 1;
	while (temp == NULL && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		buffer[nb_read] = '\0';
		stock_read = ft_strjoin(stock_read, buffer);
		temp = search_end_line(buffer);
	}
	line = make_line(stock_read);
	printf("\n line apres make line : %s\n", line);
	printf("\n stkre apres make line : %s\n", stock_read);
	temp = search_end_line(stock_read );
	printf("\n temp ap : %s\n", temp);
	printf("\nstockread 1 : %s\n", stock_read);
	printf("\n line apres line : %s\n", line);
	if (temp == NULL)
	{
		free(stock_read);
		stock_read = NULL;
	}
	printf("\n line apres tout : %s\n", line);
	stock_read = ft_strdup(temp);
	printf("\nstockread 2 : %s\n", stock_read);
	return (line);
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	// char* line = NULL;
	// int i = 1;
	// int ret = 1;
	// while (ret  > 0)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%der line : %s\n", i, line);
	// 	free(line);
	// 	i++;
	// }
	
	

	fd = open("text.txt", O_RDONLY);
	printf("\nfirst: %s \n", get_next_line(fd));
	printf("\nsecond: %s \n", get_next_line(fd));
	printf("\nthird: %s \n", get_next_line(fd));
	// printf("\nfourth: %s \n", get_next_line(fd));
	// printf("\nfifth: %s \n", get_next_line(fd));
	// printf("\n6: %s \n", get_next_line(fd));
	// printf("\n7: %s \n", get_next_line(fd));
	// printf("\n8: %s \n", get_next_line(fd));
	// printf("\nf9: %s \n", get_next_line(fd));
	// printf("\n10: %s \n", get_next_line(fd));
	// printf("\n11: %s \n", get_next_line(fd));

	// close(fd);

	
	return (0);
}