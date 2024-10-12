/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:41:50 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 17:41:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int    ft_lstsize_struct(t_struct_node *lst)
{
    ft_lstsize((t_list *)lst);
}

int is_sorted(t_struct_node *ref)
{
    int flag;
    t_struct_node *current;

    current = ref;
    while(current->next != NULL)
    {
        if (current->data > current->next->data)  //not sorted
            return (0);
        current = current->next;
    }
    return (1);
    printf("stack is already sorted");
}