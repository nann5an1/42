/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:36:12 by marvin            #+#    #+#             */
/*   Updated: 2024/09/04 12:36:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// int getLen(long nb)
// {
//     int len = 0;
//     if(nb == 0)
//         len++;
//     if(nb < 0)
//     {
//         nb = -nb;
//         len++;
//     }
//     while(nb > 0)
//     {
//         nb /= 10;
//         len++;
//     }
//     return (len);
// }
// char	*ft_itoa(int nbr)
// {
//     int nb = nbr;
//     int len = getLen(nb);
//     char* size = (char *)malloc(sizeof(char) * (len + 1));

//     if(!size)
//         return (NULL);
//     size[len] = '\0';
//     if(nb < 0)
//         nb = -nb;
//     if(nb == 0)
//         size[len - 1] = 0;
//     while(--len >= 0)
//     {
//         size[len] = (nb % 10) + '0';
//         nb /= 10;
//     }
//     if(nbr < 0)
//         size[0] = '-';
//     return (size);
// }

int getLength(int num)
{
    int len = 0;
    if(num < 0)
    {
        num = -num;
        len++;
    }
    while(num > 0)
    {
        num /= 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    int length = getLength(nbr);
    int nb = nbr;
    char* str = malloc(sizeof(char) * (length + 1));
    str[length] = '\0';
    if(nbr == 0)
        str[0] = 0;
    if(nbr < 0)
        nbr = -nbr;
    while(length--)
    {
        str[length]= (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    if(nb < 0)
        str[0] = '-';
    return (str);
}
int	main(void)
{
	//printf("%d\n", INT_MIN);
	printf("%s\n", ft_itoa(INT_MAX));
	// printf("%s\n",ft_itoa(2736488));
}

