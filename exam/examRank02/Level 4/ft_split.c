/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:06:03 by marvin            #+#    #+#             */
/*   Updated: 2024/09/11 15:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
char *ft_strncpy(char *s1, char*s2, int len)
{
    int i = -1;
    while(++i < len && s2[i])
        s1[i] = s2[i];
    s1[i] = '\0';
    return (s1);
}

char **ft_split(char *str)
{
    int wc = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    while(str[i])
    {
        while(str[i] == ' ' || str[i] == '\t')
            i++;
        if(str[i])
            wc++;
        while( str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
    }
    char** out = (char**)malloc(sizeof(char*) * (wc + 1));
    i = 0;
    while(str[i])
    {
        while(str[i] && str[i] == ' ' || str[i] == '\t')
            i++;
        j = i;
        while( str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        if(i > j)
        {
            out[k] = (char *)malloc(sizeof(char *) * ((i - j) + 1));
            ft_strncpy(out[k++], &str[j], i-j);
        }
    }
    out[k] = NULL;
    return (out);
}

int main()
{
    char* str= "Hello World";
    char** res = ft_split(str);
    int i = 0;
    while (res[i])                     // Iterate through the result array
    {
        printf("%s\n", res[i]);        // Print each word followed by a newline
        i++;
    }
}