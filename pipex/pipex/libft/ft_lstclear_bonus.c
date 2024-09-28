/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:01:10 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:20:18 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_list;

	if (!*lst || !lst)
		return ;
	while (*lst && del)
	{
		current_list = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = current_list;
	}
	*lst = NULL;
}
// current_list has to be initialized since the deletion of
// the content will delete the next as well