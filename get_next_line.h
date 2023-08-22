/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:39:04 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/22 19:53:46 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

/**@brief Creates a new node of the linked list and put a buffer
 * character in the node.
 * 
 * @param c the character to be placed
 * @return The new node
 * */
t_list			*get_char_node(char c);

/**@brief Puts the node at the end of the linked list.
 * If don't ecxist list, the new node will be the head of list.
 * 
 * @param lst the list
 * @param new the new node
 * */
void			put_in_pos(t_list **lst, t_list *new);

/**@brief frees the allocated memory if the read returns -1.
 * 
 * @param line the list to be freed
 * @return null pointer
 * */
char			*free_file(t_list *line);

typedef struct s_file{
	int			pos;
	int			nb_read;
	int			len;
	int			fd;
	char		buf[BUFFER_SIZE];
	t_list		*line;
}t_file;

/**@brief The principal function, defines the value of variables inside struct
 * cleans the buffer, and makes the first read. 
 * 
 * @param fd the int representing a file descriptor
 * @return a string passed as a parameter to the read_line function
 * */
char			*get_next_line(int fd);

/**@brief Makes a loop to read the file, create new nodes with each character
 * read, counts the size of bytes stored until it finds \n or \0
 * 
 * @param temp a struct with multiple variables
 * @return a string passed as a parameter to the get_current_line function
 * */
char			*read_line(t_file *temp);

/**@brief creates a new string and copy each character from the list into it
 * 
 * @param set a struct with multiple variables 
 * @return a string with the line
 * */
char			*get_current_line(t_file *set);

#endif