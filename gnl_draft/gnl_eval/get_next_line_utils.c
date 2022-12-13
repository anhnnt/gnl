/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:33:16 by hel-hosr          #+#    #+#             */
/*   Updated: 2022/11/22 10:57:12 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(*s2) * len);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = (ft_strlen(s) + 1);
	while (len > 0)
	{
		if (*s == (char) c)
			return ((char *)s);
		else
		{
			s++;
			len--;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		final_len;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	final_len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(*str) * final_len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;

	i = 0;
	substring = (char *)malloc(sizeof(*substring) * len + 1);
	if (!substring)
		return (NULL);
	while (s[start] && len > 0 && (start <= ft_strlen(s)))
	{
		substring[i] = s[start];
		start++;
		len--;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
