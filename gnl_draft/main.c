/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngnguyen <ngnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:06:45 by ngnguyen          #+#    #+#             */
/*   Updated: 2022/12/12 17:53:41 by ngnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
/*
int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = NULL;
	while (line == get_next_line_test(fd))
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
*/

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("text.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 15)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}

// int main()
// {
// 	int	fd;
// 	int	ret;
// 	char	*buf;

// 	fd = open("text.txt", O_RDONLY);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	while (ret != '\0')
// 	{
// 	ret = read(fd, buf, 6);
// 	buf[ret] = '\0';
// 	printf("%s\n", buf);
// 	}
// 	return (0);
// }