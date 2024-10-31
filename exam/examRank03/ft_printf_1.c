/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:08:24 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 11:08:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void ft_put_str(char *str, int *count)
{
    int i = 0;
    if(str == NULL)
        str = "(null)";
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
        (*count)++;   
    }
}

void ft_put_nbr(int num, int *count)
{
    if (num == -2147483648)
        write(1, "-2147483648", 1);
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
        (*count)++;
    }
    if (num > 9)
        ft_put_nbr(num / 10, count);
    char c;
    c = num % 10 + '0';
    write(1, &c, 1);
    (*count)++;
}

void ft_put_hex(unsigned int n, int *count)
{
    char *c = "0123456789abcdef";
    if (n >= 16)
        ft_put_hex(n / 16, count);
    write(1, &c[n % 16], 1);
    (*count)++;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while(*format)
    {
        if (*format == '%' || *(format + 1))
        {
            format++;
            if(*format == 's')
                ft_put_str(va_arg(args, char *), &count);
            else if(*format == 'd')
                ft_put_nbr(va_arg(args, int), &count);
            else if(*format == 'x')
                ft_put_hex(va_arg(args, unsigned int), &count);
            else
            {
                write(1, format, 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return (count);
}

int main()
{
    printf("%d\n", ft_printf("%d\n", 30));
}