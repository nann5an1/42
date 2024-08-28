/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:01:25 by marvin            #+#    #+#             */
/*   Updated: 2024/08/25 13:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int     *ft_range(int start, int end)
{
    int len;
    len = abs(start - end) + 1;
    int *range = malloc(sizeof(int) * len);
    len = 0;
    if (start <= end)
    {
        while(start <= end)
            range[len++] = start++;
    }
    else
    {
        while(start >= end)
            range[len++] = start--; 
    }
    return (range);
}

int main()
{
    int *range = ft_range(5, 3);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", range[i]);
    }
    free(range);
    return 0;
}