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
	char		*leitura_2;
	char		*concatenada;
	size_t	i = 0;
	size_t	size_str = 0;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	//Caso eu leia menos do que o buffer size, mudo buffer size para nb_read
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read == -1)
		return (1);
	//checo: nessa leitura eu achei um \n ?
	while(i <= nb_read)
	{
		if (buffer[i] == '\n')
			break;
		else
			i++;
	}
	//maloco espaço pra uma string de tamanho i, copio do buffer para essa nova string
	*leitura_1 = (char *)ft_calloc((i + 1), sizeof(char));
	ft_strlcpy(leitura_1, buffer, i);
	//se sim: sei q len da linha até o \n = i
	//dou free no buffer ??
	//ando o ponteiro do buffer até onde achei o \n
	//se existe \n e i < nb_read preciso salvar o que li após o \n em uma string
	//retorno a nova string

	//se não:
	//andei até o fim do que li e não achei a linha
	if (i > nb_read)
	{
		while(read)
		*leitura_2 = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		nb_read = read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while(i <= nb_read)
		{
			if (buffer[i] == '\n')
				break;
			else
			i++;
		}
		ft_strlcpy(leitura_2, buffer, i);
		concatenada = ft_strjoin(leitura_1, leitura_1);
		//se i < nb_read preciso pegar o resto da string e copiar numa string e salvar
		
	}	
	close(fd);
	//retorno a string
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
