/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:53:24 by nsan              #+#    #+#             */
/*   Updated: 2025/01/04 21:20:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t ft_strlen(const char *s)
// {
// 	size_t	i = 0;
// 	char *str = (char *)s;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

//hello hi
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		total_len;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * total_len);
	if (!dest)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	// dest[i] = c;
    // i++;
	while (i < total_len)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

int main(void){
	char *dest = ft_strjoin("hello", "world");
	printf("%s\n", dest);
}
// int main(void)
// {
//     // Test 1: Normal concatenation
//     char *result1 = ft_strjoin("Hello, ", '/');
//     if (result1)
//     {
//         printf("Test 1: \"%s\"\n", result1); // Expected: "Hello, world!"
//         free(result1);
//     }
//     else
//     {
//         printf("Test 1: NULL\n");
//     }

//     // Test 2: Concatenating two empty strings
//     char *result2 = ft_strjoin("", '/');
//     if (result2)
//     {
//         printf("Test 2: \"%s\"\n", result2); // Expected: ""
//         free(result2);
//     }

//     else
//     {
//         printf("Test 2: NULL\n");
//     }

//     // Test 3: Concatenating non-empty and empty string
//     char *result3 = ft_strjoin("foo", '/');
//     if (result3)
//     {
//         printf("Test 3: \"%s\"\n", result3); // Expected: "foo"
//         free(result3);
//     }
// }
// //     else
// //     {
// //         printf("Test 3: NULL\n");
// //     }

// //     // Test 4: Concatenating empty and non-empty string
// //     char *result4 = ft_strjoin("", "bar", '/');
// //     if (result4)
// //     {
// //         printf("Test 4: \"%s\"\n", result4); // Expected: "bar"
// //         free(result4);
// //     }
// //     else
// //     {
// //         printf("Test 4: NULL\n");
// //     }

// //     // Test 5: Concatenating strings with spaces
// //     char *result5 = ft_strjoin("Hello, ", "world! How are you?", '/');
// //     if (result5)
// //     {
// //         printf("Test 5: \"%s\"\n", result5);
// // Expected: "Hello, world! How are you?";
// //         free(result5);
// //     }
// //     else
// //     {
// //         printf("Test 5: NULL\n");
// //     }

// //     // Test 6: Handling NULL input
// //     char *result6 = ft_strjoin(NULL, "world!", '/');
// //     if (result6)
// //     {
// //         printf("Test 6: \"%s\"\n", result6); // Expected: NULL
// //         free(result6);
// //     }
// //     else
// //     {
// //         printf("Test 6: NULL\n");
// //     }

// //     char *result7 = ft_strjoin("Hello, ", NULL, '/');
// //     if (result7)
// //     {
// //         printf("Test 7: \"%s\"\n", result7); // Expected: NULL
// //         free(result7);
// //     }
// //     else
// //     {
// //         printf("Test 7: NULL\n");
// //     }

// //     char *result8 = ft_strjoin(NULL, NULL, '/');
// //     if (result8)
// //     {
// //         printf("Test 8: \"%s\"\n", result8); // Expected: NULL
// //         free(result8);
// //     }
// //     else
// //     {
// //         printf("Test 8: NULL\n");
// //     }

// //     return (0);
// // }
