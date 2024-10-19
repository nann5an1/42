/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:56:43 by nsan              #+#    #+#             */
/*   Updated: 2024/06/03 11:56:45 by nsan             ###   ########.fr       */
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
