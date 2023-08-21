/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:14:50 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/21 12:01:50 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (s == NULL)
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*strdup;

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
