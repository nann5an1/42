/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:15 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:15 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*sr1;
	unsigned char	*sr2;
	size_t			i;

	sr1 = (unsigned char *)str1;
	sr2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
	}
	return (0);
}

// int main () {
//    char str1[15];
//    char str2[15];
//    int ret;

//    memcpy(str1, "abcdef", 6);
//    memcpy(str2, "ABCDEF", 6);
//    ret = memcmp(str1, str2, 5);
//    if(ret > 0) {
//       printf("str2 is less than str1");
//    } else if(ret < 0) {
//       printf("str1 is less than str2");
//    } else {
//       printf("str1 is equal to str2");
//    }
//    return(0);
// }

// int main() {
//     // Test Case 1: Equal memory blocks
//     const char str1[] = "Hello";
//     const char str2[] = "Hello";
//     int result1 = ft_memcmp(str1, str2, sizeof(str1));
//     printf("Test 1: Result of comparison: %d\n", result1);

//     // Test Case 2: Different memory blocks (first block smaller)
//     const char str3[] = "Hello";
//     const char str4[] = "Hellp";
//     int result2 = ft_memcmp(str3, str4, sizeof(str3));
//     printf("Test 2: Result of comparison: %d\n", result2);

//     // Test Case 3: Different memory blocks (second block smaller)
//     const char str5[] = "Hellp";
//     const char str6[] = "Hello";
//     int result3 = ft_memcmp(str5, str6, sizeof(str6));
//     printf("Test 3: Result of comparison: %d\n", result3);

//     // Test Case 4: Equal memory blocks with specified size
//     const char str7[] = "Hello";
//     const char str8[] = "Hello";
//     int result4 = ft_memcmp(str7, str8, 3);
//     printf("Test 4: Result of comparison: %d\n", result4);

//     // Test Case 5: Equal memory blocks with different sizes
//     const char str9[] = "Hello";
//     const char str10[] = "Hello";
//     int result5 = ft_memcmp(str9, str10, sizeof(str9));
//     printf("Test 5: Result of comparison: %d\n", result5);

//     return (0);
// }