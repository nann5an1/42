/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:36:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 17:36:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int minVal(t_struct_node *ref)
{
    if(ref == NULL)
        return (0);
    t_struct_node* min_node = ref;
    while(ref)
    {
        if(ref->data < min_node->data)
            min_node = ref;
        ref = ref->next;
    }
    return (min_node->data);
}

int maxVal(t_struct_node *ref)
{
    if(ref == NULL)
        return (0);
    t_struct_node* max_node = ref;

    if (ref->next == NULL)
        return (max_node->data);
    while(ref)
    {
        if(ref->data > max_node->data)
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