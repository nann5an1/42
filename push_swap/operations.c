/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:41:18 by nsan              #+#    #+#             */
/*   Updated: 2024/08/30 22:06:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getLength(t_struct_node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return (length);
}

int getMed(t_struct_node *head)
{
    t_struct_node *ref = head;
    int total = 0;
    while (head)
    {
        total += head->data;
        head = head->next;
    }
    head = ref;
    int node_count = getLength(head);
    int med = total / node_count;
    return (med);
}

void do_op(t_struct_node *stackA) // t_struct_node points to the first head of the linked list
{
    t_struct_node *ref = stackA; //(*stackA is the head ref to its stack pointer)
    t_struct_node *stackB = NULL;

    int med = getMed(stackA);
    while(stackA)
    {
        if(stackA->data < med)
            push(&stackB, &stackA);
        stackA = stackA->next;
    }
    stackA = ref;
    show_lst(stackA, stackB);
}
