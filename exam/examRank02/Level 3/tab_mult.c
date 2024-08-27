/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:32:29 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 13:32:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void put_char(int num)
{
    char c  = num + '0';
    write(1, &c, 1);
}
void put_nbr(int num)
{
    if(num < 10)
        put_char(num);
    else if(num >= 10)
    {
        put_nbr(num / 10);
        put_nbr(num % 10);
    }
}

int ft_atoi(char* ar)
{
    int i = 0;
    int sign = 1;
    int nb = 0;

    while(ar[i] == ' ' || ar[i] == '\t' || ar[i] == '\n' || ar[i] == '\v' || ar[i] == '\f' \
    || ar[i] == '\r')
        i++;
    if (ar[i] == '-' || ar[i] == '+')
    {
        if(ar[i] == '-')
            sign = -1;
        i++;
    }
    while(ar[i] >= '0' && ar[i] <= '9')
    {
        nb = nb * 10 + (ar[i] - '0');
        i++;
    }
    return (nb * sign);
}
int main(int argc, char** argv)
{
    int times = 1;
    int digit = ft_atoi(argv[1]);
    if(argc == 2)
    {
        while(times <= 9)
        {
            put_char(times);
            write(1, " x ", 3);
            put_nbr(digit);
            write(1 , " = ", 3);
            put_nbr(times * digit);
            write(1, "\n", 1);
            times++;
        }
    }
    write(1, "\n", 1);
}