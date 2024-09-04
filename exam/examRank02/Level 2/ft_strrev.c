/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:10:44 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 15:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char    *ft_strrev(char *str) //reverse the string in place
{
    int i = 0;
    int j = 0;
    char temp;
    while(str[j] != '\0')
        j++;
    while(i < j / 2)
    {
        temp = str[i];
        str[i] = str[j - i - 1];
        str[j - i - 1] = temp;
        i++;
    }
    return (str);
}
int main()
{
    char s[] = "coding is fun";
    char *res = ft_strrev(s);
    printf("%s", res);
}