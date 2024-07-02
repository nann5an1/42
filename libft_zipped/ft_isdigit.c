/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:49:18 by nsan              #+#    #+#             */
/*   Updated: 2024/05/31 23:56:34 by marvin           ###   ########.fr       */
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
