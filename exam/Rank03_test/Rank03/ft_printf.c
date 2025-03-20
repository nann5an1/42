/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:45:11 by marvin            #+#    #+#             */
/*   Updated: 2024/10/29 11:45:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static void ft_put_str(const char *s, int *count)
{
    int i = 0;
    while (s[i])
    {
        write (1, &s[i], 1);
        i++;
        (*count)++;
    }
}

static void ft_put_nbr(int n, int* count)
{
    char    c;

    if (n == -2147483648)
        ft_put_str("-2147483648", count);
    if (n < 0)
    {
        write(1, "-", 1);
        (*count)++;
        n = -n;
    }
    if (n > 9)
        ft_put_nbr(n / 10, count);
    c = (n % 10) + '0';
    write(1, &c, 1);
    (*count)++;
}

static void ft_puthex(unsigned int n, int *count)
{
    char *hex = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16, count);
    write(1, &hex[n % 16], 1);
    (*count)++;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                 ft_put_str(va_arg(args, char *), &count);
            else if (*format == 'd')
                ft_put_nbr(va_arg(args, int), &count);
            else if (*format == 'x')
                ft_puthex(va_arg(args, unsigned int), &count);
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

int main(void)
{
    const char *s = "Hi there";
    // ft_put_str(s);
    // ft_put_nbr(50);
    // printf("\n");
    // ft_puthex(10);
    printf("%d\n", ft_printf("%d\n", 30));
}
