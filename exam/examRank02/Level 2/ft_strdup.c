/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:07:01 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 10:07:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
    char *strmalloc;
    int i = 0;

    while(src[i] != '\0')
        i++;
    strmalloc = (char *)malloc(sizeof(char) * (i + 1));
    if(strmalloc == NULL)
        return (NULL);
    i = 0;
    while(src[i] != '\0')
    {
        strmalloc[i] = src[i];
        i++;
    }
    strmalloc[i] = '\0';
    return (strmalloc);
}
// int main(void)
// {
//     char *src = "hello";
//     char *res= ft_strdup(src);
//     printf("%s", res);
// }