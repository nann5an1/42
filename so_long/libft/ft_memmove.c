/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:42:25 by nsan              #+#    #+#             */
/*   Updated: 2024/05/30 21:42:25 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sr;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (dest);
	dst = (char *)dest;
	sr = (char *)src;
	i = 0;
	if (sr < dst && sr + n > dst)
	{
		while (n--)
			dst[n] = sr[n];
	}
	else
	{
		while (n--)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dest);
}

// int main()
// {
//     char dest[] = "Hello World";
//     char src[] = "llo";
//     puts(memmove(dest, src, 3));
//     puts(ft_memmove(dest, src, 3));

//     // char dest1[] = "Hola";
//     // char src1[] = "Hello World";
//     // puts(memmove(dest1, src1, 12));
//     // puts(ft_memmove(dest1, src1, 12));
//     // puts(dest1);
// }
/* int main() {
	// Test case: Overlapping regions where dest is after src
	char buffer1[20] = "Hello, World!";
	ft_memmove(buffer1 + 7, buffer1 + 0, 5);
	printf("Test 1 (Overlapping, forward copy): %s\n", buffer1);

	// Test case: Overlapping regions where dest is before src
	char buffer2[20] = "Hello, World!";
	ft_memmove(buffer2 + 3, buffer2, 13);
	printf("Test 2 (Overlapping, backward copy): %s\n", buffer2);

	// Test case: Non-overlapping regions
	char buffer3[20] = "Hello, World!";
	char buffer4[20];
	ft_memmove(buffer4, buffer3, 13);
	printf("Test 3 (Non-overlapping): %s\n", buffer4);

	// Test case: src and dest are the same
	char buffer5[20] = "Hello, World!";
	ft_memmove(buffer5, buffer5, 13);
	printf("Test 4 (Same src and dest): %s\n", buffer5);

	return (0);
} */