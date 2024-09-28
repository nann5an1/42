/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:54:07 by nsan              #+#    #+#             */
/*   Updated: 2024/06/03 13:06:18 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;
	char	*hay;
	char	*n;

	hay = (char *)big;
	n = (char *)little;
	if (!*n)
		return ((char *)hay);
	needle_len = ft_strlen(n);
	while (*hay && len >= needle_len)
	{
		if (ft_strncmp(hay, n, needle_len) == 0)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
