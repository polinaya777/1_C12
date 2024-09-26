/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:40:45 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 17:44:53 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*temp;

	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			temp = current->next;
			current->next = current->next->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
			current = current->next;
	}
}
