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
    int i = 1;
    int largest = tab[0];
    
    if(len == 0)
        return (0);
    while(i < len)
    {
        if (tab[i] > largest)
            largest = tab[i];
        i++;
    }
    return (largest);
}
int main()
{
    int tab[] = {1,5,6,4,2,8};
    printf("%d", max(tab, 6));
}