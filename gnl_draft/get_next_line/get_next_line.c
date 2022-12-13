/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngnguyen <ngnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:53:23 by ngnguyen          #+#    #+#             */
/*   Updated: 2022/12/13 15:30:00 by ngnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*get_line(int fd, char *buff, char *backup)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (1)
	{
		ret = read (fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		else if (ret == 0)
			break ;
		buff[ret] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(backup, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

static char	*split(char *line)
{
	char	*backup;
	int		nl_pos;

	nl_pos = 0;
	while (line[nl_pos] != '\n' && *line)
		nl_pos++;
	if (line[nl_pos] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, nl_pos + 1, ft_strlen(line) - nl_pos);
	if (!*backup)
	{
		free(backup);
		backup = NULL;
	}
	line[nl_pos + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = get_line(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	backup = split(line);
	return (line);
}
