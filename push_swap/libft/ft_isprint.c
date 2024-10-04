/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:32:52 by nsan              #+#    #+#             */
/*   Updated: 2024/05/31 23:56:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isprint('5'));
	printf("%d", ft_isprint('C'));
	printf("%d", ft_isprint('2'));
	printf("%d", ft_isprint('+'));
	printf("%d", ft_isprint('-'));
	printf("%d", ft_isprint('\n'));
}*/
