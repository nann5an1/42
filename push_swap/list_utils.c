/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:53:40 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 21:19:22 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_struct(t_struct_node *lst)
{
	return (ft_lstsize ((t_list *)lst));
}

int	is_sorted(t_struct_node *ref)
{
	t_struct_node	*current;

	current = ref;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
