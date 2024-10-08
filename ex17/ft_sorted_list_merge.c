/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:07:25 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 20:44:34 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_insert_end(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_elem;
		return ;
	}
	current = *begin_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_elem;
}

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

void	ft_sorted_list_insert(t_list **begin_list, void *data,
		int (*cmp)(void *, void *))
{
	ft_list_insert_end(begin_list, data);
	ft_list_sort(begin_list, cmp);
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	if (begin_list2 == NULL)
		return ;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (begin_list2 != NULL)
	{
		ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
		begin_list2 = next_elem;
	}
}
