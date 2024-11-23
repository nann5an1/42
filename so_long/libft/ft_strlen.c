/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:41 by nsan              #+#    #+#             */
/*   Updated: 2024/10/23 17:45:50 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str && str[i] != '\0')
		i++;
	return (i);
}
/* int	main(void)
{
	const	char *str = "a string";
	printf("%zu", ft_strlen(str));
} */
