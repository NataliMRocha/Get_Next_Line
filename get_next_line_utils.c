/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:46:38 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/07 17:14:46 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 99

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n-- > 0)
	{
		*c = '\0';
		c++;
	}
}
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc_mem;
	size_t	total_size;

	total_size = nmemb * size;
	if ((nmemb == 0 || size == 0) || total_size / size != nmemb)
		return (NULL);
	alloc_mem = malloc(total_size);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, total_size);
	return (alloc_mem);
}

int ft_strchr(const char *s, unsigned char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	int	fd;
	static int	nb_read;
	char	buffer[BUFFER_SIZE];
	char	*result;
	int	i;
	fd = open("/nfs/homes/namoreir/GNL/teste.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read == -1)
		return (1);
	result = (char *)ft_calloc((nb_read + 1), sizeof(char));
	ft_strlcpy(result, buffer, nb_read);
	if (ft_strchr(result, '\n'))
	{
		i = 0;
		while(result[i] != '\n')
		{
			write(1, &result[i], 1);
			i++;
		}
		write (1, "\n", 1);
	}
	close(fd);
	return (0);
}
