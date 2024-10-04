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


int is_sorted(t_struct_node* ref)
{
    t_struct_node* current;

    current = ref;
    while(current)
    {
        if (current->data > ref->data)
            return (0);
        current = current->next;
    }
    printf("stack is already sorted");
    return (1);
}

int minNode(t_struct_node *ref)
{
    int index;
    int min_index;
    int min_value;

    min_value = INT_MAX;
    index = 0;
    min_index = 0;
    if(ref == NULL)
        return (0);
    while(ref)
    {
        if(ref->data < min_value)
        {
            min_value = ref->data;
            min_index = index;
        }
        index++;
        ref = ref->next;
    }
    return (min_index);
}

int maxNode(t_struct_node *ref)
{
    int index;
    int max_value;
    int max_index;
    
    index = 0;
    max_index = 0;
    max_value = INT_MIN;

    if(ref == NULL)
        return (0);
    //t_struct_node* max_node = ref;
    while(ref)
    {
        if(ref->data > max_value)
        {
            max_value = ref->data;
            max_index = index;
        }
        ref = ref->next;
        index++;
    }
    return (max_index);
}
t_struct_node	*ft_lstnew_struct(int data)
{
    t_struct_node *new;

    new = (t_struct_node *)malloc(sizeof(t_struct_node));
    if (!new)
		return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_back_struct(t_struct_node **lst, t_struct_node *new)
{
	ft_lstadd_back((t_list **)lst, (t_list *)new);
}

void show_lst(t_struct_node *stack) 
{
    printf("Stack A\t\t\n");
    while(stack != NULL)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }


    // printf("\n\n");
    // printf("Stack A\t\t");
    // while (stacka != NULL)
    // {
    //     printf("%d   ", stacka->data);
    //     stacka = stacka->next;
    // }
    // printf("\nStack B\t\t");
    // while (stackb != NULL)
    // {
    //     printf("%d   ", stackb->data);
    //     stackb = stackb->next;
    // }
    // printf("\n\n");
}