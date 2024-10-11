/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:16:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 22:16:44 by marvin           ###   ########.fr       */
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

void radix(t_struct_node **stackA, t_struct_node **stackB, t_temp *temp, int len)
{
    int j;
    // int k;
    // k = 0;
    j = 1;
    while (j <= len)
    {
            if (((*stackA)->data >> temp->i) & 1)
            {
                push(stackB, stackA, "pb\n");
                // k++;
                rotate(stackB, "rb\n");
                temp->k++;
            }
            else
                rotate(stackA, "ra\n");
         j++;
    }
    // if (k > 0)
    // {
    //     j = -1;
    //     while (++j < k)
    //     {
    //         push(stackA, stackB, "pa\n");
    //         if (j < k - 1)
    //             rotate(stackA, "ra\n");
    //     }
    // }
    j = -1;
    if ((*stackB) != NULL)
    {
        while (++j < temp->k)
        {
            push(stackA, stackB, "pa\n");
            // if (j < temp->k - 1)
            rotate(stackA, "ra\n");
        }
    }
    // show_lst(*stackA);
}
    
