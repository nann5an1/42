/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:06:41 by nsan              #+#    #+#             */
/*   Updated: 2024/06/24 19:13:10 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_nlen(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *str, int *len)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_char_nlen(str[i], len);
		i++;
	}
}
