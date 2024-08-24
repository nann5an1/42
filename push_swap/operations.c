/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:41:18 by nsan              #+#    #+#             */
/*   Updated: 2024/08/24 14:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_op_more(t_struct_node* stackA)
{
    t_struct_node* stackB = NULL;
    struct node* head = stackA;
    //get the no. of elements inside the stack
    //do comparison and sorting
    //res = send to stackB(function call) (use of rules)
   int count = getLength(stackA);
   int midPoint = getMid(stackA);

    while(count != 3)
    {
        if(head->data > midPoint)
        {
            push(&stackB, head->data);
            count--;
        }
        head = head->next;
    }
}
//finish the condition on stackA elements
//Then continue the stackB sorting