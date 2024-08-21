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
char	*ft_strpbrk(const char *s1, const char *s2) //this func: returns the pointer of the first occurence of the chrac: from the searched string
{
    int j = 0;
    int i = 0;
    char *S1 = (char *)s1;
    char *S2 = (char *)s2;
    if (S1 == NULL || S2 == NULL)
        return (NULL);
    while(S1[i] != '\0')
    {
        j = 0;
        while(S2[j] != '\0')
        {
            if(S1[i] == S2[j])
                return (&S1[i]);
            j++;
        }
        i++;
    }
    return (&S1[i]);
}

// int main()
// {
//     const char *s1 = "The cat carlos";
//     const char *s2 = "car";
//     char *res = ft_strpbrk(s1, s2);
//     printf("The first occurrence of any of the characters \"%s\" in "
//           "\"%s\" is \"%s\"\n", s2, s1, res);
// }