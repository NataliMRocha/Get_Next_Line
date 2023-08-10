/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:46:38 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/10 18:13:43 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc_mem;
	size_t	total_size;

	total_size = nmemb * size;
	if ((nmemb == 0 || size == 0) || total_size / size != nmemb)
		return (NULL);
	alloc_mem = malloc(total_size);
	if (!alloc_mem)
		return (NULL);
	while (total_size-- > 0)
	{
		*alloc_mem = '\0';
		alloc_mem++;
	}
	return ((void *)alloc_mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc(1, (total_size + 1));
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

	len = ft_strlen(s);
	strdup = (char *)ft_calloc((len + 1), sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		strdup[i] = s[i];
		i++;
	}
	return (strdup);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
