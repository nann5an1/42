/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:16:52 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 21:16:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		max(int* tab, unsigned int len)
{
    int i = 0;
    int largest = tab[len-1];
    
    if(len == 0)
        return (0);
    while(len > 0)
    {
        if (tab[len - 1] > largest)
            largest = tab[len - 1];
        len--;
    }
    return (largest);
}
int main()
{
    int tab[] = {};
    printf("%d", max(tab, 0));
}