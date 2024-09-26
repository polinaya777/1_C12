/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:59:57 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 18:16:14 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_swap_data(t_list *a, t_list *b)
{
	void	*temp_data;

	temp_data = a->data;
	a->data = b->data;
	b->data = temp_data;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*front;
	t_list	*back;
	int		i;
	int		j;
	int		size;

	size = ft_list_size(begin_list);
	if (size <= 1)
		return ;
	i = 0;
	while (i < size / 2)
	{
		front = begin_list;
		back = begin_list;
		j = 0;
		while (j < size - i - 1)
		{
			back = back->next;
			j++;
		}
		ft_list_swap_data(front, back);
		begin_list = begin_list->next;
		i++;
	}
}
