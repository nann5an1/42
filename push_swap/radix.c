/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:07 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 15:59:07 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_struct_node **stackA)
{
	int				max;
	int				max_bits;
	t_struct_node	*ref;

	max_bits = 0;
	ref = *stackA;
	max = ref->data;
	while (ref != NULL)
	{
		if (ref->data > max)
			max = ref->data;
		ref = ref->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_struct_node **stackA)
{
	t_struct_node	*ref;
	t_struct_node	*stack_b;
	int				bit_index;
	int				size;
	int				i;

	i = 0;
	stack_b = NULL;
	bit_index = 0;
	size = ft_lstsize_struct (*stackA);
	while (bit_index < max_bits (stackA))
	{
		i = -1;
		while (++i < size)
		{
			ref = *stackA;
			if (((ref->data >> bit_index) & 1) == 1)
				rotate (stackA, "ra\n");
			else
				push (&stack_b, stackA, "pb\n");
		}
		while (stack_b != NULL)
			push (stackA, &stack_b, "pa\n");
		bit_index++;
	}
}
