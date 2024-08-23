/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:38:48 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 00:38:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
unsigned int    lcm(unsigned int a, unsigned int b)
{
    int num;
    
    if(a == 0 || b == 0)
        return (0);
    if(a > b)
        num = a;
    else
        num = b;
    while(1)
    {
        if(num % a == 0 && num % b == 0)
            return (num);
        ++num;
    }
}
int main()
{
   printf("%d", lcm(2, 5));
}