/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:01:30 by nsan              #+#    #+#             */
/*   Updated: 2024/05/31 23:55:45 by marvin           ###   ########.fr       */
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
