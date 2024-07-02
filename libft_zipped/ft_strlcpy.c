/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:35 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:53:37 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sr_len;

	i = 0;
	sr_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (sr_len);
}

// int main(void)
// {
//     size_t len;
//     char dest[20] = "Hola";
//     const char *str="Hello world!!!";
//     len = ft_strlcpy(dest, str, 3);
//     printf("%zu\n", len);
// }