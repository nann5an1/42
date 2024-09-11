/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:40:21 by marvin            #+#    #+#             */
/*   Updated: 2024/09/03 17:40:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
// int ft_atoi(char *str)
// {
//     int i = 0;
//     int sign = 1;
//     int res = 0;

//     if(str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' )
//         i++;
//     if(str[i] == '-')
//         sign = -1;
//     else if(str[i] == '+')
//         i++;
//     while(str[i] >= '0' && str[i] <= '9') 
//     {
//         res = res * 10 + (str[i] - '0');
//         i++;
//     }
//     return (res * sign);
// }
// int main(int ac, char** av)
// {
//     int i = 1;
//     int num;
//     if(ac == 2)
//     {
//         num = ft_atoi(av[1]);
//         if(num == 1)
//             printf("1");
//         while(num >= ++i)
//         {
//             if(num % i == 0)
//             {
//                 printf("%d", i);
//                 if(num == i)
//                     break;
//                 printf("*");
//                 num /= i;
//                 i = 1;
//             }
//         }
//     }
//     printf("\n");
// }


int main(int argc, char* argv[])
{
    int i;
    int num;
    if(argc == 2)
    {
        i = 1;
        num = atoi(argv[1]);
        //printf("%d", num);
        if(num == 1)
            printf("1");
        while(num >= ++i)
        {
            if(num % i == 0)
            {
                printf("%d", i);
                if(num == i)
                    break;
                printf("*");
                num /= i;
                i = 1;
            }
        }
    }
    printf("\n");
}

