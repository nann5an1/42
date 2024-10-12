/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:24:26 by marvin            #+#    #+#             */
/*   Updated: 2024/10/08 11:24:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int max_bits(t_struct_node **stackA)
{
    int max;
    int max_bits;
    t_struct_node *ref;

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

void    sort_radix(t_struct_node **stackA)
{
    t_struct_node   *ref;
    t_struct_node   *stackB;
    int bit_index;
    int size;
    int i;

    i = 0;
    stackB = NULL;
    bit_index = 0;
    size = ft_lstsize_struct(*stackA);
    while (bit_index < max_bits(stackA))
    {
        i = -1;
        while (++i < size)
        {
            ref = *stackA;
            if (((ref->data >> bit_index) & 1 ) == 1)
                rotate(stackA, "ra\n");
            else
                push(&stackB, stackA, "pb\n");
        }
        while (stackB != NULL)
            push(stackA, &stackB, "pa\n");
        bit_index++;
    }
}
