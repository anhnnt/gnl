/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngnguyen <ngnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:51:20 by ngnguyen          #+#    #+#             */
/*   Updated: 2022/12/12 17:24:09 by ngnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
One reason is you want to change the value of the pointer passed to a function as the function argument, to do this you require pointer to a pointer.

In simple words, Use ** when you want to preserve (OR retain change in) the Memory-Allocation or Assignment even outside of a function call. (So, Pass such function with double pointer arg.)

This may not be a very good example, but will show you the basic use:

#include <stdio.h>
#include <stdlib.h>

void allocate(int **p)
{
    *p = (int *)malloc(sizeof(int));
}

int main()
{
    int *p = NULL;
    allocate(&p);
    *p = 42;
    printf("%d\n", *p);
    free(p);
}
*/
// #include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char		*buff;
// 	static char	*string;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	if (!string)
// 		string = ft_strdup("");
// 	line = read_line(fd, &buff, &string);
// 	return (line);
// }

// char	*read_line(int fd, char **buff, char **string)
// {
// 	int		ret;
// 	char	*temp;
// 	char	*line;

// 	ret = 1;
// 	while (ft_strchr(*string, '\n') == 0)
// 	{
// 		if (ret > 0)
// 		{
// 		ret = read (fd, *buff, BUFFER_SIZE);
// 		*buff[ret] = '\0';
// 		temp = *string;
// 		*string = ft_strjoin(*string, *buff);
// 		free(temp);
// 		}
// 		else
// 			line = handle_error_eof(ret, line, *string);
// 	}
// 	free(*buff);
// 	if (ft_strchr(*string, '\n'))
// 		line = get_line(line, string);
// 	return (line);
// }

// static char	*handle_error_eof(int ret, char **string, char **line)
// {
// 	if (ret < 0)
// 		return (NULL);
// 	else if (ret == 0)
// 	{
// 		if (*string == (NULL))
// 			*line = ft_strdup("");
// 		else
// 			*line =  *string;
// 	}
// 	return (*line);
// }

// static char	*get_line(char **line, char **string)
// {
// 	char	*temp;
// 	int		position_nl;

// 	position_nl = 0;
// 	temp = *string;
// 	while ((*string)[position_nl] != '\n')
// 		position_nl++;
// 	*line = ft_substr(*string, 0, position_nl + 1);
// 	*string = ft_strdup(*string + (position_nl + 1));
// 	if (*string == NULL)
// 	{
// 		free(temp);
// 		free(*string);
// 	}
// 	free(temp);
// 	return (*line);
// }
