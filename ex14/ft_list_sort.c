/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:55:46 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 20:43:09 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next_node;
	void	*temp_data;

	if (*begin_list == NULL)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		next_node = current->next;
		while (next_node != NULL)
		{
			if ((*cmp)(current->data, next_node->data) > 0)
			{
				temp_data = current->data;
				current->data = next_node->data;
				next_node->data = temp_data;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}
