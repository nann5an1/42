/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprimesum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:14:27 by marvin            #+#    #+#             */
/*   Updated: 2024/09/10 21:14:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_nbr(int sum)
{
    if(sum >= 10)
        put_nbr(sum / 10);
    int digit = sum % 10 + '0';
    write(1, &digit, 1);
}
int ft_atoi(char *str)
{
    int sign = 1;
    int res = 0;
    int i = 0;
    if(str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;
    else if(str[i] == '-')
        sign = -1;
    else if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

int isPrime(int num)
{
    int i = 2;
    if(num <= 1)
        return (0);
    while(i * i <= num)
    {
        if(num % i == 0)
            return (0);
        i++;
    }
    return (1);
}
int main(int argc, char** argv)
{
    int sum = 0;
    if(argc == 2)
    {
        int num = ft_atoi(argv[1]);
        //put_nbr(num);
        while(num > 0)
        {
            if(isPrime(num))
                sum += num;
            num--;
        }
        put_nbr(sum);
    }
    if(argc != 2)
        put_nbr(0);
    write(1, "\n", 1);
}