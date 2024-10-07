/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:07:56 by nsan              #+#    #+#             */
/*   Updated: 2024/10/07 12:57:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (0);
	return (1024);
}

/* int	main(void)
{
	printf("%d", ft_isalpha('5'));
	printf("%d\n", ft_isalpha('C'));
	printf("%d", ft_isalpha('2'));
	printf("%d", ft_isalpha('+'));
	printf("%d", ft_isalpha('-'));
	printf("%d", isalpha('4'));
} */
