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
    printf("max node: %d\n", maxNode(*stack));
    printf("min node: %d\n", minNode(*stack));
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
        
    }
    printf("Sorted stack:\n");
    show_lst(*stack);
}

void    sort_four(t_struct_node **stackA)
{
    t_struct_node   *stackB;
    int min_index;
    int max_index;
    
    stackB = NULL;
    
    if (is_sorted(*stackA) == 1)
    {
        printf("The stack 4 is already sorted");
        return ;
    }

    while (is_sorted(*stackA) != 1)
    {
        min_index = minNode(*stackA);
        max_index = maxNode(*stackA);

        if (min_index == 0 || max_index == 0)
            push(&stackB, stackA);
        if (min_index == 3 || max_index == 3)
            r_rotate(stackA);
        else
            swap(stackA);
        if (getLength(*stackA) <= 3)
        {
            sort_three(stackA);
            while (stackB)
            {
                push(stackA, &stackB);
            }
        }
    }
    printf("Sorted stack in sort 4:\n");
    show_lst(*stackA);
}