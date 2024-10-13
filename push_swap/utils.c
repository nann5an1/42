/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:38:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct_node	*cloned(t_struct_node *head)
{
	t_struct_node	*new_head;

	if (head == NULL)
		return (NULL);
	new_head = (t_struct_node *)malloc (sizeof(t_struct_node));
	new_head->data = head->data;
	new_head->next = cloned(head->next);
	return (new_head);
}

t_struct_node	*sort_ascend(t_struct_node *head)
{
	int				temp;
	t_struct_node	*ref;
	t_struct_node	*next_node;

	ref = head;
	while (ref != NULL)
	{
		next_node = ref->next;
		while (next_node != NULL)
		{
			if (ref->data > next_node->data)
			{
				temp = ref->data;
				ref->data = next_node->data;
				next_node->data = temp;
			}
			next_node = next_node->next;
		}
		ref = ref->next;
	}
	return (head);
}

void	lst_to_array(int *array, t_struct_node *cloned_A, int lst_size)
{
	int	i;

	i = -1;
	while (++i < lst_size)
	{
		array[i] = cloned_A->data;
		cloned_A = cloned_A->next;
	}
}

int	find_index_in_sorted(int *array, int value, int lst_size)
{
	int	i;

	i = -1;
	while (++i < lst_size)
	{
		if (array[i] == value)
			return (i);
	}
	return (-1);
}

void	index_replace(t_struct_node **stackA)
{
	t_struct_node	*temp_stack;
	t_struct_node	*org_cloned_stack_a;
	t_struct_node	*cloned_stack_a;
	t_struct_node	*cloned_sorted;
	int				*array;

	cloned_stack_a = cloned (*stackA);
	cloned_sorted = sort_ascend (cloned_stack_a);
	array = (int *)malloc (sizeof(int) * (ft_lstsize_struct (*stackA)));
	lst_to_array (array, cloned_sorted, ft_lstsize_struct (*stackA));
	temp_stack = *stackA;
	while (temp_stack)
	{
		temp_stack->data = find_index_in_sorted(array, \
		temp_stack->data, ft_lstsize_struct(*stackA));
		temp_stack = temp_stack->next;
	}
	free(cloned_stack_a);
	free (array);
}
