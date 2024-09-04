/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parasum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:44:50 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 21:44:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_nbr(int num)
{
    char c;
    // if(num < 10)
    // {
    //     c = num + '0';
    //     write(1, &c, 1); 
    // }
           
    // else if(num >= 10)
    // {
    //     c = (num / 10) + '0';
    //     write(1, &c, 1);   
    //     put_nbr(num % 10);
    // }

    if(num > 10)
        put_nbr(num / 10);
    int digit = (num % 10) + '0';
    write(1, &digit, 1);
}
int main(int argc, char** argv)
{
    (void)(argv);
    int count = 0;
    if(argc > 1)
        count = argc - 1;
    put_nbr(count);
    write(1, "\n", 1);
}