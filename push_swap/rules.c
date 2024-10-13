/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:31:51 by nsan              #+#    #+#             */
/*   Updated: 2024/10/13 20:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_struct_node **dest, t_struct_node **src, char *str)
{
	t_struct_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	write(1, str, 3);
}

void	swap(t_struct_node **headRef, char *str)
{
	t_struct_node	*first;
	t_struct_node	*second;

	first = *headRef;
	second = (*headRef)->next;
	if (*headRef == NULL || (*headRef)-> next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*headRef = second;
	write(1, str, 3);
}

void	rotate(struct node **headref, char *str)
{
	t_struct_node	*first;
	t_struct_node	*last;

	if (headref == NULL || (*headref)->next == NULL)
		return ;
	first = *headref;
	last = *headref;
	while (last->next != NULL)
		last = last->next;
	*headref = first->next;
	first->next = NULL;
	last->next = first;
	write(1, str, 3);
}

void	r_rotate(t_struct_node **headref, char *str)
{
	t_struct_node	*sec_last;
	t_struct_node	*last;

	last = *headref;
	sec_last = NULL;
	if (*headref == NULL || (*headref)-> next == NULL)
		return ;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *headref;
	*headref = last;
	write(1, str, 4);
}
