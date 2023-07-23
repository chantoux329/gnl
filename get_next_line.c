/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:03 by chkala-l          #+#    #+#             */
/*   Updated: 2023/07/23 22:51:05 by chkala-l         ###   ########.fr       */
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

	string = malloc(sizeof(char) *((size) + 1));
	if (!string)
		return (NULL);
	while (i < size)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
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
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	int			nb_read;
	static char	*stock_read;
	// static char	stock_read[BUFFER_SIZE + 1] = "";
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	// if (!stock_read)
	// 	stock_read = ft_strdup("\0");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp = NULL;
	nb_read = 1;
	while (temp == NULL && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		buffer[nb_read] = '\0';
		//temp = stock_read; //ici pour pouvoir free mon ancien stockread inutile
		stock_read = ft_strjoin(stock_read, buffer);
		//free(temp); //pour free mon vieux stock read
		if (!stock_read)
			return (NULL);
		temp = search_end_line(buffer);
	}
	free(buffer);
	line = make_line(stock_read);
	if (line == NULL)
		free(line);
	if (line)
	{
		stock_read = search_end_line(stock_read);
	}
	else
		free(temp);
	//if (!temp)
	//	free(stock_read);
	

	return (line);
}

int	main()
{
		int	fd = open("text.txt", O_RDONLY);
	char* line = NULL;
	int i = 0;
//	while ((line = get_next_line(fd)))
//	{
//	 	printf("STR = %s", line);
//	 	free(line);
//	 }
	 while (i < 15)
	 {
	 	line = get_next_line(fd);
	 	printf("STR = %s", line);
		free(line);
 		i++;
	}
	printf("\n");
	close(fd);
	return (0);
	// int	fd = open("text.txt", O_RDONLY);
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
	
	

	// fd = open("text.txt", O_RDONLY);
	// printf("\nfirst: %s \n", get_next_line(fd));
	// printf("\nsecond: %s \n", get_next_line(fd));
	// printf("\nthird: %s \n", get_next_line(fd));
	// printf("\nfourth: %s \n", get_next_line(fd));
	// printf("\nfifth: %s \n", get_next_line(fd));
	// printf("\n6: %s \n", get_next_line(fd));
	// printf("\n7: %s \n", get_next_line(fd));
	// printf("\n8: %s \n", get_next_line(fd));
	// printf("\nf9: %s \n", get_next_line(fd));
	// printf("\n10: %s \n", get_next_line(fd));
	// printf("\n11: %s \n", get_next_line(fd));

	// close(fd);

	
	// return (0);
}