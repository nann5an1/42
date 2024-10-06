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

void main_sort4(t_struct_node **stackA, t_struct_node *stackB)
{
    push(&stackB, stackA);
    sort_three(stackA);
    push(stackA, &stackB);
}

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
    
    stackB = NULL;
    while (is_sorted(*stackA) != 1)
    {
        if (maxNode(*stackA) == 0 || minNode(*stackA) == 0)
        {
            main_sort4(stackA, stackB);
            if (is_sorted(*stackA) == 1)
                break;
            rotate(stackA);
        }
        else if (minNode(*stackA) == 3 || maxNode(*stackA) == 3)
        {
            r_rotate(stackA);
            if (is_sorted(*stackA) == 1)
                break;
            main_sort4(stackA, stackB);
            rotate(stackA);
        }
        else
            swap(stackA);
    }
    show_lst(*stackA);
}