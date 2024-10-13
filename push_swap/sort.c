/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:07:41 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 13:07:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct_node	*check_first_two(t_struct_node **stack_a)
{
	t_struct_node	*stackb;
	int				i;
	int				min;
	int				pos;

	stackb = NULL;
	i = -1;
	while (++i < 2)
	{
		min = val_min (*stack_a);
		pos = find_pos (*stack_a, min);
		if (pos <= 2)
		{
			while ((*stack_a)->data != min)
				rotate (stack_a, "ra\n");
		}
		else
		{
			while ((*stack_a)->data != min)
				r_rotate (stack_a, "rra\n");
		}
		push (&stackb, stack_a, "pb\n");
	}
	return (stackb);
}

void	sort_three(t_struct_node **stack)
{
	int	min;
	int	max;

	while (!is_sorted(*stack))
	{
		max = val_max(*stack);
		min = val_min(*stack);
		if ((*stack)->data == max)
		{
			rotate(stack, "ra\n");
			if ((*stack)->next->data == min && \
			(*stack)->next->next->data == max)
				swap(stack, "sa\n");
		}
		else if ((*stack)->next->data == min && \
		(*stack)->next->next->data == max)
			swap(stack, "sa\n");
		else
			rotate(stack, "ra\n");
	}
}

void	sort_four(t_struct_node **stack_a)
{
	int				min;
	t_struct_node	*stackb;

	if (is_sorted(*stack_a))
		return ;
	min = val_min (*stack_a);
	while ((*stack_a)->data != min)
		rotate (stack_a, "ra\n");
	push (&stackb, stack_a, "pb\n");
	sort_three (stack_a);
	push (stack_a, &stackb, "pa\n");
}

void	sort_five(t_struct_node **stack_a)
{
	t_struct_node	*stackb;
	int				i;
	int				min;
	int				pos;

	i = -1;
	if (is_sorted(*stack_a))
		return ;
	stackb = check_first_two(stack_a);
	sort_three(stack_a);
	while (stackb != NULL)
		push (stack_a, &stackb, "pa\n");
}

void	simple_sort(t_struct_node **stackA, int node_count)
{
	if (node_count == 2)
	{
		if ((*stackA)->data > (*stackA)->next->data)
			swap (stackA, "sa\n");
	}
	else if (node_count == 3)
		sort_three (stackA);
	else if (node_count == 4)
		sort_four (stackA);
	else if (node_count == 5)
		sort_five (stackA);
}
