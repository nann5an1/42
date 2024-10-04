/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:44:47 by nsan              #+#    #+#             */
/*   Updated: 2024/06/03 08:56:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)(s);
	while (n--)
		str[i++] = 0;
}

/* // Test cases
void	test_basic(void) {
	char buffer[10] = "123456789";
	ft_bzero(buffer, sizeof(buffer));
	for (int i = 0; i < sizeof(buffer); i++) {
		if (buffer[i] != 0) {
			printf("Basic Test Case Failed!\n");
			return ;
		}
	}
	printf("Basic Test Case Passed!\n");
}

void	test_zero_sized_buffer(void) {
	char *buffer = NULL;
	ft_bzero(buffer, 0);
	printf("Zero-sized Buffer Test Case Passed!\n");
}

void	test_non_zero_values(void) {
	char buffer[5] = "12345";
	ft_bzero(buffer, sizeof(buffer));
	for (int i = 0; i < sizeof(buffer); i++) {
		if (buffer[i] != 0) {
			printf("Non-zero Values Test Case Failed!\n");
			return ;
		}
	}
	printf("Non-zero Values Test Case Passed!\n");
}

void	test_boundary(void) {
	char buffer[1000000]; // One megabyte buffer
	ft_bzero(buffer, sizeof(buffer));
	printf("Boundary Test Case Passed!\n");
}

void	test_performance(void) {
	const int size = 1000000; // One megabyte
	char *buffer = (char *)malloc(size);
	if (buffer == NULL) {
		printf("Memory allocation failed!\n");
		return ;
	}
	ft_bzero(buffer, size);
	free(buffer);
	printf("Performance Test Case Passed!\n");
}

void	test_null_pointer(void) {
	char *buffer = NULL;
	ft_bzero(buffer, 10);
	printf("NULL Pointer Test Case Passed!\n");
}

void	test_overlapping_memory(void) {
	char buffer[10] = "123456789";
	ft_bzero(&buffer[5], 5); // Overlapping memory
	for (int i = 0; i < sizeof(buffer); i++) {
		if (buffer[i] != 0) {
			printf("Overlapping Memory Test Case Failed!\n");
			return ;
		}
	}
	printf("Overlapping Memory Test Case Passed!\n");
}

int	main(void) {
	test_basic();
	test_zero_sized_buffer();
	test_non_zero_values();
	test_boundary();
	test_performance();
	test_null_pointer();
	test_overlapping_memory();
	return (0);
} */