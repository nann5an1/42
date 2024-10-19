/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:56:36 by nsan              #+#    #+#             */
/*   Updated: 2024/10/17 16:44:06 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isdigit('5'));
	printf("%d\n", ft_isdigit(2));
	printf("%d", ft_isdigit('a'));
	printf("%d", ft_isdigit('+'));
	printf("%d", ft_isdigit('/'));
	printf("%d", isdigit('2'));
} */
