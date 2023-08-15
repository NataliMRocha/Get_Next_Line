/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:17:12 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/15 19:25:18 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	**backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (malloc(0));
	backup = NULL;
	line = get_line(buffer, &backup, fd);
	if(line == NULL)
		return(NULL);
	*backup = ft_backup(line);
	line = ft_line(line);
	if (line == NULL)
		free(buffer);
	return (line);
}

char	*get_line(char *buffer, char **backup, int fd)
{
	size_t	nb_read;
	char	*line;
	char	*temp;
	
	nb_read = 1;
	line = NULL;
	temp = NULL;
	while(nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if ((nb_read == 0 || nb_read == -1) && backup != NULL)
			return (backup);
		if ((nb_read == 0 || nb_read == -1) && backup == NULL)
			return (NULL);
		buffer[nb_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		line = ft_strjoin(backup, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return(line);
}

char	*ft_backup(char *line)
{
	size_t	line_size;
	size_t	after_line_size;
	char	*backup;
	
	line_size = ft_strlen(line);
	after_line_size = (ft_strlen(ft_strchr(line, '\n')) - 1 );
	if(after_line_size < line_size && after_line_size != 0)
	{
		backup = (char *)malloc((after_line_size + 1) * sizeof(char));
		ft_strlcpy(backup, &line[line_size - after_line_size], (after_line_size + 1));
	}
	else
		backup = NULL;
	return (backup);
}

char	*ft_line(char *line)
{
	int	i;
	
	i = 0;
	while(line)
	{
		if(line[i] == '\n')
			break ;
		i++;
	}
	line[i + 1] = '\0';
	return(line);
}