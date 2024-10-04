/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:47:05 by nsan              #+#    #+#             */
/*   Updated: 2024/05/31 23:54:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*a;

	a = (int *)malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, nmemb * size);
	return (a);
}
// nmemb is the number of elements
// size is the bytes of each element
/* int main()
{
	int *a;
	void *ptr;

	a = (int *)calloc(10, 3);
	ptr = ft_calloc(10, 3);
	printf("calloc: %p\n", (void *)a);
	printf("ft_calloc: %p\n", ptr);

	// Don't forget to free the memory allocated by calloc and ft_calloc
	free(a);
	free(ptr);

	return (0);
} */
