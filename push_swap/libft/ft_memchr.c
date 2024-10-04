/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:52:09 by nsan              #+#    #+#             */
/*   Updated: 2024/06/01 17:52:09 by nsan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
// int main () {
//     const char str[] = "https://www.tutorialspoint.com";
//     const char ch = '.';
//     char *ret;

//     printf(memchr(str, ch, 60));
//     printf(ft_memchr(str,ch, 60));
//     return(0);
// }

// int main() {
//     // Test case 1: Character found within the string
//     const char str1[] = "tutorialspoint.com";
//     char ch1 = '.';
//     char *result1 = ft_memchr(str1, ch1, strlen(str1));
//     if (result1 != NULL) {
//         printf("Test 1: String after |%c| is - |%s|\n", ch1, result1);
//     } else {
//         printf("Test 1: Character |%c| not found.\n", ch1);
//     }

//     // Test case 2: Character not found within the string
//     const char str2[] = "tutorialspoint.com";
//     char ch2 = 'z';
//     char *result2 = ft_memchr(str2, ch2, strlen(str2));
//     if (result2 != NULL) {
//         printf("Test 2: String after |%c| is - |%s|\n", ch2, result2);
//     } else {
//         printf("Test 2: Character |%c| not found.\n", ch2);
//     }

//     // Test case 3: Character found at the beginning of the string
//     const char str3[] = "tutorialspoint.com";
//     char ch3 = 't';
//     char *result3 = ft_memchr(str3, ch3, strlen(str3));
//     if (result3 != NULL) {
//         printf("Test 3: String after |%c| is - |%s|\n", ch3, result3);
//     } else {
//         printf("Test 3: Character |%c| not found.\n", ch3);
//     }

//     // Test case 4: Character found at the end of the string
//     const char str4[] = "tutorialspoint.com";
//     char ch4 = 'm';
//     char *result4 = ft_memchr(str4, ch4, strlen(str4));
//     if (result4 != NULL) {
//         printf("Test 4: String after |%c| is - |%s|\n", ch4, result4);
//     } else {
//         printf("Test 4: Character |%c| not found.\n", ch4);
//     }

//     // Test case 5: Searching for null character
//     const char str5[] = "tutorialspoint.com";
//     char ch5 = '\0';
//     char *result5 = ft_memchr(str5, ch5, strlen(str5) + 1);
// Including null character
//     if (result5 != NULL) {
//         printf("Test 5: Null character found\n");
//     } else {
//         printf("Test 5: Null character not found\n");
//     }

//     // Test case 6: Empty string
//     const char str6[] = "";
//     char ch6 = 'a';
//     char *result6 = ft_memchr(str6, ch6, strlen(str6));
//     if (result6 != NULL) {
//         printf("Test 6: String after |%c| is - |%s|\n", ch6, result6);
//     } else {
//         printf("Test 6: Character |%c| not found.\n", ch6);
//     }

//     return (0);
// }
