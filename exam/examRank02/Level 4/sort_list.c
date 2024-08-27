/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:35:07 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 22:35:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    if(lst == NULL || *lst ==NULL)
        return;
    t_list *head_ref;

    head_ref = lst;
    while(lst != NULL && lst->next != NULL)
    {
        if(cmp(lst->next, lst->next->next) == 0)
        {
            swap = lst->next;
            lst->next = lst->next->next;
            lst->next->next = swap;
            lst = head_ref;
        }
        else
            lst = lst->next;
    }
    return (start);
}