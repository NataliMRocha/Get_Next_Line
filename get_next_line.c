/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:29:04 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/07 13:26:56 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}

int	main(const char *pathname, int BUFFER_SIZE)
{
	static int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd);
	close(fd);
	return (0);
}
