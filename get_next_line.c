/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:39:25 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/11 18:06:44 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **backup, char *buffer, int fd)
{
	int		nb_read;
	char	*temp;

	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1 || nb_read == 0)
			return (*backup);
		if (!*backup)
			*backup = ft_strdup("");
		temp = *backup;
		*backup = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
		{
			temp = end_line(backup);
			break ;
		}
	}
	return (temp);
}

char	*end_line(char **backup)
{
	size_t	i;
	size_t	size;
	char	*temp_2;

	size = ft_strlen(*backup);
	i = ft_strlen(ft_strchr(*backup, '\n')) + 1;
	temp_2 = ft_strdup(*backup);
	temp_2[size - i] = '\0';
	*backup += i;
	return (temp_2);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;
	char		*temp_3;

	line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	temp_3 = backup;
	buffer[BUFFER_SIZE] = '\0';
	line = get_line(&backup, buffer, fd);
	if (line[0] == '\0')
	{
		free(line);
		free(temp_3);
		return (NULL);
	}
	free(buffer);
	return (line);
}
