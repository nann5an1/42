/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:32:42 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:27:23 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/* int main()
{
	printf("%zu\n", isascii('f'));
	printf("%zu\n", isascii(128));
	printf("%zu\n", ft_isascii('f'));
	printf("%zu\n", ft_isascii(128));
} */
