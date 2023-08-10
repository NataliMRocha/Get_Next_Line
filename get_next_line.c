/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:39:25 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/10 18:09:47 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *backup, char *buffer, int fd)
{
	char	*temp;
	char	*one_line;
	int		nb_read;

	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (backup);
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		one_line = ft_strjoin(buffer, backup);
		free(temp);
		if (ft_strchr(one_line, '\n'))
			end_line(one_line, backup);
	}
	return (one_line);
}

char	*end_line(char *one_line, char *backup)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(one_line);
	i = -1;
	while (one_line[++i])
	{
		if (one_line[i] == '\n' || one_line[i])
			break ;
	}
	if (size > (i + 1))
	{
		backup = ft_strdup(&one_line[i]);
		one_line[i] = '\0';
	}
	return (one_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(backup, buffer, fd);
	return (line);
}
