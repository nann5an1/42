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
    printf("Before sorted stack:\n");
    show_lst(*stack);
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
    //show_lst(*stack);
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
    //show_lst(*stackA);
}

void    sort_five(t_struct_node **stackA)
{
    t_struct_node *stackB;

    while (is_sorted(*stackA) != 1)
    {
        if (minNode(*stackA) == 4 || maxNode(*stackA) == 4)
            r_rotate(stackA);
        else if (minNode(*stackA) == 1 || maxNode(*stackA) == 1)
            swap(stackA);
        else if (minNode(*stackA) == 3 || maxNode(*stackA) == 3)
        {
            r_rotate(stackA);
            r_rotate(stackA);
        }
        push(&stackB, stackA);
        sort_four(stackA);
        push(stackA, &stackB);
        if (is_sorted(*stackA) == 1)
            break;
        rotate(stackA);
    }
    show_lst(*stackA);
}