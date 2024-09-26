/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:46:50 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 16:49:56 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		current = *begin_list;
		while (current->next != NULL)
			current = current->next;
		current->next = new_elem;
	}
}
