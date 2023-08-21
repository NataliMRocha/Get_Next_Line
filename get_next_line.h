/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:39:04 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/21 11:31:07 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list	t_list;
struct s_list{
	char	char_read;
	t_list	*next;
};

t_list			*get_char_node(char c);
void			put_in_pos(t_list **lst, t_list *new);
char			*free_file(t_list *line);

typedef struct s_file{
	int			pos;
	int			nb_read;
	int			len;
	int			fd;
	char		buf[BUFFER_SIZE];
	t_list		*line;
}t_file;

char			*get_next_line(int fd);
char			*read_line(t_file *file);
char			*get_current_line(t_file *file);

#endif