/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:28:20 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 15:28:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strchr(const char *accept, int c)
{
    while(*accept != '\0')
    {
        if(*accept == c)
            return ((char *)accept);
        accept++;
    }
    return (0);
}
size_t	ft_strspn(const char *s, const char *accept) //this func: returns the bytes that the "s" found matching with all the chars: in "accept", else return (0)
{
    size_t i = 0;
    while(s[i] != '\0')
    {
        if(ft_strchr(accept, s[i]) == 0)
            break;
        i++;
    }
    return (i);
}

// int ft_strchr(const char *accept, char c)
// {
//     int i = 0;
//     while(accept[i] != '\0')
//     {
//         if(c == accept[i])
//             return (1);
//         i++;
//     }
//     return (0);
// }

// size_t	ft_strspn(const char *s, const char *accept)
// {
//     int i = 0;
//     while(s[i] != '\0')
//     {
//         if(ft_strchr(accept, s[i]) == 0)
//             break;
//         i++;
//     }
//     return (i);
// }

int main()
{
    char *string = "gae";
    char *source = "abc";
    int index;
 
    index = ft_strspn( string, source );
    printf( "The first %d characters of \"%s\" are found in \"%s\"\n",
          index, string, source );
    
}