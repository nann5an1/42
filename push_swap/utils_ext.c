/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:35 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 15:59:38 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_min(t_struct_node *ref)
{
	t_struct_node	*min_node;

	min_node = ref;
	if (ref == NULL)
		return (0);
	while (ref)
	{
		if (ref->data < min_node->data)
			min_node = ref;
		ref = ref->next;
	}
	return (min_node->data);
}

int	val_max(t_struct_node *ref)
{
	t_struct_node	*max_node;

	max_node = ref;
	if (ref == NULL)
		return (0);
	if (ref->next == NULL)
		return (max_node->data);
	while (ref)
	{
		if (ref->data > max_node->data)
			max_node = ref;
		ref = ref->next;
	}
	return (max_node->data);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	find_pos(t_struct_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->data == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
