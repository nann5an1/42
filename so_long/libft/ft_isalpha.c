/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:56:27 by nsan              #+#    #+#             */
/*   Updated: 2024/06/03 11:56:29 by nsan             ###   ########.fr       */
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
