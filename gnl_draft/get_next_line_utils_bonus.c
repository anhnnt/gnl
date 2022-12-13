/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngnguyen <ngnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:57:05 by ngnguyen          #+#    #+#             */
/*   Updated: 2022/12/12 17:57:31 by ngnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*temp;
	char	character;

	temp = (char *)str;
	character = (char)c;
	while (1)
	{
		if (*temp == character)
			return (temp);
		if (*temp == 0)
			return (NULL);
		temp++;
	}
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	*temp;

	temp = (char *)src;
	i = 0;
	while (temp[i] != '\0')
	{
		dest[i] = temp[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*des;

	des = (char *) malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (des == NULL)
		return (NULL);
	des = ft_strcpy(des, (char *)src);
	return (des);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	string_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	string_len = ft_strlen(s);
	if (start >= string_len)
		return (ft_strdup(""));
	if (len > string_len)
		len = string_len;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new)
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = '\0';
	return (new - total_len);
}
