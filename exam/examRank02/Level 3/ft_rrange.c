/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:41:11 by marvin            #+#    #+#             */
/*   Updated: 2024/08/25 13:41:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int     *ft_rrange(int start, int end)
{
    int len;
    len = abs(start - end) + 1;

    int* range = malloc(sizeof(int) * len);
    int i = 0;
    if(end >= start)
    {
        while(end >= start)
        {
            range[i++] = end--;
        }
    }
    else
    {
        while(start >= end)
        {
            range[i++] = end++;
        }
    }
    return (range);
}

int main()
{
    int* range = ft_rrange(1, 5);
    for(int i = 0; i <= 9; i++)
        printf("%d\n", range[i]);
    return (0);
}