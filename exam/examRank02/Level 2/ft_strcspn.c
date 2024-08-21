/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:38:20 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 13:38:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this function returns the index of the chracter that is found in "s" specified by the "reject"
#include <stdio.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    while(s[i] != '\0')
    {
        j = 0;
        while(reject[j] != '\0')
        {
            if(s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main()
{
    char *s1 = "world";
    char *s2 = "dr";
    size_t res = ft_strcspn(s1, s2);
    printf("%d", res);
}