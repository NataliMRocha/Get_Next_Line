/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:58:48 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/10 18:05:34 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/nfs/homes/namoreir/Get_Next_Line/teste.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("%s", line);
}
