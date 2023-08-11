/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:46:38 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/11 17:51:40 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((total_size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1 && *s1 != '\0')
		*new_str++ = *s1++;
	while (s2 && *s2 != '\0')
		*new_str++ = *s2++;
	*new_str = '\0';
	return ((new_str - total_size));
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*strdup;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	strdup = (char *)malloc((len + 1) * sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	source_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	source_len = ft_strlen(s);
	substr_len = source_len - (size_t)start;
	if (start > source_len)
		return (NULL);
	if (len > source_len)
		len = source_len - start + 1;
	if (substr_len > len)
		substr_len = len;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = -1;
	while (s[start] != '\0' && ++i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
