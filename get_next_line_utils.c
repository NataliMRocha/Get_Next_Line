/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:46:38 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/08 14:32:09 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
