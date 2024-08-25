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
    // if(range == NULL)
    //     return (0);
    if(end >= start)
    {
        while(end >= start)
        {
            range[len--] = start++;
        }
    }
    else
    {
        while(start >= end)
        {
            range[len--] = start--;
        }
    }
    return (range);
}

int main()
{
    int* range = ft_rrange(10,7);
    for(int i = 0; i <= 7; i++)
        printf("%d\n", range[i]);
    return (0);
}