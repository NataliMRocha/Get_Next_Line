/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:17:12 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/15 23:07:20 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buffer, char *backup, int fd)
{
	size_t	nb_read;
	char	*temp;
	
	nb_read = 1;
	temp = NULL;
	while(nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (NULL);
		else if (!nb_read)
			return (backup);
		buffer[nb_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return(backup);
}
static char	*ft_free(char *buffer, char *line)
{
	if (line == NULL || *line == '\0')
	{
		free(line);
		line = NULL;
	}
	free(buffer);
	buffer = NULL;
	return (line);
}
static char	*ft_backup(char *line)
{
	size_t	i;
	char	*backup;
	char	*new_line;

	if (line && ft_strchr(line, '\n'))
	{
		new_line = ft_strchr(line, '\n');
		i = ft_strlen(line) - ft_strlen(new_line) + 1;
		backup = ft_strdup(new_line + 1);
		line[i] = '\0';
		return (backup);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line(buffer, backup, fd);
	backup = ft_backup(line);
	if (!ft_strchr(line, '\n') || backup != NULL && !(*backup))
	{
		free(backup);
		backup = NULL;
	}
	return(ft_free(buffer, line));
}	