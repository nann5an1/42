/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:38:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct_node *cloned(t_struct_node* head)
{
    if (head == NULL)
        return (NULL);
    t_struct_node *new_head = (t_struct_node*)malloc(sizeof(t_struct_node));
    new_head->data = head->data;
    new_head->next = cloned(head->next);
    return (new_head);
}

t_struct_node* sort_ascend(t_struct_node* head)
{
    int temp;
    t_struct_node* ref = head;
    t_struct_node* next_node;
    while(ref != NULL)
    {
        next_node = ref->next;
        while(next_node != NULL)
        {
            if(ref->data > next_node->data)
            {
                temp = ref->data;
                ref->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        ref = ref->next;
    }
    return (head);
}

void    lst_to_array(int *array, t_struct_node *cloned_A, int lst_size)
{
    int i = -1;
    while (++i < lst_size)
    {
        array[i] = cloned_A->data;
        cloned_A = cloned_A->next;
    }
}

int    find_index_in_sorted(int *array, int value, int lst_size)
{
    int i;
    i = -1;
    while (++i < lst_size)
    {
        if (array[i] == value)
            return (i);
    }
    return (-1);
}

void    index_replace(t_struct_node **stackA)
{
    t_struct_node   *temp_stack;
    t_struct_node   *original_cloned_stackA;
    t_struct_node   *cloned_stackA;
    t_struct_node   *cloned_sorted;

    int lst_size = ft_lstsize_struct(*stackA);
    cloned_stackA = cloned(*stackA);
    cloned_sorted = sort_ascend(cloned_stackA);

    int *array = (int*)malloc(sizeof(int) * lst_size);
    lst_to_array(array, cloned_sorted, lst_size);
    temp_stack = *stackA;
    while (temp_stack)
    {
        int value = temp_stack->data;
        int index = find_index_in_sorted(array, value, lst_size);
        temp_stack->data = index;
        temp_stack = temp_stack->next;
    }
    free (array);
}

