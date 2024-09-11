/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:14 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 14:33:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    char *S1 = (char *)s1;
    char *S2 = (char *)s2;
    int i = 0;
    int j;
    while(S1[i])
    {
        j = 0;
        while(S2[j])
        {
            if(S1[i] == S2[j])
                return (&S1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}


// int main()
// {
//     char str1[] = "hello world";
//     char str2[] = "ow";
    
//     char *res = ft_strpbrk(str1, str2);
    
//     if (res)
//         printf("First matching character: %c\n", *res);
//     else
//         printf("No matching characters found.\n");

//     return 0;
// }

int main()
{
    const char *s1 = "The cat carlos";
    const char *s2 = "car";
    char *res = ft_strpbrk(s1, s2);
    printf("The first occurrence of any of the characters \"%s\" in "
          "\"%s\" is \"%s\"\n", s2, s1, res);
}