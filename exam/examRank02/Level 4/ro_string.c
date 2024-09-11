/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ro_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:08:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/11 14:08:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void write_first(char* first, char* end)
{
    while(first <= end)
    {
        write(1, first, 1);
        first++;
    }
}
int main(int ac, char** av)
{
    char* start;
    char* end;
    char* str = av[1];
    if(ac > 1)
    {
        while(*str == '\t' || *str == ' ')
            str++;
        start = str;
        while(*str && *str != '\t' && *str != ' ')
            str++;
        end = str;
        while (*str == ' ' || *str == '\t')
            str++;
        if(*str)
        {
            while(*str)
            {
                if(*str == '\t' || *str == ' ')
                {
                    while(*str == '\t' || *str == ' ')
                        str++;
                    if(*str)
                        write(1, " ", 1);
                }  
                else
                {
                    write(1, str, 1);
                    str++;
                }
            }
            write(1, " ", 1);
        }
        write_first(start, end);
    }
    write(1, "\n", 1);
}