/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:45:17 by namoreir          #+#    #+#             */
/*   Updated: 2023/08/21 11:32:38 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_char_node(char c)
{
	t_list	*set;

	set = (t_list *)malloc(sizeof(t_list));
	set->char_read = c;
	set->next = NULL;
	return (set);
}

void	put_in_pos(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

char	*free_file(t_list *line)
{
	t_list	*temp;

	temp = line;
	while (temp)
	{
		temp = temp->next;
		free(line);
		line = temp;
	}
	temp = NULL;
	return (NULL);
}
