/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:39:25 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/09 20:01:18 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(backup, buffer, fd);
}

char	*get_line(char *backup, char *buffer, int fd)
{
	char	*temp;
	char	*one_line;
	size_t	nb_read;

	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (backup);
		if (!backup)
			backup = ft_strdup("");
		one_line = ft_strjoin(buffer, backup);
		
	}
}
