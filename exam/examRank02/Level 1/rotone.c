/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:07:36 by marvin            #+#    #+#             */
/*   Updated: 2024/08/17 14:07:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void rotone(char* str)
{
        while(*str)
        {
            if(*str >= 'A' && *str<='Z' || *str >= 'a' && *str <= 'z')
                ft_putchar(*str+1);
            else if(*str == 'z' || *str == 'Z')
                ft_putchar(*str-25);
            else
                ft_putchar(*str);
            ++str;
        }
}
int main(int argc, char** argv)
{
    if(argc == 2)
        rotone(argv[1]);
    ft_putchar('\n');
    return (0);
}