/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:47:41 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/23 14:39:01 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

/**@brief The principal function, makes a lopp do read the file
 * until find the \n 
 * 
 * @param fd the int representing a file descriptor
 * @return a string passed as a parameter to the read_line function
 * */
char		*get_next_line(int fd);

/**@brief Calculates the length of the string pointed to by 's',
 * before the terminating null byte ('\0') can be found.
 * 
 * @param s as a true C string, terminated by '\0'
 * @return The number of chars in the string.
*/
size_t		ft_strlen(const char *s);

/**@brief Looks for the first occurrence of the character 'c'
 * in the string 's'.
 * 
 * @param s a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the 
 * character is not found. The terminating null byte is considered 
 * part of the string.
*/
char		*ft_strchr(const char *s, int c);

/**@brief Duplicate the contents of string 's'. Memory for the
 * new string is obtained with malloc.
 * 
 * @param s a string
 * @return char * a pointer to the duplicate string.
 * It returns NULL if insufficient memory was available.
*/
char		*ft_strdup(const char *s);

/**@brief Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of 's1' and 's2'.
 * 
 * @param s1 the prefix string
 * @param s2 the suffix string
 * @return The new string. NULL if the allocation fails.
*/
char		*ft_strjoin(char const *s1, char const *s2);

#endif
