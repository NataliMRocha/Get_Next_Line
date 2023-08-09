/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:29:04 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/08 18:41:46 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static size_t	nb_read;
	static char		*buffer;
	char		*leitura_1;
	static char		*leitura_2;
	char		*concatenada;
	size_t	i = 0;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read == -1)
		return (1);
	while(i <= nb_read)
	{
		if (buffer[i] == '\n')
			break;
		else
			i++;
	}
	*leitura_1 = (char *)ft_calloc((i + 1), sizeof(char));
	ft_strlcpy(leitura_1, buffer, i);
	if (i = nb_read)
		free(buffer);
		return (leitura_1);
	if (i < nb_read)
		*buffer = buffer + i;
		leitura_2 = (char *)ft_calloc(((buffer - i) + 1), sizeof(char));
		ft_strlcpy(leitura_2, buffer, (buffer - i));
		return (leitura_1);

	if (i > nb_read)
	{
		while(read)
		{
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (read == -1)
			{
				free(leitura_1);
				free (buffer);
				return(1);
			}
			i = 0;
			while(i <= nb_read)
			{
				if (buffer[i] == '\n')
					break;
				else
					i++;
			}
			*leitura_2 = (char *)ft_calloc((i + 1), sizeof(char));
			ft_strlcpy(leitura_2, buffer, i);
			concatenada = ft_strjoin(leitura_1, leitura_2);
			free(leitura_1);
			free(leitura_2);
		}
	}
	close(fd);
	}


int	main(void)
{
	int			fd;
	char	*line;
	
	fd = open("/nfs/homes/namoreir/Get_Next_Line/teste.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
}
