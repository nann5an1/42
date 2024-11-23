/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:56:20 by nsan              #+#    #+#             */
/*   Updated: 2024/06/03 11:56:23 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!(ft_isalpha(c) || ft_isdigit(c)))
		return (0);
	return (8);
}

/* int	main(void)
{
	printf("%d", ft_isalnum('c'));
	printf("%d", ft_isalnum('b'));
	printf("%d", ft_isalnum('1'));
	printf("%d", ft_isalnum('+'));
	printf("%d\n", isalnum('z'));
} */
