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

void sort_three(t_struct_node **stack)
{
    int min;
    int max;
    //int node_count;
    //node_count = getLength(stack);
    
    printf("Before sorted stack:\n");
    show_lst(*stack);
    printf("%dmax node:\n", maxNode(*stack));
    printf("min node%d:\n", minNode(*stack));
    while(is_sorted(*stack) != 1)
    {
        if (maxNode(*stack) == 0)
        {
            rotate(stack);
            if(minNode(*stack) == 1 && maxNode(*stack) == 2)
                swap(stack);
        }
        else if(minNode(*stack) == 1 && maxNode(*stack) == 2)
            swap(stack);
        else
            rotate(stack);
        //show_lst(*stack);
    }
    printf("Sorted stack:\n");
    show_lst(*stack);
    
}

void    sort_four()
{
    
}