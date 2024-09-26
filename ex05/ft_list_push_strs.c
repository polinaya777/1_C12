/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyarova <pyarova@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:51:10 by pyarova           #+#    #+#             */
/*   Updated: 2024/09/26 16:54:41 by pyarova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*new_list;
	t_list	*new_elem;

	new_list = NULL;
	i = 0;
	while (i < size)
	{
		new_elem = ft_create_elem(strs[i]);
		if (new_elem)
		{
			new_elem->next = new_list;
			new_list = new_elem;
		}
	}
	return (new_list);
}
