/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:20 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:20 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (d == NULL && s == NULL)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;
		char src[] = "hello";
		char dest[10] = "world";
		char src[] = "hello";
		char dest[10] = "world";
		char buffer[20] = "overlaptest";
		char buffer[20] = "overlaptest";
		int src[] = {1, 2, 3, 4, 5};
		int dest[5] = {0};
		char src[1000];
		char dest[1000];
	int		match;
		char src[] = "hello";
		char dest[5] = "world";

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (d == NULL && s == NULL)
	{
		return (dest);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
} */
// int main()
// {
//     // char src[] = "hello";
//     // char dest[5] = "world";
//     // char src1[] = "hello";
//     // char dest1[5] = "world";
//     // puts(memcpy(dest, src, 4));
//     // puts(ft_memcpy(dest1,src1, 4));
// }
/* void test_ft_memcpy() {
	// Test Case 1: Basic Functionality
	{
		ft_memcpy(dest, src, 5);
		dest[5] = '\0';  // Null-terminate the string
		printf("Test Case 1 - Expected: hello, Got: %s\n", dest);
	}
	// Test Case 2: Zero Bytes Copy
	{
		ft_memcpy(dest, src, 0);
		printf("Test Case 2 - Expected: world, Got: %s\n", dest);
	}
	// Test Case 3: Overlapping Memory (src < dest)
	{
		ft_memcpy(buffer + 5, buffer, 5);
		printf("Test Case 3 - Expected: overlverlaptest, Got: %s\n", buffer);
	}
	// Test Case 4: Overlapping Memory (dest < src)
	{
		ft_memcpy(buffer, buffer + 5, 5);
		printf("Test Case 4 - Expected: testlaptest, Got: %s\n", buffer);
	}
	// Test Case 5: Copying Non-Character Data
	{
		ft_memcpy(dest, src, 5 * sizeof(int));
		printf("Test Case 5 - Expected: {1, 2, 3, 4, 5}, Got: {");
		for (int i = 0; i < 5; i++) {
			printf("%d", dest[i]);
			if (i < 4) printf(", ");
		}
		printf("}\n");
	}
	// Test Case 6: Large Copy
	{
		for (int i = 0; i < 1000; i++) {
			src[i] = (char)(i % 256);
		}
		ft_memcpy(dest, src, 1000);
		match = 1;
		for (int i = 0; i < 1000 && match; i++) {
			if (dest[i] != src[i]) {
				match = 0;
			}
		}
		printf("Test Case 6 - \
		Expected: Match, Got: %s\n", match ? "Match" : "Mismatch");
	}
	// Test Case 7: \
		Buffer Overflow Test (should not crash but shows undefined behavior)
	// Uncomment to test buffer overflow; \
		expect potential crash or undefined behavior.
	{
		ft_memcpy(dest, src, 10);
		printf("Test Case 7 - Undefined Behavior - Result: %s\n", dest);
	}
}

int	main(void) {
	test_ft_memcpy();
	return (0);
} */