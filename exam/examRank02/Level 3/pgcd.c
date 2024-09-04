/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:49:16 by marvin            #+#    #+#             */
/*   Updated: 2024/08/22 23:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv)
{
    int nb;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    if (argc == 3)
    {
        if(num1 < num2)
            nb = num1;
        else
            nb = num2;
        while(nb--)
        {
            if(num1 % nb == 0 && num2 % nb == 0)
            {
                printf("%d", nb);
                break;
            }
        }
        // if(num1 > 0 && num2 > 0)
        // {
        //     while(num1 != num2)
        //     {
        //         if(num1 > num2)
        //             num1 -= num2;
        //         else if(num2 > num1)
        //             num2 -= num1;
        //     }
        //     printf("%d", num1);
        // }
    }
    printf("\n");
}