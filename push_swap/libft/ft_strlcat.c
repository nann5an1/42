/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:29 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:53:31 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	len_total;
	int		i;

	i = 0;
	len_src = ft_strlen((char *)src);
	len_dest = ft_strlen(dest);
	len_total = len_src + len_dest;
	if (size <= len_dest)
		return (size + len_src);
	while (src[i] && size - 1 > len_dest)
	{
		dest[len_dest++] = src[i++];
	}
	dest[len_dest] = '\0';
	return (len_total);
}

/* int main()
{
	char *dest = "Hello";
	const char *src = "world";
	size_t total_length = strlcat(dest, src, 1);
	printf("%zu, %s\n", total_length, dest);

	char dest1[5] = "Hello";
	const char *src1 = "world";
	size_t t_length = ft_strlcat(dest1, src1, 1);
	printf("%zu, %s\n", t_length, dest1);
} */